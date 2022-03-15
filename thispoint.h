#ifndef thispoint_h
#define thispoint_h

class thispoint {
private :

  int x;
  int y;
  
  int a;
  int b;
public:
  void translater(thispoint Trans);//fonction translation

  thispoint(void);//constructeur initialisation origine

  thispoint(int a, int b);//constructeur à partir d'entier
  
  thispoint(thispoint const& ref_point);//constructeur reference

  void print();//affichage des points

  //accesseurs
  void setx(int x);
  void sety(int y);

  //ostream& operator<<(ostream&, thispoint const  &);

};

//ostream& operator<< (ostream &operator, thispoint const&c){};



#endif /* thispoint_h */