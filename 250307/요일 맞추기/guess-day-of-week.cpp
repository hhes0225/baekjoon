#include <bits/stdc++.h>

using namespace std;

int m1, d1, m2, d2;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    string dayName[7]={"Mon", "Tue", "Wed", "Thu", "Tri", "Sat", "Sun"};

    int gap=0;

    int days1=0;
    int days2=0;

    for(int i=1;i<m1;i++){
        days1+=month[i];
    }
    days1+=d1;

    for(int i=1;i<m2;i++){
        days2+=month[i];
    }
    days2+=d2;

    gap=days2-days1;

    //cout<<gap<<"\n";
    
    if(gap>=0){
        cout<<dayName[gap%7]<<"\n";    
    }
    else{
        cout<<dayName[7-abs(gap)%7]<<"\n";  
    }
    

    return 0;
}