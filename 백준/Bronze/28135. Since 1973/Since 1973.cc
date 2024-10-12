#include <iostream>
#include <string>
using namespace std;

int main() {
    int limit;
    cin>>limit;
    int count=0;

    for(int i=1;i<limit;i++){
        count++;

        if(to_string(i).find("50")!=string::npos){
            count++;
        }
    }

    cout<<count+1;
    

    
    
    return 0;
}