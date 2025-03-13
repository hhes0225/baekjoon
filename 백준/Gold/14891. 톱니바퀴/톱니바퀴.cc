#include <bits/stdc++.h>
using namespace std;
const int WHEELCNT=4;

const int dir3Idx=2;
const int dir9Idx=6;

/*
    풀이과정:
    시뮬레이션

    맞닿는 부분
    1번의 3시 방향(idx=2)-2번의 9시 방향(idx=6)
    2번의 3시 방향(idx=2)-3번의 9시 방향(idx=6)
    3번의 3시 방향(idx=2)-4번의 9시 방향(idx=6)

    최종 점수에서 체크하는 부분
    모든 톱니바퀴의 12시 방향(idx=0)
*/

vector<deque<int>> wheels;
vector<pair<int, int>> command;
int finalScore=0;

void clockWise(int targetWheel){
    wheels[targetWheel].push_front(wheels[targetWheel].back());    
    wheels[targetWheel].pop_back();
}

void counterClockWise(int targetWheel){
    wheels[targetWheel].push_back(wheels[targetWheel].front());    
    wheels[targetWheel].pop_front();
}

void WheelSimul(){
    for(auto c:command){
        auto[targetWheel, dir]=c;
        targetWheel--;//idx=0부터 시작

        //현재 극 상태 저장
        bool isSameDir01=wheels[0][dir3Idx]==wheels[1][dir9Idx];
        bool isSameDir12=wheels[1][dir3Idx]==wheels[2][dir9Idx];
        bool isSameDir23=wheels[2][dir3Idx]==wheels[3][dir9Idx];
        
        if(targetWheel==0){
            if(dir==1){
                clockWise(0);

                if(!isSameDir01) counterClockWise(1);
                else continue;

                if(!isSameDir12) clockWise(2);
                else continue;

                if(!isSameDir23) counterClockWise(3);
            }
            else{//dir==-1
                counterClockWise(0);

                if(!isSameDir01) clockWise(1);
                else continue;

                if(!isSameDir12) counterClockWise(2);
                else continue;

                if(!isSameDir23) clockWise(3);
            }   
        }
        else if(targetWheel==1){
            if(dir==1){
                clockWise(1);

                if(!isSameDir01) counterClockWise(0);

                if(!isSameDir12) counterClockWise(2);
                else continue;

                if(!isSameDir23) clockWise(3);
            }
            else{//dir==-1
                counterClockWise(1);

                if(!isSameDir01) clockWise(0);

                if(!isSameDir12) clockWise(2);
                else continue;

                if(!isSameDir23) counterClockWise(3);
            }
        }
        else if(targetWheel==2){
            if(dir==1){
                clockWise(2);

                if(!isSameDir23) counterClockWise(3);

                if(!isSameDir12) counterClockWise(1);
                else continue;

                if(!isSameDir01) clockWise(0);
            }
            else{//dir==-1
                counterClockWise(2);

                if(!isSameDir23) clockWise(3);

                if(!isSameDir12) clockWise(1);
                else continue;

                if(!isSameDir01) counterClockWise(0);
            }
        }
        else{//targetWheel==3
            if(dir==1){
                clockWise(3);

                if(!isSameDir23) counterClockWise(2);
                else continue;

                if(!isSameDir12) clockWise(1);
                else continue;

                if(!isSameDir01) counterClockWise(0);
            }
            else{//dir==-1
                counterClockWise(3);

                if(!isSameDir23) clockWise(2);
                else continue;

                if(!isSameDir12) counterClockWise(1);
                else continue;

                if(!isSameDir01) clockWise(0);
            }
        }

        /*
        for(auto i:wheels){
            for(auto j:i){
                cout<<j;
            }
            cout<<"\n";
        }*/
    }

    //최종 점수 계산(12시 방향만 보기)
    int pow=1;
    for(int i=1;i<=WHEELCNT;i++){
        if(wheels[i-1][0]==0){//N극
            pow*=2;
            continue;
        }
        else{//S극
            finalScore+=pow;
            pow*=2;
        }
    }

    cout<<finalScore<<"\n";
}

int main() {
    vector<string> inputs;
    int k;

    wheels.resize(WHEELCNT);
    inputs.resize(WHEELCNT);

    for(auto &i:inputs){
        cin>>i;
    }

    for(int i=0;i<WHEELCNT;i++){
        for(auto j:inputs[i]){
            if(j=='1') wheels[i].push_back(1);
            else wheels[i].push_back(0);
        }
    }

    cin>>k;
    command.resize(k);

    for(auto &c:command)
        cin>>c.first>>c.second;

    WheelSimul();
    
    return 0;
}