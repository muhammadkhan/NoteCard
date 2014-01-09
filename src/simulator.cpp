#include "CardSet.h"
#include "Card.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  int num_options = 2;
  int option = -1;
  CardSet* cset = NULL;
  cout<<"============================================"<<endl;
  cout << "NOTECARD by Muhammad Khan" << endl;
  cout<<"============================================"<<endl;
  cout << endl << endl;
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
  return 0;
}
