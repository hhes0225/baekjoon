#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 진출 지점을 기준으로 

bool cmp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);    
    
    /*
    for(int i=0;i<routes.size();i++){
        for(int j=0;j<routes[i].size();j++){
            cout<<routes[i][j]<<" ";
        }   
        cout<<endl;
    }
    */
    
    int cameraMaxPoint = routes[0][1];
    answer++;
    
    for(int i=0;i<routes.size();i++){
        if(routes[i][0]>cameraMaxPoint){
            cameraMaxPoint=routes[i][1];
            answer++;
        }
    }
    
    return answer;
}