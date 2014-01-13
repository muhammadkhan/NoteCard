#include <iostream>
#include <cstdlib>
#include "CardSet.h"
#include "Card.h"

using namespace std;

void printCardSetContents(CardSet& cset){
  cout << "This card set has " << cset.size() << " cards in it" << endl;
  if(cset.size() > 0){
    unsigned int i;
    for(i = 0; i < cset.size(); i++){
      Card* c = cset.cardAt(i);
      cout << "Card #" << (i + 1) << ": " << c->getFrontText() << endl;
    }
  }
}

void printTitle(){
  cout<<"============================================"<<endl;
  cout << "NOTECARD by Muhammad Khan" << endl;
  cout<<"============================================"<<endl;
  cout << endl << endl;
}

void createNew_or_loadExisting(CardSet*& cset){
  int num_options = 2;
  int option = -1;
  cout << "Please enter the number corresponding to the action you wish to perform:" << endl;
  cout << "0: Create new set of flashcards" << endl;
  cout << "1: Open a set of existing flashcards" << endl;
  while(option < 0 || option >= num_options){
    cin >> option;
    if(option < 0 || option >= num_options)
      cout << "Invalid choice, please enter again" << endl;
  }
  /** Guaranteed that: 0 <= option < num_options */
  
  if(option == 0){
    string nm;
    cout << "Please enter a name for the new set: ";
    cin >> nm;
    cout << endl << endl << endl;
    cset = new CardSet(nm);
  } else if(option == 1){
    string p;
    cout << "Please provide the path to the .set file: ";
    cin >> p;
    cout << endl << endl << endl;
    cset = new CardSet("", p);
  }
}

void cardActions(Cardset*& cset, int& response){

}

int main(){
  CardSet* cset = NULL;
  int response = -1;
  printTitle();
  createNew_or_loadExisting(cset);
  printCardSetContents(*cset);
  cout << endl;
  do{
    cardActions(cset, response);
  } while(response == -1);
  return 0;
}
