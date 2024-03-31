#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    /*if(a.second != b.second){
        return a.second>b.second;
    }
    else{
        return a.first<b.first;
    }*/
    return a.first<b.first;
}

int main(void){
    int tCase;
    cin>>tCase;
    unordered_map<string, int> files;
    vector<pair<string, int>> sortedFiles;

    for(int i=0;i<tCase;i++){
        string input;
        string fileExtension;
        cin>>input;
        
        int it = input.find('.');

        
        fileExtension=input.substr(it+1, input.size()-1);
        //cout<<fileExtension<<"\n";
        
        //이미 있으면
        if(files.find(fileExtension) != files.end()){
            files[fileExtension]++;
        }
        else{
            files.insert({fileExtension, 1});
        }
    }

    //unordered_map은 sort 함수 못쓰므로 vector에 넣는다
    for(auto it:files){
        sortedFiles.push_back({it.first, it.second});
    }

    sort(sortedFiles.begin(), sortedFiles.end(), compare);
    
    for(auto it:sortedFiles){
        cout<<it.first<<" "<<it.second<<"\n";
    }

    return 0;
}