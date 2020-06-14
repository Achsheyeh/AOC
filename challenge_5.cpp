#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
// purpose is to calculate manhattan distance


/*

  calculate coordinates for each wire
  fetch all xy coordinates common to both wires
  prepare min heap using those coordinates or sort the coordinates
  display coordinates at 0-index

*/


using namespace std;

//using Coords = pair<int,int>;

struct Coords {
  int x, y;

};

struct lessDist{
    
  bool operator()(const Coords& a, const Coords& b){
    if ((abs(a.x) + abs(a.y)) < (abs(b.x) + abs(b.y))) 
      return true;
    else
      return false;
    }
};

typedef set<Coords, lessDist> CPSet; //common points                 //    horizontal line     and   vertical line

enum Quadrant{ONE=0, TWO=1, THREE=2, FOUR=3}; 

struct Plane {
   set<Coords> points;
};


enum CoordDirections { RIGHT = 'R', LEFT = 'L' , UP = 'U', DOWN = 'D' };

bool operator< (const Coords& a, const Coords& b){
  //if ((a.x + a.y) < (b.x + b.y)) 
 
  if (a.x < b.x || (a.x == b.x && a.y < b.y))
    return true;
  else
    return false;
}

void fetchCommonPoints(Plane& w1, Plane& w2, const string& mesg, CPSet& cp) {

  for (auto i = w1.points.begin(), j = w2.points.begin();
           i != w1.points.end() && j != w2.points.end();) {
    
    if (i->x == j->x && i->y == j->y) {
      cp.insert({i->x, i->y});
      i++; j++;
    } else if (*i < *j) {
      i++;
    } else {
      j++; 
    }
    
  }
} 

void fetchCoords(const string& inpStr,  Plane& vPoints) {

  string token;
  Coords cur{}, prev{};
  auto inpLen = inpStr.length();
  auto cntr = 0;


  for(auto elem : inpStr) {
     if (cntr == inpLen-1)
        token.push_back(elem);
     else if(elem != ',') {
        token.push_back(elem);
        cntr++;  
        continue;
     }
     {
       bool hline{false}, vline{false};
       auto pCord = stoi(token.substr(1));
       // cout <<  "   " <<  pCord << endl;
       bool crossQuad{false};
       cout << " point from ( " << cur.x << " , " <<  cur.y  << ") ";
       cur.x = prev.x; //Initially setting with prev
       cur.y = prev.y;
       if (token[0] == CoordDirections::RIGHT) {
         cur.x = cur.x + pCord;
        
         if(prev.x < 0 && (cur.x) > 0)
           crossQuad = true;
         hline = true;
       }
       else if (token[0] == LEFT){
         pCord = -pCord; 
         cur.x = cur.x + pCord;
         if(prev.x > 0 && (cur.x) < 0)
           crossQuad = true;
         
         hline = true;
       }
       else if (token[0] == UP) {
         cur.y = cur.y + pCord; 
         if(prev.y < 0 && (cur.y) > 0)
           crossQuad = true;
 
         vline = true;
        // cout << "its up " ;
       }
       else if (token[0] == DOWN) {
         pCord = -pCord; 
         cur.y = cur.y + pCord;
         if(prev.y > 0 && (cur.y) < 0)
           crossQuad = true;
         vline = true;
         //cout << "its down " ;
       }
       cout << "current point is ( " << cur.x << "," << cur.y << ")\n"; 
       //decide_quad(cur, curQd); 
       decltype(prev.x) start, end;
       if (vline) {
            if (prev.y  > cur.y) {
              start = cur.y; 
              end = prev.y;
            }
            else {
              start = prev.y;
               end = cur.y;
            } 
               
            for (int i = start+1; i <= end;i++)
              vPoints.points.insert({cur.x, i});
       } else {
            if (prev.x > cur.x) {
              start = cur.x; 
              end = prev.x;
            }
           else {
              start = prev.x;     
              end = cur.x;
           }
           for (int i = start+1; i <= end;i++)
             vPoints.points.insert({i, cur.y});
       }


       prev = cur;
       token.clear();
     }
     cntr++;
  }
  

}

void parseInpFile(const char* fname, vector<string>& pwires) {
  
  fstream ifs{fname};
 
  if(!ifs) {
    cout << "failed to open " << fname << endl;
    exit(-1);
  }
   
  string pos;
  while (getline(ifs, pos)) {
    pwires.push_back(move(pos));
    pos.clear();
  } 

}

void processInpFile(const char* fname) {

  vector<string> inpLinePairs;
  parseInpFile(fname, inpLinePairs);

  for (auto& elem : inpLinePairs)
    cout << elem << endl;

  Plane wire1, wire2;

  cout << "parsing wire1" << endl;
  fetchCoords(inpLinePairs[0], wire1);  
  cout << "parsing wire2" << endl;
  fetchCoords(inpLinePairs[1], wire2);  

  CPSet cp;

  fetchCommonPoints(wire1, wire2, "Comparing wire1 and wire2 ", cp);

  


  /*for (auto [x, y] : cp)  structure binding , c++17
    cout << "(" << x << "  " << y << ")" << endl; */
  for (auto elem : cp) {
    auto dist = abs(elem.x) + abs(elem.y); 
    cout << "(" << elem.x << "  " << elem.y << " ," << dist << ")" << endl;
  } 
  
}
int main(int argc, char** argv){
  

  //fstream ifs{argv[1]};


  processInpFile(argv[1]);



  

  return (0);
}
