#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 vector<vector<int>> scores;

bool compare(vector<int> a, vector<int> b){
    if(a[1]!=b[1]){
        return a[1]>b[1];
    }
    else if(a[2]!=b[2]){
        return a[2]>b[2];
    }
    else{
        return a[3]>b[3];
    }
}

int main() {
    int len, country;
    cin>>len>>country;
    int rank=1;

    scores.assign(len, vector<int>(4));

    for(int i=0;i<len;i++){
        for(int j=0;j<4;j++){
            cin>>scores[i][j];
        }
    }

    sort(scores.begin(), scores.end(), compare);

    if(country==scores[0][0]){
        cout<<rank<<"\n";
        return 0;
    }
    
    for(int i=1;i<len;i++){
        if(scores[i-1][1]!=scores[i][1]||scores[i-1][2]!=scores[i][2]||scores[i-1][3]!=scores[i][3]){
            rank++;
        }

        if(country==scores[i][0]){
            cout<<rank;
        }

    }
    cout<<"\n";
    
    return 0;
}