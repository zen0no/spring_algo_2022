#include <iostream>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;
    int A[n];
    int idA[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
        idA[i] = i;
    }

    for(int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (A[i] > A[j]) {swap(A[i], A[j]); swap(idA[i], idA[j]);}
        }
    }
    
    int id = 0;
    int k = A[0];
    string stack[k];
    while(id < n){
        string s = "";
        cout << id << endl;
        for (int i = 0; i < id; i++){
            s = s + to_string(idA[i] + 1) + " ";
        }
        if (id == n - 1){
            while(A[id] > 0){
                A[id]--;
                cout << s;
                stack[A[id]] = s;
            }
            ++id;
        }
        else {
            while(A[id] > 0  & A[id] < A[id + 1]){
                A[id]--;
                cout << s << endl;
                cout << A[id] << endl;
                stack[A[id]] = s;

            }
            id++;
        }
    }

    for (int i = 0; i < k; i++){
        cout << stack[i];
    }
}