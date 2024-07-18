#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

/*
    deque 사용
    
    if 가장 무거운 사람 + 가장 가벼운 사람 > 무게한도(초과) :
        가장 무거운 사람은 어떤 다른 사람과 무게를 더해도 한도 초과하므로 혼자 보트 타기
    else :
        가장 무거운 사람 + 가장 가벼운 사람 보트 태우기
        나머지 사람들로 계속 보트 태우기
        
    이 과정에서
    1. 내림차순으로 정렬
    2. pop_front(), pop_back() 사용

*/

deque<int> pplDeq;
int answer = 0;

void setDeq(vector<int> people){
    for(int i=0;i<people.size();i++){
        pplDeq.push_back(people[i]);
    }
}

void greedy(int limit){
    //int front=0, back=pplDeq.size()-1;
    
    while(!pplDeq.empty()){
        //cout<<pplDeq.front()<<" "<<pplDeq.back()<<"\n";
        if(pplDeq.front()+pplDeq.back()>limit){
            if(pplDeq.size()>0){
                pplDeq.pop_front();
            }
            answer++;
        }
        else{
            if(pplDeq.size()>0){
                pplDeq.pop_front();
            }
            if(pplDeq.size()>0){
                pplDeq.pop_back();
            }
            
            answer++;
        }
    }
}

int solution(vector<int> people, int limit) {
    vector<int> sorted=people;
    
    sort(sorted.begin(), sorted.end());
    reverse(sorted.begin(), sorted.end());
    
    setDeq(sorted);
    
    /*for(int i=0;i<pplDeq.size();i++){
        cout<<pplDeq[i]<<" ";
    }
    cout<<endl;*/
    
    greedy(limit);
    
    
    return answer;
}