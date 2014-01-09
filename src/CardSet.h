#include "Card.h"

#ifndef CARDSET_H
#define CARDSET_H

class CardSet{
 protected:
  std::string name;
  std::string cur_path;
 public:
  CardSet(std::string n);
  CardSet(std::string n, std::string path);
  ~CardSet();
  void addCard(Card* c);
  void removeCard(Card* c);
  void clear();
  Card* cardAt(unsigned int index);
  void save(std::string path);
  void save();
  void load(std::string path);
  unsigned int size();
};

#endif /*CARDSET_H*/
