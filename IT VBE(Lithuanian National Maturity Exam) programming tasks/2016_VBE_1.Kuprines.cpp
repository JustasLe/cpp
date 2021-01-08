#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

/// funkcija, kuri suranda sunkiausia kuprine
int rastiSunkiausiosKuprinesMase() {
    freopen("U1.txt", "r", stdin);
    int ats = 0;
    int kiekKupriniu;
    cin >> kiekKupriniu;
    for (int i = 0; i < kiekKupriniu; i++) {
        int svoris;
        cin >> svoris;
        ats = max(ats, svoris);
    }
    return ats;
}

/// funkcija, kuri suranda kiek kupriniu du ir daugiau kartu lengvesnes uz sunkiausia
int rastiKiekKupriniuDuIrDaugiauKartuLengvesnes(int sunkiausiosSvoris) {
    ifstream cin("U1.txt");
    int kiekKupriniu, ats = 0;
    cin >> kiekKupriniu;
    for (int i = 0; i < kiekKupriniu; i++) {
        int svoris;
        cin >> svoris;
        /// nenaudojame dalybos !
        if (svoris * 2 <= sunkiausiosSvoris) {
            ats++;
        }
    }
    return ats;
}

int main() {
    /// pasakome, kad dirbsime su failu ir atliekame skaiciavimus bei isvedame rezultatus
    freopen("U1rez.txt", "w", stdout);
    int sunkiausiosSvoris = rastiSunkiausiosKuprinesMase();
    cout << sunkiausiosSvoris << " " <<
        rastiKiekKupriniuDuIrDaugiauKartuLengvesnes(sunkiausiosSvoris) << "\n";
    return 0;
}
