#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    deque<int> positive, negative, zero;

    vector<int> nums;
    nums.resize(n);

    for(auto &i:nums){
        cin>>i;
    }

    for(auto i:nums){
        if(i>0) positive.push_back(i);
        else if(i==0) zero.push_back(i);
        else negative.push_back(i);
    }

    //양수는 내림차순, 음수는 오름차순 정렬(그게 가장 좋은 효율)
    sort(positive.begin(), positive.end(), [](int a, int b){
        return a>b;
    });
    sort(negative.begin(), negative.end());


    int maxSum=0;

    while(!positive.empty()){
        //1일때는 곱하는거보다 그냥 더하는게 이득
        //양수는 1개 남았을 때 0이나 음수 곱하는거보다 그냥 더하는게 이득
        if(positive.size()==1){
            maxSum+=positive.front();
            positive.pop_front();
            continue;
        }

        if(positive[0]==1){
            maxSum+=positive.front();
            positive.pop_front();
            continue;
        }

        if(positive[1]==1){
            maxSum+=positive[1];
            int tmp=positive[0];
            positive.pop_front();
            positive.pop_front();
            positive.push_front(tmp);
            continue;
        }
        
        maxSum+=(positive[0]*positive[1]);
        positive.pop_front();
        positive.pop_front();
    }

    for(int i=0;i<negative.size();i+=2){
        if(negative.size()%2==1 && i==negative.size()-1){
            //cout<<negative[i]<<"\n";

            //음수는 홀수개일 때 0 곱해서 없애는게 이득
            if(zero.size()==0)  maxSum+=negative[i];
        }
        else{
            //cout<<negative[i]<<" "<<negative[i+1]<<"\n";
            maxSum+=(negative[i]*negative[i+1]);
        }
    }

    cout<<maxSum<<"\n";
    
    return 0;
}