#include <iostream>

using namespace std;

int m1, m2, d1, d2;
string A;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    int month[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

    int dayCode;

    if(A=="Mon"){
        dayCode=0;
    }
    else if(A=="Tue"){
        dayCode=1;
    }
     else if(A=="Wed"){
        dayCode=2;
    }
     else if(A=="Thu"){
        dayCode=3;
    }
     else if(A=="Fri"){
        dayCode=4;
    }
     else if(A=="Sat"){
        dayCode=5;
    }
    else{
        dayCode=6;
    }

    
    int day1=0, day2=0;

    for(int i=1;i<m1;i++){
        day1+=month[i];
    }
    day1+=d1;

    for(int i=1;i<m2;i++){
        day2+=month[i];
    }
    day2+=d2;

    int gap=day2-day1+1;

    int ans=gap/7;
    
    if(gap%7>=dayCode){
        ans++;
    }
    cout<<ans;
    return 0;
}