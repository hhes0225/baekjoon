#include <iostream>
#include <queue>
using namespace std;
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tCase;
    priority_queue<int> pq;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int input;
        cin>>input;

        if(input!=0){
            pq.push(input);
        }
        else{
            if(pq.empty()){
                cout<<"0\n";
            }
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
    }
    
    return 0;
}