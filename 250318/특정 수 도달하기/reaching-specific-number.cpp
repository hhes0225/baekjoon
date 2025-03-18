#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr;
    arr.resize(10);

    for(auto &a:arr){
        cin>>a;
    }

    int sum=0;
    double avg=0;
    int num=0;
    for(auto a:arr){
        if(a>=250) break;
        sum+=a;
        num++;
    }

    avg=(double)sum/(double)num;

    cout<<sum<<" "<<avg<<"\n";



    
    return 0;
}