// Problem   Let us meet in Raven Run
// Class: Cs315-002 Fall 2019 -- practicum v1
// Version 2
// Algorithm Breadth First Search
// Runtime:   O(n^3)
// Author:  Lauren Bassett
// Date:      December 8 2019
// Reference: JWJ Nov, 2019

#include <cassert>
#include <queue>
#include <iostream>


using namespace std;

//state (pos1, pos2, pos3) represented as a triple
typedef pair<int,int> ipair;
typedef pair<int,ipair> itriple;

char trail[64][64];
int dist[64][64][64];

int main ()
{
//READ
  int n, pos1, pos2, pos3;
  bool flag = true;
  while (cin >> n)
  { //THIS WAS ALL GIVEN BY DR.J
    if (n == 0) break;
    assert (1 <= n && n <= 100);
    cin >> pos1 >> pos2 >> pos3;
    pos1--; pos2--; pos3--;
    assert (0 <= pos1 && pos1 < n);
    assert (0 <= pos2 && pos2 < n);
    assert (0 <= pos3 && pos3 < n);
    for (int i=0 ; i<n ; i++)
      for (int j=0 ; j<n ; j++)
        cin >> trail[i][j];
    for (int i=0 ; i<n ; i++)
      for (int j=0 ; j<n ; j++)
        assert (trail[i][j] == trail[j][i]);
    for (int i=0 ; i<n ; i++)
      for (int j=0 ; j<n ; j++)
        for (int k=0 ; k<n ; k++) {     
          dist[i][j][k] = n*n*n+1; //serves as oo
          flag = true;
        }
//INITIALIZE
    dist[pos1][pos2][pos3] = 0;
     itriple t = itriple(pos1, ipair (pos2, pos3));
     queue<itriple> takeAHike; //This is what I did. I created a queue and populated it with the initial positions.
      pos1 = t.first;
      pos2 = t.second.first;
      pos3 = t.second.second;
      takeAHike.push(t); //pusha-T ahahahahahahha

 while(takeAHike.empty() != true) { //This is going to run as long as the friends are still looking.

//CHECK TERMINATION if its empty, lets roll.
      if ((takeAHike.front()).first == (takeAHike.front()).second.first && (takeAHike.front()).first == (takeAHike.front()).second.second)
      { 
        if (flag) //print everything they need to know
        cout <<"LEB 6078\n" << dist[(takeAHike.front()).first][(takeAHike.front()).second.first][(takeAHike.front()).second.second]<< "\n";
        else
        cout <<"LEB 6078\noo\n"; // this was wrong but I am afraid to mess with my code now that it works lol
        break;

//IDENTIFY NEIGHBORS
      }
      int d = dist[(takeAHike.front()).first][(takeAHike.front()).second.first][(takeAHike.front()).second.second] + 1;
      //ALICE GOES INTO THE WOODS
      for (int k=0 ; k<n ; k++)
      {
        if (trail[(takeAHike.front()).first][k] == trail[(takeAHike.front()).second.first][(takeAHike.front()).second.second] && d < dist[k][(takeAHike.front()).second.first][(takeAHike.front()).second.second]) {
          dist[k][(takeAHike.front()).second.first][(takeAHike.front()).second.second] = d;
           itriple t2 = itriple(k, ipair(((takeAHike.front()).second.first),(takeAHike.front()).second.second) );
          takeAHike.push(t2);
	      }
	    }

      //BOB GOES INTO THE WOODS
      for (int k=0 ; k<n ; k++)
      {
        if (trail[(takeAHike.front()).second.first][k] == trail[(takeAHike.front()).first][(takeAHike.front()).second.second] && d < dist[(takeAHike.front()).first][k][(takeAHike.front()).second.second]) 
          { //BOB!
              dist[(takeAHike.front()).first][k][(takeAHike.front()).second.second] = d;
              itriple t2 = itriple((takeAHike.front()).first, ipair(k, (takeAHike.front()).second.second));
              takeAHike.push(t2);
        }
      }

      //CYNTHIA GOES INTO THE WOODS
      for (int k=0 ; k<n ; k++)
      {
        if (trail[(takeAHike.front()).second.second][k] == trail[(takeAHike.front()).first][(takeAHike.front()).second.first] && d < dist[k][(takeAHike.front()).first][(takeAHike.front()).second.first]) { //Cynthia
              dist[(takeAHike.front()).first][(takeAHike.front()).second.first][k] = d;
              itriple t2 = itriple((takeAHike.front()).first, ipair(((takeAHike.front()).second.first),k));
              takeAHike.push(t2);
        }
      }
     takeAHike.pop();
    }
     if (takeAHike.empty()) cout <<"LEB 6078\noo\n"; 
}
 
  return 0;
}

