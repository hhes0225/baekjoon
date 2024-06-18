#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string input;
    vector<int>before;
    vector<int>after;
    string tmp;

    bool result=true;

    getline(cin, input);

    for(int i=0;i<input.size();i++){
        if(input[i]!=' '){
            tmp+=input[i];

            if(i==input.size()-1){
                //cout<<tmp<<endl;
                before.push_back(stoi(tmp));
                after.push_back(stoi(tmp));
            }
        }
        else{
            //cout<<tmp<<endl;
            before.push_back(stoi(tmp));
            after.push_back(stoi(tmp));
            tmp="";
        }
    }


    sort(after.begin(),after.end());

    for(int i=0;i<before.size();i++){
        if(before[i]!=after[i]){
            result=false;
            break;
        }
    }

    if(result){
        cout<<"Good\n";
    }
    else{
        cout<<"Bad\n";
    }
    
    return 0;
}