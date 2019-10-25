#ifndef WPLATA_HPP
#define WPLATA_HPP

#include <string>
#include "Osoba.hpp"

struct Wplata {
  unsigned int numerKontaDoPrzelewu, kwotaDoPrzelewu;
  std::string tytulPrzelewu, imieZleceniodawcy, nazwiskoZleceniodawcy,
      adresZleceniodawcy;
};

#endif  // WPLATA_HPP
