#ifndef PRZELEW_HPP
#define PRZELEW_HPP

#include <string>
#include "Osoba.hpp"

class Przelew {
 private:
  std::string data, tytulPrzelewu;
  int numerKontaKlienta;
  int numerKontaNabywcy;
  float kwota;

 public:
  void setData(std::string data);
  std::string getData();
  void setNumerkontaKlienta(int numerKontaKlienta);
  int getNumerKontaKlienta();
  void setNumerkontaNabywcy(int numerKontaNabywcy);
  int getNumerKontaNabywcy();
  void setKwota(float kwota);
  float getKwota();
  std::string getTytulPrzelewu();

  Przelew(std::string data, int numerKontaKlienta, int numerKontaNabywcy,
          std::string tytulPrzelewu, float kwota);
};

#endif  // PRZELEW_HPP
