#include <iostream>
#include <algorithm>

using namespace std;

/// struktura, kurioje saugome avies duomenis
struct avis {
    /// kintamieji
    string vardas, DNR;
    int sutapimoKoeficientas = 0;
    /// tuscias konstruktorius
    avis() {

    }
    /// maziau operatorius, kuris mums pades rikiuojant
    bool operator <(avis kita) {
        if (sutapimoKoeficientas == kita.sutapimoKoeficientas) {
            return DNR < kita.DNR;
        }
        return sutapimoKoeficientas > kita.sutapimoKoeficientas;
    }
};

/// funkcija, kuri nuskaito duomenis
void skaitytiDuomenis(int &kiekAviu, int &DNRilgis, int &kuriAvis, avis avys[]) {
    freopen("U2.txt", "r", stdin);
    cin >> kiekAviu >> DNRilgis;
    cin >> kuriAvis;
    cin.ignore();
    for (int i = 0; i < kiekAviu; i++) {
        char masyvas[10];
        cin.get(masyvas, 11);
        avys[i].vardas = masyvas;
        cin >> avys[i].DNR;
        cin.ignore();
    }
}

/// funkcija, kuri suskaiciuoja dveju aviu sutapimo koeficienta
int skaiciuotiSutapimoKoeficienta(avis pirma, avis antra, int DNRilgis) {
    int ats = 0;
    for (int i = 0; i < DNRilgis; i++) {
        ats += (pirma.DNR[i] == antra.DNR[i]);
    }
    return ats;
}

/// funkcija, kuri rikiuoja avis pasitelkiant burbulo rikiavima
void rikiuotiAvis(avis avys[], int kiekAviu) {
    bool baigta = false;
    while (!baigta) {
        baigta = true;
        for (int i = 0; i + 1 < kiekAviu; i++) {
            if (avys[i + 1] < avys[i]) {
                baigta = false;
                swap(avys[i], avys[i + 1]);
            }
        }
    }
}

/// funkcija, kuri spausdina rezultatus
void spausdintiRezultatus(avis avys[], int kiekAviu) {
    freopen("U2rez.txt", "w", stdout);
    cout << avys[kiekAviu - 1].vardas << "\n";
    for (int i = 0; i + 1 < kiekAviu; i++) {
        cout << avys[i].vardas << " " << avys[i].sutapimoKoeficientas << "\n";
    }
}

int main() {
    /// susikuriam kintamuosius
    int kiekAviu, DNRilgis, kuriAvis;
    const int MAX_DYDIS = 25;
    avis avys[MAX_DYDIS];
    skaitytiDuomenis(kiekAviu, DNRilgis, kuriAvis, avys);
    kuriAvis--;
    avis &ypatinga = avys[kuriAvis];
    /// apskaiciuojam sutapimo koeficientus
    for (int i = 0; i < kiekAviu; i++) {
        avys[i].sutapimoKoeficientas = skaiciuotiSutapimoKoeficienta(avys[i], ypatinga, DNRilgis);
    }
    /// po sio pakeitimo isrikiavus ypatinga avis bus paskutine,
    /// tai pravers spausdinant rezultatus
    ypatinga.sutapimoKoeficientas = -1;
    /// isirkiuojam avis
    rikiuotiAvis(avys, kiekAviu);
    /// spausdiname rezultatus
    spausdintiRezultatus(avys, kiekAviu);
    return 0;
}
