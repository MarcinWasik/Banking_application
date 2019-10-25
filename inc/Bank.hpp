#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include "Kasjer.hpp"
#include "Klient.hpp"
#include "Przelew.hpp"
#include "Transakcje.hpp"
#include "Zarzadca.hpp"

enum Uzytkownik { klient, kasjer, zarzadca };

class Bank {
 private:
  std::string nazwaPlikuKlienci;
  std::string nazwaPlikuKasjerzy;
  std::string nazwaPlikuZarzadcy;
  std::vector<Klient> klienci;
  std::vector<Kasjer> kasjerzy;
  std::vector<Zarzadca> zarzadcy;
  Transakcje transakcje;
  std::string loginZalogowanegoUzytkownika;

 public:
  Uzytkownik uzytkownik;
  void setKlienci(std::vector<Klient> klienci);
  std::vector<Klient> getKlienci();
  void setKasjerzy(std::vector<Kasjer> kasjerzy);
  std::vector<Kasjer> getKasjerzy();
  void setZarzadcy(std::vector<Zarzadca> zarzadcy);
  std::vector<Zarzadca> getZarzadcy();
  void setTransakcje(Transakcje transakcje);
  Transakcje getTransakcje();
  void wczytywanieDanychKlientow();
  void wczytywanieDanychKasjerow();
  void wczytywanieDanychZarzadcow();
  void zapisywanieDanychKlientow();
  void zapisywanieDanychKasjerow();
  void zapisywanieDanychZarzadcow();
  bool logowanieUzytkownika();
  bool czyIstniejeLogin(std::string login);
  bool czyHasloJestPoprawneDlaLoginu(std::string login, std::string haslo);
  void wyswietlMenuKlienta();
  void wyswietlMenuKasjera();
  void wyswietlMenuZarzadcy();
  void operacjeUzytkownika();
  void operacjeKlienta(bool& niePrzerywac);
  void operacjeKasjera(bool& niePrzerywac);
  void operacjeZarzadcy(bool& niePrzerywac);
  Klient& zwrocZalogowanegoKlienta();
  Kasjer& zwrocZalogowanegoKasjera();
  Zarzadca& zwrocZalogowanegoZarzadce();

  Bank(std::string plikKlienci, std::string plikKasjerzy,
       std::string plikZarzadcy);
  ~Bank();
};

#endif  // BANK_HPP
