#include <bits/stdc++.h>
using namespace std;

deque<string> splits;


int main() {
    string input;
    getline(cin, input);

    string tmp="";
    
    for(int i=0;i<input.size();i++){
         if(input[i]=='-'||input[i]=='+'){
             if(tmp!="")splits.emplace_back(tmp);
             tmp="";
             splits.emplace_back("");
             splits[splits.size()-1]=input[i];
         }
        else{
            tmp+=input[i];

            if(i==input.size()-1){
                splits.emplace_back(tmp);
            }
        }
    }

    /*
    for(auto it:splits){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    int result=0;
    int minus=0;
    
    while(!splits.empty()){
        if(splits.front()=="-"){
            splits.pop_front();
            while(!splits.empty()&&splits.front()!="-"){
                if(splits.front()=="+"){
                    splits.pop_front();
                    continue;
                }
                else{
                    minus+=stoi(splits.front());
                    splits.pop_front();
                }
            }
        }
        else{
            if(splits.front()=="+"){
                splits.pop_front();
                continue;
            }
            else{
                result+=stoi(splits.front());
                splits.pop_front();
            }
        }
    }

    cout<<result-minus<<"\n";
    
    
    return 0;
}