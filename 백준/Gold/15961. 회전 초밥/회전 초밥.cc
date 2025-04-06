#include <bits/stdc++.h>
using namespace std;

deque<int> sushi;
deque<int> eat;
unordered_map<int, int> sushiKind;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, d, k, c;
    cin>>n>>d>>k>>c;

    sushi.resize(n);
    for(auto &s:sushi){
        cin>>s;
    }

    //유사 원형 만들어줌(순환 구조 위해)
    for(int i=0;i<n-1;i++){
        sushi.push_back(sushi[i]);
    }

    // for(auto s: sushi) cout<<s<<" ";
    // cout<<"\n";

    int maxEat=0;
    int left=0, right=0;

    //대신 입력 마지막 초밥까지만 left가 될 수 있음
    //그 다음부터는 left=0부터 중복되기 때문에
    for(left=0;left<n;left++){
        while(right<left+k&&right<sushi.size()){
            // cout<<sushi[right]<<" 추가됨\n";
            sushiKind[sushi[right]]++;//현재 값 set에 넣고
            right++;//인덱스 증가
        }
        
        //k개 연속으로 초밥 먹으면서
        //쿠폰에 있는 초밥은 먹지 않는 경우,
        //쿠폰에 있는 초밥 추가로 먹을 수 있음
        if(sushiKind.find(c)==sushiKind.end()){
            // cout<<"초밥 추가요\n";
            maxEat=max(maxEat, (int)sushiKind.size()+1);
        }
        else maxEat=max(maxEat, (int)sushiKind.size());

        // cout<<"초밥 set 현황:\n";
        // for(auto c: sushiKind) cout<<c.first<<": "<<c.second<<", ";
        // cout<<"\n"; 
        // cout<<"-=-------------\n";
        
        sushiKind[sushi[left]]--;
        if(sushiKind[sushi[left]]<=0){
            sushiKind.erase(sushi[left]);
        }
    }
    

    cout<<maxEat<<"\n";
    
    return 0;
}