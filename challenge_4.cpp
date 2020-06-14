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
 
  vector<int> dupVec;

  int targetVal = 19690720;
  int sum = 0;

  for (int pos = 2, startPos = 12; sum < targetVal && pos <= 99 && startPos <= 99; ++pos) {
    dupVec = posVec;
    dupVec[1] = startPos;
    dupVec[2] = pos;
   
    for(int i=0 ; i < dupVec.size(); i++) {
     // cout << endl << i << " " << (i + 1) << " " << (i + 2) << " " << (i + 3) << endl;
    // cout << dupVec[i] << " " << dupVec[i + 1] << " " << dupVec[i + 2] << " " << dupVec[i + 3] << " ";
  
      if (dupVec[i] == 1) {
        dupVec[dupVec[i+3]] = dupVec[dupVec[i+1]] + dupVec[dupVec[i+2]];
      }
      else if (dupVec[i] == 2) {
        dupVec[dupVec[i+3]] = dupVec[dupVec[i+1]] * dupVec[dupVec[i+2]];
      }
      else  if (dupVec[i] == 99) {
        break;
      }
/*     if (dupVec[i + 3] < dupVec.size()) 
        cout << "pos is " << dupVec[i + 3] << " " << "value is " << dupVec[dupVec[i + 3]];
     else
         cout << "pos is " << dupVec[i + 3] <<  " not sure";
     cout << endl;
  */   // cout << (100 * dupVec[dupVec[i + 1]]) << " " << dupVec[dupVec[i+2]] << " " << (100* dupVec[dupVec[i+1]] + dupVec[dupVec[i+2]]) << endl; 
      i += 3; 
      continue;
      
    } 
    sum = dupVec[0]; 
    cout << sum << endl; 
    dupVec.clear();
    if (pos == 99) {
      ++startPos;
      pos = 1;
    }
    if (sum == targetVal) {
      cout << "target reached for positions " << startPos << " " << pos << endl;
      break;
    }
 } 
 
  return (0);
  
}
