#include <bits/stdc++.h>
using namespace std;



int main() {
    string input;
    cin>>input;

    vector<string> splitReverseStr;

    for(int i=1;i<input.size()-1;i++){
        string sub1, sub2, sub3;

        //0~i
        sub1=input.substr(0, i);
        // cout<<sub1<<"=1/";
        reverse(sub1.begin(), sub1.end());
        
        for(int j=i+1;j<input.size();j++){
            //i+1~j
            sub2=input.substr(i, j-i);
            // cout<<sub2<<"=2/";
            reverse(sub2.begin(), sub2.end());

            //j~끝
            sub3=input.substr(j, input.size()-j);
            // cout<<sub3<<"=3\n";
            reverse(sub3.begin(), sub3.end());

            splitReverseStr.push_back(sub1+sub2+sub3);
        }
    }

    sort(splitReverseStr.begin(), splitReverseStr.end());

    cout<<splitReverseStr.front()<<"\n";
    
    return 0;
}