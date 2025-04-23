#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1000000000000000000LL;
ll d[1003][1003];
int p[1003][1003];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, n; cin >> m >> n;

    vector<int> a(n+2);
    for (int i=1; i<=n; i++) cin >> a[i];
    a[n+1] = m;
    sort(a.begin(), a.end());
    n += 2;

    for (int i=0; i<n; i++) {
        d[i][i] = 0, p[i][i] = i;
        for (int j=i+1; j<n; j++) d[i][j] = 0, p[i][j] = i;
    }

    for (int l=2; l<=n; l++) {
        for (int i=0; i+l<n; i++) {
            int j = i+l;
            d[i][j] = inf;
            for (int k=p[i][j-1]; k<=p[i+1][j]; k++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k;
                }
            }
            d[i][j] += a[j]-a[i];
        }
    }
    cout << d[0][n-1];
}