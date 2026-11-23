#ifndef USLUGA_H
#define USLUGA_H

#include <string>
#include <iostream>

using namespace std;

class Usluga {
protected:
    int id;
    string klient;
    string artysta;
    double cenaBazowa;

public:
    Usluga();
    Usluga(int id, const string& klient, const string& artysta, double cenaBazowa);
    virtual ~Usluga();

    int getId() const;
    string getKlient() const;
    string getArtysta() const;
    double getCenaBazowa() const;

    void setKlient(const string& nowyKlient);
    void setArtysta(const string& nowyArtysta);
    void setCenaBazowa(double nowaCena);

    virtual double obliczCeneKoncowa() const = 0;
    virtual string pobierzTyp() const = 0;
    virtual void wyswietlSzczegoly(ostream& os) const;

    bool operator==(const Usluga& inna) const;
    bool operator<(const Usluga& inna) const;
    friend ostream& operator<<(ostream& os, const Usluga& usluga);
};

#endif
