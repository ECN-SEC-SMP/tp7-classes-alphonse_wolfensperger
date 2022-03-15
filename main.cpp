#include <iostream>
using namespace std;

class thispoint {
private :

  int x;
  int y;
  
  int a;
  int b;
public:
  void translater(thispoint Trans){
    this->x += Trans.x;
    this->y += Trans.y;
  }

  thispoint(){
    this->x = 0;
    this->y = 0;
  }

  thispoint(int a, int b){
    this->x = a;
    this->y = b;
  }
  

  thispoint(thispoint const& ref_point){
    this->x = ref_point.x;
    this->y = ref_point.y;
  }
  void print(){
    cout<<"x"<<x<<endl;
    cout<<"y"<<y<<endl;
  }
};



int main() { 
  
  thispoint p(2,5);
  thispoint p2(3,3);
  thispoint p3(p2); //construction référence
  p.print(); //avant translation

  p.translater(p2); //translation de p par p2
  p.print(); //après translation
  p2.print();
  p3.print();
}
