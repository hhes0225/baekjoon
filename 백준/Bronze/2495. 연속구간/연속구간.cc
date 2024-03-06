#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    

    for(int i=0;i<3;i++){
        cin>>input;
        int continuous=1;
        int maxContinuous=0;
        
        for(int j=1;j<input.size();j++){
            if(input[j]==input[j-1]){
                continuous++;
            }
            else{
                maxContinuous=max(maxContinuous, continuous);
                continuous=1;
            }
        }
        
        maxContinuous=max(maxContinuous, continuous);

        cout<<maxContinuous<<"\n";
    
    }

    
    return 0;
}