#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        vector<int> scores;
        scores.resize(5);

        int totalsum=0;
        for(int j=0;j<5;j++){
            cin>>scores[j];
            //cout<<scores[i]<<endl;
        }
        
        sort(scores.begin(), scores.end());
        totalsum+=scores[1]+scores[2]+scores[3];
        
        if(abs(scores[3]-scores[1])>=4){
            cout<<"KIN\n";
        }
        else{
            cout<<totalsum<<"\n";
        }

    }

    return 0;
}