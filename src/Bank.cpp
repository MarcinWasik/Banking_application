#include "Bank.hpp"
#include <fstream>
#include <limits>

Bank::Bank(std::string plikKlienci, std::string plikKasjerzy,
           std::string plikZarzadcy)
    : nazwaPlikuKlienci(plikKlienci),
      nazwaPlikuKasjerzy(plikKasjerzy),
      nazwaPlikuZarzadcy(plikZarzadcy) {
  setlocale(LC_ALL, "");
  wczytywanieDanychKlientow();
  wczytywanieDanychKasjerow();
  wczytywanieDanychZarzadcow();
}

Bank::~Bank() {
  setlocale(LC_ALL, "");
  zapisywanieDanychKlientow();
  zapisywanieDanychKasjerow();
  zapisywanieDanychZarzadcow();
}

void Bank::setKlienci(std::vector<Klient> klienci) { this->klienci = klienci; }

std::vector<Klient> Bank::getKlienci() { return klienci; }

void Bank::setKasjerzy(std::vector<Kasjer> kasjerzy) {
  this->kasjerzy = kasjerzy;
}

std::vector<Kasjer> Bank::getKasjerzy() { return kasjerzy; }

void Bank::setZarzadcy(std::vector<Zarzadca> zarzadcy) {
  this->zarzadcy = zarzadcy;
}

std::vector<Zarzadca> Bank::getZarzadcy() { return zarzadcy; }

void Bank::setTransakcje(Transakcje transakcje) {
  this->transakcje = transakcje;
}

Transakcje Bank::getTransakcje() { return transakcje; }

void Bank::wczytywanieDanychKlientow() {
  std::fstream plik(nazwaPlikuKlienci);
  if (plik.good()) {
    std::string pesel, imie, nazwisko, adres, login, haslo;
    unsigned int numerKonta;
    float stanKonta;
    while (plik >> pesel >> imie >> nazwisko >> adres >> login >> haslo >>
           numerKonta >> stanKonta) {
      Klient wczytany(pesel, imie, nazwisko, adres, login, haslo, numerKonta,
                      stanKonta);
      klienci.push_back(wczytany);
    }
  }
}

void Bank::zapisywanieDanychKlientow() {
  std::ofstream zapisz(nazwaPlikuKlienci);
  for (auto v : klienci) {
    zapisz << v.getPesel() << " " << v.getImie() << " " << v.getNazwisko()
           << " " << v.getAdres() << " " << v.getLogin() << " " << v.getHaslo()
           << " " << v.getNumerKonta() << " " << v.getStanKonta() << std::endl;
  }
}

void Bank::wczytywanieDanychKasjerow() {
  std::fstream plik(nazwaPlikuKasjerzy);
  if (plik.good()) {
    std::string pesel, imie, nazwisko, adres, login, haslo, idKasjera;
    while (plik >> pesel >> imie >> nazwisko >> adres >> login >> haslo >>
           idKasjera) {
      Kasjer wczytany(pesel, imie, nazwisko, adres, login, haslo, idKasjera);
      kasjerzy.push_back(wczytany);
    }
  }
}

void Bank::zapisywanieDanychKasjerow() {
  std::ofstream zapisz(nazwaPlikuKasjerzy);
  for (auto v : kasjerzy) {
    zapisz << v.getPesel() << " " << v.getImie() << " " << v.getNazwisko()
           << " " << v.getAdres() << " " << v.getLogin() << " " << v.getHaslo()
           << " " << v.getIdKasjera() << std::endl;
  }
}

void Bank::wczytywanieDanychZarzadcow() {
  std::fstream plik(nazwaPlikuZarzadcy);
  if (plik.good()) {
    std::string pesel, imie, nazwisko, adres, login, haslo, idZarzadcy;
    while (plik >> pesel >> imie >> nazwisko >> adres >> login >> haslo >>
           idZarzadcy) {
      Zarzadca wczytany(pesel, imie, nazwisko, adres, login, haslo, idZarzadcy);
      zarzadcy.push_back(wczytany);
    }
  }
}

