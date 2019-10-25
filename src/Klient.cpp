#include "Klient.hpp"
#include <limits>
#include "Narzedzia.hpp"
#include "Przelew.hpp"

Klient::Klient() : Osoba() {}

Klient::Klient(std::string pesel, std::string imie, std::string nazwisko,
               std::string adres, std::string login, std::string haslo,
               unsigned int numerKonta, float stanKonta)
    : numerKonta(numerKonta),
      stanKonta(stanKonta),
      Osoba(pesel, imie, nazwisko, adres, login, haslo) {}

void Klient::setNumerKonta(unsigned int numerKonta) {
  this->numerKonta = numerKonta;
}

unsigned int Klient::getNumerKonta() { return numerKonta; }

void Klient::setStanKonta(float stanKonta) { this->stanKonta = stanKonta; }

float Klient::getStanKonta() { return stanKonta; }

void Klient::wyswietlStanKonta() {
  std::cout << "Stan konta wynosi: " << stanKonta << "\n";
}

void Klient::zmianaHasla() {
  std::string stareHaslo;
  std::cout << "Podaj stare haslo:\n";
  std::cin >> stareHaslo;
  if (getHaslo() == stareHaslo) {
    std::string noweHaslo;
    std::cout << "Podaj nowe haslo:\n";
    std::cin >> noweHaslo;
    setHaslo(noweHaslo);
  } else {
    std::cout << "Niepoprawne haslo!\n";
  }
}

void Klient::wykonajPrzelew(std::vector<Klient>& klienci,
                            Transakcje& transakcje) {
  try {
    Narzedzia w;
    unsigned int numerKontaNabywcy;
    std::string tytul;
    unsigned int kwota;
    std::cout << "Podaj numer konta do przelewu:\n";
    std::cin >> numerKontaNabywcy;
    if (std::cin.fail()) {
      throw std::string("Nie poprawny typ danych!\n");
    }
    std::cout << "Podaj tytul do przelewu:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, tytul);
    w.zamianaBialychZnakowNaPodloge(tytul);
    std::cout << "Podaj kwote do przelewu:\n";
    std::cin >> kwota;
    if (std::cin.fail()) {
      throw std::string("Nie poprawny typ danych!\n");
    }
    Przelew przelew(w.pobierzAktualnaDate(), numerKonta, numerKontaNabywcy,
                    tytul, kwota);
    bool transakcjaPoprawna = false;
    for (auto& v : klienci) {
      if (v.getNumerKonta() == numerKontaNabywcy) {
        v.setStanKonta(v.getStanKonta() + kwota);
        stanKonta = stanKonta - kwota;
        std::cout << "Transakcja przebiegla pomyslnie!\n";
        std::vector<Przelew> v = transakcje.getPrzelewy();
        v.push_back(przelew);
        transakcje.setPrzelewy(v);
        transakcjaPoprawna = true;
      }
    }
    if (!transakcjaPoprawna) {
      std::cout
          << "Transakcja przebiegla niepoprawnie! Nabywca nie istnieje!\n";
    }
  } catch (std::string wyjatek) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << wyjatek;
  }
}

void Klient::wyswietlTransakcje(std::vector<Przelew> przelewy) {
  std::cout << "Historia transakcji:\n";
  for (auto v : przelewy) {
    if (v.getNumerKontaKlienta() == numerKonta ||
        v.getNumerKontaNabywcy() == numerKonta) {
      std::cout << "Data: " << v.getData()
                << " Zleceniodawca: " << v.getNumerKontaKlienta()
                << " Nabywca: " << v.getNumerKontaNabywcy()
                << " Tytul Przelewu: " << v.getTytulPrzelewu()
                << " Kwota przelewu: " << v.getKwota() << std::endl;
    }
  }
}
