#include <iostream>
#include <vector>
using namespace std;
int main() {
    int size, row, col;
    vector<vector<int>> seat;
    bool isUnhappy=false;
    
    cin>>size>>row>>col;

    seat.resize(size);

    for(int i=0;i<seat.size();i++){
        seat[i].resize(size);
    }

    for(int i=0;i<seat.size();i++){
        for(int j=0;j<seat.size();j++){
            cin>>seat[i][j];
        }
    }

    /*
    for(int i=0;i<seat.size();i++){
        for(int j=0;j<seat.size();j++){
            cout<<seat[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    //행 검사
    for(int i=0;i<seat.size();i++){
        if(seat[row-1][i]>seat[row-1][col-1]){
            isUnhappy=true;
        }
        //cout<<seat[row-1][i]<<" ";
    }
    //cout<<endl;

    //열 검사
    for(int i=0;i<seat.size();i++){
        if(seat[i][col-1]>seat[row-1][col-1]){
            isUnhappy=true;
        }
        //cout<<seat[i][col-1]<<" ";
    }
    //cout<<endl;

    if(isUnhappy){
        cout<<"ANGRY\n";
    }
    else{
        cout<<"HAPPY\n";
    }
    
    return 0;
}