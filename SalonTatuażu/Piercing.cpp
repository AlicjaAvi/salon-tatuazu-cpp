#include "Piercing.h"

using namespace std;

Piercing::Piercing()
    : Usluga(), miejscePrzeklucia("Ucho"), materialKolczyka("Tytan") {}

Piercing::Piercing(int id, const string& klient, const string& artysta,
                   double cenaBazowa, const string& miejscePrzeklucia, const string& materialKolczyka)
    : Usluga(id, klient, artysta, cenaBazowa),
      miejscePrzeklucia(miejscePrzeklucia),
      materialKolczyka(materialKolczyka) {
    if (miejscePrzeklucia.empty() || materialKolczyka.empty()) {
        throw invalid_argument("Miejsce przeklucia oraz material kolczyka nie moga byc puste.");
    }
}

Piercing::~Piercing() {}

string Piercing::getMiejscePrzeklucia() const { return miejscePrzeklucia; }
string Piercing::getMaterialKolczyka() const { return materialKolczyka; }

void Piercing::setMiejscePrzeklucia(const string& noweMiejsce) {
    if (noweMiejsce.empty()) {
        throw invalid_argument("Miejsce przeklucia nie moze byc puste.");
    }
    miejscePrzeklucia = noweMiejsce;
}

void Piercing::setMaterialKolczyka(const string& nowyMaterial) {
    if (nowyMaterial.empty()) {
        throw invalid_argument("Material kolczyka nie moze byc pusty.");
    }
    materialKolczyka = nowyMaterial;
}

double Piercing::obliczCeneKoncowa() const {
    // Tytan G23 dolicza +50 PLN do ceny bazowej, pozostałe materiały +20 PLN
    double doplata = (materialKolczyka == "Tytan" || materialKolczyka == "tytan") ? 50.0 : 20.0;
    return cenaBazowa + doplata;
}

string Piercing::pobierzTyp() const {
    return "Piercing";
}

void Piercing::wyswietlSzczegoly(ostream& os) const {
    Usluga::wyswietlSzczegoly(os);
    os << " | Miejsce: " << miejscePrzeklucia
       << " | Material: " << materialKolczyka;
}
