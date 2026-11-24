#ifndef USLUGA_H // zabezpieczenie przed podwojnym wczytaniem pliku naglowkowego
#define USLUGA_H

#include <string>
#include <iostream>

using namespace std;

class Usluga {
protected: // dostepne dla klas pochodnych (Tatuaz, Piercing), ukryte przed main i Salon
    int id;
    string klient;
    string artysta;
    double cenaBazowa;

public:
    Usluga(); // konstruktor domyslny
    Usluga(int id, const string& klient, const string& artysta, double cenaBazowa); // konstruktor parametryczny (referencja & unika kopiowania)
    virtual ~Usluga(); // wirtualny destruktor - poprawnie zwalnia pamiec klas pochodnych

    // gettery (const gwarantuje, ze metoda nie zmienia pol obiektu)
    int getId() const;
    string getKlient() const;
    string getArtysta() const;
    double getCenaBazowa() const;

    // settery - bezpieczna modyfikacja pol z walidacja
    void setKlient(const string& nowyKlient);
    void setArtysta(const string& nowyArtysta);
    void setCenaBazowa(double nowaCena);

    // metody czysto wirtualne (= 0) -> klasa Usluga jest abstrakcyjna, realizacja polimorfizmu
    virtual double obliczCeneKoncowa() const = 0;
    virtual string pobierzTyp() const = 0;
    virtual void wyswietlSzczegoly(ostream& os) const; // metoda wirtualna rozszerzana w klasach pochodnych

    // przeciazenie operatorow (Prog 10.0)
    bool operator==(const Usluga& inna) const; // porownuje wizyty po ID
    bool operator<(const Usluga& inna) const;  // porownuje wizyty po cenie koncowej (do sortowania)
    friend ostream& operator<<(ostream& os, const Usluga& usluga); // friend daje dostep do pol protected przy wypisywaniu
};

#endif
