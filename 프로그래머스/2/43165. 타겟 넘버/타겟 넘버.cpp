#include <string>
#include <vector>
#include <iostream>

using namespace std;

int result = 0;

void dfs(vector<int> numbers, int target, int sum, int idx){
    //재귀 탈출조건
    if(idx == numbers.size()-1){//마지막 인덱스 탐색
        if(sum + numbers[idx]==target || sum - numbers[idx]==target){
            //마지막 idx 덧셈값 or 뺄셈값이 target 목표치와 같다면 경우의수+1;
            result++;
        }
        return;
    }
    
    int addNext = sum+numbers[idx]; //+경우
    dfs(numbers, target, addNext, idx+1);
    
    int subNext = sum-numbers[idx]; // -경우
    dfs(numbers, target, subNext, idx+1);
    
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, 0, 0);
    
    answer=result;
    
    return answer;
}

