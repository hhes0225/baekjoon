#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    vector<int> freq;
    cin>>input;

    freq=vector<int>((int)'z'-(int)'a'+1, 0);

    for(int i=0;i<input.size();i++){

        freq[(int)input[i]-(int)'a']++;
    }

    for(int i=0;i<freq.size();i++){
        cout<<freq[i]<<" ";
    }

    return 0;
}