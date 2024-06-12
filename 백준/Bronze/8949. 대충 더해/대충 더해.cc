#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    string a, b;
    vector<string> result;
    
    cin>>a>>b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int minLen = min(a.size(), b.size());

    for(int i=0;i<minLen;i++){
        int tmp = (int)a[i]-(int)'0' + (int)b[i]-(int)'0';
        result.push_back(to_string(tmp));
    }

    if(a.size()>minLen){
        for(int i= minLen;i<a.size();i++){
            string tmp ="";
            tmp+=a[i];
            result.push_back(tmp);
        }
    }

    if(b.size()>minLen){
        for(int i= minLen;i<b.size();i++){
            string tmp ="";
            tmp+=b[i];
            result.push_back(tmp);
        }
    }

    reverse(result.begin(), result.end());

    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
    
    
    
    
    return 0;
}