#ifndef TATUAZ_H
#define TATUAZ_H

#include "Usluga.h"

using namespace std;

class Tatuaz : public Usluga {
private:
    double rozmiarCm2;
    bool czyKolorowy;

public:
    Tatuaz();
    Tatuaz(int id, const string& klient, const string& artysta,
           double cenaBazowa, double rozmiarCm2, bool czyKolorowy);
    ~Tatuaz() override;

    double getRozmiarCm2() const;
    bool getCzyKolorowy() const;

    void setRozmiarCm2(double nowyRozmiar);
    void setCzyKolorowy(bool kolor);

    double obliczCeneKoncowa() const override;
    string pobierzTyp() const override;
    void wyswietlSzczegoly(ostream& os) const override;
};

#endif
