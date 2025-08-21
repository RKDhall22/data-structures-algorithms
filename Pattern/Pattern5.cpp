// * * * * * 
// * * * * 
// * * * 
// * * 
// * 

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void Pattern1(int n){
    
    for(int i=0 ; i<n ; i++){
        
        for(int j=0; j<n; j++){
            
            cout<<"* ";
            
        }
        
        cout<<endl;
        
    }
}

void Pattern2(int n){
    
    for(int i=0 ; i<n ; i++){
        
        for(int j=0; j<=i; j++){
            
            cout<<"* ";
            
        }
        
        cout<<endl;
        
    }
}

void Pattern3(int n){
    
    for(int i=1 ; i<=n ; i++){
        
        for(int j=1; j<=i; j++){
            
            cout<<j<<" ";
            
        }
        
        cout<<endl;
        
    }
}

void Pattern4(int n){
    
    for(int i=1 ; i<=n ; i++){
        
        for(int j=1; j<=i; j++){
            
            cout<<i<<" ";
            
        }
        
        cout<<endl;
        
    }
}

void Pattern5(int n){
    
    for(int i=1 ; i<=n ; i++){
        
        for(int j=i; j<=n; j++){
            
            cout<<"*"<<" ";
            
        }
        
        cout<<endl;
        
    }
}



int main() {
    // Write C++ code here
    
    int t; // 2 times
    
    // cout<<"Enter the number of times you want to print: ";
    // cin>>n;
    
    cout<<" How many times you want to print the pattern: ";
    cin>>t;
    
    int n;
    
    for( int i=0 ; i<t ; i++){
        
        // int n;
        cout<<"Enter the number :";
        cin>>n;
        
        // Pattern1(n);
        // Pattern2(n);
        // Pattern3(n);
        // Pattern4(n);
        Pattern5(n);
        
        
        
        
    }
    
    // Pattern(n);
    

    return 0;
}