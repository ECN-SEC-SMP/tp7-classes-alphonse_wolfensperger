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
  
  thispoint & operator+=(const thispoint & pointtrans);

  //accesseurs
  void setx(int x)  {  this->x = x; }
  void sety(int y)  {  this->y = y; }
};


ostream& operator<< (ostream &os,const thispoint &pt){ //utilisation cout<<Point genere l'affichage des coordonees
  os<<"X value "<<pt.x<<endl;
  os<<"Y value "<<pt.y<<endl;
  return os;
};


thispoint & thispoint::operator+=(const thispoint & pointtrans){
  x+=pointtrans.x;
  y+=pointtrans.y;
  return *this;
};

int main() {
  thispoint p2(3,3);
  thispoint p(1,1);
  p+=p2;
  cout<<p;
}