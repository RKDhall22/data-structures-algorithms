// *             * 
// * *         * * 
// * * *     * * * 
// * * * * * * * * 
// * * *     * * * 
// * *         * * 
// *             * 

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

void Pattern6(int n){
    
    for(int i=1 ; i<=n ; i++){
        
        for(int j=1; j<=n-i+1; j++){
            
            cout<<j<<" ";
            
        }
        
        cout<<endl;
        
    }
}

void Pattern7(int n){
    
    for(int i=1 ; i<=n ; i++){
        
        int space= n-i;
        
        for(int j=1; j<n+i; j++){
            
            if(space>0){
                
                cout<<"  ";
                space--;
                
            }
            
            else{
                
                cout<<"* ";
                
            }
            
        }
        
        cout<<endl;
        
    }
}

// Solving the 7th Pattern in another way
void Pattern7_1(int n){
    
    for(int i=n ; i>0 ; i--){
        
        // int space= n-i;
        
        for(int j=1; j<=(2*n-i)   ; j++){
            
          if(i>j){
              
              //Print Space
              
              cout<<"  ";
              
          }
          
          else{
              
              //Print Star
              cout<<"* ";
              
          }
            
        }
        
        cout<<endl;
        
    }
}

void Pattern7_2(int n){
    
    for(int i=0 ; i<n ; i++){
        
        //For Spaces
        
        for(int j=0; j< (n-i-1) ; j++){
            
            cout<<"  ";
            
        }
        
        //For Stars
        
        for(int j=0 ; j< (2*i+1) ; j++){
            
            cout<<"* ";
            
        }
        
        
        cout<<endl;
        
    }
}

void Pattern8(int n){
    
  for(int i=0 ; i<n ; i++){
        
        //For Spaces
        
        for(int j=0; j< i ; j++){
            
            cout<<"  ";
            
        }
        
        //For Stars
        
        for(int j=0 ; j< (2*(n-i)-1) ; j++){
            
            cout<<"* ";
            
        }
        
        
        cout<<endl;
        
    }
}

