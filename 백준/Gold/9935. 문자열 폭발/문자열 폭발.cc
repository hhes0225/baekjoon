#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> result;
string comp;

int main() {
    string input;
    string target;

    cin>>input>>target;


    for(int i=0;i<input.size();i++){
        result.push_back(input[i]);


        if(result.size()>=target.length()){
            bool match=true;

            for(int i=0;i<target.length();i++){
                if(result[result.size()-target.length()+i]!=target[i]){
                    match=false;
                    break;
                }
            }

            if(match){
                for(int i=0;i<target.length();i++){
                    result.pop_back();
                }
            }
        }
    }

    if(result.empty()){
        cout<<"FRULA\n";
    }
    else{
        for(char it:result){
            cout<<it;
        }
        cout<<"\n";
    }
    
    return 0;
}
