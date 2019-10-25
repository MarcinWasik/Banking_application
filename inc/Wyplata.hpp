#ifndef WYPLATA_HPP
#define WYPLATA_HPP
#include <string>

struct Wyplata {
  std::string peselKlienta, nazwiskoKlienta;
  unsigned int zadanaKwota;
};

#endif  // WYPLATA_HPP
