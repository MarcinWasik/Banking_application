#ifndef TRANSAKCJE_HPP
#define TRANSAKCJE_HPP

#include <iostream>
#include <vector>
#include "Przelew.hpp"
#include "Wplata.hpp"
#include "Wyplata.hpp"

class Transakcje {
 private:
  std::vector<Przelew> przelewy;
  std::string nazwaPliku;

 public:
  void wczytywaniePrzelewow();
  void zapisywaniePrzelewow();
  void setPrzelewy(std::vector<Przelew> przelewy);
  std::vector<Przelew> getPrzelewy();
  void wyswietlanieWplat();
  void wyswietlanieWyplat();
  void wyswietlaniePrzelewow();

  Transakcje();
  ~Transakcje();
};
#endif  // TRANSAKCJE_HPP
