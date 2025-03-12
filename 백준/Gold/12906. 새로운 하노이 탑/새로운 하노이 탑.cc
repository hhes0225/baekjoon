#include <bits/stdc++.h>
using namespace std;

/*
    풀이과정:
    A 원판은 A 막대에
    B 원판은 B 막대에
    C 원판은 C 막대에
    이때, 원판 크기는 고려하지 않음

    1. queue에 각 막대별 초기 상태와 이동 횟수를 push
    2. q가 존재할 동안 loop
    3. q에서 꺼낸 후 A B C 막대의 상태 조합해 방문상태 의미하는 문자열 생성
    4. 목표를 달성하면(AA, BB, CC) 이동횟수 출력 후 종료
    5. 방문하지 않은 상태라면 하노이 탑 과정 수행
        - A막대 원판 존재하면 A 마지막 원판 B로 이동한 경우, C로 이동한 경우-> 2가지 경우 q에 저장
        - B, C 막대에 대해서도 마찬가지

    시간복잡도:


    자료구조:
    
*/
struct StickState{
    string aStick="";
    string bStick="";
    string cStick="";
    int moveCnt=0;

    void toString(){
        cout<<"State:\n";
        cout<<aStick<<"\n";
        cout<<bStick<<"\n";
        cout<<cStick<<"\n";
        cout<<"------------\n";
    }
};

//set<string> visited;

bool isGoalState(const string& A, const string& B, const string& C) {
    for (char ch : A) {
        if (ch != 'A') return false;
    }
    for (char ch : B) {
        if (ch != 'B') return false;
    }
    for (char ch : C) {
        if (ch != 'C') return false;
    }
    return true;
}


void newHanoi(StickState s){
    queue<StickState> q;
    set<string> visited;
    visited.clear();
    q.push({s.aStick, s.bStick, s.cStick, s.moveCnt});
    //visited.insert(s.aStick+"/"+s.bStick+"/"+s.cStick);

    while(!q.empty()){
        StickState curState=q.front();
        q.pop();

        //curState.toString();

        //만약 탈출 목표 달성하면 반복문 종료
        if(isGoalState(curState.aStick, curState.bStick, curState.cStick)){
            cout<<curState.moveCnt<<"\n";
            break;
        }

        //visited에 없는 경우만 탐색하며 이미 했던 상태 반복하지 않음
        string stateKey = curState.aStick + "/" + curState.bStick + "/" + curState.cStick;
        if(visited.find(stateKey)==visited.end()){
            visited.insert(stateKey);//현재 상태 방문 처리
                
            if(curState.aStick.size()!=0){//빈 문자열 아니면
                char plate=curState.aStick.back();
                string moveToB=curState.bStick+plate;
                string moveToC=curState.cStick+plate;

                //원판 뺀 상태가 빈 문자열일 경우 처리
                string leftPlate = (curState.aStick.size() == 1) ? "" : curState.aStick.substr(0, curState.aStick.size()-1);

                q.push({leftPlate, moveToB, curState.cStick, curState.moveCnt+1});
                q.push({leftPlate, curState.bStick, moveToC, curState.moveCnt+1});
            }
            if(curState.bStick.size()!=0){//빈 문자열 아니면
                char plate=curState.bStick.back();
                string moveToA=curState.aStick+plate;
                string moveToC=curState.cStick+plate;
                
                //원판 뺀 상태가 빈 문자열일 경우 처리
                string leftPlate = (curState.bStick.size() == 1) ? "" : curState.bStick.substr(0, curState.bStick.size()-1);
                
                q.push({moveToA, leftPlate, curState.cStick, curState.moveCnt+1});
                q.push({curState.aStick, leftPlate, moveToC, curState.moveCnt+1});
            }
            if(curState.cStick.size()!=0){//빈 문자열 아니면
                char plate=curState.cStick.back();
                string moveToA=curState.aStick+plate;
                string moveToB=curState.bStick+plate;

                //원판 뺀 상태가 빈 문자열일 경우 처리
                string leftPlate = (curState.cStick.size() == 1) ? "" : curState.cStick.substr(0, curState.cStick.size()-1);
                
                q.push({moveToA, curState.bStick, leftPlate, curState.moveCnt+1});
                q.push({curState.aStick, moveToB, leftPlate, curState.moveCnt+1});
            }
        }
    }
}


int main() {
    int size;
    StickState s;
    
    //A 막대
    cin>>size;
    if(size>0){
        cin>>s.aStick;
    }
    else{
        s.aStick="";
    }

    //B 막대
    cin>>size;
    if(size>0){
        cin>>s.bStick;
    }
    else{
        s.bStick="";
    }

    //C 막대
    cin>>size;
    if(size>0){
        cin>>s.cStick;
    }
    else{
        s.cStick="";
    }
    
    newHanoi(s);
    
    return 0;
}