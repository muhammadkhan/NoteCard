#include "Card.h"

#ifndef CARDSET_H
#define CARDSET_H

class CardSet{
 protected:
  std::string name;
  std::string cur_path;
 public:
  CardSet(std::string n);
  CardSet(std::string n, std::string path, bool ld = true);
  ~CardSet();
  unsigned int size();
  void addCard(Card* c, int pos = -1 );
  void removeCard(Card* c);
  void removeCard(unsigned int pos);
  void clear();
  Card* cardAt(unsigned int index);
  void save(std::string path);
  void save();
  void load(std::string path);
};

#endif /*CARDSET_H*/
