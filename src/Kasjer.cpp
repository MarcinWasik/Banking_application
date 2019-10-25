#include "Kasjer.hpp"
#include <fstream>
#include <limits>
#include "Narzedzia.hpp"
#include "Wplata.hpp"
#include "Wyplata.hpp"

Kasjer::Kasjer() : Osoba() {}

Kasjer::Kasjer(std::string pesel, std::string imie, std::string nazwisko,
               std::string adres, std::string login, std::string haslo,
               std::string idKasjera)
    : idKasjera(idKasjera), Osoba(pesel, imie, nazwisko, adres, login, haslo) {}

void Kasjer::setIdKasjera(std::string idKasjera) {
  this->idKasjera = idKasjera;
}

std::string Kasjer::getIdKasjera() { return idKasjera; }

bool Kasjer::zweryfikujKlienta(std::vector<Klient>& klienci, std::string pesel,
                               std::string nazwisko) {
  bool klientIstnieje = false;
  for (auto& a : klienci) {
    if (a.getPesel() == pesel && a.getNazwisko() == nazwisko) {
      std::cout << "Klient istnieje w bazie!" << std::endl;
      klientIstnieje = true;
    }
  }
  if (!klientIstnieje) {
    std::cout << "Klient nie istnieje w bazie!" << std::endl;
  }
  return klientIstnieje;
}

void Kasjer::zarejestrujWplate(std::vector<Klient>& klienci) {
  try {
    Wplata wplata;
    Narzedzia w;
    std::cout << "Podaj numer konta do przelewu:\n";
    std::cin >> wplata.numerKontaDoPrzelewu;
    if (std::cin.fail()) {
      throw std::string("Nie poprawny typ danych!\n");
    }

    std::cout << "Podaj imie zleceniodawcy:\n";
    std::cin >> wplata.imieZleceniodawcy;
    std::cout << "Podaj nazwisko zleceniodawcy:\n";
    std::cin >> wplata.nazwiskoZleceniodawcy;
    std::cout << "Podaj adres zleceniodawcy:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, wplata.adresZleceniodawcy);
    w.zamianaBialychZnakowNaPodloge(wplata.adresZleceniodawcy);
    std::cout << "Podaj Kwote do przelewu:\n";
    std::cin >> wplata.kwotaDoPrzelewu;
    if (std::cin.fail()) {
      throw std::string("Nie poprawny typ danych!\n");
    }
    bool transakcjaPozytywna = false;
    for (auto& v : klienci) {
      if (v.getNumerKonta() == wplata.numerKontaDoPrzelewu) {
        v.setStanKonta(v.getStanKonta() + wplata.kwotaDoPrzelewu);
        transakcjaPozytywna = true;
        std::cout << "Transakcja przebiegla pomyslnie!\n";
        Narzedzia w;
        std::fstream plik;
        plik.open("/home/marcin/Pulpit/Bank/wplaty.txt",
                  std::ios::app | std::ios::app);
        if (plik.good() == true) {
          plik << w.pobierzAktualnaDate() << " " << wplata.imieZleceniodawcy
               << " " << wplata.nazwiskoZleceniodawcy << " "
               << wplata.adresZleceniodawcy << " " << wplata.tytulPrzelewu
               << " " << wplata.numerKontaDoPrzelewu << " "
               << wplata.kwotaDoPrzelewu;
          plik.close();
        }
      }
    }
    if (!transakcjaPozytywna) {
      std::cout << "Transakcja anulowana! Numer konta niepoprawny!\n";
    }
  } catch (std::string wyjatek) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << wyjatek;
  }
}

void Kasjer::zarejestrujWyplate(std::vector<Klient>& klienci) {
  Wyplata wyplata;
  std::cout << "Podaj pesel klienta:\n";
  std::cin >> wyplata.peselKlienta;
  std::cout << "Podaj nazwisko klienta:\n";
  std::cin >> wyplata.nazwiskoKlienta;
  Narzedzia w;
  bool istniejeKlient =
      zweryfikujKlienta(klienci, wyplata.peselKlienta, wyplata.nazwiskoKlienta);
  if (istniejeKlient) {
    std::cout << "Podaj kwote, którą klient chce wyplacic:\n";
    std::cin >> wyplata.zadanaKwota;
    for (auto& v : klienci) {
      if (v.getPesel() == wyplata.peselKlienta) {
        v.setStanKonta(v.getStanKonta() - wyplata.zadanaKwota);
        std::cout << "Transakcja przebiegla pomyslnie!\n";
        std::fstream plik;
        plik.open("/home/marcin/Pulpit/Bank/wyplaty.txt",
                  std::ios::app | std::ios::app);
        if (plik.good() == true) {
          plik << w.pobierzAktualnaDate() << wyplata.peselKlienta << " "
               << wyplata.nazwiskoKlienta << " " << wyplata.zadanaKwota;
          plik.close();
        }
      }
    }
  } else {
    std::cout << "Brak klienta w bazie!\n";
  }
}
