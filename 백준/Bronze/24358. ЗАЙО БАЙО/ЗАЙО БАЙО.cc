#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isLeap(int y){
    return (y%400==0) || (y%4==0 && y%100!=0);
}
int mdays(int m, int y){
    static int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2) return d[2] + (isLeap(y)?1:0);
    return d[m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, n;
    int d, m, y;
    cin >> x >> n;
    cin >> d >> m >> y;

    // 총 더할 일수: (2x-1)*n - 1 (당일 포함)
    ll add = (2*x - 1) * n - 1;

    while(add > 0){
        int dim = mdays(m, y);
        int rem = dim - d; // 이번 달에서 남은 일수(내일~말일까지)
        if(add <= rem){
            d += (int)add;
            add = 0;
        }else{
            add -= (rem + 1); // 이번 달 끝까지 넘어감
            d = 1;
            if(++m == 13){ m = 1; ++y; }
        }
    }

    cout << d << ' ' << m << ' ' << y << '\n';
    return 0;
}
