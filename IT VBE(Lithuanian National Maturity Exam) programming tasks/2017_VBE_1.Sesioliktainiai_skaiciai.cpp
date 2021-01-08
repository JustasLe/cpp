#include <iostream>

using namespace std;

/// funkcija, kuri konvertuoja desimtaini skaiciu (iki 255) i sesioliktaini
string konvertuotiISesioliktaini(int skaicius) {
    /// atliekame viska pagal salyga
    string rezultatas = "";
    int sveikojiDalis = skaicius / 16;
    if (sveikojiDalis < 10) {
        rezultatas += to_string(sveikojiDalis);
    } else {
        rezultatas += (char) ('A' + sveikojiDalis - 10);
    }
    int liekana = skaicius % 16;
    if (liekana < 10) {
        rezultatas += to_string(liekana);
    } else {
        rezultatas += (char) ('A' + liekana - 10);
    }
    return rezultatas;
}

int main() {
    /// pasakome, kad dirbsime su failais
    freopen("U1.txt", "r", stdin);
    freopen("U1rez.txt", "w", stdout);
    /// susikuriam kintamuosius, nusiskaitom duomenis ir skaiciuojame bei isvedame rezultatus
    int ilgis, plotis;
    cin >> ilgis >> plotis;
    for (int i = 0; i < ilgis * plotis; i++) {
        string langelis = "";
        for (int j = 0; j < 3; j++) {
            int skaicius;
            cin >> skaicius;
            /// pridedame langelio duomenis
            langelis += konvertuotiISesioliktaini(skaicius);
        }
        /// isvedame langeli
        cout << langelis << ";\n"[(i + 1) % plotis == 0];
    }
    return 0;
}
