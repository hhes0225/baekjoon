 #include <bits/stdc++.h>
using namespace std;

vector<int> gomgom;

int main() {
    int chicken, beef, pasta;
    cin>>chicken>>beef>>pasta;
    int a,b,c;
    cin>>a>>b>>c;

    int result=0;
    if(chicken-a<0){
        result+=abs(chicken-a);
    }
    if(beef-b<0){
        result+=abs(beef-b);
    }
    if(pasta-c<0){
        result+=abs(pasta-c);
    }
    
    cout<<result<<"\n";
    
    return 0;
}