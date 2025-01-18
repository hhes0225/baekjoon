#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    요즘 스터디의 태그 맞추기처럼 풀고 있는데,
    일단 부분합 -> 누적합
    k인 것이 몇개인가? -> dp는 아닐 것 같음

    처음에는 투포인터로도 되지 않을까? 라고 생각했는데
    누적합 쓰면 굳이 투포인터는 안써도 될 것 같았음.
*/

vector<ll> arr;
ll kCnt=0;
unordered_map<ll, ll> partialSum;

/* 1st try
void countK(int n, int k){
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            //cout<<arr[j]<<" "<<arr[i-1]<<"\n";
            if(arr[j]-arr[i-1]==k){
                kCnt++;
            }
        }
    }
}
*/

int main() {
    int n, k;
    cin>>n>>k;

    arr.resize(n);

    cin>>arr[0];
    //partialSum[arr[0]]++;
    for(int i=1;i<n;i++){
        int input;
        cin>>input;

        arr[i]=arr[i-1]+input;

        //partialSum[arr[i]]++;//0~n까지의 누적합 map에 등록

        /*2nd try
        for(int j=0;j<i;j++){
            partialSum[arr[i]-arr[j]]++;
        }
        */
    }

    //arr[i]~[j]까지의 부분합 == k 이다?
    //== arr[j-k]를 부분합으로 가지고 있다

    for(int i=0;i<n;i++){
        //0~i까지의 부분합이 k인 경우(누적합이 k)
        if(arr[i]==k) kCnt++;
        
        if(partialSum.find(arr[i]-k)!=partialSum.end()){
            kCnt+=partialSum[arr[i]-k];
        }
        partialSum[arr[i]]++;
    }

    /*
    // map 출력
    for(pair<int, int> it:partialSum){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    */
    
    
    cout<<kCnt<<"\n";
    
    return 0;
}