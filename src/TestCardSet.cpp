#include <iostream>
#include "CardSet.h"

using namespace std;

int main(){
  Card* c1 = new Card("oneF", "oneB"), *c2 = new Card("twoF", "twoB");
  CardSet cards("my cards");
  cards.addCard(c1);
  cards.addCard(c2);
  cout << "Card size: " << cards.size() << endl;
  cards.save("myset.set");
  return 0;
}
