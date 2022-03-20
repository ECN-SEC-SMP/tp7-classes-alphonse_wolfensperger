#pragma once
#include <iostream>
#define PI 3.14
using namespace std;


class thispoint {
private :
  int a;
  int b;
public:
   int x;
   int y;
  void translater(thispoint Trans);

  thispoint();

  thispoint(int a, int b);
  
  thispoint(thispoint const& ref_point);
  void print();

  friend ostream& operator<<(ostream& os,  const thispoint& pt); //friend acceder aux variables privees de la classe
  
  thispoint & operator+=(const thispoint & pointtrans);

  //accesseurs
  void setx(int x) ;
  void sety(int y) ;
};



class Forme {
	private :
	public :
    thispoint Point_centre;

    //méthodes abstraites
    void perimetre(Forme Point_centre);
    void surface(Forme Point_centre);
  

    Forme&Forme ::operator+=(const thispoint& pointtrans);
    friend ostream& operator<<(ostream &os,const Forme &Fot);

    Forme(void);

    Forme(thispoint const& ref_point);
};

//***********************FORME CERCLE******************************//
//Classe hérité de forme auquel on ajoute des paramètres// Voir les classes hérités
class Cercle {
	private :
    
	public :
    Forme formeCercle;
    int rayon;

    friend ostream& operator<<(ostream &os,const Cercle &Cet);

    Cercle(void);
    
    Cercle(Forme const&ref_forme, int r);
};


//***********************FORME RECTANGLE******************************//


//***********************FORME CARRE*********************************//
