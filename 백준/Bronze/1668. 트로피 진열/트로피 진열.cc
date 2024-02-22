#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int tCase;
    vector<int> trophy;
    int maxHeight;
    
    cin>>tCase;
    
    trophy.resize(tCase);
    
    for(int i=0;i<tCase;i++){
        cin>>trophy[i];
    }
    
    int left=1;//첫번째 것은 무조건 보임
    maxHeight=trophy[0];
    for(int i=1;i<trophy.size();i++){
        if(maxHeight<trophy[i]){
            left++;
            maxHeight=trophy[i];
        }
    }
    
    cout<<left<<endl;
    reverse(trophy.begin(), trophy.end());
    
    int right=1;//첫번재 것은 무조건 보임
    maxHeight=trophy[0];
    for(int i=1;i<trophy.size();i++){
        if(maxHeight<trophy[i]){
            right++;
            maxHeight=trophy[i];
        }
    }
    
    cout<<right<<endl;
    
    return 0;
}