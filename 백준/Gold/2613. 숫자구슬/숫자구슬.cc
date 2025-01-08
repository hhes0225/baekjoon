#include<iostream>
using namespace std;
 
int n, m, i, j, a[301] = { 0 }, b[300];
 
bool go(int lim) {
    int cnt = m;
    i = 0;
    while (i < n) {
        j = n - cnt + 1;
        while (i<j && a[j] - a[i]>lim)--j;
        if (i == j)return false;
        b[--cnt] = j - i;
        i = j;        
    }
    return cnt == 0;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
 
    int l = 1, r = a[n];
    while (l <= r) {
        int mid = (l + r) / 2;
        if (go(mid))r = mid - 1;
        else l = mid + 1;
    }
 
    cout << l << endl;
    go(l);
    for (int i = m - 1; i >= 0; --i)cout << b[i] << ' ';
}