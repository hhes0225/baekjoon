#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//최소 단계->DFS

int answer = 100;


int checkDiff(string begin, string target){
    int diff = 0;
    
    for(int i=0;i<begin.size();i++){
        if(begin[i]!=target[i]){
            diff++;
        }
    }
    
    return diff;
}

void dfs(string begin, string target, vector<string> words, vector<bool> visited, int step){    
    //문자열이 완벽하게 같은 경우, 결과의 최소값 체크.
    if(begin==target){
        answer=min(answer, step);
    }
    
    //문자열의 차이가 1개인 경우, 자식 노드 순회
    for(int i=0;i<words.size();i++){
        //문자열의 차이가 1개가 아닌 경우, 체크 X
        if(checkDiff(begin, words[i])!=1){
            continue;
        }
        else if(visited[i]==true){
            continue;
        }
        else{
            cout<<words[i]<<endl;
            visited[i]=true;
            dfs(words[i], target, words, visited, step+1);
        }
        
    }
    
    
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited;
    visited.resize(words.size());
    
    //target이 words 안에 있는지 확인
    if(find(words.begin(), words.end(), target) ==words.end()){
        return 0;
    }
    
    dfs(begin, target, words, visited, 0);
    cout<<answer<<"\n";
    
    return answer;
}