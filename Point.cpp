#include <iostream>
#include "Point.h"
#define PI 3.14
using namespace std;


  void thispoint:: translater(thispoint Trans){ //fonction translation
    this->x += Trans.x;
    this->y += Trans.y;
  }

  thispoint::thispoint(){ //constructeur initialisation origine
    this->x = 0;
    this->y = 0;
  }

  thispoint::thispoint(int a, int b){ //constructeur à partir d'entier
    this->x = a;
    this->y = b;
  }
  
  thispoint::thispoint(thispoint const& ref_point){ //constructeur reference
    this->x = ref_point.x;
    this->y = ref_point.y;
  }
  void thispoint:: print(){ //affichage des points
    cout<<"x"<<x<<endl;
    cout<<"y"<<y<<endl;
  }


  //accesseurs
  void thispoint:: setx(int x){
    this->x = x;
    }
  void thispoint:: sety(int y){ 
    this->y = y; 
    }


  ostream& operator<< (ostream &os,const thispoint &pt){ //utilisation cout<<Point genere l'affichage des coordonees
    os<<"X value "<<pt.x<<endl;
    os<<"Y value "<<pt.y<<endl;
    return os;
  }

  thispoint & thispoint::operator+=(const thispoint & pointtrans){
    x+=pointtrans.x;
    y+=pointtrans.y;
    return *this;
  }


  Forme::Forme(void){ //constructeur reference
    thispoint p;
    this->Point_centre = p;
  }

  Forme::Forme(thispoint const& ref_point){ //constructeur reference
    this->Point_centre.x = ref_point.x;
    this->Point_centre.y = ref_point.y;
  }
/*
    Forme& operator+=(const thispoint & pointtrans);
    friend ostream& operator<<(ostream &os,const Forme &Fot);

    Forme(void);

    Forme(thispoint const& ref_point);*/

  Forme&Forme ::operator+=(const thispoint& pointtrans){
    Point_centre.x += pointtrans.x;
    Point_centre.y += pointtrans.y;
    return *this;
  }

  ostream& operator<<(ostream &os,const Forme &Fot){ //utilisation cout<<Point 
    os<<"Forme X value "<<Fot.Point_centre.x<<endl;
    os<<"Forme Y value "<<Fot.Point_centre.y<<endl;
    return os;
  }


   Cercle:: Cercle(void){ 
      Forme f;
      this->formeCercle = f;
      this->rayon=1;
 		}
    
   Cercle:: Cercle(Forme const&ref_forme, int r){ 
    	/*this->frm_Cercle.Point_centre.x = ref_forme.Point_centre.x;
      this->frm_Cercle.Point_centre.y = ref_forme.Point_centre.y;*/
      this->formeCercle = ref_forme;
      this->rayon=r;
 		}

    /*float perimetre(void) override {
      return 2*PI*this->rayon;
    }

    float surface(void) override {
      return PI*((this->rayon)^2);
    }*/

ostream& operator<<(ostream &os,const Cercle &Cet){ //utilisation cout<<Point 
  os<<"Centre cercle X value "<<Cet.formeCercle.Point_centre.x<<endl;
  os<<"Centre cercle y value "<<Cet.formeCercle.Point_centre.y<<endl;
  os<<"Cercle rayon value "<<Cet.rayon<<endl;
  return os;
}

//***********************FORME RECTANGLE******************************//


//***********************FORME CARRE*********************************//

int main() {
  Cercle c;
  
  thispoint p(3,4);
  Forme f(p);
  Cercle c2(f,5);

  cout<<c<<endl;
  cout<<c2;
}