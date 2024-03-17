#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main(void){
    int size;
    int input;
    queue<int> router;

    cin>>size;

    

    while(1){
        cin>>input;
        
        if(input==-1){
            break;
        }
    
        if(input==0){
            router.pop();
        }
        else{
            if(router.size()>=size){
                //cout<<"overflow\n";
                continue;
            }
            else{
                //cout<<input<<" push success\n";
                router.push(input);   
            }
        }
    }

    if(router.size()==0){
        cout<<"empty\n";
    }
    else{
        int tmp=router.size();
        for(int i=0;i<tmp;i++){
            cout<<router.front()<<" ";
            router.pop();
        }
        cout<<"\n";
    }

    return 0;
}