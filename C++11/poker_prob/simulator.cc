#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "poker_prob.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

void init_deck(vector<card> & d) {
  for(int i = 1; i < 14; ++i) {
    card c1(suit::SPADE, i); d[i - 1] = c1; // 0 ~ 12
    card c2(suit::HEART, i); d[i + 12] = c1; // 13 ~ 25
    card c3(suit::DIAMOND, i); d[i + 25] = c3; // 26 ~ 38
    card c4(suit::CLUB, i); d[i + 38] = c4; // 39 ~ 51
  }
}

void print(vector<card> & deck) {
  for(auto & card_val : deck) {
    cout << card_val;
  }
  cout << endl;
}

bool is_flush(vector<card> & hand) {
  suit s = hand[0].get_suit();
  for(auto p = hand.begin() + 1; p != hand.end(); ++p) {
    if(s != p->get_suit()) {
      return false;
    }
  }
  return true;
}

bool is_straight(vector<card> & hand) {
  int pips_v[5], i = 0;
  for(auto p = hand.begin(); p!= hand.end(); ++p) {
    pips_v[i++] = (p->get_pips()).get_pips();
  }
  sort(pips_v, pips_v + 5);
  if(pips_v[0] != 1) { //non-aces
    return (pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1)
  	&& (pips_v[2] == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1);
  } else { //aces have a special logic
    return (pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1)
    	&& (pips_v[2] == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1)
	|| (pips_v[1] == 10) && (pips_v[2] == 11) && (pips_v[3] == 12)
	&& (pips_v[4] == 13);
  }
}

bool is_straight_flush(vector<card> & hand) {
  return is_flush(hand) && is_straight(hand);
}

bool is_4of_akind(vector<card> & hand) {}

bool is_straight_flush_7(vector<card> & hand) {}

int main(int argc, char *argv[])
{
  vector<card> deck(52);
  srand(time(0));
  init_deck(deck);
  int how_many;
  int flush_cnt = 0, str_cnt = 0, str_flush_cnt = 0;
  cout << "How many shuffles?\n";
  cin >> how_many;
  for(int loop = 0; loop < how_many; ++loop) {
    random_shuffle(deck.begin(), deck.end());
    vector<card> hand(5);
    int i = 0;
    for(auto p = deck.begin(); i < 5; ++p) { hand[i++] = *p; }
    if(is_flush(hand)) flush_cnt ++;
    if(is_straight(hand)) str_cnt ++;
    if(is_straight_flush(hand)) str_flush_cnt ++;
  }
  cout << "Flushes" << flush_cnt << " out of " << how_many << endl;
  cout << "Straights" << str_cnt << " out of " << how_many << endl;
  cout << "Straights Flushes" << str_flush_cnt << " out of " << how_many << endl;
  return 0;
}
