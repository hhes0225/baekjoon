#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    vector<int> alphabets;
    alphabets.assign(26, 0);

    string input;
    while(getline(cin, input)){
        for(int i=0;i<input.size();i++){
            alphabets[input[i]-'a']++;
        }
    }

    int maxval=*max_element(alphabets.begin(), alphabets.end());

    for(int i=0;i<alphabets.size();i++){
        if(alphabets[i]==maxval){
            cout<<(char)(i+'a');
        }
    }
    
    return 0;
}