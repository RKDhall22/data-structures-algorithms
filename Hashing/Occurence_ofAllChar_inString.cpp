#include<bits/stdc++.h>
using namespace std;

// Lets see the occurence of specific characters inside the String which can have all the characters, be special char, uppercase or lowercase


// There are total 256 Characters 


// Lets solve this using Hashing technique

int main(){
    
    string str;
    
    cout<<"Enter the String you want: ";
    cin>>str;
    
    // Precompute
    
    int hash[256]={0};  // string can have a mix of all char, uppercase, lower , special char
    
    for(int i=0 ; i<str.size() ; i++){
        
        hash[str[i]]++;   // Here, directly go the that particular position using its ASCII value, for eg-B, its ASCII is- 66
        
    }
    
    int q; // Number of queries 
    cout<<"enter the number of queries you want to see: ";
    cin>>q;
    
    while(q--){
        
        char c;
        cout<<"Enter the character to check its count : ";
        cin>>c;
        
        cout<<"The count of "<<c<<" is :"<<hash[c]<<endl;
        
        
        
    }
    
    
    
}