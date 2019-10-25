#include "Osoba.hpp"

Osoba::Osoba() {}

Osoba::Osoba(std::string pesel, std::string imie, std::string nazwisko,
             std::string adres, std::string login, std::string haslo)
    : pesel(pesel),
      imie(imie),
      nazwisko(nazwisko),
      adres(adres),
      login(login),
      haslo(haslo) {}

void Osoba::setPesel(std::string pesel) { this->pesel = pesel; }

std::string Osoba::getPesel() { return pesel; }

void Osoba::setImie(std::string imie) { this->imie = imie; }

std::string Osoba::getImie() { return imie; }

void Osoba::setNazwisko(std::string nazwisko) { this->nazwisko = nazwisko; }

std::string Osoba::getNazwisko() { return nazwisko; }

void Osoba::setAdres(std::string adres) { this->adres = adres; }
std::string Osoba::getAdres() { return adres; }

void Osoba::setLogin(std::string login) { this->login = login; }

std::string Osoba::getLogin() { return login; }

void Osoba::setHaslo(std::string haslo) { this->haslo = haslo; }

std::string Osoba::getHaslo() { return haslo; }
