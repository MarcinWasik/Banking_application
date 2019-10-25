#include "Przelew.hpp"
#include "Narzedzia.hpp"

Przelew::Przelew(std::string data, int numerKontaKlienta, int numerKontaNabywcy,
                 std::string tytulPrzelewu, float kwota) {
  this->numerKontaKlienta = numerKontaKlienta;
  this->numerKontaNabywcy = numerKontaNabywcy;
  this->tytulPrzelewu = tytulPrzelewu;
  this->kwota = kwota;
  Narzedzia w;
  this->data = data;
}

void Przelew::setData(std::string data) { this->data = data; }
std::string Przelew::getData() { return data; }

void Przelew::setNumerkontaKlienta(int numerKontaKlienta) {
  this->numerKontaKlienta = numerKontaKlienta;
}
int Przelew::getNumerKontaKlienta() { return numerKontaKlienta; }

void Przelew::setNumerkontaNabywcy(int numerKontaNabywcy) {
  this->numerKontaNabywcy = numerKontaNabywcy;
}
int Przelew::getNumerKontaNabywcy() { return numerKontaNabywcy; }

void Przelew::setKwota(float kwota) { this->kwota = kwota; }

float Przelew::getKwota() { return kwota; }

std::string Przelew::getTytulPrzelewu() { return tytulPrzelewu; }
