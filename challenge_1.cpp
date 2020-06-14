#include <iostream>

using std::cout;
using std::endl; 
using std::cin;

int calculateFuel(int mass){
 
  return (mass/3) - 2;

}

int main(){

   int mass;
   long long totFuel = 0;
   while (cin >> mass) {
     totFuel += calculateFuel(mass); 
     mass = 0;
   }

   cout << totFuel << endl;
   return(0);
}
