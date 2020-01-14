#ifndef KANJITABLE_HPP
#define KANJITABLE_HPP

class kanjiTable {
public:
  kanji array[2137];
  kanjiTable();
  kanji findByKanji(std::string v);
  kanji findByKun(std::string v);
  kanji findByOn(std::string v);
  void print();
};
#endif
