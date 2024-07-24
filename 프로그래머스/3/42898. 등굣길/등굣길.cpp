#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int grid[100][100];
    
    //전체 경로 -1로 초기화(이후 갈 수 있는 칸 의미하게 됨)
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            grid[i][j]=-1;
        }   
    }
    
    //시작 지점의 값:1(경로 이동 불가)
    grid[0][0]=1;
    
    //물에 잠긴 지역:0(경로 이동 불가)
    for(int i=0;i<puddles.size();i++){
        grid[puddles[i][0]-1][puddles[i][1]-1]=0;
    }
    
    /*
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    
    //idx가 음수(-1)이면 
    //물에 잠긴 지역(0)이면 변경 X
    //오버플로우 방지 - 모듈러 연산
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==-1){//갈 수 있는 길이라면
                if(i==0){//더 이상 왼쪽으로 갈 수 없음
                    grid[i][j]=grid[i][j-1]%1000000007;
                }
                else if(j==0){//더 이상 위쪽으로 갈 수 없음
                    grid[i][j]=grid[i-1][j]%1000000007;
                }
                else{
                    grid[i][j]=(grid[i][j-1]+grid[i-1][j])%1000000007;
                }
                
            }
        }
    }
    
    /*
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    
    answer=grid[m-1][n-1];//목적지
    
    return answer;
}

//https://ssocoit.tistory.com/47