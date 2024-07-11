#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//최소 단계->DFS

int answer = 100;

//isChangeable로 아예 1인지 아닌지 if 체크도 여기서 하는게 좋을듯
int checkDiff(string begin, string target){
    int diff = 0;
    
    for(int i=0;i<begin.size();i++){
        if(begin[i]!=target[i]){
            diff++;
        }
    }
    
    return diff;
}

//words, visited & 넣기
void dfs(string begin, string target, vector<string> words, vector<bool> visited, int step){ 
    //현재 step이 answer보다 큰 경우 더 탐색할 필요가 없음(answer보다 작아지는 경우를 탐색하는게 목표이므로)
    //미리 탐색을 중단하는 것이 좋음(최적화)

    //문자열이 완벽하게 같은 경우, 결과의 최소값 체크.
    if(begin==target){
        answer=min(answer, step);
    }
    
    //배열 순회, 문자열의 차이가 1개인 경우만 자식 노드로 두기 위함
    for(int i=0;i<words.size();i++){
        //문자열의 차이가 1개가 아닌 경우, 체크 X
        if(checkDiff(begin, words[i])!=1){
            continue;
        }
        else if(visited[i]==true){
            //전역X 매개변수로 둔 이유 : 각 step별로 방문한 노드는 true처리/다른 step에는 이것의 영향을 받지 않고 독립적으로 시행하기 위함
            //ex) hot->dot->dog->log->cog : 전역으로 한다면 다음 예시 처리되지 않음
            //ex) hot->dot->dog->cog
            continue;
        }
        else{
            //cout<<words[i]<<endl;
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