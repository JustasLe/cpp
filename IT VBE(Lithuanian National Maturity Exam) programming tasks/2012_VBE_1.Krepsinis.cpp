#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// krepsininko struktura
struct krepsininkas {
    /// kintamieji
    int nr;
    int sedejo = 0, zaide = 0;
    int kiekLaiku;
    int laikai[45];
    /// konstruktorius be parametru
    krepsininkas() {

    }
    /// konstruktorius su parametrais
    krepsininkas(int numeris, int laikuKiekis, int laikai2[]) {
        nr = numeris;
        kiekLaiku = laikuKiekis;
        /// suskaiciuojam, kiek krepsininkas sedejo ir kiek zaide
        for (int i = 0; i < kiekLaiku; i++) {
            laikai[i] = laikai2[i];
            int laikas = laikai[i];
            if (laikas > 0) {
                zaide += laikas;
            } else {
                sedejo -= laikas;
            }
        }
    }
};

/// nusiskaitom duomenis
void skaitytiDuomenis(krepsininkas krepsininkai[], int &krepsininkuKiekis,
                      vector<int> &pradinisPenketas) {
    freopen("U1.txt", "r", stdin);
    cin >> krepsininkuKiekis;
    for (int i = 0; i < krepsininkuKiekis; i++) {
        int nr;
        cin >> nr;
        int kiekLaiku;
        cin >> kiekLaiku;
        const int MAX_LAIKU = 45;
        int laikai[MAX_LAIKU];
        for (int i = 0; i < kiekLaiku; i++) {
            cin >> laikai[i];
            /// jei krepsininkas pradejo rungtynes, idedam ji i starto penketa
            if (i == 0 && laikai[i] > 0) {
                pradinisPenketas.push_back(nr);
            }
        }
        krepsininkai[i] = krepsininkas(nr, kiekLaiku, laikai);
    }
}

/// ieskom daugiausiai zaidusio
int rastiDaugiausiaiZaidusi(krepsininkas krepsininkai[], int krepsininkuKiekis) {
    int indeksas = 0;
    for (int i = 1; i < krepsininkuKiekis; i++) {
        if (krepsininkai[i].zaide == krepsininkai[indeksas].zaide &&
            krepsininkai[i].nr < krepsininkai[indeksas].nr) {
            indeksas = i;
        }
        if (krepsininkai[i].zaide > krepsininkai[indeksas].zaide) {
            indeksas = i;
        }
    }
    return indeksas;
}

/// ieskom daugiausiai sedejusio
int rastiDaugiausiaiSedejusi(krepsininkas krepsininkai[], int krepsininkuKiekis) {
    int indeksas = 0;
    for (int i = 1; i < krepsininkuKiekis; i++) {
        if (krepsininkai[i].sedejo == krepsininkai[indeksas].sedejo &&
            krepsininkai[i].nr < krepsininkai[indeksas].nr) {
            indeksas = i;
        }
        if (krepsininkai[i].sedejo > krepsininkai[indeksas].sedejo) {
            indeksas = i;
        }
    }
    return indeksas;
}

int main () {
    /// pasakom, kad dirbsime su failu
    freopen("U1rez.txt", "w", stdout);
    /// sukuriam kintamuosius
    int krepsininkuKiekis;
    const int MAX_DYDIS = 20;
    krepsininkas krepsininkai[MAX_DYDIS];
    vector<int> startinisPenketas;
    skaitytiDuomenis(krepsininkai, krepsininkuKiekis, startinisPenketas);
    /// isrikiuojam startini penketa ir isvedam
    sort(startinisPenketas.begin(), startinisPenketas.end());
    for (int i = 0; i < 5; i++) {
        cout << startinisPenketas[i] << " \n"[i + 1 == 5];
    }
    /// surandam ir isvedam duomenis apie rupimus krepsininkus
    int daugiausiaiZaidusioIndeksas = rastiDaugiausiaiZaidusi(krepsininkai,
                                                              krepsininkuKiekis);
    int daugiausiaiSedejusioIndeksas = rastiDaugiausiaiSedejusi(krepsininkai,
                                                                krepsininkuKiekis);
    cout << krepsininkai[daugiausiaiZaidusioIndeksas].nr << " " <<
        krepsininkai[daugiausiaiZaidusioIndeksas].zaide << "\n";
    cout << krepsininkai[daugiausiaiSedejusioIndeksas].nr << " " <<
        krepsininkai[daugiausiaiSedejusioIndeksas].sedejo << "\n";
    return 0;
}
