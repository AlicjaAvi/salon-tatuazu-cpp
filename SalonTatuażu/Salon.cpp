#include "Salon.h"
#include <iostream>
#include <algorithm>

using namespace std;

Salon::Salon() : nazwaSalonu("Domyslny Salon") {}

Salon::Salon(const string& nazwa) : nazwaSalonu(nazwa) {}

Salon::~Salon() {
    for (Usluga* u : wizyty) {
        delete u;
    }
    wizyty.clear();
}

string Salon::getNazwaSalonu() const { return nazwaSalonu; }

void Salon::setNazwaSalonu(const string& nowaNazwa) {
    if (nowaNazwa.empty()) {
        throw "Nazwa salonu nie moze byc pusta.";
    }
    nazwaSalonu = nowaNazwa;
}

void Salon::dodajWizyte(Usluga* nowaWizyta) {
    if (!nowaWizyta) {
        throw "Nie mozna dodac pustego wskaznika wizyty.";
    }
    for (const Usluga* u : wizyty) {
        if (*u == *nowaWizyta) {
            delete nowaWizyta;
            throw "Wizyta o podanym ID juz istnieje w systemie.";
        }
    }
    wizyty.push_back(nowaWizyta);
}

void Salon::usunWizytePoId(int id) {
    for (auto it = wizyty.begin(); it != wizyty.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            wizyty.erase(it);
            return;
        }
    }
    throw "Nie znaleziono wizyty o podanym ID.";
}

void Salon::modyfikujCeneBazowa(int id, double nowaCena) {
    for (Usluga* u : wizyty) {
        if (u->getId() == id) {
            u->setCenaBazowa(nowaCena);
            return;
        }
    }
    throw "Nie znaleziono wizyty o podanym ID.";
}

void Salon::wyszukajPoKliencie(const string& fraza) const {
    bool znaleziono = false;
    cout << "\n--- Wyniki wyszukiwania dla klienta: \"" << fraza << "\" ---\n";
    for (const Usluga* u : wizyty) {
        if (u->getKlient().find(fraza) != string::npos) {
            cout << *u << "\n";
            znaleziono = true;
        }
    }
    if (!znaleziono) {
        cout << "Brak wizyt dla podanego klienta.\n";
    }
}

void Salon::wyswietlWszystkieWizyty() const {
    cout << "\n=== Lista wizyt w salonie: " << nazwaSalonu << " ===\n";
    if (wizyty.empty()) {
        cout << "Brak zaplanowanych wizyt.\n";
        return;
    }
    for (const Usluga* u : wizyty) {
        cout << *u << "\n";
    }
}

void Salon::sortujWizytyWgCeny() {
    sort(wizyty.begin(), wizyty.end(), [](const Usluga* a, const Usluga* b) {
        return *a < *b;
    });
}
