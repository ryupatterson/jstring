#ifndef KANJI_HPP
#define KANJI_HPP

#include "jstring.hpp"

class kanji{
public:
  int id;
  jstring value;
  int stroke;
  std::vector<jstring> onyomi;
  std::vector<jstring> kunyomi;
  std::vector<std::string> radicals;
  kanji();
  kanji(int index,std::string v, int strokeCount,
    std::vector<std::string> radicalList, std::vector<jstring> on,std::vector<jstring> kun);
  void print();
};
#endif
