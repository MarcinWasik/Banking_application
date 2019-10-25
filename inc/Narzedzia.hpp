#ifndef NARZEDZIA_HPP
#define NARZEDZIA_HPP

#include <regex.h>
#include <string>

class Narzedzia {
 public:
  Narzedzia();
  bool czyWyrazenieZgodneZRegexem(const char *string, char *pattern);
  bool czyPeselJestPrawidlowy(std::string pesel);
  std::pair<long int, int> zamianaGroszyNaZlotowkiIGrosze(long long int grosze);
  unsigned int generatorIBAN();
  std::string pobierzAktualnaDate();
  void wczytywaniePliku(std::string nazwaPliku);
  void zamianaBialychZnakowNaPodloge(std::string &str);
  // przelicznikgroszynazłotkówiigrosze
  // generowanienumerowkonta
};

#endif  // NARZEDZIA_HPP
