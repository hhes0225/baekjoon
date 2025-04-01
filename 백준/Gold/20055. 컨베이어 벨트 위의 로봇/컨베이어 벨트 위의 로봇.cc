#include <bits/stdc++.h>
using namespace std;

/*
    1번: 올리는 위치
    N번: 내리는 위치
    로봇 올리는 위치에 올리거나 다른 칸 이동하면 
    이동한 칸의 내구도 1 감소
    k 이상 내구도 0개 칸 있으면 종료

    1. 벨트가 로봇과 함께 한 칸 회전
    2. 가장 먼저 벨트에 올라간 로봇부터 벨트 회전 방향으로 이동 가능하면 이동
        2-1. 이동하려는 칸에 로봇 없어야 하고, 칸 내구도 1이상이어야 함
    3. 올리는 위치 칸의 내구도 1 이상일때만 로봇 놓는다
    4. 내구도 0인 칸의 개수 k개 이상이라면 과정 종료. 그렇지 않으면 1번 반복
    
*/
struct Belt {
    int cntLeft;
    bool isHereRobot=false;
};
deque<Belt> conveyer; 

int steps=0;

void step1_rotateBelt(int n){
    steps++;
    conveyer.push_front(conveyer.back());
    conveyer.pop_back();

    if(conveyer[n-1].isHereRobot){//빼주기
        conveyer[n-1].isHereRobot=false;
    }
}

void putRobot(int idx){
    conveyer[idx].cntLeft--;
    conveyer[idx].isHereRobot=true;
}

void step2_moveRobot(int n){
    for(int i=n-2;i>=0;i--){
        if(conveyer[i].isHereRobot&&//칸에 로봇 있으면서
            conveyer[i+1].cntLeft>0 && !conveyer[i+1].isHereRobot){
            //다음 칸으로 옮길 수 있다면
            conveyer[i].isHereRobot=false;
            putRobot(i+1);
        }

        //만약 마지막 지점 도달한 경우 바로 빼주기
        if(conveyer[n-1].isHereRobot){
            conveyer[n-1].isHereRobot=false;
        }
    }
}

void step3_putStartPoint(){
    if(conveyer[0].cntLeft>0){
        putRobot(0);
    }
}

bool step4_checkCnt(int k){
    int noLonger=0;
    for(auto c:conveyer){
        if(c.cntLeft<=0){
            noLonger++;
        }
    }
    
    return noLonger>=k;
    //내구도 0개가 k개 이상이면 true 반환
}

void print(){
    for(auto c:conveyer){
        cout<<c.cntLeft<<" "<<c.isHereRobot<<"\n";
    }
    cout<<"\n";
}

int main() {
    int n, k;
    cin>>n>>k;

    conveyer.resize(2*n);

    for(auto&c:conveyer){
        cin>>c.cntLeft;
    }

    bool isStatusTrue=false;

    while(!isStatusTrue){
        step1_rotateBelt(n);
        // cout<<"step1: \n";
        // print();
        step2_moveRobot(n);
        // cout<<"step2: \n";
        // print();
        step3_putStartPoint();
        // cout<<"step3: \n";
        // print();
        isStatusTrue=step4_checkCnt(k);
    }

    cout<<steps<<"\n";
    
    
    return 0;
}