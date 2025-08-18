#include<bits/stdc++.h>
using namespace std;

// Now lets user Map data structure to see the counts of characters inside the String

// As, there are total 256 characters, hence, we can do this using Hash array, but lets solve this using Map, which will take also less memory as compare to Hash , because it takes the char/Numbers which are present in String or in the Array.

// Here, in key will store the char which are there inside the String and the frequency will store in value section.

// The main thing to know is, Map stores the key-value pair in sorted order based on the key 

// The most important* thing in Map is related to Time Complexity is - for Storing/Fetching it takes -> Log(N) in all cases, Best, Avg and Worst Case , where N is number of elements in the Map data Structure

// Here , we can also use Unordered Map which will also give the output correctly , but the keys are not in sorted order

int main(){
    
    string str;
    
    cout<<"enter the string to check :";
    cin>>str;
    
    map<char,int> mpp;
    
    for(int i=0 ; i<str.size() ; i++){
        
        mpp[str[i]]++; // eg-> (a,2), (e,0)
        
    }


    // lets print the Map
    for(auto i:mpp){
        
        cout<<i.first<<"-->"<<i.second<<endl;  // It will give result in sorted order

//         enter the string to check :WSFeeAWTE
//         A-->1
//         E-->1
//         F-->1
//         S-->1
//         T-->1
//         W-->2
//         e-->2  // as ASCII of e = 101
        
    }
    
    int q;
    cout<<"Enter the total number of queries: ";
    cin>>q;
    
    while(q--){
        
        char c;
        cout<<"enter the char you want to check its count in string: ";
        cin>>c;
        
        cout<<"The count of "<<c<<" is :"<<mpp[c]<<endl;
        
    }
    
    
}

