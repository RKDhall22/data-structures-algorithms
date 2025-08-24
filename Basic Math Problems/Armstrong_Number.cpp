#include<bits/stdc++.h>
using namespace std;

// Here this function gives the result of the power of that digit that is --> digit^count

 int power_of_digit( int ld , int count){
     
     int result=1;
     
     for(int i=0 ; i<count; i++){
         
         result = result * ld;
         
     }
     
     return result;
     
 }

int main(){
    
    // Check whether the number is Armstrong or not
    // An Armstrong number is a number that is equal to the sum of its digits, each raised to the power of the number of digits in the number. 
    // eg- 371 --> 3^3 + 7^3 + 1^3 = 371
    // 1634 --> 1^4 + 6^4 + 3^4 + 4^4 = 1634
    // 35 --> 3^2 + 5^2 = 34 --> not Armstrong
    
    
    int n ,ld, count=0;
    
    cout<<"Enter the number to check its Armstrong or not: ";
    cin>>n;
    
    // we have taken 2 duplicates of n , because one will be used to check the digits in the number and another will be used to add the digits, so at the end, we require one more value to check with the result whether the number is Armstrong or not, hence we have taken--> dup , dup2 , n
    int dup = n;
    int dup2 = n;
    
    // Lets first count the digits in the number , here the value of dup dissolve when its 0
    
    while(dup>0){
        
        dup=dup/10;
        count++;
        
    }
    
    // cout<<count;
    
    // Now i have the total number of digits that is "count"
    
    int value , sum=0;
    
    // Here the value of dup2 dissolves too, when its value will be 0
    
    while(dup2>0){
        
        // lets take the digits from the back
        
        ld= dup2%10;
        value = power_of_digit(ld , count);
        sum= sum + value;
        dup2 = dup2/10;
        
        
    }
    
    // Now lets check whether the number is Armstrong or not
    
    if(n == sum) cout<<"Armstrong Number";
    else cout<<" Not an Armstrong Number";
    

    
    
}
    