#include <bits/stdc++.h>

using namespace std;

struct dievas {
    /// kintamieji
    string vardas;
    vector<int> taskai;
    /// konstruktorius be parametru
    dievas() {

    }
    /// konstruktorius su parametrais
    dievas(string vardas, vector<int> taskai) : vardas(vardas), taskai(taskai) {

    }
};

/// funkcija, kuri nuskaito duomenis
void skaitytiDuomenis(int &kiekDievu, vector<dievas> &dievai) {
    freopen("U2.txt", "r", stdin);
    int kiekKauliuku;
    cin >> kiekDievu >> kiekKauliuku;
    cin.ignore();
    for (int i = 0; i < kiekDievu; i++) {
        char masyvas[10];
        cin.get(masyvas, 11);
        string vardas = masyvas;
        vector<int> taskai(kiekKauliuku);
        for (int &taskas : taskai) {
            cin >> taskas;
        }
        cin.ignore();
        dievai.push_back(dievas(vardas, taskai));
    }
}

/// funkcija, kuri suskaiciuoja vieno valdovo taskus ir kiek lyginiu kauliuku ismete
int rastiSuma(dievas d, int &kiekLyginiu) {
    int suma = 0;
    kiekLyginiu = 0;
    for (int &taskas : d.taskai) {
        if (taskas % 2 == 0) {
            suma += taskas;
            kiekLyginiu++;
        } else {
            suma -= taskas;
        }
    }
    return suma;
}

/// funkcija, kuri suranda valdova
dievas surastiValdova(int kiekDievu, vector<dievas> dievai) {
    int maxSuma = -1, maxLyginiu = -1;
    dievas valdovas;
    for (int i = 0; i < kiekDievu; i++) {
        int kiekLyginiu;
        int suma = rastiSuma(dievai[i], kiekLyginiu);
        if (suma == maxSuma && kiekLyginiu > maxLyginiu) {
            maxLyginiu = kiekLyginiu;
            valdovas = dievai[i];
        }
        if (suma > maxSuma) {
            maxSuma = suma;
            maxLyginiu = kiekLyginiu;
            valdovas = dievai[i];
        }
    }
    return valdovas;
}

int main () {
    /// pasakome, kad dirbsime su failu
    freopen("U2rez.txt", "w", stdout);
    int kiekDievu;
    vector<dievas> dievai;
    /// nusiskaitom duomenis ir surandam valdova
    skaitytiDuomenis(kiekDievu, dievai);
    dievas valdovas = surastiValdova(kiekDievu, dievai);
    /// isvedam atsakyma
    int kiekLyginiu;
    cout << valdovas.vardas << " " << rastiSuma(valdovas, kiekLyginiu);
    return 0;
}
