#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b){
    if(a.second!=b.second){
        return a.second>b.second;
    }
    else if(a.first.size()!=b.first.size()){
        return a.first.size()>b.first.size();
    }
    else{
        return a.first<b.first;
    }
        
}

int main(void){
    int tCase, wordLimit;
    cin>>tCase>>wordLimit;
    
    unordered_map<string, int> dictionary;

    for(int i=0;i<tCase;i++){
        string input;

        cin>>input;
        
        if(input.size() < wordLimit){
            continue;
        }

        //맵에 존재하면 
        if(dictionary.find(input)!=dictionary.end()){
            dictionary[input]++;
        }
        else{
            dictionary.insert({input, 0});
        }
    }

    //맵으로는 sort가 불가능하므로 현 상태를 vector에 복사
    vector<pair<string, int>> vCopy(dictionary.begin(), dictionary.end());

    //이 vector를 대상으로 정렬한다
    sort(vCopy.begin(), vCopy.end(), compare);

    for(auto & it:vCopy){
        cout<<it.first<<"\n";
        //cout<<it.first<<" "<<it.second<<"\n";
    }

    return 0;
}