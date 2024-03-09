#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> num;
vector<int>primeNum;
int n, k;
int kthNum=0;

void removeNum(int input) {
    for (int i = input; i < n+1; i += input) {
        //cout << "k의 상태: " << k << endl;
        if (num[i] == false) {
            num[i] = true;
            //cout << input << "의 배수 " << i << endl;
            k--;
        }
        if (k == 0) {
            kthNum = i;
            //cout << kthNum << "이 정답\n";
            return;
        }
    }
}

int main() {
    cin >> n >> k;
    num = vector<bool>(n+1, false);

    

    for (int i = 2; i < n+1; i++) {
        if (num[i] == false) {
            primeNum.push_back(i);
            //cout << i << "는 소수입니다.\n";
            if(k > 0){
                removeNum(i);   
            }
        }
        else {
            continue;
        }
    }


    cout << kthNum << "\n";


    return 0;
}