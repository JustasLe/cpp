#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// funkcija, kuri rikiuoja slidininkus pasitelkdama burbulo rikiavima
void rikiuotiSlidininkus(vector<pair<string, int>> &slidininkai) {
    bool baigta = false;
    while (!baigta) {
        baigta = true;
        for (int i = 0; i + 1 < slidininkai.size(); i++) {
            /// tikriname, ar reikia apkeisti juos vietomis
            if (slidininkai[i + 1].second < slidininkai[i].second) {
                baigta = false;
                swap(slidininkai[i], slidininkai[i + 1]);
            }
            if (slidininkai[i + 1].second == slidininkai[i].second) {
                if (slidininkai[i + 1].first < slidininkai[i].first) {
                    baigta = false;
                    swap(slidininkai[i], slidininkai[i + 1]);
                }
            }
        }
    }
}

/// funkcija, kuri spausddina rezultatus faile
void spausdintiRezultatusFaile(vector<pair<string, int>> sportininkai) {
    freopen("U2rez.txt", "w", stdout);
    for (auto pora : sportininkai) {
        cout << pora.first << " " << pora.second / 60 << " " << pora.second % 60 << "\n";
    }
}

int main() {
    /// nurodome, kad skaitysime is failo
    freopen("U2.txt", "r", stdin);
    /// nusiskaitome duomenis
    int kiekStartavo;
    cin >> kiekStartavo;
    cin.ignore();
    vector<pair<string, int>> startaveSlidininkai; /// vardas, startavimo laikas sekundemis
    for (int i = 0; i < kiekStartavo; i++) {
        char masyvas[20];
        cin.get(masyvas, 21);
        string vardas = masyvas;
        int h, m, s;
        cin >> h >> m >> s;
        cin.ignore();
        /// apskaiciuojam startavimo laika sekundemis
        s += m * 60 + h * 60 * 60;
        startaveSlidininkai.emplace_back(vardas, s);
    }
    /// nusiskaitome pabaigusius slidininkus
    int kiekPabaige;
    cin >> kiekPabaige;
    cin.ignore();
    vector<pair<string, int>> pabaigeSlidininkai; /// vardas, uztrukimo laikas sekundemis
    for (int i = 0; i < kiekPabaige; i++) {
        char masyvas[20];
        cin.get(masyvas, 21);
        string vardas = masyvas;
        int h, m, s;
        cin >> h >> m >> s;
        cin.ignore();
        /// pabaigos laika paverciame i laika sekundemis
        s += m * 60 + h * 60 * 60;
        /// ieskome slidininko pradiniame sarase ir skaiciuojam kiek jis uztruko
        for (int j = 0; j < kiekStartavo; j++) {
            if (startaveSlidininkai[j].first == vardas) {
                /// idedame ji i vektoriu
                pabaigeSlidininkai.emplace_back(vardas, s - startaveSlidininkai[j].second);
            }
        }
    }
    /// isrikiuojame rezultatus ir juos spausdiname faile
    rikiuotiSlidininkus(pabaigeSlidininkai);
    spausdintiRezultatusFaile(pabaigeSlidininkai);
    return 0;
}
