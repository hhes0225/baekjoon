#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> dpTable;

/*
int dp(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else if(n==3){
        return 0;
    }

    
}*/

int main() {
    int stones;
    cin>>stones;

    if(stones%2==0){
        cout<<"CY\n";
    }
    else{
        cout<<"SK\n";
    }

    return 0;
}
