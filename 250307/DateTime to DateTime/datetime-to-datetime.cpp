#include <iostream>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    int today = 11*24*60+11*60+11;//11일(24시간*60분), 11시(60분), 11분

    int dstDay = a*24*60+b*60+c;

    cout<<dstDay-today<<"\n";

    return 0;
}