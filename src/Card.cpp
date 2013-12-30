#include "Card.h"

typedef enum {FRONT, BACK} side;

side showing;

Card::Card() : frontText(""), backText(""){
  showing = FRONT;
}

Card::~Card(){

}

std::string Card::getVisibleText(){
  if(!isFlippedOver())
    return frontText;
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
