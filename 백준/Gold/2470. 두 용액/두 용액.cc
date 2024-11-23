#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    vector<int> liquid;

    cin>>n;

    liquid.resize(n);

    for(int i=0;i<liquid.size();i++){
        cin>>liquid[i];
    }

    sort(liquid.begin(), liquid.end());
    int left=0, right=n-1;
    int leftAns=2e9, rightAns=2e9;
    int mixAns=2e9;

    while(left<right){
        int mix = liquid[left]+liquid[right];
        int absMix=abs(mix);
        
        if(mix==0){
            leftAns=left;
            rightAns=right;
            break;
        }

        if(mixAns>absMix){
            //cout<<mix<<"\n";
            leftAns=left;
            rightAns=right;
            mixAns=absMix;
        }

        //양수인 경우 더 작은 양수를 음수와 더하면 0이 될 확률 높아짐
        if(mix>0){
            right--;
        }
        //음수일 경우 더 작은 음수를 양수와 더하면 0이 될 확률 높아짐
        else{
            left++;
        }
        
    }

    cout<<liquid[leftAns]<<" "<<liquid[rightAns]<<"\n";
    
    return 0;
}