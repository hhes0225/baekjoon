#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main() {
    int from, to;
    int tryCase=0;
    bool match = false;

    cin>>from>>to;  
    
    while(to>0){
        if(to==from){
            tryCase++;
            match=true;
            break;
        }
        else if(to<from){
            break;
        }
        
        if(to%2==0){//짝수인 경우, 2로 나눈다
            tryCase++;
            to/=2;
            //cout<<to<<endl;
        }
        else if(to%10==1){//숫자가 1로 끝나는 경우, 1을 뗀다
            tryCase++;
            
            string tmp = to_string(to);
            string sub = tmp.substr(0, tmp.size()-1);
            //cout<<sub <<endl;

            to=stoi(sub);
        }
        else{//짝수가 아니고 1로 끝나지 않는 경우 - 무조건 불가능 : ex) 23 15 ... 
            break;
        }
    }

    if(match){
        cout<<tryCase<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    
    return 0;
}