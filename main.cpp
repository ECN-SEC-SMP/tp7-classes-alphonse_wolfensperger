#include <iostream>
using namespace std;

class thispoint {
private :

  int x;
  int y;
  
  int a;
  int b;
public:
  void translater(thispoint Trans){ //fonction translation
    this->x += Trans.x;
    this->y += Trans.y;
  }

  thispoint(void){ //constructeur initialisation origine
    this->x = 0;
    this->y = 0;
  }

  thispoint(int a, int b){ //constructeur à partir d'entier
    this->x = a;
    this->y = b;
  }
  
  thispoint(thispoint const& ref_point){ //constructeur reference
    this->x = ref_point.x;
    this->y = ref_point.y;
  }
  void print(){ //affichage des points
    cout<<"x"<<x<<endl;
    cout<<"y"<<y<<endl;
  }
  friend ostream& operator<<(ostream& os,  const thispoint& pt); //friend acceder aux variables privees de la classe

  //accesseurs
  void setx(int x)  {  this->x = x; }
  void sety(int y)  {  this->y = y; }
};


ostream& operator<< (ostream &os,const thispoint &pt){ //utilisation cout<<Point genere l'affichage des coordonees
  os<<"X value "<<pt.x<<endl;
  os<<"Y value "<<pt.y<<endl;
  return os;
};


int main() {
  thispoint p(2,5);
  thispoint p2(3,3);
  thispoint p3(p2); //construction référence
  //p.print(); //avant translation

  p.translater(p2); //translation de p par p2
  //p.print(); //après translation

  //p3.print();

  p2.setx(9); //test d'un accesseur
  //p2.print();

  cout<<p2;
}

