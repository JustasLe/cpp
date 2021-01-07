#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// sukuriame struktura, kurioje saugosime begiko duomenis
struct begikas {
    string vardasPavarde;
    int minutes, sekundes;
    /// tuscias konstruktorius
    begikas() {

    }
    /// konstruktorius su duomenimis
    begikas(string vardasPavarde, int minutes, int sekundes) : vardasPavarde(vardasPavarde),
        minutes(minutes), sekundes(sekundes) {

    }
    /// maziau operatorius, kuris mums pades daryti std::sort
    bool operator <(begikas kitas) {
        if (minutes == kitas.minutes) {
            return sekundes < kitas.sekundes;
        }
        return minutes < kitas.minutes;
    }
};

/// funkcija, kuri spausdins rezultatus faile
void spausdintiFaile(vector<begikas> atrinkti) {
    freopen("U2rez.txt", "w", stdout);
    for (begikas b : atrinkti) {
        cout << b.vardasPavarde << " " << b.minutes << " " << b.sekundes << "\n";
    }
}

int main() {
    /// sakome, kad dirbsime su failu ir nusiskaitome visus duomenis
    freopen("U2.txt", "r", stdin);
    int grupiuSkaicius;
    cin >> grupiuSkaicius;
    cin.ignore();
    vector<begikas> atrinkti;
    for (int i = 0; i < grupiuSkaicius; i++) {
        int begikuSkaicius;
        cin >> begikuSkaicius;
        cin.ignore();
        const int MAX_DYDIS = 55;
        begikas begikai[MAX_DYDIS];
        for (int j = 0; j < begikuSkaicius; j++) {
            char masyvas[20];
            cin.get(masyvas, 21);
            string vardasPavarde = masyvas;
            int minutes, sekundes;
            cin >> minutes >> sekundes;
            begikai[j] = begikas(vardasPavarde, minutes, sekundes);
            cin.ignore();
        }
        /// isrikiuojame begikus ir atrenkame tuos, kurie greiciausi
        sort(begikai, begikai + begikuSkaicius);
        for (int j = 0; j < begikuSkaicius / 2; j++) {
            atrinkti.push_back(begikai[j]);
        }
    }
    /// isrikiuojame rezultatus ir kvieciame spausdinimo funkcija
    sort(atrinkti.begin(), atrinkti.end());
    spausdintiFaile(atrinkti);
}
