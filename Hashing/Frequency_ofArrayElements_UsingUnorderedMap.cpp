#include<bits/stdc++.h>
using namespace std;

// counting frequencies of Array Elements

// Here using Unordered Map to count the frequency , and the TC is O(1) , rarely TC goes to - O(N) , when internal collisions are there

// If used here Map data struture then the TC is- Log(N), hence better is using Unordered Map whose TC is - O(1)

int main(){
    
    int n;
    cout<<"Enter the size of Array :";
    cin>>n;
    
    int arr[n];
    unordered_map<int,int> mpp; // Init Unordered Map
    
    cout<<"Enter the elements in the array now: ";
    
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        mpp[arr[i]]++;
        
    }
    
    // Now lets print frequecy of the Array elements 
    
    for(auto i : mpp){
        
        cout<<i.first<<"-->"<<i.second<<endl;
        
        
    }
    
    
    
    
    
    
    
    
}