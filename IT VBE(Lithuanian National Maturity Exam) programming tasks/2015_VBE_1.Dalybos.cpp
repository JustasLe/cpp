#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// funkcija, kuri suskaiciuoja kiek suvalge kiekvienas mokinys
vector<int> apskaiciuotiKiekSuvalgeMokiniai(vector<int> kiekSuvalgeMergaites) {
    vector<int> rezultatai = kiekSuvalgeMergaites;
    /// pridedam berniukus
    for (int i = 0; i < 10; i++) {
        rezultatai.push_back(0);
    }
    assert(rezultatai.size() == 20);
    /// suskaiciuojam kiek liko visuose dubeneliuose
    vector<int> liko;
    for (int i = 0; i < 10; i++) {
        liko.push_back(10 - kiekSuvalgeMergaites[i]);
    }
    /// siunciam visus dubenelius toliau ir skaiciuojam
    for (int i = 0; i < 10; i++) {
        int pozicija = i + 1;
        while (liko[i]) {
            assert(pozicija < 20);
            rezultatai[pozicija]++;
            liko[i]--;
            pozicija++;
        }
    }
    /// grazinam rezultatus
    return rezultatai;
}

int main() {
    /// pasakome, kad dirbsime su failais
    freopen("U1.txt", "r", stdin);
    freopen("U1rez.txt", "w", stdout);
    /// isivedam duomenis
    vector<int> kiekSuvalgeMergaites(10);
    for (int &suvalge : kiekSuvalgeMergaites) {
        cin >> suvalge;
    }
    /// apskaiciuojam ir isvedam rezultatus
    vector<int> rezultatai = apskaiciuotiKiekSuvalgeMokiniai(kiekSuvalgeMergaites);
    for (int i = 0; i < 20; i++) {
        cout << rezultatai[i] << " \n"[i + 1 == 20];
    }
    return 0;
}
