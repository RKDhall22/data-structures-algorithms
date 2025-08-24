#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // Check whether the number is prime or not
    
    // The number is prime only if it has 2 factors that is 1 and the number itself
    
    int n, count=0;
    
    cout<<" Enter the number you want to check whether its Prime or not:";
    cin>>n;
    
    
    // Lets solve this using the brute force approach from i=1 to N and if the count>2 then, the number is not prime, else prime
    // In this, the time complexity of the code is O(N)
    
    for(int i=1 ; i<=n ; i++){
        
        if(n%i==0) count++; // the least value of count after the loop finishes will always be 2 for any number, as the number will definately divide by 1 and the number itself
        
    }
    
    if(count!=2) cout<<"Not Prime !! ";
    else cout<<" Prime Number!! ";
    
    // Now lets solve this problem by another approach to optimize the time complexity
    
    // If we runs the loop upto the sqrt(N), then too we will get all the factors of the number N that is by i and N/i
    
    // And in this approach the time complexity will be O(n)^1/2
    
    cout<<endl<<" Lets solve this problem by optimizing the code :";
    count=0;
    
    for(int i=1 ; i*i<=n ; i++){
        
        if(n/i == 0){
            
            count++;
            
            if(i!= n/i ) count++;  // eg- n=4, 1*4, 2*2 , so if we not use this condition, it will take factor 2, twice in count , so count value will be total-4, which should be 3 as 4 has 3 factors only- 1,2,4 
            
        }
        
    }
    cout<<endl;
    if(count!=2)cout<<"Not Prime***";
    else cout<<"Its Prime ***";
    
    
    
    
    
    
}