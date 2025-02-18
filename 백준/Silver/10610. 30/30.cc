#include <bits/stdc++.h>
using namespace std;


int main() {
    string n;
    cin>>n;

    sort(n.begin(), n.end(), [](char a, char b){
        return a>b;
    });

    //cout<<n<<"\n";

    if(n.back()!='0'){
        cout<<-1;
    }
    else{
        int sum=0;
        for(auto it:n){
            sum+=((int)it-(int)'0');
        }

        //cout<<sum<<"\n";

        if(sum%3!=0){
            cout<<-1;
        }
        else{
            cout<<n<<"\n";
        }
    }
    
    return 0;
}