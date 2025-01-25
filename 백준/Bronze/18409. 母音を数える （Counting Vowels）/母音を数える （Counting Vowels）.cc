#include <bits/stdc++.h>
using namespace std;

int count_vowels(const string& s) {
    // 모음 목록을 해시셋(unordered_set)으로 정의 (빠른 검색을 위해)
    unordered_set<char> vowels = {'a', 'i', 'u', 'e', 'o'};
    int count = 0;

    // 문자열을 순회하면서 모음 개수 카운트
    for (char c : s) {
        if (vowels.count(c)) { // 문자가 모음인지 확인
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    string s;

    // 입력 받기
    cin >> n >> s;

    // 모음 개수 출력
    cout << count_vowels(s) << endl;

    return 0;
}
