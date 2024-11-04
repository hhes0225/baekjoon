#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<long long> arr;
vector<long long> tree;

//세그트리를 배열의 각 구간 합으로 채워주기
//start: 배열 시작 인덱스, end: 배열 마지막 인덱스
//node: 세그트리 인덱스(무조건 1부터 시작)
void init(int node, int start, int end){
    //가장 최하단 노드
    if(start==end){
        tree[node]=arr[start];
    }

    else{
        int mid=(start+end)/2;

        init(node*2, start, mid);
        init(node*2+1, mid+1, end);

        tree[node]=tree[node*2]+tree[node*2+1];
    }
}

//구간 합을 구하는 함수
//start: 시작 인덱스, 마지막 인덱스
//left부터 right까지의 합을 구하게 됨
//현재 순회중인 노드 인덱스는 node
long long query(int node, int start, int end, int left, int right){
    //범위 밖
    if(left>end || right<start){
        return 0;
    }

    //범위 안
    if(left<=start && right>=end){
        return tree[node];
    }

    //나머지: 부분적으로 범위 걸침
    int mid = (start+end)/2;

    long long lsum = query(node*2, start, mid, left, right);//왼쪽 자식노드 부분합
    long long rsum = query(node*2+1, mid+1, end, left, right);//오른쪽 자식노드 부분합

    return lsum + rsum;
}

void update(int node, int start, int end, int idx, long long val){
    if(idx<start||idx>end){
        return;
    }
    if(start==end){//시작구간==끝구간->최하단 자신 노드
        arr[idx]=val;
        tree[node]=val;
        return;
    }

    int mid=(start + end)/2;

    update(node*2, start, mid, idx, val);
    update(node*2+1, mid+1, end, idx, val);

    tree[node]=tree[node*2]+tree[node*2+1];
    
}


int main() {
    cin>>n>>m>>k;

    arr.resize(n);
    tree.assign(n*4, 0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    init(1, 0, n-1);
    

    for(int i=0;i<m+k;i++){
        int a, b;
        long long c;

        cin>>a>>b>>c;

        if(a==1){//b번째 원소의 값을 c로 변경
            update(1, 0, n-1, b-1, c); 
        }
        else{//a==2, b번째부터 c번째까지의 부분합
            cout<<query(1, 0, n-1, b-1, c-1)<<"\n";
        }
    }
    
    return 0;
}