#include<bits/stdc++.h>
using namespace std;

// Find Highest/Lowest frequency Element

int main(){
    
    int n;
    cout<<"Enter the size of Array :";
    cin>>n;
    
    int arr[n];
    unordered_map<int,int> mpp;
    
    
    cout<<"enter Array elements :";
    
    for(int i=0 ;i<n ; i++){
        
        cin>>arr[i];
        mpp[arr[i]]++;  // Here stored the element and freq.
        
        
    }
    
    for(auto i : mpp){
        
        cout<<i.first<<"-->"<<i.second<<endl;
        
    }
    
    
    // Now lets find the highest and lowest
    
    // initialize highest_frequency and lowest_fre that is hf and lf , these are for the frequency (value)
    
    // Then initialize highest_Ele and Lowest_Ele that is he and le for the element (Key)
    
    int hf= mpp[arr[0]] , lf= mpp[arr[0]];
    
    int he=arr[0], le=arr[0]; // Declared intially because if the below for loop does not execute means if it does not go into the "if Statement ", then something should be there in he and le , that why declared them with ar[0]

    // We can go without init the above he and le if in the for loop we check the condition with if(i.second >= hf) && if(i.second <= lf)
    
    cout<<hf<<" "<<lf<<endl;
    
    // int he, le;
    
    // int cnt=0;
    
    // Lets iterate the unordered map
    for(auto i : mpp){
        
        if(i.second > hf){     // Wants highest
            
            hf=i.second;
            he=i.first;
            // cnt=1;
            
        }
        
        if( i.second < lf ){  // Wants lowest
            
            lf=i.second;
            le=i.first;
            
        }
        
    }
    // cout<<"count is : "<<cnt<<endl;
    
    cout<<"The highest frequency element is :"<<he<<endl;
    cout<<"The lowest frequency element is :"<<le;
    
   
}