#ifndef ZARZADCA_HPP
#define ZARZADCA_HPP

#include <string>
#include "Klient.hpp"
#include "Osoba.hpp"
#include "Transakcje.hpp"

class Zarzadca : public Osoba {
 private:
  std::string idZarzadcy;

 public:
  void dodajKlienta(std::vector<Klient>& klienci);
  void wyswietlListeKlientow(std::vector<Klient>& klienci);
  void usunKlienta(std::vector<Klient>& klienci);
  void setIdZarzadcy(std::string idZarzadcy);
  std::string getIdZarzadcy();
  void pobierzKwoteZaProwadzenieKonta(std::vector<Klient>& klienci,
                                      int kosztProwadzeniaKonta);
  Zarzadca();
  Zarzadca(std::string pesel, std::string imie, std::string nazwisko,
           std::string adres, std::string login, std::string haslo,
           std::string idZarzadcy);
};

#endif  // ZARZADCA_HPP
