#include <iostream>

using namespace std;

int m1, d1, m2, d2;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    int numOfDays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    int ans=0;

    //시작 달: 한 달의 해당 일자부터 남은 일수 더하기
    ans+=(numOfDays[m1]-d1+1);//+1한 이유는 자기 자신 포함해야 하기 때문
    //cout<<numOfDays[m1]-d1<<"\n";

    //끼이는 중간 달: 그냥 통으로 더해주기
    for(int i=m1+1;i<m2;i++){
        ans+=numOfDays[i];
    }

    if(m1!=m2)
        //마지막달: d2 일수 더하기
        ans+=d2;

    cout<<ans<<"\n";

    return 0;
}