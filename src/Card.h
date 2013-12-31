#include <cstdlib>
#include <string>

#ifndef CARD_H
#define CARD_H

class Card{
 protected:
  std::string frontText;
  std::string backText;
 public:
  Card();
  Card(std::string f, std::string b);
  ~Card();
  std::string getFrontText() const;
  std::string getBackText() const;
  std::string getVisibleText();
  void setFrontText(std::string txt);
  void setBackText(std::string txt);
  bool isFlippedOver();
  void flip();
  bool operator==(const Card& rhs);
};

#endif /*CARD.H*/
