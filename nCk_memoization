//Course: CS315 JWJ CS UK
//Author: developed for CS315
//Date: Sep 11, 2019
//Project: Calculating nCk with memoization
//Algorithm: n choose k recursive with memoization, based on nCk = (n-1)C(k-1) + (n-1)Ck
//Purpose: to compare the running time of  memoization with the long time taken to calculate nCk recursively
//Running time: #Calls is = ?? 
//Extras/Bugs: possible overflow
//Compilation: g++ Scratchs7m.cpp
//Synopsis: ./a.out
#include <iostream>

using namespace std;

int values[1000][1000] = {(int)0};

int n_choose_k(int n, int k) {
  if (k == 0)
    return (0); //CHANGE THESE TO RETURN 0 TO FIT THE ANSWER
  if (n == k)
    return (0);
  if (values[n][k] != 0)
    return values[n][k];
  return values[n][k] = (n_choose_k(n - 1, k) + n_choose_k(n - 1, k-1)+ 2)%100000000;
} //this is the equatiom

int main() {
  cout << n_choose_k(10, 5) << endl;
  cout << n_choose_k(20, 10) << endl;
  cout << n_choose_k(30, 15) << endl;
  cout << n_choose_k(39, 15) << endl; //25140840660
  cout << n_choose_k(39, 14) << endl; //15084504396
  cout << n_choose_k(40, 15) << endl; //should be 40225345056
}


