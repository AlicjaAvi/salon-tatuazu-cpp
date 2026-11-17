# System zarządzania salonem tatuażu i piercingu

Projekt zaliczeniowy z przedmiotu **Podstawy programowania obiektowego w C++**.

## 1. Opis architektury

System umożliwia zarządzanie rezerwacjami i wizytami w studiu tatuażu i piercingu. Został zaprojektowany zgodnie z paradygmatem obiektowym:

* **`Usluga`** – abstrakcyjna klasa bazowa reprezentująca pojedynczą wizytę w salonie. Przechowuje identyfikator (`id`), dane klienta, imię artysty oraz cenę bazową. Definiuje czysto wirtualne metody `obliczCeneKoncowa()` oraz `pobierzTyp()`, a także przeciąża operatory:
  * `operator==` – porównuje usługi po unikalnym `id`,
  * `operator<` – porównuje usługi na podstawie polimorficznie obliczanej ceny końcowej,
  * `operator<<` – formatuje i wypisuje szczegóły wizyty na strumień wyjściowy.
* **`Tatuaz`** – klasa pochodna dziedzicząca po `Usluga`. Rozszerza model o powierzchnię tatuażu (`rozmiarCm2`) oraz informację o kolorze (`czyKolorowy`). Cena końcowa uwzględnia stawkę za każdy cm2 oraz narzut 25% za tusz kolorowy.
* **`Piercing`** – klasa pochodna dziedzicząca po `Usluga`. Zawiera informację o miejscu przekłucia (`miejscePrzeklucia`) i materiale biżuterii (`materialKolczyka`). Cena końcowa uwzględnia koszt materiału (wyższa dopłata za hipoalergiczny tytan).
* **`Salon`** – klasa zarządzająca kolekcją polimorficznych wskaźników `std::vector<Usluga*>`. Odpowiada za operacje CRUD (dodawanie, wyszukiwanie, modyfikację, sortowanie oraz usuwanie wizyt) oraz zwalnianie pamięci w destruktorze (relacja kompozycji).
* **Obsługa wyjątków (`try-catch-throw`)** – konstruktory, settery oraz metody klasy `Salon` rzucają wyjątki `std::invalid_argument` oraz `std::runtime_error` w przypadku próby wprowadzenia ujemnej ceny, pustych napisów, zduplikowanego ID lub odwołania do nieistniejącej wizyty.

## 2. Schemat klas UML

```mermaid
classDiagram
    class Usluga {
        <<abstract>>
        #int id
        #string klient
        #string artysta
        #double cenaBazowa
        +Usluga()
        +Usluga(int id, string klient, string artysta, double cenaBazowa)
        +virtual ~Usluga()
        +getId() int
        +getKlient() string
        +getArtysta() string
        +getCenaBazowa() double
        +setKlient(string nowyKlient) void
        +setArtysta(string nowyArtysta) void
        +setCenaBazowa(double nowaCena) void
        +obliczCeneKoncowa()* double
        +pobierzTyp()* string
        +wyswietlSzczegoly(ostream& os) void
        +operator==(const Usluga& inna) bool
        +operator<(const Usluga& inna) bool
    }

    class Tatuaz {
        -double rozmiarCm2
        -bool czyKolorowy
        +Tatuaz()
        +Tatuaz(int id, string klient, string artysta, double cenaBazowa, double rozmiarCm2, bool czyKolorowy)
        +~Tatuaz()
        +getRozmiarCm2() double
        +getCzyKolorowy() bool
        +setRozmiarCm2(double nowyRozmiar) void
        +setCzyKolorowy(bool kolor) void
        +obliczCeneKoncowa() double
        +pobierzTyp() string
        +wyswietlSzczegoly(ostream& os) void
    }

    class Piercing {
        -string miejscePrzeklucia
        -string materialKolczyka
        +Piercing()
        +Piercing(int id, string klient, string artysta, double cenaBazowa, string miejscePrzeklucia, string materialKolczyka)
        +~Piercing()
        +getMiejscePrzeklucia() string
        +getMaterialKolczyka() string
        +setMiejscePrzeklucia(string noweMiejsce) void
        +setMaterialKolczyka(string nowyMaterial) void
        +obliczCeneKoncowa() double
        +pobierzTyp() string
        +wyswietlSzczegoly(ostream& os) void
    }

    class Salon {
        -string nazwaSalonu
        -vector~Usluga*~ wizyty
        +Salon()
        +Salon(string nazwa)
        +~Salon()
        +getNazwaSalonu() string
        +setNazwaSalonu(string nowaNazwa) void
        +dodajWizyte(Usluga* nowaWizyta) void
        +usunWizytePoId(int id) void
        +modyfikujCeneBazowa(int id, double nowaCena) void
        +wyszukajPoKliencie(string fraza) void
        +wyswietlWszystkieWizyty() void
        +sortujWizytyWgCeny() void
    }

    Usluga <|-- Tatuaz : dziedziczenie
    Usluga <|-- Piercing : dziedziczenie
    Salon *-- Usluga : kompozycja
```

## 3. Instrukcja kompilacji i uruchomienia

Wymagany kompilator wspierający standard **C++17** (np. `g++` lub `clang++`).

### Kompilacja w terminalu:
```bash
g++ -std=c++17 -Wall -Wextra main.cpp Usluga.cpp Tatuaz.cpp Piercing.cpp Salon.cpp -o salon
```

### Uruchomienie:
* Linux / macOS: `./salon`
* Windows: `salon.exe`

## 4. Przykłady działania programu

### Wyświetlenie listy wizyt (opcja `1`):
```text
=== Lista wizyt w salonie: Ink & Needle Studio ===
[ID: 1] Typ: Tatuaz | Klient: Anna Nowak | Artysta: Marek | Cena bazowa: 300 PLN | Rozmiar: 25 cm2 | Kolor: Nie | Cena koncowa: 675 PLN
[ID: 2] Typ: Piercing | Klient: Kamil Kowalski | Artysta: Zuza | Cena bazowa: 120 PLN | Miejsce: Septum | Material: Tytan | Cena koncowa: 170 PLN
[ID: 3] Typ: Tatuaz | Klient: Piotr Wisniewski | Artysta: Marek | Cena bazowa: 400 PLN | Rozmiar: 40 cm2 | Kolor: Tak | Cena koncowa: 1250 PLN
[ID: 4] Typ: Piercing | Klient: Anna Nowak | Artysta: Zuza | Cena bazowa: 150 PLN | Miejsce: Daith | Material: Tytan | Cena koncowa: 200 PLN
```

### Przechwycenie wyjątku przy próbie dodania błędnych danych (opcja `2`):
```text
Podaj ID wizyty: 5
Imie i nazwisko klienta: Jan Testowy
Artysta (tatuator): Marek
Cena bazowa (PLN): -100
Rozmiar tatuazu (cm2): 15
Czy kolorowy? (1 - Tak, 0 - Nie): 0

[WYJATEK / BLAD]: Cena bazowa musi byc wieksza od zera.
```