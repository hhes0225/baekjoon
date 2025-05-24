#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    음수 입력은 음수 벡터에,
    양수 입력은 양수 벡터에

    0 처리는 어떻게 할까?

    양수벡터: 큰수부터 내림차순(5 5 3 2)
    음수벡터: 작은수부터 오름차순(-5 -5 -3 -2)

    양수: 최대한 곱해나가는게 이득. 그리고 0이랑 안곱하는게 이득
    (짝수면 2개씩 짝지어나가고 홀수면 큰거부터 짝짓기, 마지막 하나 남은 제일 작은거 더하기)

    음수: 최대한 음수*음수 해서 양수로 만들어주는게 이득.
    만약 음수 1개 남고, 0 있으면 0이랑 곱해줘서 뺄셈 없애는게 이득
    (짝수 개수면 2개씩 짝지어서 음*음=양 만들어주고
    홀수 개수면 1개 남은거 그대로 빼주거나, 0 있으면 0과 곱해서 뺄셈 없애기)

    0: 만약 음수 1개 남으면 그 1개랑 곱해주고,
    나머지 0들은 1개 그 자체를 제거해서 0 더해줌
*/

vector<ll> positive;
vector<ll> negative;
vector<ll> zero;

int main() {
    ll n;
    ll maxSum=0;
    cin>>n;

    for(ll i=0;i<n;i++){
        ll tmp;
        cin>>tmp;

        if(tmp>0){
            if(tmp>1) positive.emplace_back(tmp);
            else maxSum++;//1일땐 곱하지 않고 더하는 게 이득!
        }
        else if(tmp<0){
            negative.emplace_back(tmp);
        }
        else{
            zero.emplace_back(tmp);
        }
    }

    sort(positive.begin(), positive.end(), [](ll a, ll b){
        return a>b;
    });

    sort(negative.begin(), negative.end());

    

    //양수 점수 최대합
    // for(auto p:positive) cout<<p<<" ";
    // cout<<"\n";
    
    if(positive.size()%2==1){
        // cout<<"홀\n";
        maxSum+=positive.back();
        positive.pop_back();
    }
    
    for(ll i=0;i<positive.size();i+=2){
        // cout<<"덧: "<<positive[i]<<" "<<positive[i+1]<<"\n";
        maxSum+=(positive[i]*positive[i+1]);
    }

    

    //음수 점수 최대합
    // for(auto p:negative) cout<<p<<" ";
    // cout<<"\n";
    
    ll restNegative=0;
    if(negative.size()%2==1){
        // cout<<"음수 홀\n";
        restNegative=negative.back();
        negative.pop_back();

        //0으로 커버 못치면 어쩔 수 없이 더하기
        if(zero.size()==0){
            maxSum+=restNegative;   
        }
    }

    
    
    for(ll i=0;i<negative.size();i+=2){
        // cout<<"뺄: "<<negative[i]<<" "<<negative[i+1]<<"\n";
        maxSum+=(negative[i]*negative[i+1]);
    }

    cout<<maxSum<<"\n";
    
    return 0;
}