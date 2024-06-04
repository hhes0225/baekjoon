#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    string input;

    while(1){
        cin>>input;
        int sum=0;
        
        if(input=="0"){
            break;
        }

        while(1){
            for(int i=0;i<input.size();i++){
                sum+=(int)input[i]-(int)'0';
            }
            
            input=to_string(sum);
            //cout<<input<<"\n";

            if(input.size()==1){
                break;
            }
            else{
                sum=0;
            }
        }

        cout<<sum<<"\n";
    }
    
    
    return 0;
}