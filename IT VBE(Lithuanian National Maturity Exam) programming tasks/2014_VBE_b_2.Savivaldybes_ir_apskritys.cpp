#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/// struktura, kurioje saugomi savivaldybes duomenys
struct savivaldybe {
    /// kintamieji
    string pavadinimas;
    int kiekMokyklu;
    string apskritiesPavadinimas;
    /// konstruktorius be parametru
    savivaldybe() {

    }
};

int main() {
    /// pasakome, kad dirbsime su failais
    freopen("U2.txt", "r", stdin);
    freopen("U2rez.txt", "w", stdout);
    /// susikuriam kintamuosius ir isivedam duomenis
    int savivaldybiuSkaicius;
    cin >> savivaldybiuSkaicius;
    cin.ignore();
    const int MAX_DYDIS = 65;
    savivaldybe savivaldybes[MAX_DYDIS];
    set<string> apskritys;
    map<string, int> kiekSavivaldybiu;
    map<string, int> kiekDaugiausiaMokyklu;
    for (int i = 0; i < savivaldybiuSkaicius; i++) {
        char masyvas[20];
        cin.get(masyvas, 21);
        savivaldybes[i].pavadinimas = masyvas;
        cin >> savivaldybes[i].kiekMokyklu;
        cin.ignore();
        char kitasMasyvas[13];
        cin.get(kitasMasyvas, 14);
        cin.ignore();
        string apskritis = kitasMasyvas;
        savivaldybes[i].apskritiesPavadinimas = apskritis;
        /// dirbame su duomenu strukturomis, kurios cia labai tinka
        apskritys.insert(apskritis);
        kiekSavivaldybiu[apskritis]++;
        kiekDaugiausiaMokyklu[apskritis] = max(kiekDaugiausiaMokyklu[apskritis],
                                               savivaldybes[i].kiekMokyklu);
    }
    /// pradedame isvedineti rezultatus
    cout << apskritys.size() << "\n";
    vector<tuple<string, int, int>> rezultatai;
    for (set<string>::iterator it = apskritys.begin(); it != apskritys.end(); it++) {
        rezultatai.emplace_back(*it, kiekSavivaldybiu[*it], kiekDaugiausiaMokyklu[*it]);
    }
    /// isrikiuojame rezultatus pagal nurodytus kriterijus
    sort(rezultatai.begin(), rezultatai.end(), [&](const tuple<string, int, int> &first,
                                                   const tuple<string, int, int> &second) {
        int kiekMokyklu1 = get<2>(first), kiekMokyklu2 = get<2>(second);
        string pavadinimas1 = get<0>(first), pavadinimas2 = get<0>(second);
        if (kiekMokyklu1 == kiekMokyklu2) {
            return pavadinimas1 < pavadinimas2;
        }
        return kiekMokyklu1 > kiekMokyklu2;
         });
    /// isvedame galutinius rezultatus
    for (auto tup : rezultatai) {
        cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << "\n";
    }
    return 0;
}
