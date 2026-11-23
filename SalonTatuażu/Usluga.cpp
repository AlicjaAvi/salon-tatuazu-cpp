#include "Usluga.h"

Usluga::Usluga() : id(0), klient("Nieznany"), artysta("Brak"), cenaBazowa(100.0) {}

Usluga::Usluga(int id, const string& klient, const string& artysta, double cenaBazowa)
    : id(id), klient(klient), artysta(artysta), cenaBazowa(cenaBazowa) {
    if (id <= 0) {
        throw "ID wizyty musi byc liczba dodatnia.";
    }
    if (klient.empty() || artysta.empty()) {
        throw "Imie klienta oraz artysty nie moga byc puste.";
    }
    if (cenaBazowa <= 0) {
        throw "Cena bazowa musi byc wieksza od zera.";
    }
}

Usluga::~Usluga() {}

int Usluga::getId() const { return id; }
string Usluga::getKlient() const { return klient; }
string Usluga::getArtysta() const { return artysta; }
double Usluga::getCenaBazowa() const { return cenaBazowa; }

void Usluga::setKlient(const string& nowyKlient) {
    if (nowyKlient.empty()) {
        throw "Imie klienta nie moze byc puste.";
    }
    klient = nowyKlient;
}

void Usluga::setArtysta(const string& nowyArtysta) {
    if (nowyArtysta.empty()) {
        throw "Imie artysty nie moze byc puste.";
    }
    artysta = nowyArtysta;
}

void Usluga::setCenaBazowa(double nowaCena) {
    if (nowaCena <= 0) {
        throw "Nowa cena bazowa musi byc wieksza od zera.";
    }
    cenaBazowa = nowaCena;
}

void Usluga::wyswietlSzczegoly(ostream& os) const {
    os << "[ID: " << id << "] Typ: " << pobierzTyp()
       << " | Klient: " << klient
       << " | Artysta: " << artysta
       << " | Cena bazowa: " << cenaBazowa << " PLN";
}

bool Usluga::operator==(const Usluga& inna) const {
    return this->id == inna.id;
}

bool Usluga::operator<(const Usluga& inna) const {
    return this->obliczCeneKoncowa() < inna.obliczCeneKoncowa();
}

ostream& operator<<(ostream& os, const Usluga& usluga) {
    usluga.wyswietlSzczegoly(os);
    os << " | Cena koncowa: " << usluga.obliczCeneKoncowa() << " PLN";
    return os;
}
