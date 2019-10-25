#ifndef KLIENT_HPP
#define KLIENT_HPP

#include <iostream>
#include <vector>
#include "Osoba.hpp"
#include "Transakcje.hpp"

class Klient : public Osoba {
 private:
  unsigned int numerKonta;
  float stanKonta;

 public:
  void setNumerKonta(unsigned int numerKonta);
  unsigned int getNumerKonta();
  void setStanKonta(float stanKonta);
  float getStanKonta();
  void wyswietlStanKonta();
  void zmianaHasla();
  void wykonajPrzelew(std::vector<Klient>& klienci, Transakcje& transakcje);
  void wyswietlTransakcje(std::vector<Przelew> przelewy);

  Klient();
  Klient(std::string pesel, std::string imie, std::string nazwisko,
         std::string adres, std::string login, std::string haslo,
         unsigned int numerKonta, float stanKonta);
};

#endif  // KLIENT_HPP
