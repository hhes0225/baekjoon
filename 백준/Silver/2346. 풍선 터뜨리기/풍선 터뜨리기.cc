#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main() {
    int num;
    cin>>num;

    deque<pair<int, int>> balloons;
    
    for(int i=0;i<num;i++){
        int paper;
        cin>>paper;
        balloons.push_back({paper, i+1});
    }

    /*for(auto it:balloons){
        cout<<it.first<<" "<<it.second<<"\n";
    }*/

    //첫번째 요소는 바로 pop
    cout<<balloons.front().second<<" ";
    int count = balloons.front().first;
    balloons.pop_front();

    
    while(!balloons.empty()){
        //양수일 경우
        if(count>=0){
            for(int i=0;i<count-1;i++){
                pair<int, int> tmp;
                tmp=balloons.front();
                balloons.pop_front();
                balloons.push_back(tmp);
             } 
            count=balloons.front().first;
            cout<<balloons.front().second<<" ";
            balloons.pop_front();
            
        }
        //음수일 경우
        else{
            for(int i=0;i<abs(count)-1;i++){
                pair<int, int> tmp;
                tmp=balloons.back();
                balloons.pop_back();
                balloons.push_front(tmp);
             } 
            count=balloons.back().first;
            cout<<balloons.back().second<<" ";
            balloons.pop_back();
        }
           
    }
    
    
    return 0;
}