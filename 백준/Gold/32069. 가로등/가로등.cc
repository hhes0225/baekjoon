#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr ll MAX = 1'000'000'000'000'000'000;

int main() {
    ll l, n, k;
    cin>>l>>n>>k;
    
    vector<ll> lights;
    lights.resize(n);
    
    for(auto& lit:lights){
        cin>>lit;
    }
    
    priority_queue<ll, vector<ll>, greater<ll>> minDarkness;
    set<ll> checkedPosition;
    
    int check=0;
    
    
    while(minDarkness.size()<k){
        if(check==0){
            //불빛이 있는 경우
            for(int i=0;i<lights.size();i++){
                minDarkness.push(check);
                checkedPosition.insert(lights[i]);
                
                if(minDarkness.size()>=k) break;
            }
        }
        else{
            for(int i=0;i<lights.size();i++){
                
                ll leftCheck=lights[i]-check;
                ll rightCheck=lights[i]+check;
                
                //범위 내면서 이미 체크하지 않은 경우
                if(leftCheck>=0 
                && checkedPosition.find(leftCheck)==checkedPosition.end()){
                    minDarkness.push(check);
                    checkedPosition.insert(leftCheck);
                }
                
                if(minDarkness.size()>=k) break;
                
                if(rightCheck<=l
                && checkedPosition.find(rightCheck)==checkedPosition.end()){
                    minDarkness.push(check);
                    checkedPosition.insert(rightCheck);
                }
                
                if(minDarkness.size()>=k) break;
                
            }
        }
        check++;
    }
    
    
    //출력
    for(int i=0;i<k;i++){
        cout<<minDarkness.top()<<"\n";
        minDarkness.pop();
    }
    
    return 0;
}