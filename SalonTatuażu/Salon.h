#ifndef SALON_H
#define SALON_H

#include <vector>
#include <string>
#include "Usluga.h"

class Salon {
private:
    string nazwaSalonu;
    vector<Usluga*> wizyty; // wektor wskaznikow bazowych -> przechowuje razem Tatuaz i Piercing (polimorfizm)

public:
    Salon();
    explicit Salon(const string& nazwa); // explicit blokuje niejawna konwersje string -> Salon
    ~Salon(); // destruktor zwalnia pamiec obiektow z wektora (kompozycja)

    string getNazwaSalonu() const;
    void setNazwaSalonu(const string& nowaNazwa);

    // operacje CRUD na obiektach
    void dodajWizyte(Usluga* nowaWizyta);
    void usunWizytePoId(int id);
    void modyfikujCeneBazowa(int id, double nowaCena);
    void wyszukajPoKliencie(const string& fraza) const;
    void wyswietlWszystkieWizyty() const;
    void sortujWizytyWgCeny();
};

#endif
