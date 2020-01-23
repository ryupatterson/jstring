#include "jstring.hpp"


jstring::jstring(){
}

jstring::jstring( std::string v){
  for(int i =0; i < v.size(); i++){
    val.push_back(v[i]);
  }
}

bool operator==(jstring const &a, jstring const &b){
  if( a.val.size() != b.val.size()){
    return false;
  }
  for(int i = 0; i < a.val.size(); i++){
    if( a.val[i] != b.val[i]){
      return false;
    }
  }
  return true;
}

bool operator!=(jstring const &a, jstring const &b){
  if( a.val.size() != b.val.size()){
    return true;
  }
  for(int i = 0; i < a.val.size(); i++){
    if( a.val[i] != b.val[i]){
      return true;
    }
  }
  return false;
}

jstring &jstring::operator[](int index){
  if(index >= val.size()){
    throw "Out of range";
  }
  int count = 0;
  int three = 0;
  std::string temp = "";
  for( int i = 0; i < val.size(); i++){
    std::cout<<three<<std::endl;
    if( count == index){
      temp+=val[i];
      std::cout<<temp<<'\n';
      three++;
      if(three == 2){
        std::cout<<temp<<'\n';
        jstring x = jstring(temp);
        return x;
      }
    }
    else{
      if( three == 2){
        three = 0;
        count++;
      }
      if(val[i] < 0){
        three++;
      } else{
        count++;
        three = 0;
      }
    }
  }
}

void jstring::print(){
  std::string temp = "";
  std::cout<<val.size()<<'\n';
  for( int i = 0; i < val.size(); i++){
    temp+=val[i];
    if( (i+1) % 3 == 0 && i != 0 ){
      std::cout<<temp;
      temp = "";
    }
  }
  std::cout<<'\n';
}

void jstring::printChars(){
  for(char c : val){
    std::cout<<(int)c<<" ";
    std::cout<<'\n';
  }
}

int jstring::getChar(){
  int output = 0;
  for( char c : val ){
    output+=(int)c;
  }
  return output;
}

bool jstring::isHira(){
  int output = 1;
  std::string temp = "";
  for( int i = 0; i < val.size(); i++){
    temp+=val[i];
    if( (i+1) % 3 == 0 && i != 0 ){
      if( (temp >= "\u3041" && temp <= "\u3096") || temp == "\uFF08" || temp == "\uff09" || temp == "\uff70"){
      } else{
        output *=0;
      }
      temp = "";
    }
  }
  return output;
}

bool jstring::isKata(){
  int output = 1;
  std::string temp = "";
  for( int i = 0; i < val.size(); i++){
    temp+=val[i];
    if( (i+1) % 3 == 0 && i != 0 ){
      if(!(temp >= "\u30a0" && temp <= "\u30ff")){
        output*=0;
      }
      temp = "";
    }
  }
  return output;
}

bool jstring::isKanji(){
  int output = 1;
  std::string temp = "";
  for( int i = 0; i < val.size(); i++){
    temp+=val[i];
    if( (i+1) % 3 == 0 && i != 0 ){
      if((temp >= "\u3400" && temp <= "\u4db5") || (temp >= "\u4e00" && temp <= "\u9fcb") || (temp >= "\uf900" && temp <= "\ufa6a")){
      } else{
        output *=0;
      }
      temp = "";
    }
  }
  return output;
}

bool jstring::isRadical(){
  int output = 1;
  std::string temp = "";
  for( int i = 0; i < val.size(); i++){
    temp+=val[i];
    if( (i+1) % 3 == 0 && i != 0 ){
      if(temp >= "\u2e80" && temp <= "\u2fd5"){
        output*=0;
      }
      temp = "";
    }
  }
  return output;
}

std::string jstring::conversion(std::string v){
  if(v.size() > 3){
    std::cout<<"Only use one character"<<'\n';
    return v;
  }
  jstring x = jstring(v);
  std::string temp = "";
  if(x.isHira()){
    for( int i = 0; i < x.val.size(); i++){
      if(i == 1){
        temp+=(int)x.val[i]+1;
      } else if(i == 2){
        temp+=(int)x.val[i]+32;
      } else{
        temp+=x.val[i];
      }
    }
    return temp;
  } else if( x.isKata()){
    for( int i = 0; i < x.val.size(); i++){
      if(i == 1){
        temp+=(int)x.val[i]-1;
      } else if(i == 2){
        temp+=(int)x.val[i]-32;
      } else{
        temp+=x.val[i];
      }
    }
    return temp;
  } else{
    std::cout<<"Invalid Param"<<"\n";
    return v;
  }
}
