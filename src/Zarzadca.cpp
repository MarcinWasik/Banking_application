#include "Zarzadca.hpp"
#include <limits>
#include "Narzedzia.hpp"
Zarzadca::Zarzadca() : Osoba() {}

Zarzadca::Zarzadca(std::string pesel, std::string imie, std::string nazwisko,
                   std::string adres, std::string login, std::string haslo,
                   std::string idZarzadcy)
    : idZarzadcy(idZarzadcy),
      Osoba(pesel, imie, nazwisko, adres, login, haslo) {}

void Zarzadca::setIdZarzadcy(std::string idZarzadcy) {
  this->idZarzadcy = idZarzadcy;
}

std::string Zarzadca::getIdZarzadcy() { return idZarzadcy; }

void Zarzadca::dodajKlienta(std::vector<Klient>& klienci) {
  Narzedzia narzedzia;
  std::string peselK, imieK, nazwiskoK, adresK, loginK, hasloK;

  std::cout << "Podaj pesel:\n";
  std::cin >> peselK;
  bool peselPrawidlowy = narzedzia.czyPeselJestPrawidlowy(peselK);
  if (!peselPrawidlowy) {
    std::cout << "Pesel jest nieprawidłowy!\nPodaj jeszcze raz:\n";
    std::cin >> peselK;
    peselPrawidlowy = narzedzia.czyPeselJestPrawidlowy(peselK);
  }
  if (peselPrawidlowy) {
    std::cout << "Podaj imie:\n";
    std::cin >> imieK;
    std::cout << "Podaj nazwisko:\n";
    std::cin >> nazwiskoK;
    std::cout << "Podaj adres:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, adresK);
    narzedzia.zamianaBialychZnakowNaPodloge(adresK);
    std::cout << "Podaj login:\n";
    std::cin >> loginK;
    std::cout << "Podaj haslo:\n";
    std::cin >> hasloK;
    Klient klient(peselK, imieK, nazwiskoK, adresK, loginK, hasloK,
                  narzedzia.generatorIBAN(), 0);
    klienci.push_back(klient);
  }
}

void Zarzadca::usunKlienta(std::vector<Klient>& klienci) {
  std::string peselUsuwanegoKlienta;
  std::cout << "Podaj pesel usuwanego klienta:\n";
  std::cin >> peselUsuwanegoKlienta;
  std::vector<Klient>::iterator itUsuwanegoKlienta;
  for (auto it = klienci.begin(); it != klienci.end(); it++) {
    if ((*it).getPesel() == peselUsuwanegoKlienta) {
      itUsuwanegoKlienta = it;
    }
  }
  klienci.erase(itUsuwanegoKlienta);
}

void Zarzadca::wyswietlListeKlientow(std::vector<Klient>& klienci) {
  std::cout << "Lista klientów:\n";
  int numeracja = 1;
  for (auto& v : klienci) {
    std::cout << numeracja << ". "
              << "Pesel: " << v.getPesel() << " , Imie: " << v.getImie()
              << " , Nazwisko: " << v.getNazwisko() << std::endl;
    numeracja++;
  }
}

void Zarzadca::pobierzKwoteZaProwadzenieKonta(std::vector<Klient>& klienci,
                                              int kosztProwadzeniaKonta) {
  for (auto& v : klienci) {
    v.setStanKonta(v.getStanKonta() - kosztProwadzeniaKonta);
  }
}
