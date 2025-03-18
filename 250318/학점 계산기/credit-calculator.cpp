#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<double> arr;

    cin>>n;
    arr.resize(n);

    for(auto &a:arr){
        cin>>a;
    }

    double sum=0;
    double avg=0;

    for(auto a:arr){
        sum+=a;
    }

    avg=(double)sum/(double)n;

    //cout<<sum<<" "<<avg<<"\n";

    printf("%.1lf\n", avg);

    if(avg>=4.0) cout<<"Perfect\n";
    else if(avg>=3.0) cout<<"Good\n";
    else cout<<"Poor\n";

    
    return 0;
}