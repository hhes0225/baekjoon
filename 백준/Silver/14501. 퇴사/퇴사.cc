#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> T;
vector<int> P;
vector<int> dpTable;

/*
    dp 테이블 점화식
    dp 테이블의 의미: i일 까지 상담했을 때 받을수 있는 최대 수익

    만약 i일부터 i+n일(상담일수) 까지 상담했다면,
    겹치지 않기 위해서는
    i-1일까지 최대수익 + i~i+n일까지 상담했을 때 수익이 
    i+n일 항목에 저장될 것이다.
    
    따라서 점화식은
    dpTable[i+n-1] = max(dpTable[i+n-1], dpTable[i-1]+수익(i~i+n))

    참고로 n은 T[i]
    수익은 P[i]

    이런 식으로 세워지지 않을까?
    라는 가정 하에 일단 해보자.
*/

void memoi(){
    for(int i=1;i<dpTable.size();i++){
        if(i+T[i]-1>=dpTable.size()){
            //cout<<"통과\n";
            continue;
        }

        //cout<<*max_element(dpTable.begin(), dpTable.begin()+i)<<endl;
        int prevMax=*max_element(dpTable.begin(), dpTable.begin()+i);

        //cout<<dpTable[i+T[i]-1]<<" "<<(prevMax+P[i])<<"\n";
        
        dpTable[i+T[i]-1] = max(dpTable[i+T[i]-1], prevMax+P[i]);

        //cout<<"dpTable["<<i+T[i]-1<<"]="<<dpTable[i+T[i]-1]<<"\n";
    }
}

int main() {
    int days;
    cin>>days;

    T.resize(days+1);
    P.resize(days+1);
    dpTable.assign(days+1, 0);

    for(int i=1;i<=days;i++){
        cin>>T[i]>>P[i];
    }

    memoi();

    /*
    for(auto it: dpTable){
        cout<<it<<" ";
    }*/

    cout<<*max_element(dpTable.begin(), dpTable.end());
    
    return 0;
}