#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

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