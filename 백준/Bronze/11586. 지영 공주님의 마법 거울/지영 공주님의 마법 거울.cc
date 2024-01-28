#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int lines;
    vector<string> mirror;
    int choice;
    
    cin>>lines;
    
    mirror.resize(lines);
    
    for(int i=0;i<lines;i++){
        cin>>mirror[i];
    }
    
    cin>>choice;
    
    if(choice==1){
        for(int i=0;i<lines;i++){
            cout<<mirror[i]<<"\n";
        }
    }
    else if(choice==2){
        for(int i=0;i<lines;i++){
            reverse(mirror[i].begin(), mirror[i].end());
            cout<<mirror[i]<<"\n";
        }
    }
    else{
        reverse(mirror.begin(), mirror.end());
        for(int i=0;i<lines;i++){
            cout<<mirror[i]<<"\n";
        }
    }
    
    return 0;
}