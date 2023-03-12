#include <iostream>
#include <vector>

using namespace std;

vector<int>  vertices[100];
int visited[100];

bool dfs(int i, int color){
    visited[i] = color;

    int next_color = 1 - color;

    for (int j: vertices[i]){
        if (visited[j] == color) return false;
        if (visited[j] == -1 && !dfs(j, next_color)) return false;
    } 
    return true;
}


int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int j;
        cin >> j;
        while (j != 0){
            j -= 1;
            vertices[i].push_back(j);
            vertices[j].push_back(i);
            cin >> j;
        }
        
    }


    for (int i = 0; i < n; i++){
        visited[i] = -1;
    }

    for (int i = 0; i < n; i++){
        if (visited[i] == -1 && !dfs(i, 0)){
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++){
        cout << visited[i];
    }
    cout << endl;

}