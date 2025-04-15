#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    1. 누적합을 저장하고
     i번째 값 - 1~i-1번째 값 해서 d로 나누어 떨어지는지 구하기 
     200(테케) * ((49998(n-1)*49999(n))/2: 등차수열 합)-> O(n^2)
     이 경우 최대 연산이 2천억 이상 나와서 불가..

    2. 누적합 저장
    누적합%mod 결과를 map에 [%mod, cnt] 형태로 누적
    값%mod가 같으면, 그 두개를 뺄 때 mod로 나누어떨어짐
    2 1 2 1 1 2 1 2 의 경우 누적합은 
    2 3 5 6 7 9 10 12, 를 mod=4로 하면
    2 3 1 2 3 1 2 0 이고, 이때 mod한 결과값이 같은
    2,6,10(2)의 경우 6-2=4, 10-2=8, 10-6=4
    5,9의 경우 9-5=4
    3의 경우 7-3=4
    i-j=j+1번~i번까지의 누적합
    로 mod로 나누어 떨어지는 것을 알 수 있다

    그래서 각 map의 항목에 대해 0을 제외하면
    nC2 계산하면 되지 않을까??
    
    200(테케)*(100만 순회(mod)+5만 순회(입력, 맵에 넣기))
    ->O(n)...?
     
*/

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int d, n;
        cin>>d>>n;
        vector<ll> arr;
        unordered_map<int, ll> mods;
        ll ans=0;

        // mods[0]=1;//누적합 0 포함

        arr.assign(n+1, 0);

        for(int j=1;j<=n;j++){
            cin>>arr[j];            
            arr[j]+=arr[j-1];//누적합
        }

        //맵에 넣기
        for(int j=1;j<=n;j++){
            mods[arr[j]%d]++;
        }

        ans+=mods[0];
        //모듈러 연산 결과가 0인 경우
        //== 첫 번째 값~j번째 값까지의 합이 d로 나누어 떨어짐
        //따라서 이 자체를 그냥 더해줌
        //그리고 0이 2번 이상 나올 경우 해당 부분구간 다시 만들 수 있음
        //ex) 1~2번째까지 0, 1~4번째까지 0인 경우, 3~4번째도 0

        //map 순회하며 nC2 가능할 경우 nC2 수행
        for(auto [mod, cnt]:mods){
            // cout<<it->first<<" "<<it->second<<"\n";
            if(cnt>=2){
                ans+=((cnt*(cnt-1))/2);
            }
        }

        cout<<ans<<"\n";
    }
    
    return 0;
}
