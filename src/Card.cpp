#include "Card.h"

typedef enum {FRONT, BACK} side;

side showing;

Card::Card() : frontText(""), backText(""){
  showing = FRONT;
}

Card::Card(std::string f, std::string b) : frontText(f), backText(b){
  showing = FRONT;
}

Card::~Card(){

}

std::string Card::getVisibleText(){
  if(!isFlippedOver())
    return frontText;
  return backText;
}

std::string Card::getFrontText() const{
  return frontText;
}

std::string Card::getBackText() const{
  return backText;
}

void Card::setFrontText(std::string txt){
  frontText = txt;
}

void Card::setBackText(std::string txt){
  backText = txt;
}

void Card::flip(){
  if(showing == FRONT)
    showing = BACK;
}

bool Card::isFlippedOver(){
  return (showing == BACK);
}

bool Card::operator==(const Card& rhs){
  return ((frontText == rhs.getFrontText()) && (backText == rhs.getBackText()));
}
