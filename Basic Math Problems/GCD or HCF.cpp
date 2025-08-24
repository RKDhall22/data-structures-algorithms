#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //GCD or HCF of number
    
    //GCD(52,10) --> 2 , as is the highest common factor
    
    // The first brute force approach is, lets run the loop from 1 to min(a,b), because its obvious that for example, lets take (52,10), if we run the loop for the numbers after 10, then its obvious that no number will able to divide 10 because the answer will be always in 0.something. Hence, will always get the GCD which will be lesser than min(a,b).
    
    //Hence, time complexity of this logic is --> O(min(a,b))
    
    int n1,n2 , gcd=1; // gcd will always atleast 1
    
    cout<<"Enter both the numbers to get the gcd of it: ";
    cin>>n1>>n2;
    
    for(int i=1 ; i<=min(n1,n2) ; i++){
        
        if(n1%i==0 && n2%i==0){
            
            gcd=i;
            
        }
        
    }
    
    cout<<"GCD of both the numbers is : "<<gcd;
    
    // Now lets solve this code by using Euclidean Algorithm
    
    //what it says,  gcd(a,b) == gcd(a-b,b) , where a>b , have to do this until one number becomes 0 and then the another number is the GCD of both.
    
    //eg- gcd(12,9) = gcd (3,9) now swap as a<b == gcd(9,3) == gcd(6,3) ==gcd(3,3) == gcd (0,3) , now as one element is 0, then the 2nd element is the gcd of both that is 3 , gcd(12,9) = 3
    
    // but this above approach of doing subtraction again and again might not help up in optimizing the linear complexity by much
    
    // But if we check the above approach closely will able to see that, we are decreasing that a by b that is by 9, so it is nothing but we are doing divide operation means in the first position, the remainder is being stored that is 12%9 = 3 , (3,9) and now when b>a, then it should be b%a that comes =0 , and then the 2nd element is the gcd of both.
    
    // now lets see the code of it, we have to run the loop until both the numbers are greater than 0
    
    cout<<endl<<"Now lets see the optimized version where we used Euclidean Algorithm :"<<endl;
    
    
    while(n1>0 && n2>0){
        
        if(n1>n2) n1 = n1%n2;
        else n2 = n2%n1;
        
    }
    
    if(n1==0) cout<<"gcd is :"<<n2;
    else cout<<"gcd is :"<<n1;
    
    // Here, now the time complexity is-  O(log (base φ) min(n1,n2)) , why φ, because here we dont know by which number the other number is getting divided.
    
    // Why time complexity is in terms of log, because the number gets divided/modulo by some other number, as that number is not fixed hence used φ as base of log.
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}