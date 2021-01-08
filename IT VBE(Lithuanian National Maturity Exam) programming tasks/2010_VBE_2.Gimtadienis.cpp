#include <iostream>
#include <vector>

using namespace std;

struct patiekalas {
    /// kintamieji
    string pavadinimas;
    vector<int> reikalingiProduktai;
    /// konstruktorius be parametru
    patiekalas() {

    }
    /// konstruktorius su parametrais
    patiekalas(string pav, vector<int> produktai) : pavadinimas(pav),
        reikalingiProduktai(produktai) {

    }
};

/// funkcija, kuri suskaiciuoja, kiek kainuoja vienas patiekalas
int kiekKainuoja(int kainos[], patiekalas p) {
    int suma = 0;
    for (int i = 0; i < p.reikalingiProduktai.size(); i++) {
        suma += kainos[i] * p.reikalingiProduktai[i];
    }
    return suma;
}

/// funkcija, kuri suskaiciuoja vieno svecio pietu kaina
int skaiciuotiSvecioPietuKaina(int dydis, int kainos[], patiekalas patiekalai[]) {
    int suma = 0;
    for (int i = 0; i < dydis; i++) {
        suma += kiekKainuoja(kainos, patiekalai[i]);
    }
    return suma;
}

int main() {
    /// pasakome, kad dirbsime su failais
    freopen("U2.txt", "r", stdin);
    freopen("U2rez.txt", "w", stdout);
    /// susikuriam kintamuosius ir nusiskaitom duomenis
    int produktuKiekis, patiekaluKiekis;
    cin >> produktuKiekis >> patiekaluKiekis;
    cin.ignore();
    const int MAX_DYDIS = 20;
    int kainos[MAX_DYDIS];
    for (int i = 0; i < produktuKiekis; i++) {
        cin >> kainos[i];
    }
    cin.ignore();
    patiekalas patiekalai[MAX_DYDIS];
    for (int i = 0; i < patiekaluKiekis; i++) {
        char masyvas[15];
        cin.get(masyvas, 16);
        string pavadinimas = masyvas;
        vector<int> produktai(produktuKiekis);
        for (int &kiekis : produktai) {
            cin >> kiekis;
        }
        cin.ignore();
        patiekalai[i] = patiekalas(pavadinimas, produktai);
        /// isvedam pavadinima ir patiekalo kaina
        cout << pavadinimas << " " << kiekKainuoja(kainos, patiekalai[i]) << "\n";
    }
    /// suskaiciuojam ir isvedam svecio pietu kaina
    int kainaCentais = skaiciuotiSvecioPietuKaina(patiekaluKiekis, kainos, patiekalai);
    int litai = kainaCentais / 100;
    int centai = kainaCentais % 100;
    cout << litai << " " << centai << "\n";
    return 0;
}
