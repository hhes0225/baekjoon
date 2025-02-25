#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int total = a + b + c + d;
    int minimum = min({a, b, c, d});
    cout << total - minimum + 1 << endl;
    return 0;
}
