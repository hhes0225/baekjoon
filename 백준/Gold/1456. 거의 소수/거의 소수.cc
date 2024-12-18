#include <bits/stdc++.h>
#define MAX 10'000'000
using namespace std;


vector<int> prime;
vector<long long> almostPrime;
vector<bool> nums;

void era(long long to){
    int range = (int)sqrt(to)+1;
    //예를 들어, 10^14까지의 수에서 거의 소수를 구하기 위해선,ㄴ
    //sqrt((10^7)^2 ) 범위 까지의 소수만 판별하면 됨(그 이후는 제곱을 해도 범위를 초과하므로)
    //따라서 소수 판별 범위는 sqrt(to)까지만으로 충분.

    //+ 메모리 너무 커서 줄이기 위해.
    
    //O(nlogn)?
    for(long long i=2;i<=range;i++){
        if(!nums[i]){
            prime.push_back(i);

            //에라토스테네스의 체: 소수의 배수 전부 소수 후보에서 탈락
            for(long long j=i+i;j<=range;j+=i){
                nums[j]=true;
            }

            //응용-거의 소수: 소수의 제곱수 전부 거의 소수에 추가
            for(long long j=i*i;j<=to;j*=i){
                //if (j > to / i) break; // 오버플로우 방지
                almostPrime.push_back(j);

                if (j > to / i) break;;
            }
        }
    }

    //--이하 시험출력--
    /*
    for(auto it:prime){
        cout<<it<<" ";
    }
    cout<<"\n";
    */
    //cout<<almostPrime.size()<<"\n";

    /*
    for(auto it:almostPrime){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    /*
    for(auto it:nums){
        cout<<it<<" ";
    }
    cout<<"\n";
    */
}

int main() {
    long long from, to;

    cin>>from>>to;

    nums.assign((int)sqrt(to)+1, false);

    era(to);

    //sort(almostPrime.begin(), almostPrime.end());

    int ans=0;
    for(int i=0;i<almostPrime.size();i++){
        if(almostPrime[i]>=from&&almostPrime[i]<=to){
            ans++;
            //cout<<almostPrime[i]<<" ";
        }
        
    }
    //cout<<"\n";

    cout<<ans<<"\n";
    
    return 0;
}