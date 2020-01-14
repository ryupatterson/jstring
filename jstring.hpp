#ifndef JSTRING_HPP
#define JSTRING_HPP

#include <iostream>
#include <string>
#include <vector>


class jstring{
public:
  std::vector<char> val;
  jstring();
  jstring(std::string v);
  friend bool operator==(jstring const &a, jstring const &b);
  int size();
  void print();
  void printChars();
  int getChar();
  bool isHira();
  bool isKata();
  bool isKanji();
  bool isRadical();
  static std::string conversion(std::string v);
};

#endif
