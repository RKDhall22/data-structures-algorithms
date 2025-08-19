#include<bits/stdc++.h>
using namespace std;

// x^n

// 2nd Approach optimized

// 2^4= 2*2*2*2 = f(x,n/2)*f(x,n/2) --> Here , we are using multiple recursion call , that is 2

// But when the power is odd, for example 17 then,
// 2^17 = 2* 2^8 * 2^8 = 2* f(x,n/2)*f(x,n/2)

// The time complexity of this is - O(log(base2)n) , because here we are dividing n by 2 everytime.

int f(int x, int n){
    
    if(n==1) return x;
    
    if(n%2!=0){  // Means odd
        
        return x * f(x , n/2) * f(x , n/2);
        
    }
    
    return f(x , n/2) * f(x , n/2);  // Means Even
    
}

int main(){
    
    int x,n;
    
    cout<<"Enter the value of x and n :";
    cin>>x>>n;
    
    cout<<f(x,n);
    
    
    
}