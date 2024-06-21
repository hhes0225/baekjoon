#include <iostream>
using namespace std;

int main() {
    int num;
    cin>>num;
    
    int maxStric=0;
    int tmp=0;
    

    for(int i=0;i<num;i++){
        int s;
        cin>>s;
        
        if(s==0){
            //cout<<maxStric<<" "<<tmp<<endl;
            maxStric=max(maxStric, tmp);
            tmp=0;
        }
        else if(i==num-1){
            tmp++;
            maxStric=max(maxStric, tmp);
        }
        else{
            tmp++;
        }
    }

    cout<<maxStric<<"\n";
    
    return 0;
}