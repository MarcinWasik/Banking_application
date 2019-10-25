#ifndef KASJER_HPP
#define KASJER_HPP

#include <string>
#include <vector>
#include "Klient.hpp"
#include "Osoba.hpp"

class Kasjer : public Osoba {
 private:
  std::string idKasjera;

 public:
  void setIdKasjera(std::string idKasjera);
  std::string getIdKasjera();
  bool zweryfikujKlienta(std::vector<Klient>& klienci, std::string pesel,
                         std::string nazwisko);
  void zarejestrujWplate(std::vector<Klient>& klienci);
  void zarejestrujWyplate(std::vector<Klient>& klienci);

  Kasjer();
  Kasjer(std::string pesel, std::string imie, std::string nazwisko,
         std::string adres, std::string login, std::string haslo,
         std::string idKasjera);
};

#endif  // KASJER_HPP
