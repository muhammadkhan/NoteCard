#include <iostream>
#include "Card.h"

using namespace std;

int main(){
  Card c1("fronttext", "backtext");
  Card c2;
  Card* c3 = new Card();
  Card* c4 = new Card("yolo", "swag");

  c2.setFrontText("yolo2");
  c2.setBackText("swag2");
  c3->setFrontText("pointer set front");
  c3->setBackText("pointer set back");

  cout << c1.getFrontText() << "|" << c1.getBackText() << endl;
  cout << c2.getFrontText() << "|" << c2.getBackText() << endl;
  cout << c3->getFrontText() << "|" << c3->getBackText() << endl;
  cout << c4->getFrontText() << "|" << c4->getBackText() << endl;
  cout << endl << endl;
  cout << c3->getVisibleText() << c3->isFlippedOver() << endl;
  c3->flip();
  cout << c3->getVisibleText() << c3->isFlippedOver() << endl;
  c3->flip();
  cout << c3->getVisibleText() << c3->isFlippedOver() << endl;
  cout << endl;
  cout << (c1 == c2) << endl;
  c1.setFrontText("yolo2"); c1.setBackText("swag2");
  cout << (c1 == c2) << endl;
  return 0;
}
