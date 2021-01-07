#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

/// konstanta, kiek skirtingu figuru tipu yra
const int FIGURU_KIEKIS = 6;

/// funkcija, kuri suskaiciuoja kiek komplektu galime sudaryti
int kiekKomplektu(int figuros[], int mokiniuKiekis) {
    /// kiek skirtingu tipu figuru reikia vienam komplektui
    int kiekReikia[] = {8, 2, 2, 2, 1, 1};
    /// skaiciuojam kiek galim sudaryti
    int galim = INT_MAX;
    for (int i = 0; i < FIGURU_KIEKIS; i++) {
        galim = min(galim, figuros[i] / kiekReikia[i]);
    }
    /// grazinam min, kad netycia nesudarytum daugiau komplektu nei turim juodu figuru
    /// komplektu, kuriu turim tiek, kiek yra mokiniu
    return min(galim, mokiniuKiekis);
}

int main () {
    /// pasakome, kad dirbsime su failais
    freopen("U1.txt", "r", stdin);
    freopen("U1.rez.txt", "w", stdout);
    const int MAX_DYDIS = 110;
    /// sukuriam pradini masyva
    int figuros[FIGURU_KIEKIS] = {0};
    int mokiniuSkaicius;
    /// nusiskaitom visus duomenis
    cin >> mokiniuSkaicius;
    for (int i = 0; i < mokiniuSkaicius; i++) {
        for (int j = 0; j < FIGURU_KIEKIS; j++) {
            int kiekFiguru;
            cin >> kiekFiguru;
            /// sumuojam, kiek is viso tam tikro tipo baltu figuru turime
            figuros[j] += kiekFiguru;
        }
    }
    /// suskaiciuojam ir isvedam atsakyma
    int atsakymas = kiekKomplektu(figuros, mokiniuSkaicius);
    cout << atsakymas << "\n";
	return 0;
}
