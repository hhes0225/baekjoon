#include <iostream> 
using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b>>c;

    int maxMove = max(b-a-1, c-b-1);

    cout<<maxMove<<"\n";
    
    return 0;
}