#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    unordered_map<string, char> table;

    // T개의 문자-이진수 쌍 입력받기
    for (int i = 0; i < T; ++i) {
        char ch;
        string bin;
        cin >> ch >> bin;
        table[bin] = ch;
    }

    string code;
    cin >> code;

    string result;
    // 4비트 단위로 끊어서 매핑
    for (int i = 0; i < code.size(); i += 4) {
        string chunk = code.substr(i, 4);
        if (table.find(chunk) != table.end()) {
            result += table[chunk];
        } else {
            result += '?';
        }
    }

    cout << result << endl;
    return 0;
}
