#include "kanji.hpp"


kanji::kanji(){
  value = jstring();
  stroke = 0;
  id = 0;
}

kanji::kanji(int index,std::string v, int strokeCount,
  std::vector<std::string> radicalList, std::vector<jstring> on, std::vector<jstring> kun){
  id = index;
  value = jstring(v);
  stroke = strokeCount;
  for(std::string rad : radicalList){
    radicals.push_back(rad);
  }
  for(jstring r : on){
    onyomi.push_back(r);
  }
  for(jstring r : kun){
    kunyomi.push_back(r);
  }
}

void kanji::print(){
  std::cout<<id<<" ";
  value.print();
  std::cout<<" ";
  std::cout<<stroke<<" ";
  if(!(radicals[0]=="")){
    std::cout<<"[";
    for(int i = 0; i < radicals.size(); i++){
      std::cout<<radicals[i];
      if( !(i == radicals.size()-1)){
        std::cout<<",";
      }
    }
    std::cout<<"]";
    std::cout<<" ";
  }
  if(!(onyomi.empty())){
    std::cout<<"[";
    for(int i = 0; i < onyomi.size(); i++){
      onyomi[i].print();
      if( i != onyomi.size()-1){
        std::cout<<",";
      }
    }
    std::cout<<"]";
    std::cout<<" ";
  }
  if(!(kunyomi.empty())){
    std::cout<<"[";
    for(int i = 0; i < kunyomi.size(); i++){
      kunyomi[i].print();
      if( i != kunyomi.size()-1){
        std::cout<<",";
      }
    }
    std::cout<<"]";
  }
  std::cout<<'\n';
}
