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

float Forme:: perimetre() {} //méthodes abstraites
float Forme:: surface() {}


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


//***********************FORME CERCLE******************************//
Cercle:: Cercle(void){ 
  Forme f;
  this->formeCercle = f;
  this->rayon=1;
}
    
Cercle:: Cercle(Forme const&ref_forme, int r){ 
  this->formeCercle = ref_forme;
  this->rayon=r;
}

float Cercle::perimetre(void){
  return 2*PI*this->rayon;
}

float Cercle::surface(void) {
  return PI*((this->rayon)^2);
}

ostream& operator<<(ostream &os,const Cercle &Cet){ //utilisation cout<<Point 
  os<<"Centre cercle X value "<<Cet.formeCercle.Point_centre.x<<endl;
  os<<"Centre cercle y value "<<Cet.formeCercle.Point_centre.y<<endl;
  os<<"Cercle rayon value "<<Cet.rayon<<endl;
  return os;
}

//***********************FORME RECTANGLE******************************//
Rectangle:: Rectangle(void){ 
  Forme f;
  this->formeRectangle = f;
  this->largeur=1;
  this->hauteur=1;
}
    
Rectangle:: Rectangle(Forme const&ref_forme, int largeur, int hauteur){ 
  this->formeRectangle = ref_forme;
  this->largeur=largeur;
  this->hauteur=hauteur;
}

float Rectangle::perimetre(void){
  return (2*this->largeur)+(2*this->hauteur);
}

float Rectangle::surface(void) {
  return (this->largeur)*(this->hauteur);
}

ostream& operator<<(ostream &os,const Rectangle &Ret){ //utilisation cout<<Rectangle
  os<<"Centre Rectangle X value "<<Ret.formeRectangle.Point_centre.x<<endl;
  os<<"Centre Rectangle y value "<<Ret.formeRectangle.Point_centre.y<<endl;
  os<<"Rectangle largeur value "<<Ret.largeur<<endl;
  os<<"Rectangle hauteur value "<<Ret.hauteur<<endl;
  return os;
}

//***********************FORME CARRE*********************************//
Carre:: Carre(void){ 
  Rectangle r;
  this->rectCarre = r;
}
    
Carre:: Carre(Forme const&ref_forme, int cote){ 
  this->rectCarre.formeRectangle = ref_forme;
  this->rectCarre.largeur=cote;
  this->rectCarre.hauteur=cote;
}

float Carre::perimetre(void){
  return (4*this->rectCarre.largeur);
}

float Carre::surface(void) {
  return this->rectCarre.largeur*this->rectCarre.largeur;
}

ostream& operator<<(ostream &os,const Carre &Cat){ //utilisation cout<<Carre 
  os<<"Centre Carré X value "<<Cat.rectCarre.formeRectangle.Point_centre.x<<endl;
  os<<"Centre Carré y value "<<Cat.rectCarre.formeRectangle.Point_centre.y<<endl;
  os<<"Carré côté value "<<Cat.rectCarre.largeur<<endl;
  return os;
}


int main() {
  //test Carre:
  Carre ca;
  
  thispoint p(3,4);
  Forme f(p);
  Carre ca2(f,5);

  cout<<ca<<endl;
  cout<<ca2;

  cout<<"perimetre de ca2 :"<<ca2.perimetre()<<endl;
  cout<<"surface de ca2 :"<<ca2.surface()<<endl;
  
  //test rectangle:
  /*Rectangle r;
  
  thispoint p(3,4);
  Forme f(p);
  Rectangle r2(f,5,10);

  cout<<r<<endl;
  cout<<r2;

  cout<<"perimetre de r2 :"<<r2.perimetre()<<endl;
  cout<<"surface de r2 :"<<r2.surface()<<endl;*/
  
  //test cercle:
  /*Cercle c;
  
  thispoint p(3,4);
  Forme f(p);
  Cercle c2(f,5);

  cout<<c<<endl;
  cout<<c2;

  cout<<"perimetre de c2 :"<<c2.perimetre()<<endl;
  cout<<"surface de c2 :"<<c2.surface()<<endl;*/
}