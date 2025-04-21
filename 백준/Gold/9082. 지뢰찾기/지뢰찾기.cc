#include <bits/stdc++.h>
using namespace std;

string firstLine;
string secondLine;
vector<int> leftMine;
vector<int> maxMine;
set<int> minePos;
int mines=0;

/*
    필요한 함수
    1. string->vector<int> : 첫번째 줄 보기 편하게 vector<int>로 변환
*/

void printVI(vector<int>& vi){
    for(auto l:vi){
        cout<<l;
    }
    cout<<"\n";
}

void init(){
    cin>>firstLine;//첫번째 줄: 숫자만
    cin>>secondLine;//두번째 줄: *와 #만

    //firstLine(string) -> leftMine(vector<int>)
    for(auto f:firstLine){
        leftMine.push_back(f-'0');
    }

    // printVI(leftMine);
}


//인덱스 범위 내에서 pos 기준으로 pos-1, pos, pos+1 지뢰 개수 카운트-1
//해당 pos가 지뢰가 있다고 확실시 될 경우 사용
void removeMineCount(int pos){
    for(int i=pos-1;i<=pos+1;i++){
        if(i>=0&&i<leftMine.size()){
            leftMine[i]--;
        }
    }
}

// 이미 확실한 지뢰 있으면 위치 저장,(인덱스 오름차순 정렬되어 있음)
// 지뢰 개수 알려주는 첫번째 줄에 지뢰 개수 하나 쳐서 카운트-1
// 총 지뢰 개수+1
void getMinesFromSecondLine(){
    for(int i=0;i<secondLine.size();i++){
        if(secondLine[i]=='*'){
            removeMineCount(i);
            minePos.insert(i);
            mines++;
        }
    }

    // printVI(leftMine);
}

bool canExist(int pos){
    //이미 그 칸에 지뢰가 있는 상태라면(minePos에 해당 인덱스 존재)
    if(minePos.find(pos)!=minePos.end()){
        // cout<<"그 칸에 지뢰 있음.false\n";
        return false;
    }
    
    for(int i=pos-1;i<=pos+1;i++){
        if(i>=0&&i<leftMine.size()){
            //지뢰 놓을 수 없는 상태(지뢰 카운트 0)
            if(leftMine[i]<=0){
                // cout<<"지뢰 놓을 수 없는 상태(지뢰카운트 0).false\n";
                return false;
            }
        }
    }

    return true;
}

void findMines(){
    for(int i=0;i<maxMine.size();i++){
        if(canExist(i)){
            removeMineCount(i);
            if(i==0) maxMine[i]++;
            else maxMine[i]=maxMine[i-1]+1;
        }
        else{
            if(i>0) maxMine[i]=maxMine[i-1];
        }
        
        // printVI(leftMine);
        // printVI(maxMine);
        // cout<<"---\n";
    }

}

void getMaxMines(){
    mines+=maxMine.back();
    cout<<mines<<"\n";
}

void endLoop(){
    leftMine.clear();
    maxMine.clear();
    minePos.clear();
    mines=0;
}

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int col;
        cin>>col;

        maxMine.assign(col, 0);
        
        init();
        getMinesFromSecondLine();
        findMines();
        getMaxMines();

        endLoop();
    }
    return 0;
}