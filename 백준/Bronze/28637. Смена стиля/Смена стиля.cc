#include <iostream>
#include <string>
using namespace std;

string to_snake_case(const string& s) {
    string res;
    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i])) {
            if (i != 0) res += '_';         // 첫 글자 제외하고 앞에 '_' 추가
            res += tolower(s[i]);
        } else {
            res += s[i];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << to_snake_case(s) << '\n';
    }

    return 0;
}
