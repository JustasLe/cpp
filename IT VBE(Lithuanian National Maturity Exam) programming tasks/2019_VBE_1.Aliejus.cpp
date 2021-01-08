#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// funkcija, kuri suskaiciuoja kiek stiklainiu buvo panaudota ir kiek aliejaus liko
int skaiciuotiKiekBuvoPanaudotaIrKiekLikoAliejaus(vector<int> talpos, vector<int> &uzpildyti,
                                                  int &aliejausKiekis) {
    for (int litrai : {5, 3, 1}) {
        int turimTalpu = talpos[litrai];
        int pakankaAliejaus = aliejausKiekis / litrai;
        int pildysim = min(turimTalpu, pakankaAliejaus);
        uzpildyti[litrai] += pildysim;
        aliejausKiekis -= pildysim * litrai;
    }
}

int main() {
    /// pasakome, kad dirbsime su failais
    freopen("U1.txt", "r", stdin);
    freopen("U1rez.txt", "w", stdout);
    /// suskuriam kintamuosius ir isivedam duomenis
    vector<int> talpos(10), uzpildyti(10, 0);
    int aliejausKiekis;
    cin >> talpos[1] >> talpos[3] >> talpos[5] >> aliejausKiekis;
    int gamybosIslaidos;
    cin >> gamybosIslaidos;
    vector<int> kainos(10);
    cin >> kainos[1] >> kainos[3] >> kainos[5];
    /// kvieciame skaiciavimu funkcija
    skaiciuotiKiekBuvoPanaudotaIrKiekLikoAliejaus(talpos, uzpildyti, aliejausKiekis);
    /// pradedame isvedineti rezultatus
    cout << uzpildyti[1] << " " << uzpildyti[3] << " " << uzpildyti[5] << " "
        << aliejausKiekis << "\n";
    /// paskaiciuojame, kiek stiklainiu liko
    int liko1 = talpos[1] - uzpildyti[1];
    int liko3 = talpos[3] - uzpildyti[3];
    int liko5 = talpos[5] - uzpildyti[5];
    cout << liko1 << " " << liko3 << " " << liko5 << "\n";
    vector<int> darReiketu(10);
    /// paskaiciuojame, kiek stiklainiu dar reiketu
    for (int litrai : {5, 3, 1}) {
        int reikia = aliejausKiekis / litrai;
        darReiketu[litrai] = reikia;
        aliejausKiekis -= reikia * litrai;
    }
    cout << darReiketu[1] << " " << darReiketu[3] << " " << darReiketu[5] << "\n";
    /// pradedam skaiciuoti, kiek pinigu gavome
    int gavomIsPardavimu = 0;
    gavomIsPardavimu += kainos[1] * (uzpildyti[1] + darReiketu[1]);
    gavomIsPardavimu += kainos[3] * (uzpildyti[3] + darReiketu[3]);
    gavomIsPardavimu += kainos[5] * (uzpildyti[5] + darReiketu[5]);
    /// apskaiciuojame ir isvedame pelna
    int pelnas = gavomIsPardavimu - gamybosIslaidos;
    cout << pelnas << "\n";
    return 0;
}