void Bank::zapisywanieDanychZarzadcow() {
  std::ofstream zapisz(nazwaPlikuZarzadcy);
  for (auto v : zarzadcy) {
    zapisz << v.getPesel() << " " << v.getImie() << " " << v.getNazwisko()
           << " " << v.getAdres() << " " << v.getLogin() << " " << v.getHaslo()
           << " " << v.getIdZarzadcy() << std::endl;
  }
}

bool Bank::czyIstniejeLogin(std::string login) {
  for (auto i : klienci) {
    if (i.getLogin() == login) {
      uzytkownik = klient;
      return true;
    }
  }

  for (auto i : kasjerzy) {
    if (i.getLogin() == login) {
      uzytkownik = kasjer;
      return true;
    }
  }

  for (auto i : zarzadcy) {
    if (i.getLogin() == login) {
      uzytkownik = zarzadca;
      return true;
    }
  }
  return false;
}

bool Bank::czyHasloJestPoprawneDlaLoginu(std::string login, std::string haslo) {
  if (uzytkownik == klient) {
    for (auto i : klienci) {
      if (i.getLogin() == login) {
        return (i.getHaslo() == haslo) ? true : false;
      }
    }
  } else if (uzytkownik == kasjer) {
    for (auto i : kasjerzy) {
      if (i.getLogin() == login) {
        return (i.getHaslo() == haslo) ? true : false;
      }
    }
  } else {
    for (auto i : zarzadcy) {
      if (i.getLogin() == login) {
        return (i.getHaslo() == haslo) ? true : false;
      }
    }
  }
  return false;
}

bool Bank::logowanieUzytkownika() {
  std::string login, haslo;

  std::cout << "Witaj w Banku!\n";
  std::cout << "Podaj Login:\n";
  std::cin >> login;
  if (czyIstniejeLogin(login)) {
    std::cout << "Podaj hasło:\n";
    std::cin >> haslo;
    if (czyHasloJestPoprawneDlaLoginu(login, haslo)) {
      std::cout << "Zalogowałeś się poprawnie!\n";
      loginZalogowanegoUzytkownika = login;
      return true;
    }
  } else {
    std::cout << "Login jest niepoprawny!\n";
    return false;
  }
  std::cout << "Logowanie niepowiodło sie!\n";
  return false;
}

void Bank::wyswietlMenuKlienta() {
  std::cout << "   * * * * * * * * * * * * * * * * * * * * * *\n";
  std::cout << "   *      Menu klienta:                      *\n";
  std::cout << "   * * * * * * * * * * * * * * * * * * * * * *\n";
  std::cout << "   *  1 - Wyświetl stan konta                *\n";
  std::cout << "   *  2 - Wyświetl historię transakcji       *\n";
  std::cout << "   *  3 - Wykonaj przelew                    *\n";
  std::cout << "   *  4 - Zmień hasło                        *\n";
  std::cout << "   *  5 - Zakończ działanie programu         *\n";
  std::cout << "   * * * * * * * * * * * * * * * * * * * * * *\n";
}

void Bank::wyswietlMenuKasjera() {
  std::cout << "   * * * * * * * * * * * * * * * * * * * * * *\n";
  std::cout << "   *     Menu kasjera:                       *\n";
  std::cout << "   * * * * * * * * * * * * * * * * * * * * * *\n";
  std::cout << "   * 1 - Zarejestruj wpłatę pieniędzy        *\n";
  std::cout << "   * 2 - Zarejestruj wypłatę pieniędzy       *\n";
  std::cout << "   * 3 - Zakończ działanie programu          *\n";
  std::cout << "   * * * * * * * * * * * * * * * * * * * * * *\n";
}

void Bank::wyswietlMenuZarzadcy() {
  std::cout << "   * * * * * * * * * * * * * * * * * * * * * *\n";
  std::cout << "   *     Menu zarządcy:                      *\n";
  std::cout << "   * * * * * * * * * * * * * * * * * * * * * *\n";
  std::cout << "   * 1 - Dodaj klienta                       *\n";
  std::cout << "   * 2 - Usuń klienta                        *\n";
  std::cout << "   * 3 - Wyświetl historię operacji          *\n";
  std::cout << "   * 4 - Wyświetl listę klientów banku       *\n";
  std::cout << "   * 5 - Pobierz kwotę za prowadzenie konta  *\n";
  std::cout << "   * 6 - Zakończ działanie programu          *\n";
  std::cout << "   * * * * * * * * * * * * * * * * * * * * * *\n";
}

