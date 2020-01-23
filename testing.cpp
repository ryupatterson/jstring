#include "jstring.hpp"

int main(){
  jstring x = jstring("あいうえお");
  x[1].print();
  return 0;
}
