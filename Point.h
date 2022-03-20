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

  friend ostream& operator<<(ostream& os,  const thispoint& pt); 
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
    virtual float perimetre();
    virtual float surface();
  
    //surcharge
    Forme& operator+=(const thispoint& pointtrans);
    friend ostream& operator<<(ostream &os,const Forme &Fot);

    //constructeurs
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

    float perimetre();
    float surface();

    friend ostream& operator<<(ostream &os,const Cercle &Cet);

    Cercle(void);
    
    Cercle(Forme const&ref_forme, int r);
};


//***********************FORME RECTANGLE******************************//
class Rectangle {
	private :
    
	public :
    Forme formeRectangle;
    int largeur;
    int hauteur;

    float perimetre();
    float surface();

    friend ostream& operator<<(ostream &os,const Rectangle &Ret);

    Rectangle(void);
    
    Rectangle(Forme const&ref_forme, int largeur, int hauteur);
};


//***********************FORME CARRE*********************************//
class Carre {
	private :
    
	public :
    Rectangle rectCarre;

    float perimetre();
    float surface();

    friend ostream& operator<<(ostream &os,const Carre &Cat);

    Carre(void);
    
    Carre(Forme const&ref_forme, int cote);
};
