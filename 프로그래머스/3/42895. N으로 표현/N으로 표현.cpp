#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//dpTable[i] = 숫자 N을 i번 사용해서 만들 수 있는 모든 수의 집합(set)
//N=1: N
//N=2: NN | N+N, N-N, N*N, N/N
//N=3: NNN | N=1과 N=2간의 사칙연산


int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> s[8];//정렬 불필요, 중복제거 필요
    
    int sum=0;
    for(int i=0;i<8;i++){
        sum=10*sum+N;//N, NN, NNN 꼴 숫자 생상
        s[i].insert(sum);
    }
    
    for(int i=1;i<8;i++){
        for(int j=0;j<i;j++){
            for(int a:s[j]){
                for(int b:s[i-j-1]){
                    s[i].insert(a+b);
                    s[i].insert(a-b);
                    s[i].insert(a*b);
                    if(b!=0){
                        s[i].insert(a/b);
                    }
                }
            }
            
        }
    }
    
    //number가 set에 들어가 있는지 확인
    for(int i=0;i<8;i++){
        if(s[i].find(number)!=s[i].end()){
            answer = i+1;
            break;
        }
    }
    
    
    return answer;
}

//https://ssocoit.tistory.com/43