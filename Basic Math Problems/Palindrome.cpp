#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // Check the number is Palindrome or not
    // Palindrome is the reverse of the number is same as the orginal number
    
    // 121--> 121 Palindrome
    // 11 --> 11 Palindrome
    // 345 --> 543 Not Palindrome
    
    
    
    int n , reverse_digit=0;
    
    cout<<"Enter the digit to check its palindrome or not: ";
    cin>>n;
    
    int dup= n;
    
    while(n>0){
        
        reverse_digit = reverse_digit*10 + n%10;
        n/=10;
        
    }
    
    if(reverse_digit == dup) cout<<true;
    else cout<<false;
    
}