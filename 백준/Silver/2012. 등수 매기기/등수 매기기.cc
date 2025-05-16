#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> students(n+1);

    for(int i=1;i<=n;i++) cin>>students[i];

    sort(students.begin(), students.end());

    long long minComplaints=0;
    for(int i=1;i<=n;i++){
        minComplaints+=abs(students[i]-i);
    }

    cout<<minComplaints<<"\n";
    
    return 0;
}