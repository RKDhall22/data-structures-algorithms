#include<bits/stdc++.h>
using namespace std;

// Lets see the occurence of specific characters inside the String
// If all the characters in the String are in lower case and all are alphabets

// There are total 256 Characters 
// But here we are using alphabets, all are in lowercase , hence total characters will be 26

// Lets solve this using Hashing technique

int main(){
    
    string str;
    
    cout<<"Enter the String you want: ";
    cin>>str;
    
    // Precompute
    
    int hash[26]={0};  // 26 size for alpha and init with all 0
    
    for(int i=0 ; i<str.size() ; i++){
        
        hash[str[i]-'a']++;   // We are using the ASCII here , for eg-(b-a)--> (98-97)--> (1) , b's count will stored at index 1 in hash
        
    }
    
    int q; // Number of queries 
    cout<<"enter the number of queries you want to see: ";
    cin>>q;
    
    while(q--){
        
        char c;
        cout<<"Enter the character to check its count : ";
        cin>>c;
        
        cout<<"The count of "<<c<<" is :"<<hash[c-'a']<<endl;
        
        
        
    }
    
    
    
}