#include <iostream>
#include <algorithm>

using namespace std;

/// struktura, kuriome saugomi sportininko duomenys
struct sportininkas {
    /// kintamieji
    string vardas;
    int numeris;
    int pradziosLaikas;
    int pabaigosLaikas;
    int uztruko;
    /// konstruktorius su parametrais
    sportininkas(string vardas, int numeris, int pradziosLaikas) : vardas(vardas),
        numeris(numeris), pradziosLaikas(pradziosLaikas) {

    }
    /// maziau operatorius, kuris mums pades rikiuojant
    bool operator <(sportininkas kitas) {
        if (uztruko == kitas.uztruko) {
            return vardas < kitas.vardas;
        }
        return uztruko < kitas.uztruko;
    }
};

/// rikiavimo funkcija, kuri pasitelkia burbulo rikiavima
void rikiuotiSportininkus(vector<sportininkas> &sportininkai) {
    bool baigta = false;
    while (!baigta) {
        baigta = true;
        for (int i = 0; i + 1 < sportininkai.size(); i++) {
            if (sportininkai[i + 1] < sportininkai[i]) {
                baigta = false;
                swap(sportininkai[i], sportininkai[i + 1]);
            }
        }
    }
}

/// funkcija, kuri spausdina rezultatus faile
void spausdintiFaile(vector<sportininkas> sportininkai, string eilute) {
    /// atidarome faila su append mode
    freopen("U2rez.txt", "a", stdout);
    cout << eilute << "\n";
    for (sportininkas dabartinis : sportininkai) {
        cout << dabartinis.numeris << " " << dabartinis.vardas << " ";
        /// apskaiciuojam pabaigos laika formatu h:m:s
        int h = dabartinis.uztruko / (60 * 60);
        dabartinis.uztruko %= (60 * 60);
        int m = dabartinis.uztruko / 60;
        int s = dabartinis.uztruko % 60;
        cout << h << " " << m << " " << s << "\n";
    }
}

int main() {
    /// nurodome, kad skaitysime is failo
    freopen("U2.txt", "r", stdin);
    /// susikuriame kintamuosius ir nusiskaitome duomenis
    int kiekStartavo;
    cin >> kiekStartavo;
    cin.ignore();
    vector<sportininkas> startaveSportininkai;
    for (int i = 0; i < kiekStartavo; i++) {
        char masyvas[20];
        cin.get(masyvas, 21);
        string vardas = masyvas;
        int numeris;
        cin >> numeris;
        int h, m, s;
        cin >> h >> m >> s;
        cin.ignore();
        /// suskaiciuojam laika sekundemis
        s += m * 60 + h * 60 * 60;
        startaveSportininkai.push_back(sportininkas(vardas, numeris, s));
    }
    /// isivedam dar daugiau duomenu
    int kiekFinisavo;
    cin >> kiekFinisavo;
    vector<sportininkas> finisavusiosMerginos, finisaveVaikinai;
    for (int i = 0; i < kiekFinisavo; i++) {
        int numeris;
        cin >> numeris;
        int h, m, s;
        cin >> h >> m >> s;
        for (sportininkas dabartinis : startaveSportininkai) {
            if (dabartinis.numeris == numeris) {
                int nepataike = 0;
                /// tikriname, kokia dalyvio lytis ir pagal tai nusiskaitome duomenis
                /// bei skaiciuojame nepataikytus suvius
                if (numeris / 100 == 1) {
                    vector<int> taiklusSuviai(2);
                    for (int &kiekTaikliu : taiklusSuviai) {
                        cin >> kiekTaikliu;
                        nepataike += 5 - kiekTaikliu;
                    }
                } else {
                    vector<int> taiklusSuviai(4);
                    for (int &kiekTaikliu : taiklusSuviai) {
                        cin >> kiekTaikliu;
                        nepataike += 5 - kiekTaikliu;
                    }
                }
                /// pridedam baudos minutes
                m += nepataike;
                /// paverciam laika sekundemis
                s += m * 60 + h * 60 * 60;
                dabartinis.pabaigosLaikas = s;
                dabartinis.uztruko = dabartinis.pabaigosLaikas - dabartinis.pradziosLaikas;
                /// dedame i rezultatus
                if (numeris / 100 == 1) {
                    finisavusiosMerginos.push_back(dabartinis);
                } else {
                    finisaveVaikinai.push_back(dabartinis);
                }
            }
        }
    }
    /// surikiuojame rezultatus
    rikiuotiSportininkus(finisavusiosMerginos);
    rikiuotiSportininkus(finisaveVaikinai);
    /// jei failas jau yra, ji pasaliname, nes darysime append text
    remove("U2rez.txt");
    /// kvieciame spausdinimo funkcijas
    spausdintiFaile(finisavusiosMerginos, "Merginos");
    spausdintiFaile(finisaveVaikinai, "Vaikinai");
    return 0;
}
