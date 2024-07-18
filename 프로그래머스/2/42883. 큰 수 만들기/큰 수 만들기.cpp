#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

//greedy
//왼쪽부터 num[i]<num[i+1]이면 num[i] 제거하는 게 더 큰 수를 만들 수 있음

stack<char> maxNum;
string answer = "";
bool duplicate=false;

void greedyMaxNum(string number, int k){

    for (int i = 0; i < number.size(); i++) {
        // 현재 문자가 스택의 top 문자보다 크면 스택의 top을 제거
        while (!maxNum.empty() && k > 0 && maxNum.top() < number[i]) {
            maxNum.pop();
            k--;
        }
        maxNum.push(number[i]);
    }
    
     // 남아 있는 k개의 문자를 제거
    while (k > 0) {
        maxNum.pop();
        k--;
    }
    
    //스택을 문자열로 변환
    while(!maxNum.empty()){
        if(maxNum.top()!='a'){
            answer+=maxNum.top();
        }
        maxNum.pop();
    }
    
    //스택이라 문자열이 반대 순서이므로 역순으로 만들기
    reverse(answer.begin(), answer.end());
    //cout<<answer<<"\n";
}



string solution(string number, int k) {
    
    greedyMaxNum(number, k);
    
    return answer;
}

//12번만 틀릴 경우
//앞의 숫자가 뒤의 숫자보다 작은 경우가 없는 경우도 넣어보니 통과되네요
//입력값 〉	"4321", 1
//기댓값 〉	"432"
//https://school.programmers.co.kr/questions/33636
