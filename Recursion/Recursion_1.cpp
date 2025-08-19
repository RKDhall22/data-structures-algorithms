#include<bits/stdc++.h>
using namespace std;

// Lets learn Recursion --> When a function calls itself until a specified condition is met.

// Important things to know in Recursion

  // 1) If there is no condition like base condition in the function to stop the function loop, then its like the function is running for infinite times.
  
  // 2) So as there is some fixed memory and as you keeps on calling the function, these functions gets stored in stack one on another and these functions are never gets out of the stack because they are not calling back as there is not return statement in the function. So this leads to "Stack Overflow or Segmentation Fault".
  
  // 3) So its important that there should be a base condition in the function.
  
  //4) One more thing is there that is - Recursion Tree, its just a representation of the fucntion in the form of a tree that how many times the function is being called.
  
  
  // Now lets see the code
  
  
  // Here in this function as there is no base condition , this fucntion will run infinitely which cause in Segmentation error or Stack Overflow
  void Recursive(){
      
      
      cout<<1;
      
      Recursive(); // 
      
  }
  
  // Here in this function we have used base condition, that is if count is 2 , then return from there, and once return statement comes, there and then only the function gets terminated,it means the function gets out of the memory and the space is now empty.
  
  void f2(int count){
      
      if(count == 2) return;
      
      cout<<count<<" ";
      count++;
      f2(count);
      
  }
  
  int main(){
      
      // lets call a function
      
    //   Recursive();
    
    int count=0;
    
    f2(count);
    
      
  }
  
  
  
  
  
  
  

