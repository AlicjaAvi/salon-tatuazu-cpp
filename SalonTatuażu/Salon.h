#ifndef SALON_H
#define SALON_H

#include <vector>
#include <string>
#include "Usluga.h"

using namespace std;

class Salon {
private:
    string nazwaSalonu;
    vector<Usluga*> wizyty;

public:
    Salon();
    explicit Salon(const string& nazwa);
    ~Salon();

    string getNazwaSalonu() const;
    void setNazwaSalonu(const string& nowaNazwa);

    // Operacje na obiektach (CRUD)
    void dodajWizyte(Usluga* nowaWizyta);
    void usunWizytePoId(int id);
    void modyfikujCeneBazowa(int id, double nowaCena);
    void wyszukajPoKliencie(const string& fraza) const;
    void wyswietlWszystkieWizyty() const;
    void sortujWizytyWgCeny();
};

#endif
