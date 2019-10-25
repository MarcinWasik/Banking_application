#include "Transakcje.hpp"
#include <fstream>
#include "Narzedzia.hpp"
#include "Przelew.hpp"

Transakcje::Transakcje() { wczytywaniePrzelewow(); }

Transakcje::~Transakcje() { zapisywaniePrzelewow(); }

void Transakcje::wczytywaniePrzelewow() {
  std::fstream plik("/home/marcin/Pulpit/Bank/przelewy.txt");
  if (plik.good()) {
    std::string data, tytulPrzelewu;
    int numerKontaKlienta;
    int numerKontaNabywcy;
    float kwota;
    while (plik >> data >> numerKontaKlienta >> numerKontaNabywcy >>
           tytulPrzelewu >> kwota) {
      Przelew wczytany(data, numerKontaKlienta, numerKontaNabywcy,
                       tytulPrzelewu, kwota);
      przelewy.push_back(wczytany);
    }
  }
}

void Transakcje::zapisywaniePrzelewow() {
  std::ofstream zapisz("/home/marcin/Pulpit/Bank/przelewy.txt");
  for (auto v : przelewy) {
    zapisz << v.getData() << " " << v.getNumerKontaKlienta() << " "
           << v.getNumerKontaNabywcy() << " " << v.getTytulPrzelewu() << " "
           << v.getKwota() << std::endl;
  }
}

void Transakcje::setPrzelewy(std::vector<Przelew> przelewy) {
  this->przelewy = przelewy;
}

std::vector<Przelew> Transakcje::getPrzelewy() { return przelewy; }

void Transakcje::wyswietlanieWplat() {
  Narzedzia w;
  std::cout << "Wplaty:\n";
  w.wczytywaniePliku("/home/marcin/Pulpit/Bank/wplaty.txt");
}

void Transakcje::wyswietlanieWyplat() {
  Narzedzia w;
  std::cout << "Wyplaty:\n";
  w.wczytywaniePliku("/home/marcin/Pulpit/Bank/wyplaty.txt");
}

void Transakcje::wyswietlaniePrzelewow() {
  Narzedzia w;
  std::cout << "Przelewy:\n";
  w.wczytywaniePliku("/home/marcin/Pulpit/Bank/przelewy.txt");
}
