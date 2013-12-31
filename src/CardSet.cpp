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
    delete (*iter);
  }
}

void CardSet::addCard(Card* c){
  cardList.push_back(c);
}

void CardSet::removeCard(Card* c){
  std::vector<Card*>::iterator iter;
  for(iter = cardList.begin(); iter != cardList.end(); ++iter){
    
  }
}

void CardSet::clear(){
  cardList.clear();
}

Card* CardSet::cardAt(int index){
  return NULL;
}

void CardSet::save(std::string path){
  std::ofstream outputFile;
  std::vector<Card*>::iterator iter;
  outputFile.open(path);
  //TODO things
  outputFile << cardList.size() << std::endl;
  for(iter = cardList.begin(); iter != cardList.end(); ++iter){
    outputFile << (*iter)->getFrontText();
    outputFile << "|";
    outputFile << (*iter)->getBackText() << std::endl;
  }
  outputFile.close();
}

void CardSet::load(std::string path){
  std::ifstream cardSetFile;
  int T, i;
  cur_path = path;
  cardSetFile.open(path);
  cardSetFile >> T;
  for(i = 0; i < T; i++){
    std::string line, front, back;
    size_t pipePos;
    cardSetFile >> line;
    pipePos = line.find("|");
    if(pipePos == std::string::npos){
      std::cerr << "load: invalid cardset file" << std::endl;
      return;
    }
    front = line.substr(0, pipePos);
    back = line.substr(pipePos + 1);
    addCard(new Card(front, back));
  }
  cardSetFile.close();
}
