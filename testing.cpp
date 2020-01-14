#include "jstring.hpp"

int main(){
  std::string m = "か";
  jstring x = jstring(m);
  x.printChars();
  jstring f = jstring(jstring::conversion(m));
  f.print();
  return 0;
}
