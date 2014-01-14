#include <iostream>
#include <cstdlib>
#include <set>
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
    string nm, f;
    cout << "Please enter a name for the new set: ";
    cin >> nm;
    cout << "Please enter a filename for this new set: ";
    cin >> f;
    cout << endl << endl << endl;
    cset = new CardSet(nm, f, false);
  } else if(option == 1){
    string p;
    cout << "Please provide the path to the .set file: ";
    cin >> p;
    cout << endl << endl << endl;
    cset = new CardSet("", p);
  }
}

void newCard(CardSet*& cset){
  set<char> yesno ({'y', 'Y', 'n', 'N'});
  string front, back, tok;
  char to_append;
  cout << "Please enter the text for the front of the new card (end the text with one final space (' ') followed by the character '~' - these won't actually be included on the card)" << endl << endl;
  while(tok != "~"){
    cin >> tok;
    if(tok != "~")
      front += (" " + tok);
  }
  cout << endl << endl;
  /* Read for back now */
  cout << "Please enter the text for the back of the new card (again, end the text with one final space (' ') followed by the character '~')" << endl << endl;
  do{
    if(tok != "~")
      back += (" " + tok);
    cin >> tok;
  } while(tok != "~");
  cout << endl << endl;
  /* Ask for whether appending or inserting elsewhere */
  cout << "Would you like to add this card to the end of the set? (y/n): ";
  while(yesno.find(to_append) == yesno.end()){
    cin >> to_append;
    cout << endl;
    if(yesno.find(to_append) == yesno.end())
      cout << "That was an invalid answer, please respond appropriately: ";
  }
  if(to_append == 'y' || to_append == 'Y'){
    cset->addCard(new Card(front, back));
  } else if(to_append == 'n' || to_append == 'N'){
    int p = -1, s = cset->size();
    cout << endl << endl;
    cout << "What position would you like to add this card to? (0 - ";
    cout << s << "): ";
    while(p < 0 || p >= s){
      cin >> p;
      cout << endl;
      if(p < 0 || p >= s)
	cout << "Invalid position entered, please respond appropriately: ";
    }
    cset->addCard(new Card(front, back), p);
  }
  cset->save();
  cout << endl << endl;
  cout << "New card was added! This set now has " << cset->size() << " card(s)" << endl << endl;
}

void remCard(CardSet*& cset){
  int cardnum = -1;
  unsigned int s = cset->size();
  printCardSetContents(*cset);
  cout << endl << endl;
  cout << "Please indicate the number of the card you would like to remove:" << endl << endl;
  while(cardnum <= 0 || cardnum > s){
    cin >> cardnum;
    if(cardnum <= 0 || cardnum > s)
      cout << "Invalid number, please select an appropriate card: ";
  }
  cset->removeCard(cardnum - 1);
  cset->save();
  cout << endl << endl;
  cout << "Card was removed! This set now has " << cset->size() << " card(s)" << endl << endl;
}

void cardActions(CardSet*& cset, int& response){
  int num_choices = 7;
  int choice_exit = num_choices - 1;
  cout << "What would you like to perform on the set?" << endl;
  cout<<"0: Create a new card for the set"<<endl;
  cout<<"1: Delete a card from the set"<<endl;
  cout<<"2: Edit a card" << endl;
  cout<<"3: Work on another set"<<endl;
  cout<<"4: Create a new set of cards"<<endl;
  cout<<"5: Quiz yourself on this set!"<<endl;
  cout<<"6: Exit the program"<<endl;

  cout << endl;
  while(response < 0 || response >= num_choices){
    cin >> response;
    cout << endl;
    if(response < 0 || response >= num_choices)
      cout << "Invalid choice, please enter again" << endl;
  }
  /* Got valid response */
  if(response == 0){
    newCard(cset);
  } else if(response == 1){
    remCard(cset);
  } else if(response == 2){

  } else if(response == 3){

  } else if(response == 4){

  } else if(response == 5){

  }

  if(response != choice_exit)
    response = -1;
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
