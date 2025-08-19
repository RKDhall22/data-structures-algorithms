#include<bits/stdc++.h>
using namespace std;

// Now lets check whether the String is Palindrome or not using Parameterized Way

// This is similar to Reverse logic that is if after reverse both are same, then its palindrome, but instead of reversing the string, if we check the condition that is for eg- "abba" , check for s[i] with s[n-i-1] and if at any point both the values are not equal, string is not Palindrome.


// The time complexity is - O(n/2) , half time iterate on String , where n, size of String
// Auxiliary Space - O(n/2) , in the stack space that is being returned

void f(int i , string &s){
    
    if(i>=s.size()/2){
        
        cout<<true;
        return ;
        
    } 
    
    if(s[i]!=s[s.size()-i-1]) {
        
        cout<<false;
        return;
        
        }
    
     f(i+1 , s);
    
}


int main(){
    
    // string s="abababa";
    
    string s;
    
    cout<<"Enter the string to check whether its Palindrome or not: ";
    cin>>s;
    
    f(0,s);
    
}