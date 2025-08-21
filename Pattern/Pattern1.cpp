//Pattern Printing

// * * * * * * 
// * * * * * * 
// * * * * * * 
// * * * * * * 
// * * * * * * 
// * * * * * * 

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



int main() {
    // Write C++ code here
    
    int n;
    
    cout<<"Enter the number of times you want to print: ";
    cin>>n;
    
    Pattern1(n);
    

    return 0;
}