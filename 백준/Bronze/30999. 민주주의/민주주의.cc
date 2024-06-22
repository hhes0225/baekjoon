#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int problem;
    int ppl;
    int pass=0;
    
    cin>>problem>>ppl;

    for(int i=0;i<problem;i++){
        string input;
        cin>>input;
        int o=0,x=0;
        
        for(int j=0;j<input.size();j++){
            if(input[j]=='O'){
                o++;
            }
            else{
                x++;
            }
        }

        if(o>x){
            pass++;
        }
    }

    cout<<pass<<endl;
    
    return 0;
}