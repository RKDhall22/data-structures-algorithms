#include<bits/stdc++.h>
using namespace std;

int main(){

    // Count the number of digits that are there inside the number
    // 234 --> 3 digits

    int n, count=0;

    cout<<"Enter the number of digits that are there in number :";
    cin>>n;

    // Whenever there is any divide operation is going on, the number by which its get divided, that will the base of log time of that number. If the number is getting divided by 5, then its log(base 5) (N)

    while(n>0){

        count++;

        n/=10;  // Here the time complexity of the code will be log(N)/log10 means log10(N) --> log base 10 (N)

    }

    cout<<endl<<"The number of digits inside the number is : "<<count;

}



