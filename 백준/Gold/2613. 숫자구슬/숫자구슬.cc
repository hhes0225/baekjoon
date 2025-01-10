#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> beads;
vector<int> groups;

bool isDividable(int maxVal){
    int sum=0;
    int cnt=1;
    
    for(int i=0;i<beads.size();i++){
        sum+=beads[i];//비즈 누적해서서

        //누적값이 최댓값을 초과하게 되면
        if(sum>maxVal){
            //현재 인덱스부터 새 그룹으로 넘어가기
            //이전 인덱스까지 컷
            cnt++;
            sum=beads[i];
        }
        //그렇지 않으면 다음 요소 더해가면서 최댓값 초과하도록 만듦
    }

    return cnt<=m;
}

void makeGroup(int maxVal){
    int sum=0;
    int elements=0;
    int groupNum=m;

    for(int i=0;i<beads.size();i++){
        sum+=beads[i];

        if(sum>maxVal){
            groups.push_back(elements);
            groupNum--;
            elements=0;
            sum=beads[i];
        }
        
        elements++;

        //1 그룹당 1개는 있어야 하므로
        //남은 구슬 개수가 그룹 수와 동일하면 그만큼 넣어줌
        //예를 들어, gNum=3이면 {..4 1 1} 이런식으로
        //먼저 남은 누적 수 넣고, 뒤에 gNum만큼 1 추가해주기
        if(n-i==groupNum){
            break;
        }
    }

    for(int i=0;i<groupNum;i++){
        groups.push_back(elements);
        elements=1;
    }
}

int main() {
    cin>>n>>m;

    beads.resize(n);

    int sum=0;
    for(int i=0;i<n;i++){
        cin>>beads[i];
        sum+=beads[i];
    }

    int left=*max_element(beads.begin(), beads.end());
    int right=sum;

    //최댓값의 최소화!!
    //이분탐색에서는 최소화만 해주면 됨.
    //그룹의 최댓값 구하는 로직은 함수에서 체크하면 됨
    while(left<=right){
        int mid=(left+right)/2;

        if(isDividable(mid)){
            right=mid-1;
            //성공했으면 이것보다 작은 것에 대해 확인
            //최소화를 해야 하므로!!
        }
        else{
            left=mid+1;
            //실패하면 어쩔 수 없이 큰 값으로 고고링
        }
    }

    cout<<left<<"\n";
    makeGroup(left);

    for(auto i:groups){
        cout<<i<<" ";
    }
    cout<<"\n";
    
    
    return 0;
}