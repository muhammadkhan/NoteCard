#include "CardSet.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define DELIMITER "|"
#define END_MARKER "~"

std::vector<Card*> cardList;

/* LOCAL FUNCTIONS, UNEXPOSED THROUGH INTERFACE */

std::string fixPath(std::string path){
  size_t last_dot = path.find_last_of('.');
  if(last_dot == std::string::npos){
    return (path + ".set");
  } else if(last_dot + 1 == path.length()){
    return (path + "set");
  } else{
    std::string ext = path.substr(last_dot + 1);
    if(ext.compare("set") != 0){
      return (path.substr(0, last_dot + 1) + "set");
    }
    return path;
  }
}

/* IMPLEMENTATION OF INTERFACE FUNCTIONS */

CardSet::CardSet(std::string n) : name(n), cur_path(""){

}

CardSet::CardSet(std::string n, std::string path) : name(n), cur_path(fixPath(path)){
  load(cur_path);
}

CardSet::~CardSet(){
  std::vector<Card*>::iterator iter;
  for(iter = cardList.begin(); iter != cardList.end(); ++iter){
    delete (*iter);
  }
}

unsigned int CardSet::size(){
  return cardList.size();
}

void CardSet::addCard(Card* c, int pos){
  if(pos == -1 || pos >= size() - 1)
    cardList.push_back(c);
  else {
    std::vector<Card*>::iterator iter = cardList.begin();
    cardList.insert(iter + pos, c);
  }
}

void CardSet::removeCard(Card* c){
  std::vector<Card*>::iterator iter;
  for(iter = cardList.begin(); iter != cardList.end(); ++iter){
    if(**iter == *c){
      cardList.erase(iter);
      return;
    }
  }
}

void CardSet::clear(){
  cardList.clear();
}

Card* CardSet::cardAt(unsigned int index){
  return cardList.at(index);
}

void CardSet::removeCard(unsigned int pos){
  if(pos < 0 || pos >= size()){
    std::cerr << "This is an invalid position" << std::endl;
    return;
  }
  return removeCard(cardAt(pos));
}

void CardSet::save(){
  if(cur_path.size() == 0){
    std::cerr << "Sorry, there is no path associated with this set" << std::endl;
    return;
  }
  save(cur_path);
}

void CardSet::save(std::string path){
  std::ofstream outputFile;
  std::vector<Card*>::iterator iter;
  outputFile.open(fixPath(path));
  outputFile << cardList.size() << " " << name << std::endl;
  for(iter = cardList.begin(); iter != cardList.end(); ++iter){
    outputFile << (*iter)->getFrontText();
    outputFile << " " << DELIMITER << " ";
    outputFile << (*iter)->getBackText();
    outputFile << " " << END_MARKER << std::endl;
  }
  outputFile.close();
}

void CardSet::load(std::string path){
  std::ifstream cardSetFile;
  std::string n;
  int T, i;
  if(cur_path.length() == 0)
    cur_path = fixPath(path);
  cardSetFile.open(fixPath(path));
  cardSetFile >> T;
  cardSetFile >> n;
  name = n;
  for(i = 0; i < T; i++){
    bool foundDelim = false;
    std::string token;
    std::string front, back;
    cardSetFile >> token;
    while(token.compare(END_MARKER) != 0){
      if(token.compare(DELIMITER) == 0){
	foundDelim = true;
      } else if(!foundDelim){
	front.append(" " + token);
      } else{
	back.append(" " + token);
      }
      cardSetFile >> token;
    }
    addCard(new Card(front, back));
  }
  cardSetFile.close();
}
