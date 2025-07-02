#include <bits/stdc++.h>

using namespace std;

vector<int> nemo;

int search(int k, int s, int e){
	int mid;
	while(s<e){
		mid = (s+e)/2;
		if(nemo[mid] >= k){ s = mid + 1; }
		else{ e = mid; }
	}
	return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
	int n,q;
	int res;
	int tmp;
	int x,y;
	
	cin>>n>>q;
    nemo.resize(n+1);
	for(int i=1;i<=n;i++)cin>>nemo[i];
	
	for(int i=0; i<q;  i++){
		cin>>x>>y;
		if(nemo[n] >= x) res = 1;
		else             res = 0;
		
		tmp = search(x,1,n);
		
		if( nemo[y]-x <0 || tmp-y <0 ) cout<<"0\n";
		else cout<<res + nemo[y]-x + tmp-y<<"\n";
	}
	return 0; 
}