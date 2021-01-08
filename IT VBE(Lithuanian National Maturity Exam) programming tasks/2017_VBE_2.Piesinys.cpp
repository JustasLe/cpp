#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

/// struktura, kurioje saugome staciakampio duomenis
struct staciakampis {
    /// kintamieji
    int pradziosX, pradziosY;
    int plotis, ilgis;
    int red, green, blue;
    /// konstruktorius be parametru
    staciakampis() {

    }
    /// konstruktorius su parametrais
    staciakampis(int x, int y, int plotis, int ilgis, int r, int g, int b) : pradziosX(x), pradziosY(y),
        plotis(plotis), ilgis(ilgis), red(r), green(g), blue(b) {

    }
};

/// funkcija, kuri uzdeda staciakampi ant piesinio
void uzdetiStaciakampi(staciakampis s, vector<vector<tuple<int, int ,int>>> &piesinys) {
    for (int x = s.pradziosX; x < s.pradziosX + s.plotis; x++) {
        for (int y = s.pradziosY; y < s.pradziosY + s.ilgis; y++) {
            piesinys[y][x] = make_tuple(s.red, s.green, s.blue);
        }
    }
}

int main() {
    /// pasakome, kad dirbsime su failais
    freopen("U2.txt", "r", stdin);
    freopen("U2rez.txt", "w", stdout);
    /// sukuriam pradini piesini, baltai
    tuple<int, int, int> baltasLangelis = make_tuple(255, 255, 255);
    vector<vector<tuple<int, int, int>>> piesinys(110, vector<tuple<int, int ,int>>(110, baltasLangelis));
    /// nusiskaitome duomenis
    int kiekStaciakampiu;
    cin >> kiekStaciakampiu;
    int galutinisPlotis = -1, galutinisIlgis = -1;
    for (int i = 0; i < kiekStaciakampiu; i++) {
        int kampoX, kampoY, plotis, ilgis, red, green, blue;
        cin >> kampoX >> kampoY >> plotis >> ilgis >> red >> green >> blue;
        /// sukuriam staciakampi ir ji uzdedam
        staciakampis dabartinis(kampoX, kampoY, plotis, ilgis, red, green, blue);
        uzdetiStaciakampi(dabartinis, piesinys);
        /// tikrinam nauja dydi
        galutinisPlotis = max(galutinisPlotis, kampoX + plotis);
        galutinisIlgis = max(galutinisIlgis, kampoY + ilgis);
    }
    /// isvedame rezultatus
    cout << galutinisIlgis << " " << galutinisPlotis << "\n";
    for (int i = 0; i < galutinisIlgis; i++) {
        for (int j = 0; j < galutinisPlotis; j++) {
            tuple<int, int, int> langelis = piesinys[i][j];
            int red = get<0>(langelis), green = get<1>(langelis), blue = get<2>(langelis);
            cout << red << " " << green << " " << blue << "\n";
        }
    }
    return 0;
}
