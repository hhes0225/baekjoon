#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
unordered_map<string, double> grade_map = {
    {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0},
    {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0},
    {"F",  0.0}
};

int main() {
    double sum=0;
    double avg;

    string subject;
    double credit;
    string grade;

    double totalCredit=0;

    while(cin>>subject>>credit>>grade){
        if(grade!="P") {
            sum+=(credit*grade_map[grade]);
            totalCredit+=credit;
        }
    }

    printf("%lf\n", sum/totalCredit);
    
    return 0;
}