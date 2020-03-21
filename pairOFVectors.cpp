// C++ program to demonstrate vector of pairs 
#include<bits/stdc++.h> 
using namespace std; 
typedef pair<int, int> pairs; 
int main() 
{ 
    map<int,int> s; 
    int arr[] = {10, 20, 5, 40 }; 
    int arr1[] = {30, 60, 20, 50}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    // Entering values in vector of pairs 
    for (int i=0; i<n; i++) 
       s.insert( make_pair(arr[i],arr1[i]) );
	
    s.insert(make_pair(8,4) );
    for (auto const &x : s) {
        cout << "(" << x.first << ", "
             << x.second << ")"
             << " "; 
    } 
    auto it = s.find(999);
    cout << it->first << "," << it->second <<endl;
	return 0; 
} 
