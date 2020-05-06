#include <iostream>
#include <algorithm>
using namespace std;
long long inversions = 0;
void  bubblesortS(int *a, int n) {
	int tmp, inversions;
	inversions = 0;
	for(int i=0 ; i<n  ; i++) {
			for(int j =i+1; j<n; j++) {
				if (a[i] > a[j] ){
			       	
				//	cout << inversions<< endl;
				//	tmp = a[j];
				//	a[j] = a[j+1];
				//	a[j+1] = tmp;
					inversions++;
				}
			}		
	} cout << inversions << endl; 
	//return inversions;
}

int main(){
	int n, a[1000];
	cin>>n;
	for(int i =1; i<n; i++) {
		cin >>a[i];
		}
	bubblesortS(a,n);

	//for (int i = 1; i<n; i++) {cout<<a[i] << "\n";}
//	cout << "Inversions = " << inversions << endl;
}

