#include "Tatuaz.h"

Tatuaz::Tatuaz() : Usluga(), rozmiarCm2(10.0), czyKolorowy(false) {}

Tatuaz::Tatuaz(int id, const string& klient, const string& artysta,
               double cenaBazowa, double rozmiarCm2, bool czyKolorowy)
    : Usluga(id, klient, artysta, cenaBazowa), rozmiarCm2(rozmiarCm2), czyKolorowy(czyKolorowy) {
    if (rozmiarCm2 <= 0) {
        throw "Rozmiar tatuazu musi byc wiekszy od 0 cm2.";
    }
}

Tatuaz::~Tatuaz() {}

double Tatuaz::getRozmiarCm2() const { return rozmiarCm2; }
bool Tatuaz::getCzyKolorowy() const { return czyKolorowy; }

void Tatuaz::setRozmiarCm2(double nowyRozmiar) {
    if (nowyRozmiar <= 0) {
        throw "Rozmiar tatuazu musi byc wiekszy od 0 cm2.";
    }
    rozmiarCm2 = nowyRozmiar;
}

void Tatuaz::setCzyKolorowy(bool kolor) {
    czyKolorowy = kolor;
}

double Tatuaz::obliczCeneKoncowa() const {
    double suma = cenaBazowa + (rozmiarCm2 * 15.0);
    if (czyKolorowy) {
        suma *= 1.25;
    }
    return suma;
}

string Tatuaz::pobierzTyp() const {
    return "Tatuaz";
}

void Tatuaz::wyswietlSzczegoly(ostream& os) const {
    Usluga::wyswietlSzczegoly(os);
    os << " | Rozmiar: " << rozmiarCm2 << " cm2"
       << " | Kolor: " << (czyKolorowy ? "Tak" : "Nie");
}
