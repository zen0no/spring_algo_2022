#include <iostream>

using namespace std;


int main(){
    int w[8];
    for(int i = 0; i < 8; i ++) cin >> w[i];

    #define A w[0]
    #define B w[1]
    #define C w[2]
    #define D w[3]
    #define E w[4]
    #define F w[5]
    #define G w[6]
    #define H w[7]

    if ((A + C + F + H) - (B + D  + E + G) != 0) {
        cout << "IMPOSSIBLE" << endl;
    }

    else {
        while(1){
            if (A > 0 & B > 0) {
                cout << "AB-" << endl;
                A--;
                B--;
            }

            else if (A > 0 & D > 0){
                cout << "AD-" << endl;
                A--;
                D--;
            }

            else if (A > 0 & E > 0){
                cout << "AE-" << endl;
                A--;
                E--;
            }

            else if (E > 0 & H > 0){
                cout << "EH-" << endl;
                E--;
                H--;
            }

            else if (G > 0 & H > 0){
                cout << "GH-" << endl;
                G--;
                H--;
            }

            else if (D > 0 & H > 0){
                cout << "DH-" << endl;
                D--;
                H--;
            }

            else if (B > 0 & C > 0){
                cout << "BC-" << endl;
                B--;
                C--;
            }

            else if (C > 0 & D > 0){
                cout << "CD-" << endl;
                C--;
                D--;
            }

            else if (C > 0 & G > 0){
                cout << "CG-" << endl;
                C--;
                G--;
            }

            else if (B > 0 & F > 0){
                cout << "BF-" << endl;
                B--;
                F--;
            }

            else if (E > 0 & F > 0){
                cout << "EF-" << endl;
                E--;
                F--;
            }

            else if (F > 0 & G > 0){
                cout << "FG-" << endl;
                F--;
                G--;
            }
            else {
                break;
            }
        }

        while (1){
            if (A > 0 & G > 0){
                cout << "BF+" << endl
                << "FG-" << endl
                << "AB-" << endl;
                A--;
                G--;
            }
            else if (B > 0 & H > 0){
                cout << "AE+" << endl
                << "EH-" << endl
                << "AB-" << endl;
                B--;
                H--;
            }

            else if (D > 0 & F > 0){
                cout << "EF+" << endl
                << "AE-" << endl
                << "AD-" << endl;
                D--;
                F--;
            }

            else if (C > 0 & E > 0){
                cout << "BF+" << endl
                << "EF-" << endl
                << "BC-" << endl;
                C--;
                E--;
            }
            else break;
        }

    }

}