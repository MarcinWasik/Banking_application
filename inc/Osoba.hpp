#ifndef OSOBA_HPP
#define OSOBA_HPP

#include <string>

class Osoba {
 private:
  std::string pesel;
  std::string imie;
  std::string nazwisko;
  std::string adres;
  std::string login;
  std::string haslo;

 public:
  void setPesel(std::string pesel);
  std::string getPesel();

  void setImie(std::string imie);
  std::string getImie();

  void setNazwisko(std::string nazwisko);
  std::string getNazwisko();

  void setAdres(std::string adres);
  std::string getAdres();

  void setLogin(std::string login);
  std::string getLogin();

  void setHaslo(std::string haslo);
  std::string getHaslo();

  Osoba();
  Osoba(std::string pesel, std::string imie, std::string nazwisko,
        std::string adres, std::string login, std::string haslo);
};

#endif  // OSOBA_HPP
