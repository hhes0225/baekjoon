#include <string>
#include <vector>

using namespace std;

//dp[i][j]: (i,j)까지의 최대합

//양 사이드의 숫자는 본인+위의 값 고정
//(왼쪽 사이드)
//dp[i][j] = triangle[i][j](본인) + dp[i-1][j]
//(오른쪽 사이드)
//dp[i][j] = triangle[i][j](본인) + dp[i-1][j-1]

//중간의 숫자는 본인 + 양 대각선 위쪽 값 중 큰 값
//dp[i][j] = triangle[i][j](본인) + max(dp[i-1][j], dp[i-1][j-1])


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int length = triangle.size()-1;
    
    int dp[501][501];
    dp[0][0]=triangle[0][0];
    
    for(int i=1;i<=length;i++){
        for(int j=0;j<=i;j++){
            //본인 더하기
            dp[i][j]+=triangle[i][j];
            
            //+
            if(j==0){//왼쪽 사이드
                dp[i][j]=dp[i-1][j];
            }
            else if(j==i){//오른쪽 사이드
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-1]);
            }
            
            dp[i][j]+=triangle[i][j];
        }
    }
    
    //dp 배열 제일 마지막 줄 중 가장 큰 값이 최대합
    
    answer=dp[length][0];//최하단
    for(int i=1;i<length;i++){
        if(dp[length][i]>answer){
            answer=dp[length][i];
        }
    }
    
    return answer;
}

//https://aerimforest.tistory.com/172