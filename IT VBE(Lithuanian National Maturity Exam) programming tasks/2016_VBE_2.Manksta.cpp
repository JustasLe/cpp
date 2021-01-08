#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/// struktura, kurioje saugome pratimo duomenis
struct pratimas {
    /// kintamieji
    string pavadinimas;
    int kiekis = 0;
    /// tuscias konstruktorius
    pratimas() {

    }
    /// konstruktorius su parametrais
    pratimas(string pavadinimas, int kiekis) : pavadinimas(pavadinimas), kiekis(kiekis) {

    }
    /// maziau operatorius, kuris mums pades rikiavime
    bool operator <(pratimas kitas) {
        if (kiekis == kitas.kiekis) {
            return pavadinimas < kitas.pavadinimas;
        }
        return kiekis > kitas.kiekis;
    }
};

/// rikiavimo funkcija, pasitelkiame burbulo rikiavima
void rikiuotiPratimus(vector<pratimas> &pratimai) {
    bool baigta = false;
    while (!baigta) {
        baigta = true;
        for (int i = 0; i + 1 < pratimai.size(); i++) {
            if (pratimai[i + 1] < pratimai[i]) {
                baigta = false;
                swap(pratimai[i], pratimai[i + 1]);
            }
        }
    }
}

int main() {
    /// pasakome, kad dirbsime su failais
    freopen("U2.txt", "r", stdin);
    freopen("U2rez.txt", "w", stdout);
    /// susikuriam kintamuosius ir isivedame duomenis
    int kiekPratimu;
    cin >> kiekPratimu;
    cin.ignore();
    /// pasitelkiame patogias duomenu strukturas
    vector<pratimas> pratimai;
    set<string> buvePavadinimai;
    for (int i = 0; i < kiekPratimu; i++) {
        char masyvas[20];
        cin.get(masyvas, 21);
        string pavadinimas = masyvas;
        int kiekis;
        cin >> kiekis;
        cin.ignore();
        /// jei toks pavadinimas jau buvo, pridedame kieki
        if (buvePavadinimai.count(pavadinimas)) {
            for (pratimas &p : pratimai) {
                if (p.pavadinimas == pavadinimas) {
                    p.kiekis += kiekis;
                }
            }
        } else {
            /// kitaip pridedame nauja pratima
            pratimai.emplace_back(pratimas(pavadinimas, kiekis));
            buvePavadinimai.insert(pavadinimas);
        }
    }
    /// surikiuojame pratimus ir isvedame rezultatus
    rikiuotiPratimus(pratimai);
    for (pratimas p : pratimai) {
        cout << p.pavadinimas << " " << p.kiekis << "\n";
    }
    return 0;
}
