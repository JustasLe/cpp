#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// funkcija, kuri skaiciuoja taskus skyriuje
void skaiciuotiTaskusSkyriuje(vector<int> &taskai, vector<pair<int, int>> &balsai) {
    sort(balsai.rbegin(), balsai.rend());
    if (balsai[0].first > balsai[1].first) {
        taskai[balsai[0].second] += 4;
        return;
    }
    /// kitaip jie yra lygus
    if (balsai[1].first == balsai[2].first) {
        return;
    }
    taskai[balsai[0].second] += 2;
    taskai[balsai[1].second] += 2;
}

/// funkcija, kuri suranda geriausia logotipa
int rastiGeriausia(vector<int> &taskai, vector<int> direktoriausTaskai) {
    vector<pair<int, int>> rezultatai;
    for (int i = 0; i < 3; i++) {
        rezultatai.emplace_back(taskai[i], i);
    }
    sort(rezultatai.rbegin(),rezultatai.rend());
    if (rezultatai[0].first == rezultatai[1].first) {
        for (int i = 0; i < 3; i++) {
            taskai[i] += direktoriausTaskai[i];
        }
        rezultatai.clear();
        for (int i = 0; i < 3; i++) {
            rezultatai.emplace_back(taskai[i], i);
        }
        sort(rezultatai.rbegin(),rezultatai.rend());
        return rezultatai[0].second + 1;
    }
    return rezultatai[0].second + 1;
}

int main () {
    /// pasakome, kad dirbsime su failais
    freopen("U1.txt", "r", stdin);
    freopen("U1rez.txt", "w", stdout);
    /// isivedam duomenis ir skaiciuojam balsus
    int kiekSkyriu;
    cin >> kiekSkyriu;
    vector<int> balsai(3, 0);
    vector<int> taskai(3, 0);
    for (int i = 0; i < kiekSkyriu; i++) {
        vector<pair<int, int>> skyriausBalsai; /// kiek balsu, uz kuri logotipa
        for (int j = 0; j < 3; j++) {
            int kiekBalsu;
            cin >> kiekBalsu;
            balsai[j] += kiekBalsu;
            skyriausBalsai.emplace_back(kiekBalsu, j);
        }
        skaiciuotiTaskusSkyriuje(taskai, skyriausBalsai);
    }
    vector<int> direktoriausTaskai(3);
    for (int &taskas: direktoriausTaskai) {
        cin >> taskas;
    }
    /// isvedam rezultatus
    cout << balsai[0] << " " << balsai[1] << " " << balsai[2] << "\n";
    int geriausias = rastiGeriausia(taskai, direktoriausTaskai);
    cout << taskai[0] << " " << taskai[1] << " " << taskai[2] << "\n";
    cout << geriausias << "\n";
    return 0;
}
