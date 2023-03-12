#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;

    int w[n];

    for(int i = 0; i < n; i++){
        cin >> w[i];
    }

    int ans = 12e5; // INF

    //Перебераем всевозможные варинты, то есть 2^n
    for (long i = 0; i < (1 << n); i++){
        int s1 = 0; //вес первой кучи 
        int s2 = 0; //вес второй кучи

        long k = i;

        //считаем суммы. Если i-ый бит равен 1, то камень идёт в первую кучу, иначе во вторую
        for(int j = 0; j < n; j++){
            if (k % 2 == 1) s1 += w[j];
            else s2 += w[j];
            k >>= 1;
        }

        //обновляем ответ, если разность меньше
        if (abs(s1 - s2) < ans) ans = abs(s1 - s2);
    }

    cout << ans << endl;
}