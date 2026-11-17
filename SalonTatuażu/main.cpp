#include <iostream>
#include "Salon.h"
#include "Tatuaz.h"
#include "Piercing.h"

using namespace std;

int main() {
    Salon salon("Ink & Needle Studio");

    // Dane testowe do sprawdzenia czy dziedziczenie dziala
    salon.dodajWizyte(new Tatuaz(1, "Anna_Nowak", "Marek", 300.0, 25.0, false));
    salon.dodajWizyte(new Piercing(2, "Kamil_Kowalski", "Zuza", 120.0, "Septum", "Tytan"));

    int wybor = -1;
    while (wybor != 0) {
        cout << "\n--- MENU SALONU ---\n"
             << "1. Wyswietl wszystkie wizyty\n"
             << "2. Dodaj tatuaz\n"
             << "3. Dodaj piercing\n"
             // dodac wyszukiwanie, sortowanie i usuwanie po ID
             << "0. Wyjscie\n"
             << "Wybor: ";

        cin >> wybor;

        if (wybor == 1) {
            salon.wyswietlWszystkieWizyty();
        } else if (wybor == 2) {
            int id, kolor;
            string klient, artysta;
            double cena, rozmiar;

            cout << "ID: "; cin >> id;
            cout << "Klient: "; cin >> klient;
            cout << "Artysta: "; cin >> artysta;
            cout << "Cena bazowa: "; cin >> cena;
            cout << "Rozmiar cm2: "; cin >> rozmiar;
            cout << "Kolor (1/0): "; cin >> kolor;

            salon.dodajWizyte(new Tatuaz(id, klient, artysta, cena, rozmiar, kolor == 1));
        } else if (wybor == 3) {
            // dokonczyc wczytywanie piercingu z konsoli
            cout << "do zrobienia";
        }
    }

    return 0;
}
