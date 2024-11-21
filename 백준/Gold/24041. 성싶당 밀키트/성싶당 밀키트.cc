#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
	DP?-> 날짜 1e9 ->너무 오래 걸림

  **날짜 범위를 좁히며 탐색** 해야 한다.

  1) 날짜 x가 커질수록 세균 수 총합은 커진다
  - 날짜 x가 커지면 max(1, x-L_i) 값이 커질 것임->세균 수 증가
  - x가 커질수록 조건(세균 합<=G 만족하지 않을 가능성 커짐

  2) x가 작아지면 세균 총합 작아짐

  -> 날짜 x에 대해 G 이하인지 확안하며 T->F로 변하는 시점 찾아야 함
  ->이분탐색(어떤 값이 가능한지 확인할 수 있는 함수 있을 때 사용)
  (단순 최대, 최소값 X 주어진 범위에서 특정 값)

*/

vector<vector<long long>> ingre;

bool isSafe(long long x, long long G, long long K){
    long long totalGerm=0;

    priority_queue<long long> removeable;
    //제외할 재료 최대한 효율적으로 선택
    //K개의 재료를 빼서 세균 수를 가장 크게 줄여야
    //세균 총합이 G 이하 될 가능성 높아짐

    //ingre의 최대 길이==N의 최대 길이==20만
    //x는 mid day의 값
    for(auto& i:ingre){
        long long S=i[0];
        long long L=i[1];
        long long O=i[2];

        //세균 수 계산
        long long germ=S*max(1LL, x-L);
        totalGerm+=germ;

        //중요하지 않은 재료 처리
        if(O==1){
            //중요하지 않은 재료의 x 시점에서의 세균 수
            removeable.push(germ);
        }

    }

    while(!removeable.empty()&&K>0){
        totalGerm-=removeable.top();
        removeable.pop();
        K--;
    }
    
    return totalGerm<=G;
}

long long binarySearch(long long N, long long G, long long K){
    long long left =1, right =2e9, answer =0;
	//left는 날짜의 최소값, right는 날짜의 최대값
	//right는 INTMAX로 해도 되지만 시간초과가 날 수 있다.
	//20억이 되는 이유: G가 10억이 되게 하기 위한 최대값은 20억이 되기 때문

    while(left<=right){
        long long mid = (left+right)/2;

        if(isSafe(mid, G, K)){
		//먹을 수 있다면
            answer=mid;
            left=mid+1;//최대값을 찾기 위해 mid 다음날부터 다시 이분탐색
        }
        else{//먹을 수 없다면
            right=mid-1;//그 이후는 아예 못먹기 때문에 이전날까지 다시 이분탐색
        }
    }

    return answer;
}

int main() {
    long long N,G,K;

    cin>>N>>G>>K;

    ingre.resize(N, vector<long long>(3));

    for(int i=0;i<N;i++){
        cin>>ingre[i][0]>>ingre[i][1]>>ingre[i][2];
    }

    cout<< binarySearch(N,G,K)<<"\n";

    
    
    return 0;
}
