#include <iostream>
#include "CardSet.h"

using namespace std;

int main(){
  CardSet loaded("set");
  loaded.load("myset.set");
  cout << loaded.size() << endl;
  loaded.addCard(new Card("yolo just added this", "and this is a back"));
  cout << loaded.size() << endl;
  loaded.save();
  return 0;
}
