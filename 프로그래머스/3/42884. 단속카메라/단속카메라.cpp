#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//그리디 단골유형
//UCPC 기준으로 진출 기준 정렬 & 탐색

// 진출 지점을 기준으로 카메라 설치
// (init. 진출지점 기준 오름차순 정렬 후 첫 번째 루트의 진출지점)
// 순회 루트의 진입 지점이 기존 설치 진출지점보다 크다면 루트가 겹치지 않으므로 카메라 설치
// (순회 당시 진입과 세트인 진출지점에, 카메라 설치 포인트 갱신)

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

//참고
//https://school.programmers.co.kr/questions/72005