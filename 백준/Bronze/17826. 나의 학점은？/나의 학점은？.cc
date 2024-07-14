#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<int, int> scores;
    int myScore;

    for(int i=0;i<50;i++){
        int score;
        cin>>score;
        
        scores[score]=i+1;
    }

    cin>>myScore;

    //cout<<scores[myScore]<<endl;

    if(scores[myScore]<=5){
        cout<<"A+\n";
    }
    else if(scores[myScore]<=15){
        cout<<"A0\n";
    }
    else if(scores[myScore]<=30){
        cout<<"B+\n";
    }
    else if(scores[myScore]<=35){
        cout<<"B0\n";
    }
    else if(scores[myScore]<=45){
        cout<<"C+\n";
    }
    else if(scores[myScore]<=48){
        cout<<"C0\n";
    }
    else{
        cout<<"F\n";
    }
    
    
    return 0;
}