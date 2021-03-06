#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value <= VALUE_ACE);
  assert(c.value >= 2);
  assert(c.suit >= SPADES);
  assert(c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; break;
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; break;
  case FULL_HOUSE: return "FULL_HOUSE"; break;
  case FLUSH: return "FLUSH"; break;
  case STRAIGHT: return "STRAIGHT"; break;
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; break;
  case TWO_PAIR: return "TWO_PAIR"; break;
  case PAIR: return "PAIR"; break;
  case NOTHING: return "NOTHING"; break;
  }
  return "";
}

char value_letter(card_t c) {
  char x;
  switch(c.value) {
  case 2: x = '2'; break;
  case 3: x = '3'; break;
  case 4: x = '4'; break;
  case 5: x = '5'; break;
  case 6: x = '6'; break;
  case 7: x = '7'; break;
  case 8: x = '8'; break;
  case 9: x = '9'; break;
  case 10: x = '0'; break;
  case VALUE_JACK: x = 'J'; break;
  case VALUE_QUEEN: x = 'Q'; break;
  case VALUE_KING: x = 'K'; break;
  case VALUE_ACE: x = 'A'; break;
  default: x = 'D';
  }
  return x;
}


char suit_letter(card_t c) {
  char x;
  switch(c.suit){
  case SPADES: x = 's'; break;
  case HEARTS: x = 'h'; break;
  case DIAMONDS: x = 'd'; break;
  case CLUBS: x = 'c'; break;
  default: x = 'D';
  }
  return x;
}

void print_card(card_t c) {
  char x = value_letter(c);
  char y = suit_letter(c);
  printf("%c%c",x,y);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  int i;

  static const char* value_lets = "234567890JQKA";
  static const char* suit_lets = "shdc";
  
  for(i=0;i<13;i++){
    if(value_lets[i] == value_let){
      temp.value = i + 2;
      break;
    }
  }
  
  for(i=0;i<4;i++){
    if(suit_lets[i] == suit_let){
      temp.suit = i;
      break;
    }
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c % 13 + 2;
  temp.suit = c/13;
  return temp;
}
