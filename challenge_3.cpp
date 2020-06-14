#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

  if (argc != 2) {
    cerr << "argument count not matched : challenge_3 inputfile " << endl;
    exit(-1);
  }
    
  fstream ifs{argv[1]};
  vector<int> posVec;
  string pos;
  char delim;
  while(getline(ifs, pos, ',')) {
     posVec.push_back(stoi(pos)); 
  }

  for (auto elem: posVec)  
    cout << elem << ",";

  cout << endl;

  
  posVec[1] = 12;
  posVec[2] = 2;
 
  for(int i=0 ; i < posVec.size(); i++) {
    cout << endl << i << " " << (i + 1) << " " << (i + 2) << " " << (i + 3) << endl;
    cout << posVec[i] << " " << posVec[i + 1] << " " << posVec[i + 2] << " " << posVec[i + 3] << " ";

    if (posVec[i] == 1) {
      posVec[posVec[i+3]] = posVec[posVec[i+1]] + posVec[posVec[i+2]];
    }
    else if (posVec[i] == 2) {
      posVec[posVec[i+3]] = posVec[posVec[i+1]] * posVec[posVec[i+2]];
    }
    else  if (posVec[i] == 99) {
      break;
    }
   if (posVec[i + 3] < posVec.size()) 
      cout << "pos is " << posVec[i + 3] << " " << "value is " << posVec[posVec[i + 3]];
   else
       cout << "pos is " << posVec[i + 3] <<  " not sure";
   cout << endl;
   // cout << (100 * posVec[posVec[i + 1]]) << " " << posVec[posVec[i+2]] << " " << (100* posVec[posVec[i+1]] + posVec[posVec[i+2]]) << endl; 
    i += 3; 
    continue;
    
  } 
 
  cout << posVec[0] << endl; 
  return (0);
  
}
