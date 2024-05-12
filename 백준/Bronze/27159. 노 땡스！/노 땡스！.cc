#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tCase;
    cin>>tCase;
    int input=0;
    int sum=0;
    vector<int> arr;
    
    for(int i=0;i<tCase;i++){
        cin>>input;
        arr.push_back(input);
    }

    sum=arr[0];

    for(int i=1;i<tCase;i++){
        if(arr[i]-arr[i-1]==1){
            continue;
        }
        else{
            sum+=arr[i];
        }
    }

    cout<<sum<<endl;
    
    return 0;
}