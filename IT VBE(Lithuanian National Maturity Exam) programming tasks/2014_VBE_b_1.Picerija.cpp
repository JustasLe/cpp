#include <iostream>
#include <vector>

using namespace std;

/// funkcija, kuri nuskaito duomenis
void skaitytiDuomenis(int &kiekUzsakovu, int &kilometruPlanas,
                      vector<pair<int, int>> &uzsakovai) {
    freopen("U1.txt", "r", stdin);
    cin >> kiekUzsakovu >> kilometruPlanas;
    uzsakovai.resize(kiekUzsakovu);
    for (auto &pora : uzsakovai) {
        cin >> pora.first >> pora.second;
    }
}

/// funkcija, kuri apskaiciuoja atstuma tarp picerijos ir uzsakovo pirmyn ir atgal
int apskaiciuotiAtstuma(int uzsakovoX, int uzsakovoY) {
    return 2 * (abs(uzsakovoX) + abs(uzsakovoY));
}

/// funkcija, kuri spausdina rezultatus
void spausdintiRezultatus(int kiekNeaptarnautu, int nuvaziuotiKilometrai) {
    freopen("U1rez.txt", "w", stdout);
    cout << kiekNeaptarnautu << " " << nuvaziuotiKilometrai << "\n";
}

int main () {
    /// sukuriam kintamuosius ir nusiskaitome duomenis
    int kiekUzsakovu, kilometruPlanas;
    vector<pair<int, int>> uzsakovai; /// uzsakovo x ir y
    skaitytiDuomenis(kiekUzsakovu, kilometruPlanas, uzsakovai);
    int jauNuvaziuota = 0;
    int neaptarnauta = kiekUzsakovu;
    /// lankome uzsakovus ir skaiciuojam
    for (int i = 0; i < kiekUzsakovu && jauNuvaziuota <= kilometruPlanas; i++) {
        jauNuvaziuota += apskaiciuotiAtstuma(uzsakovai[i].first, uzsakovai[i].second);
        neaptarnauta--;
    }
    /// spausdiname rezultatus
    spausdintiRezultatus(neaptarnauta, jauNuvaziuota);
    return 0;
}
