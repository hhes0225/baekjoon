#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int wCount;
    vector<string> words;
    unordered_map<string, int> wordMap;

    cin>>wCount;

    for(int i=0;i<wCount;i++){
        string word;
        cin>>word;
        words.push_back(word);
        wordMap[word]++;
    }

    
    
    char start='?', end='?';
    for(int i=0;i<wCount;i++){
        if(words[i]=="?"){
            if(i-1>=0){
                start=words[i-1][words[i-1].size()-1];
            }
            if(i+1<wCount){
                end=words[i+1][0];
            }
            
        }    
    }
    //cout<<start<<" "<<end<<"\n";

    cin>>wCount;

    for(int i=0;i<wCount;i++){
        string input;
        cin>>input;


        if(wCount==1){
            cout<<input<<"\n";
            break;
        }
        
        if(input[0]==start && input[input.size()-1]==end &&
            wordMap.find(input)==wordMap.end()){
            cout<<input<<"\n";
        }
        else if(start=='?' && input[input.size()-1]==end &&
            wordMap.find(input)==wordMap.end()){
            cout<<input<<"\n";
        }
        else if(input[0]==start && end=='?' &&
            wordMap.find(input)==wordMap.end()){
            cout<<input<<"\n";
        }
    
    }
    
    return 0;
}