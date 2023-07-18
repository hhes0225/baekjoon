// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tCase;
    int tmp;
    vector<int> divisor;
    int resultNumber;
    
    cin >> tCase;
    
    for(int i=0;i<tCase;i++){
        cin >> tmp;
        divisor.push_back(tmp);
    }
    
    sort(divisor.begin(), divisor.end());
    
    if(divisor.size()!=1)  
        resultNumber=divisor[0]*divisor[divisor.size()-1];
    else
        resultNumber=divisor[0]*divisor[0];
    
    cout<<resultNumber<<'\n';

    return 0;
}