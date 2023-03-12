#include <iostream>
#include <cmath>

using namespace std;


void combat_sort(int n, int a[]){
    const float factor = 1.247;
    double step = n - 1;
    
    while (step >= 1) {
        for (int i = 0; i + step < n; i++){ 
            if (a[i] < a[(int) (i + step)]){
                swap(a[i], a[(int) (i + step)]);
            }
        }
        step /= factor;
    }
}


int main(){
    int n;
    int s = 0;
    cin >> n;

    int w[n];
    for(int i = 0; i < n; i++)
        cin >> w[i], s += w[i];

    combat_sort(n, w);


    int f[n][s / 2 + 1];

    if (n == 1) {cout << w[0] << endl; return 0;}

    for (int i = 0; i < s / 2; i++){
        f[0][i] = 0;
    }

    for (int i  = 1; i < n; i++){
        for (int j = 0; j < s / 2 + 1; j++){
            if (w[i] > j) f[i][j] = f[i - 1][j];
            else  f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + w[i]);
        }
    }

    cout << s - 2 * f[n - 1][s / 2] << endl;

}
