#include <iostream>
using namespace std;

class thispoint {
private :
  int a;
  int b;
public:
   int x;
   int y;
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

class Forme {
	private :
	public :
  thispoint Point_centre;

  //méthodes abstraites
  void perimetre(Forme Point_centre);
  void surface(Forme Point_centre);

    Forme& operator+=(const thispoint & pointtrans);
    friend ostream& operator<<(ostream &os,const Forme &Fot);
    
    Forme(thispoint const& ref_point){ //constructeur reference
    	this->Point_centre.x = ref_point.x;
   		this->Point_centre.y = ref_point.y;
 		}
};

Forme& Forme::operator+=(const thispoint& pointtrans){
  Point_centre.x += pointtrans.x;
  Point_centre.y += pointtrans.y;
  return *this;
};

ostream& operator<< (ostream &os,const Forme &Fot){ //utilisation cout<<Point 
  os<<"Forme X value "<<Fot.Point_centre.x<<endl;
  os<<"Forme Y value "<<Fot.Point_centre.y<<endl;
  return os;
};

//***********************FORME CERCLE******************************//
//Classe hérité de forme auquel on ajoute des paramètres// Voir les classes hérités
class Cercle {
	private :
    Forme frm_Cercle;
    int rayon;
	public :

    Cercle(Forme const&ref_forme, int r){ 
    	/*this->frm_Cercle.Point_centre.x = ref_forme.Point_centre.x;
      this->frm_Cercle.Point_centre.y = ref_forme.Point_centre.y;*/
      this->frm_Cercle = ref_forme;
      this->rayon=r;
 		}

};
//***********************FORME RECTANGLE******************************//

//***********************FORME CARRE******************************//



int main() {
  thispoint p2(3,3);
  thispoint p(1,1);
  p+=p2;
  Forme f(p);
  cout<<f;
  f+=p2;
  cout<<f;
  //int ray = 5;
  //Cercle(f,5);
}