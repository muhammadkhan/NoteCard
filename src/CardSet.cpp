#include "CardSet.h"
#include <iostream>
#include <fstream>

CardSet::CardSet(std::string n) : name(n), cur_path(""){

}

CardSet::CardSet(std::string n, std::string path) : name(n), cur_path(path){
  load(path);
}

CardSet::~CardSet(){
  std::vector<Card*>::iterator iter;
  for(iter = cardList.begin(); iter != cardList.end(); ++iter){
    free(*iter);
  }
}

void CardSet::addCard(Card* c){
  cardList.push_back(c);
}

void CardSet::removeCard(Card* c){

}

void CardSet::clear(){

}

Card* CardSet::cardAt(int index){
  return NULL;
}

void CardSet::save(std::string path){
  std::ofstream outputFile;
  outputFile.open (path);
  //TODO things
  outputFile.close();
}

void CardSet::load(std::string path){

}