void Bank::operacjeUzytkownika() {
  bool czyUzytkownikZalogowany;
  czyUzytkownikZalogowany = logowanieUzytkownika();
  if (czyUzytkownikZalogowany) {
    if (uzytkownik == klient) {
      bool niePrzerywac = true;
      while (niePrzerywac) {
        wyswietlMenuKlienta();
        operacjeKlienta(niePrzerywac);
      }
    } else if (uzytkownik == kasjer) {
      bool niePrzerywac = true;
      while (niePrzerywac) {
        wyswietlMenuKasjera();
        operacjeKasjera(niePrzerywac);
      }
    } else {
      bool niePrzerywac = true;
      while (niePrzerywac) {
        wyswietlMenuZarzadcy();
        operacjeZarzadcy(niePrzerywac);
      }
    }
  }
}

void Bank::operacjeKlienta(bool& niePrzerywac) {
  try {
    Klient& w = zwrocZalogowanegoKlienta();
    std::cout << "Podaj numer:\n";
    int numer;
    std::cin >> numer;
    if (std::cin.fail()) {
      throw std::string("Nie poprawny typ danych!\n");
    }
    switch (numer) {
      case 1:
        w.wyswietlStanKonta();
        break;
      case 2:
        w.wyswietlTransakcje(transakcje.getPrzelewy());
        break;
      case 3:
        w.wykonajPrzelew(klienci, transakcje);
        break;
      case 4:
        w.zmianaHasla();
        break;
      case 5:
        niePrzerywac = false;
        break;
      default:
        std::cout << "Brak takiego numeru!\n";
        break;
    }
  } catch (std::string wyjatek) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << wyjatek;
  }
}

void Bank::operacjeKasjera(bool& niePrzerywac) {
  try {
    Kasjer& w = zwrocZalogowanegoKasjera();
    std::cout << "Podaj numer:\n";
    int numer;
    std::cin >> numer;
    if (std::cin.fail()) {
      throw std::string("Nie poprawny typ danych!\n");
    }
    switch (numer) {
      case 1:
        w.zarejestrujWplate(klienci);
        break;
      case 2:
        w.zarejestrujWyplate(klienci);
        break;
      case 3:
        niePrzerywac = false;
        break;
      default:
        std::cout << "Brak takiego numeru!\n";
        break;
    }
  } catch (std::string wyjatek) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << wyjatek;
  }
}

void Bank::operacjeZarzadcy(bool& niePrzerywac) {
  try {
    Zarzadca& w = zwrocZalogowanegoZarzadce();
    std::cout << "Podaj numer:\n";
    int numer;
    std::cin >> numer;
    if (std::cin.fail()) {
      throw std::string("Nie poprawny typ danych!\n");
    }
    switch (numer) {
      case 1:
        w.dodajKlienta(klienci);
        break;
      case 2:
        w.usunKlienta(klienci);
        break;
      case 3:
        transakcje.wyswietlaniePrzelewow();
        transakcje.wyswietlanieWplat();
        transakcje.wyswietlanieWyplat();
        break;
      case 4:
        w.wyswietlListeKlientow(klienci);
        break;
      case 5:
        int koszt;
        std::cout << "Podaj koszt prowadzenia konta:\n";
        std::cin >> koszt;
        w.pobierzKwoteZaProwadzenieKonta(klienci, koszt);
        break;
      case 6:
        niePrzerywac = false;
        break;
      default:
        std::cout << "Brak takiego numeru!\n";
        break;
    }
  } catch (std::string wyjatek) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << wyjatek;
  }
}

Klient& Bank::zwrocZalogowanegoKlienta() {
  for (auto& v : klienci) {
    if (v.getLogin() == loginZalogowanegoUzytkownika) {
      return v;
    }
  }
}

Kasjer& Bank::zwrocZalogowanegoKasjera() {
  for (auto& v : kasjerzy) {
    if (v.getLogin() == loginZalogowanegoUzytkownika) {
      return v;
    }
  }
}

Zarzadca& Bank::zwrocZalogowanegoZarzadce() {
  for (auto& v : zarzadcy) {
    if (v.getLogin() == loginZalogowanegoUzytkownika) {
      return v;
    }
  }
}
