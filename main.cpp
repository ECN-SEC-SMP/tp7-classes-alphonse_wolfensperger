#include <iostream>
#include "thispoint.h"
using namespace std;

int main() {
  thispoint p(2,5);
  thispoint p2(3,3);
  thispoint p3(p2); //construction référence
  p.print(); //avant translation

  p.translater(p2); //translation de p par p2
  p.print(); //après translation

  p3.print();

  p2.setx(9); //test d'un accesseur
  p2.print();
}

