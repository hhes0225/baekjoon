#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

/*
    https://please-amend.tistory.com/175
    https://velog.io/@ich0906/%EB%B0%B1%EC%A4%80-1285-%EB%8F%99%EC%A0%84-%EB%92%A4%EC%A7%91%EA%B8%B0
    핵심 아이디어
    행 or 열 중 하나만 완전탐색(2^20)을 하고, 
    각 탐색 케이스마다 최적이 되도록 열 or 행을 뒤집어 구하기
*/

int tableSize;
vector<vector<char>> coinTable;

void flipRow(int row) {
    for (int i = 0; i < tableSize; i++) {
        if (coinTable[row][i] == 'H') {
            coinTable[row][i] = 'T';
        } else {
            coinTable[row][i] = 'H';
        }
    }
}


//각 행을 뒤집을지 여부 row로 주어졌을 때, 뒷면 최소 개수
int countTWithFlipColumn(int row){
    int totalCnt=0;

    //각 열을 뒤집을지 말지 여부를 tail 개수 최소가 되도록 결정
    for(int i=0;i<tableSize;i++){
        int cnt=0;

        for(int j=0;j<tableSize;j++){
            if(coinTable[j][i]=='T'){
                cnt++;
            }
        }
        totalCnt+=min(cnt, tableSize-cnt);
    }
    return totalCnt;
}

void printTable(vector<vector<char>>& input){
    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i].size();j++){
            cout<<input[i][j];
        }
        cout<<"\n";
    }

    cout<<"\n";
    
}

int main() {
    int minTailCnt=INT_MAX;

    cin>>tableSize;
    
    coinTable.assign(tableSize, vector<char>(tableSize, 0));

    for(int i=0;i<tableSize;i++){
        for(int j=0;j<tableSize;j++){
            cin>>coinTable[i][j];
        }
    }

    //printTable(coinTable);


    //모든 행에 대해 뒤집기 여부를 결정하는 완전탐색
    //(1<<tableSize) : tableSize^2(3일 경우, 8)
    //따라서 0~7까지의 모든 경우의 수 탐색 가능
    for(int i=0;i<(1<<tableSize);i++){
        vector<vector<char>> tmpTable = coinTable;

        for(int j=0;j<tableSize;j++){
            //특정 행을 뒤집을지 여부 결정
            
            //i & (1 << j)가 1인 경우, 즉 i의 j번째 비트가 1인 경우에 
            //flipRow(j)를 호출하여 j번째 행을 뒤집기

            //i==5(0101) 인 경우
            //j==1,3일 때 참이 되어 2개의 행을 뒤집는다
            
            if(i&(1<<j)){
                flipRow(j);
                //printTable(coinTable);
            }
        }
        
        minTailCnt=min(minTailCnt, countTWithFlipColumn(i));

        coinTable=tmpTable;
    }

    cout<<minTailCnt<<"\n";

    return 0;
}