#include <iostream>
#include "Salon.h"
#include "Tatuaz.h"
#include "Piercing.h"

using namespace std;
// referencja Salon& pozwala modyfikowac oryginalny obiekt salonu z main()
void zaladujDaneStartowe(Salon& salon) {
    // operator new alokuje obiekt w pamieci dynamicznej i zwraca wskaznik
    salon.dodajWizyte(new Tatuaz(1, "Anna_Nowak", "Marek", 300.0, 25.0, false));
    salon.dodajWizyte(new Piercing(2, "Kamil_Kowalski", "Zuza", 120.0, "Septum", "Tytan"));
    salon.dodajWizyte(new Tatuaz(3, "Piotr_Wisniewski", "Marek", 400.0, 40.0, true));
    salon.dodajWizyte(new Piercing(4, "Anna_Nowak", "Zuza", 150.0, "Daith", "Tytan"));
}

int main() {
    Salon salon("Ink & Needle Studio");
    zaladujDaneStartowe(salon);

    int wybor = -1;
    while (wybor != 0) { 
        cout << "\n============================================\n"
             << "  SYSTEM ZARZADZANIA SALONEM TATUAZU I PIERCINGU\n"
             << "============================================\n"
             << "1. Wyswietl wszystkie wizyty\n"
             << "2. Dodaj wizyte - Tatuaz\n"
             << "3. Dodaj wizyte - Piercing\n"
             << "4. Wyszukaj wizyty po kliencie\n"
             << "5. Modyfikuj cene bazowa wizyty\n"
             << "6. Sortuj wizyty rosnaco wg ceny koncowej (operator <)\n"
             << "7. Usun wizyte po ID\n"
             << "0. Wyjscie\n"
             << "Twoj wybor: ";

        cin >> wybor;

        try { // blok chroniony - wylapuje bledy rzucone przez throw w klasach
            if (wybor == 1) {
                salon.wyswietlWszystkieWizyty();
            } else if (wybor == 2) {
                int id, kolorWybor;
                string klient, artysta;
                double cena, rozmiar;

                cout << "Podaj ID wizyty: ";
                cin >> id;
                cout << "Klient (np. Jan_Kowalski): ";
                cin >> klient;
                cout << "Artysta (tatuator): ";
                cin >> artysta;
                cout << "Cena bazowa (PLN): ";
                cin >> cena;
                cout << "Rozmiar tatuazu (cm2): ";
                cin >> rozmiar;
                cout << "Czy kolorowy? (1 - Tak, 0 - Nie): ";
                cin >> kolorWybor;

                // kolorWybor == 1 zamienia liczbe 1/0 na wartosc bool true/false
                salon.dodajWizyte(new Tatuaz(id, klient, artysta, cena, rozmiar, kolorWybor == 1));
                cout << "Pomyslnie dodano wizyte na tatuaz!\n";

            } else if (wybor == 3) {
                int id;
                string klient, artysta, miejsce, material;
                double cena;

                cout << "Podaj ID wizyty: ";
                cin >> id;
                cout << "Klient (np. Jan_Kowalski): ";
                cin >> klient;
                cout << "Artysta (piercer): ";
                cin >> artysta;
                cout << "Cena bazowa (PLN): ";
                cin >> cena;
                cout << "Miejsce przeklucia (np. Septum, Daith, Labret): ";
                cin >> miejsce;
                cout << "Material kolczyka (Tytan / Stal): ";
                cin >> material;

                salon.dodajWizyte(new Piercing(id, klient, artysta, cena, miejsce, material));
                cout << "Pomyslnie dodano wizyte na piercing!\n";

            } else if (wybor == 4) {
                string fraza;
                cout << "Podaj imie lub nazwisko klienta: ";
                cin >> fraza;
                salon.wyszukajPoKliencie(fraza);

            } else if (wybor == 5) {
                int id;
                double nowaCena;
                cout << "Podaj ID wizyty do modyfikacji: ";
                cin >> id;
                cout << "Podaj nowa cene bazowa (PLN): ";
                cin >> nowaCena;

                salon.modyfikujCeneBazowa(id, nowaCena);
                cout << "Cena bazowa zostala zaktualizowana.\n";

            } else if (wybor == 6) {
                salon.sortujWizytyWgCeny();
                cout << "Wizyty zostaly posortowane rosnaco wg ceny koncowej.\n";
                salon.wyswietlWszystkieWizyty();

            } else if (wybor == 7) {
                int id;
                cout << "Podaj ID wizyty do usuniecia: ";
                cin >> id;

                salon.usunWizytePoId(id);
                cout << "Wizyta o ID " << id << " zostala usunieta.\n";

            } else if (wybor == 0) {
                cout << "Zamykanie programu...\n";
            } else {
                cout << "Nieznana opcja w menu.\n";
            }
        } catch (const char* blad) { // przechwytuje tekst rzucony przez throw
            cout << "\n[BLAD]: " << blad << "\n";
        }
    }

    return 0; //automatycznie wywoluje destruktor ~Salon()
}
