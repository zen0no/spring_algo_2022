#include <iostream>


using namespace std;

#define LSB(x) x&-x


void update_fenwick_tree(int tree[], int k, int size){
    int i = k;
    while (i <= size){
        tree[i] -= 1;
        i += LSB(i);
    }
}

int prefixsum(int tree[], int k, int size){
    int sum = 0;
    int i = k;
    while (i > 0){
        sum += tree[i];
        i -= LSB(i);
    }

    return sum;
    
}


int main(){

    int N, K;
    cin >> N >> K;
    int FT[N + 1];


    for (int i = 0; i <= N; i++){
        FT[i] = LSB(i);
    }

    
    int counter = N;
    int s;

    int p = 0;

    do {
        int psum = prefixsum(FT, p, N);
        int nK;
        int l, r, m;
        if (counter - psum >= K){
            l = p; r = N; nK = K;
        }

        else {
            l = 0; r = N; nK = (K - counter + psum - 1) % counter + 1; psum = 0;
        }

        //cout << "psum: " << psum << " counter: " << counter << " nK: " << nK << " l: " << l << " r: " << r << endl;
        while (l < r - 1){
            m = (l + r) / 2;
            int npsum = prefixsum(FT, m, N);
            //cout << m << " " << npsum << " " << nK << endl;

            if (npsum - psum < nK) l = m; else r = m;
        }
        //cout << "psums ";
        for (int i = 1; i <= N; i++){
            //cout << prefixsum(FT, i, N) << " ";
        }

        //cout << endl;
        

        p = r;
        update_fenwick_tree(FT, p, N);
        cout << p << " ";
    }

    while(--counter);
}