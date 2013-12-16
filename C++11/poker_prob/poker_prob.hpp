#ifndef POKER_PROB_HPP
#define POKER_PROB_HPP

#include <assert.h>
#include <iostream>

using std::ostream;
using std::cout;

enum class suit : short { SPADE, HEART, DIAMOND, CLUB };

class pips {

public:
  pips(int val) :v(val) { assert(v > 0 && v < 14); }
  friend ostream& operator<<(ostream & out, pips p);
  inline int get_pips() { return v; }

private:
  int v;
};

class card {

public:
  card() : s(suit::SPADE), v(1) {}
  card(suit s, pips v) : s(s), v(v) {}
  friend ostream& operator<<(ostream & out, card c);
  suit get_suit() { return s; }
  pips get_pips() { return v; }
  void set_suit(const suit & s) { this->s = s; }
  void set_pips(const pips & v) { this->v = v; }

private:
  suit s;
  pips v;
};

ostream& operator<<(ostream & out, suit s) {
  out << static_cast<std::underlying_type<suit>::type>(s);
  return out;
}

ostream& operator<<(ostream & out, pips p) {
  out << p.get_pips();
  return out;
}

ostream& operator<<(ostream & out, card c) {
  out << c.v << " " << c.s;
  return out;
}

#endif
