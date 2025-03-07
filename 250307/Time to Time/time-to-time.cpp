#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;

    // Please write your code here.
    int timeSrc=a*60+b;
    int timeDst=c*60+d;
    
    cout<<timeDst-timeSrc<<"\n";

    return 0;
}