#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> PII;

int n, k;
vector<PII> obj;
vector<vector<int>> dpTable;

void knapsack(){
    for(int i=1;i<dpTable.size();i++){
        for(int j=1;j<dpTable[i].size();j++){
            int curWeight=obj[i-1].first;
            int curVal=obj[i-1].second;
            
            //짐 넣을 수 있는 경우
            if(curWeight<=j){
                dpTable[i][j]=max(dpTable[i-1][j], dpTable[i-1][j-curWeight]+curVal);
            }
            else{// 짐 넣을 수 없는 경우
                //윗칸 값 계승==가방에 넣지 않는다
                dpTable[i][j]=dpTable[i-1][j];
                
            }
        }
    }

    /*
    for(int i=1;i<dpTable.size();i++){
        for(int j=1;j<dpTable[i].size();j++){
            cout<<dpTable[i][j]<<" ";
        }
        cout<<endl;
    }
    */
}


int main() {
    cin>>n>>k;

    //k+1로 설정해야 무게 k까지 확인할 수 있음
    dpTable.assign(n+1, vector<int>(k+1, 0));

    for(int i=0;i<n;i++){
        int w, v;
        cin>>w>>v;

        obj.push_back({w, v});        
    }

    knapsack();

    cout<<dpTable[n][k]<<"\n";
    
    return 0;
}