void Pattern10(int n){
    
  for(int i=0 ; i<n ; i++){
        
       if(i<n/2){
           // Have to print in increasing order
           
           for(int j=0 ; j<=i ; j++){
               
               cout<<"* ";
               
           }
           
       }
       
       else{
           //if i>n/2 --> Have to print in decreasing order
           
           for(int j=0; j<n-i; j++){
               
               cout<<"* ";
               
           }
           
        //   cout<<endl;
           
       }
       
       cout<<endl;
        
    }
}

  void Pattern11(int n){
      
      int binary=1;
      int temp;
      
      for(int i=0 ; i<n ; i++){
          
          temp=binary;
          
          for(int j=0 ; j<=i ; j++){
              
              cout<<temp<<" ";
              
              if(temp+1>1)  //It means temp is greater than 1 or equal to 1
               temp=0;
               
              else
                temp=1;
              
          }
          
          if(binary==1) binary=0;
          else binary=1;
          
          cout<<endl;
          
      }
  }
  
  void Pattern11_1(int n){
      
      int binary;
      
      for(int i=0 ; i<n ; i++){
          
          if(i%2==0) binary=1;
          else binary =0;
          
          for(int j=0 ; j<=i ; j++){
              
              cout<<binary<<" ";
              binary=1-binary;//flip the value from 0-1 and 1-0
              
          }
          
          cout<<endl;
          
      }
  }
  
  void Pattern12(int n){
      
      for(int i=0 ; i<n ; i++){
          
          //Number to print
          
          //2(i+1)/2 --> i+1 
          
          for(int j=1 ; j<=(2*i+2)/2 ; j++){
              
              cout<<j<<" ";
              
          }
          
          //for Spaces
          
          for(int j=0 ; j<(2*n-2-2*i) ; j++ ){
              
              cout<<"  ";
              
          }
          
          //After space , then again number to print in decreasing order
          
          for(int j=i+1 ; j>0 ; j--){
              
              cout<<j<<" ";
              
          }
          
          cout<<endl;
      }
  }
  
  void Pattern13(int n){
      
      int number=1;
      
      for(int i=0 ; i<n ; i++){
          
          for(int j=0 ; j<=i ; j++){
              
              cout<<number<<" ";
              number++;
              
          }
          
          cout<<endl;
      }
  }
  
  void Pattern14(int n){
      
      char ch;
      
      for(int i=0 ; i<n ; i++){
          
          ch='A';
          
          for(int j=0 ; j<=i ; j++){
              
              cout<<ch<<" ";
              ch++;
              
          }
          
          cout<<endl;
      }
  }
  
   void Pattern14_1(int n){
      
    //   char ch;
      
      for(int i=0 ; i<n ; i++){
          
        //   ch='A';
          
          for(char j='A' ; j<='A'+i ; j++){
              
              cout<<j<<" ";
            //   ch++;
              
          }
          
          cout<<endl;
      }
  }
  
  void Pattern15(int n){
      
      for(int i=0 ; i<n ; i++){
          
          for(char j='A' ; j<'A'+(n-i) ; j++){
              
              cout<<j<<" ";
              
          }
          
          cout<<endl;
  }
      
  }    
  
  void Pattern16(int n){
      
      for(char i='A' ; i<'A'+n ; i++){
          
          for(char j='A' ; j<=i ; j++){
              
             cout<<i<<" ";
             
          }
          
          cout<<endl;
          
      }
  }
  
  void Pattern17(int n){
      
      for(int i=0 ; i<n ; i++){
          
          char ch='A';
          
          //for Spaces
          
          for(int j=0 ; j<(n-i-1) ; j++){
              
              cout<<"  ";
              
          }
          
          //for Alpabets now
          
          for(int j=0 ; j<(2*i+1) ; j++){
              
              if(j>(2*i+1)/2){
                  
                  ch--;  
                  cout<<ch<<" ";
                  
              }
              
             else{
                 cout<<ch<<" ";
                 
                if(j<(2*i+1)/2){
                    ch++;
                }
                 
             } 
            
            // if(j<(2*i+1)/2){
                
            //     ch++;
                
            // }
            // else{
                
            //     ch--;
                
            // }
            
            // cout<<ch<<" ";
            
              
              
          }
          
          cout<<endl;
          
      }
  }
  
  void Pattern17_1(int n){
      
      for(int i=0 ; i<n ; i++){
          
         
          char ch='A';
          
           //for Spaces
           
          for(int j=0 ; j<(n-i-1) ; j++){
              
              cout<<"  ";
              
          }
          
          //Characters
          
         int breakpoint= (2*i+1)/2;
         for(int j=1 ; j<=2*i+1 ; j++){
             
             cout<<ch<<" ";
             
             if(j<=breakpoint){
                 ch++;
                 
             }
             else{
                 
                 ch--;
                 
             }
             
             
         }
         
         cout<<endl;
         
      }
  }
  
  void Pattern18(int n){
      
      for(int i=0 ; i<n ; i++){
          
          for(char j='A'+n-i-1 ; j<='A'+n-1; j++){
              
              cout<<j<<" ";
              
          }
          
          cout<<endl;
          
      }
  }
  
  void Pattern19(int n){
      
      int upper_half = n/2;
      
    // Upper half of the pattern
      for(int i=0 ; i< upper_half ; i++){
      
       //For Stars of left hand side its like ( * space *)
       
       for(int j=0 ; j< upper_half-i ; j++){
           
           cout<<"*"<<" ";
           
       }
       
       //for spaces
       
       for(int j=0 ; j<2*i ; j++){
           
           cout<<"  ";
           
       }
       
       //Stars of right hand side
       
       for(int j=0 ; j<upper_half-i ; j++){
           
           cout<<"*"<<" ";
           
       }
       
       
       cout<<endl;
       
      }
      
      // Lower half of the pattern, khali reverse krna hai
      //upper_half=3
      for(int i=upper_half-1 ; i>=0 ; i--){  // 3 times chalega for n=6
      
       //For Stars of left hand side its like ( * space *)
       
       for(int j=0 ; j< upper_half-i ; j++){
           
           cout<<"*"<<" ";
           
       }
       
       //for spaces
       
       for(int j=0 ; j<2*i ; j++){
           
           cout<<"  ";
           
       }
       
       //Stars of right hand side
       
       for(int j=0 ; j<upper_half-i ; j++){
           
           cout<<"*"<<" ";
           
       }
       
       
       cout<<endl;
       
      }
       
  }
  
  void Pattern20(int n){
      
      int space=2*n-2;
     
     //Upper Part
      for(int i=0 ; i<n ; i++){
          
          //stars 
         //star space star
         
          for(int j=0 ; j<i+1 ; j++){
              
              cout<<"*"<<" ";
              
          }

          //space
          
          for(int j=0 ; j<space; j++){
              
              cout<<"  ";
              
          }
          
          //stars
          
          for(int j=0 ; j<i+1 ; j++){
              
              cout<<"*"<<" ";
              
          }
          
          space=space-2;
          cout<<endl;
          
          
      }
    //   space value becomes 0
      //Lower Part
      //n=5
      space=2;
      for(int i=n-1 ; i>0; i-- ){
          
          //stars
          for(int j=1 ; j<=i ; j++){  // i=4, j=4 stars
              
              cout<<"*"<<" ";
              
          } 
          
          //space
          
          for(int j=1 ; j<=space; j++){
              
              cout<<"  ";
              
          }
          
          //stars
          
            for(int j=1 ; j<=i ; j++){  // i=4, j=4 stars
              
              cout<<"*"<<" ";
              
          } 
          
          space=space+2;
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
        // Pattern5(n);
        // Pattern6(n);
        // Pattern7(n);
        // Pattern7_1(n);
        // Pattern7_2(n);
        // Pattern8(n);
        
        // Pattern10(n);
        // Pattern11(n);
        // Pattern11_1(n);
        // Pattern12(n);
        // Pattern13(n);
        // Pattern14(n);
        // Pattern14_1(n);
        // Pattern15(n);
        // Pattern16(n);
        // Pattern17(n);
        // Pattern17_1(n);
        // Pattern18(n);
        // Pattern19(n);
        Pattern20(n);
        
   
    }
    
    // Pattern(n);
    

    return 0;
}

