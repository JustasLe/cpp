#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

/// struktura, kurioje saugome vykdymo rezultatus
struct sekosVykdymas {
    /// kintamieji
    int visoIvykdyta = 0;
    int seka[35];
    string rezultatas;
    /// konstruktorius be parametru
    sekosVykdymas() {

    }
};

int main() {
    /// pasakome, kad dirbsime su failais
    freopen("U2.txt", "r", stdin);
    freopen("U2rez.txt", "w", stdout);
    /// susikuriam kintamuosius ir nusiskaitome pradinius duomenis
    int pradziosX, pradziosY, pabaigosX, pabaigosY;
    cin >> pradziosX >> pradziosY;
    cin >> pabaigosX >> pabaigosY;
    int kiekKomanduSeku;
    cin >> kiekKomanduSeku;
    const int MAX_DYDIS = 15;
    sekosVykdymas vykdymai[MAX_DYDIS];
    for (int i = 0; i < kiekKomanduSeku; i++) {
        int dabartinisX = pradziosX, dabartinisY = pradziosY;
        int sekosIlgis;
        cin >> sekosIlgis;
        bool baigta = false;
        sekosVykdymas dabartinis;
        for (int j = 0; j < sekosIlgis; j++) {
            int komanda;
            cin >> komanda;
            if (!baigta) {
                /// jei netycia x0 == x1 ir y0 == y1
                if (pradziosX == pabaigosX && pradziosY == pabaigosY) {
                    dabartinis.rezultatas = "pasiektas tikslas";
                    baigta = true;
                } else {
                    /// atliekame judejimo skaiciavimus ir tikriname bei keiciame rezultata
                    switch (komanda) {
                        case 1: dabartinisY++; break;
                        case 2: dabartinisX++; break;
                        case 3: dabartinisY--; break;
                        case 4: dabartinisX--; break;
                        default: assert(false);
                    }
                    dabartinis.seka[dabartinis.visoIvykdyta++] = komanda;
                    if (dabartinisX == pabaigosX && dabartinisY == pabaigosY) {
                        dabartinis.rezultatas = "pasiektas tikslas";
                        baigta = true;
                    }
                }
            }
        }
        if (!baigta) {
            dabartinis.rezultatas = "sekos pabaiga";
        }
        /// isvedame vykdymo rezultatus
        cout << left << setw(20) << dabartinis.rezultatas << " ";
        for (int j = 0; j < dabartinis.visoIvykdyta; j++) {
            cout << dabartinis.seka[j] << " ";
        }
        cout << dabartinis.visoIvykdyta << "\n";
    }
    return 0;
}
