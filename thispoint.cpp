#include <iostream>
#include "thispoint.h"
using namespace std;

void thispoint::translater(thispoint Trans){ //fonction translation
  this->x += Trans.x;
  this->y += Trans.y;
}

void thispoint::thispoint(void){ //constructeur initialisation origine
  this->x = 0;
  this->y = 0;
}

void thispoint::thispoint(int a, int b){ //constructeur à partir d'entier
  this->x = a;
  this->y = b;
}
  
void thispoint::thispoint(thispoint const& ref_point){ //constructeur reference
  this->x = ref_point.x;
  this->y = ref_point.y;
  }
void thispoint::print(){ //affichage des points
  cout<<"x"<<x<<endl;
  cout<<"y"<<y<<endl;
}

void thispoint::setx(int x)  {  this->x = x; }
void thispoint::sety(int y)  {  this->y = y; }