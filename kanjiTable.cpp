#include "kanji.hpp"
#include "kanjiTable.hpp"
#include <map>
#include <fstream>



std::map<jstring,int> INDEXES = {};

kanjiTable::kanjiTable(){
  //read in file
  std::ifstream file("kanji.csv");
  std::string line;
  while(getline(file,line)){
    std::string temp = "";
    std::vector<std::string> currLine;
    std::vector<std::string> tempRad;
    std::vector<jstring> tempOn;
    std::vector<jstring> tempKun;
    int tempID = 0;
    for(int i = 0; i < line.size(); i++){
      if( i == line.size()-1){
        temp += line[i];
        currLine.push_back(temp);
        temp = "";
      } else if(line[i]!= ';'){
        temp+= line[i];
      } else{
        currLine.push_back(temp);
        temp = "";
      }
    }
    tempID = stoi(currLine[0]);
    for(int i = 0; i < currLine[3].size(); i++){
      if( i == currLine[3].size()-1){
        if(currLine[3][i] != '"'){
          temp += currLine[3][i];
        }
        tempRad.push_back(temp);
        temp = "";
      }
      if( currLine[3][i] == '"'){
        if( temp == ""){
        } else{
          tempRad.push_back(temp);
          temp = "";
        }
      } else if( currLine[3][i] == ','){
        tempRad.push_back(temp);
        temp = "";
      } else{
        temp += currLine[3][i];
      }
    }
    std::string mainTemp = "";
    std::string japTemp = "";
    int counter = 0;
    for(int i = 0; i < currLine[4].size(); i++){
      if( (int)currLine[4][i] < 0){
        japTemp += currLine[4][i];
        counter++;
        if( i == currLine[4].size() -1 ){
          mainTemp += japTemp;
          jstring input = jstring(mainTemp);
          if(input.isHira()){
            tempKun.push_back(input);
          } if(input.isKata()){
            tempOn.push_back(input);
          }
          mainTemp = "";
          counter = 0;
        }
        if(counter == 3){
          if( japTemp != "、"){
            mainTemp += japTemp;
            counter = 0;
            japTemp = "";
          } else{
            jstring input = jstring(mainTemp);
            if(input.isHira()){
              tempKun.push_back(input);
            } if(input.isKata()){
              tempOn.push_back(input);
            }
            mainTemp = "";
            japTemp = "";
            counter = 0;
          }
        }
      } if((int)currLine[4][i] == 45){
          mainTemp+="ｰ";
      }
    }
    kanji k = kanji(tempID,currLine[1],stoi(currLine[2]),tempRad,tempOn, tempKun);
    array[tempID] = k;
  }
  file.close();
}

kanji kanjiTable::findByKanji(std::string v){
  jstring val = jstring(v);
  for( int i = 0; i < 2137 ; i++){
    if( val == array[i].value){
      return array[i];
    }
  }
}

kanji findByKun(std::string v){
  jstring value = jstring(v);
  if(value.isKata()){
    bool state = false;
    int index = 1600;
    while(state == false){
      if(array[index].kunyomi[0] == value){
        state = true;
      } else{

      }
    }
  }
}


void kanjiTable::print(){
  for( int i = 1; i < 2137; i++){
    array[i].print();
  }
}

int main(){
  kanjiTable k = kanjiTable();
  k.print();
  return 0;
}
