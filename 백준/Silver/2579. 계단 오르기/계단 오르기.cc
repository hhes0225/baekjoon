#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dpTable;

/*
    dp[i]: i번째 계단까지 도달했을 때 얻을 수 있는 최대 점수

    기본 아이디어: i 번째 계단에 도달하는 방법은 두 가지
    - i-1번째 계단에서 한 계단
    - i-2번째 계단에서 두 계단

    dp[i]를 계산할 때, 연속된 세 개의 계단을 밟지 않도록 주의해야 함
    따라서 dp[i]는 다음과 같이 계산될 수 있음

    dp[i]=max(dp[i-2], dp[i-3]+stairs[i-1])+stairs[i];
    즉, i-2번째 계단에서 두 계단을 올라오거나,
    
    연속으로 1계단을 2번 움직일 수 없으니
    1 계단만을 움직이려면 전 계단은 무조건 2칸 움직였어야 됨.
    1->1-> 불가능하고 2->1이나 1->2로 가야 한다는 것임
    따라서 i-1번째에서 i번째로 1칸만 움직이려면, i-1번째에서는 무조건
    i-3번째에서 2칸 올라왔어야만 한다는 것임.

    따라서 i-3번째에서 2칸 올라온 값을 계산하기 위해
    dp[i-3]+stairs[i-1]을 사용하여
    연속된 두 개의 계단을 밟지 않는 dp[i-1]의 최댓값을 구함...
    생각보다 이걸 처리하는 게 간단했군
*/

void dp(vector<int>&stairs){
    if(stairs.size()==1){
        dpTable[0]=stairs[0];
        return;
    }
    else if(stairs.size()==2){
        dpTable[0]=stairs[0];
        dpTable[1]=dpTable[0]+stairs[1];
        return;
    }
    else if(stairs.size()==3){
        dpTable[0]=stairs[0];
        dpTable[1]=dpTable[0]+stairs[1];
        dpTable[2]=max(dpTable[0], stairs[1])+stairs[2];
        return;
    }
    
    dpTable[0]=stairs[0];
    dpTable[1]=dpTable[0]+stairs[1];
    dpTable[2]=max(dpTable[0], stairs[1])+stairs[2];

    for(int i=3;i<stairs.size();i++){
        dpTable[i]=max(dpTable[i-2], dpTable[i-3]+stairs[i-1])+stairs[i];
    }
    
    return;
}

int main() {
    int num;
    vector<int> stairs;

    cin>>num;
    stairs.resize(num);
    dpTable.resize(num);

    for(int i=0;i<num;i++){
        cin>>stairs[i];
    }

    dp(stairs);

    /*
    for(int i=0;i<num;i++){
        cout<<dpTable[i]<<" ";
    }*/

    //cout<<endl;

    //마지막 도착 계단을 반드시 밟아야 하므로 dp 테이블의 마지막 값 출력
    cout<<dpTable[dpTable.size()-1];
    
    
    
    return 0;
}