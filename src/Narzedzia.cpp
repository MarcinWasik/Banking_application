#include "Narzedzia.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

Narzedzia::Narzedzia() { srand(time(NULL)); }

bool Narzedzia::czyWyrazenieZgodneZRegexem(const char* string, char* wzor) {
  int status;
  regex_t re;

  if (regcomp(&re, wzor, REG_EXTENDED | REG_NOSUB) != 0) {
    return false;
  }
  status = regexec(&re, string, (size_t)0, NULL, 0);
  regfree(&re);
  if (status != 0) {
    regfree(&re);
    return false;
  }
  return true;
}

bool Narzedzia::czyPeselJestPrawidlowy(std::string pesel) {
  if (!czyWyrazenieZgodneZRegexem(pesel.c_str(), "^[0-9]{11}")) {
    return false;
  }
  int checkSuma = (1 * (pesel[0] - '0')) + (3 * (pesel[1] - '0')) +
                  (7 * (pesel[2] - '0')) + (9 * (pesel[3] - '0')) +
                  (1 * (pesel[4] - '0')) + (3 * (pesel[5] - '0')) +
                  (7 * (pesel[6] - '0')) + (9 * (pesel[7] - '0')) +
                  (1 * (pesel[8] - '0')) + (3 * (pesel[9] - '0'));
  int ostaniaCyfraZCheckSumy = checkSuma % 10;
  if (10 - ostaniaCyfraZCheckSumy != (pesel[10] - '0')) {
    return false;
  }
  return true;
}

std::pair<long int, int> Narzedzia::zamianaGroszyNaZlotowkiIGrosze(
    long long int grosze) {
  std::pair<long int, int> gotowka;
  long int zlotowki = grosze / 100;
  long int resztaGroszy = grosze % 100;
  gotowka.first = zlotowki;
  gotowka.second = resztaGroszy;
  return gotowka;
}

unsigned int Narzedzia::generatorIBAN() {
  return (std::rand() % 9999999) + 10000000;
}

std::string Narzedzia::pobierzAktualnaDate() {
  time_t czas;
  struct tm* data;
  char godzina[80];

  time(&czas);
  data = localtime(&czas);

  strftime(godzina, 80, "%d.%m_%H:%M:%S_%Y", data);
  return godzina;
}

void Narzedzia::wczytywaniePliku(std::string nazwaPliku) {
  std::string linia;
  std::fstream plik;

  plik.open(nazwaPliku, std::ios::in);
  if (plik.good() == true) {
    while (!plik.eof()) {
      std::getline(plik, linia);
      std::cout << linia << std::endl;
    }
    plik.close();
  }
}

void Narzedzia::zamianaBialychZnakowNaPodloge(std::string& str) {
  for (auto& v : str) {
    if (v == ' ') {
      v = '_';
    }
  }
}
