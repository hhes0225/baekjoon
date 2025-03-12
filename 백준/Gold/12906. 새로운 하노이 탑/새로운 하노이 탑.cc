#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

struct State {
	string A;
	string B;
	string C;
};

State Init;//초기 막대 3개
set<pair<pair<string,string>,string>>check;

bool Finish(string A, string B, string C) {
	int Asize = A.size();
	int Bsize = B.size();
	int Csize = C.size();
	if (Asize > 0) {
		for (int i = 0; i < Asize; i++) {
			if (A[i] != 'A')
				return false;
		}
	}
	if (Bsize > 0) {
		for (int i = 0; i < Bsize; i++) {
			if (B[i] != 'B')
				return false;
		}
	}
	if (Csize > 0) {
		for (int i = 0; i < Csize; i++) {
			if (C[i] != 'C')
				return false;
		}
	}
	return true;
}

string MoveTop(string s) {
	string tmp = "";
	int sSize = s.size();
	for (int i = 0; i < sSize - 1; i++) {
		tmp += s[i];
	}
	return tmp;
}

int bfs() {
	queue<pair<State,int>> q;//막대 상태와 움직임 횟수
	q.push(make_pair(Init,0));
	check.insert(make_pair(make_pair(Init.A,Init.B),Init.C));
	while (!q.empty()) {
		string A = q.front().first.A;
		string B = q.front().first.B;
		string C = q.front().first.C;
		int cnt = q.front().second;
		q.pop();
		if (Finish(A, B, C))
			return cnt;
		//A에서 원판 옮기기
		if (A.size() > 0) {
			//B로 옮기기
			string A_tmp = MoveTop(A);
			string B_tmp = B + A[A.size() - 1];
			State Stmp = { A_tmp,B_tmp,C };
			//한 번도 나오지 않았던 조건이면 queue에 저장
			if (check.find(make_pair(make_pair(A_tmp,B_tmp),C)) == check.end()) {
				q.push(make_pair(Stmp, cnt + 1));
				check.insert(make_pair(make_pair(A_tmp, B_tmp), C));
			}
			//C로 옮기기
			string C_tmp = C + A[A.size() - 1];
			Stmp = { A_tmp,B,C_tmp };
			if (check.find(make_pair(make_pair(A_tmp, B), C_tmp)) == check.end()) {
				q.push(make_pair(Stmp, cnt + 1));
				check.insert(make_pair(make_pair(A_tmp, B), C_tmp));
			}
		}
		//B에서 원판 옮기기
		if (B.size() > 0) {
			//A로 옮기기
			string B_tmp = MoveTop(B);
			string A_tmp = A + B[B.size() - 1];
			State Stmp = { A_tmp,B_tmp,C };
			if (check.find(make_pair(make_pair(A_tmp, B_tmp), C)) == check.end()) {
				q.push(make_pair(Stmp, cnt + 1));
				check.insert(make_pair(make_pair(A_tmp, B_tmp), C));
			}
			//C로 옮기기
			string C_tmp = C + B[B.size() - 1];
			Stmp = { A,B_tmp,C_tmp };
			if (check.find(make_pair(make_pair(A_tmp, B), C_tmp)) == check.end()) {
				q.push(make_pair(Stmp, cnt + 1));
				check.insert(make_pair(make_pair(A_tmp, B), C_tmp));
			}
		}
		//C에서 원판 옮기기
		if (C.size() > 0) {
			//A로 옮기기
			string C_tmp = MoveTop(C);
			string A_tmp = A + C[C.size() - 1];
			State Stmp = { A_tmp,B,C_tmp };
			if (check.find(make_pair(make_pair(A_tmp, B), C_tmp)) == check.end()) {
				q.push(make_pair(Stmp, cnt + 1));
				check.insert(make_pair(make_pair(A_tmp, B), C_tmp));
			}
			//B로 옮기기
			string B_tmp = B + C[C.size() - 1];
			Stmp = { A,B_tmp,C_tmp };
			if (check.find(make_pair(make_pair(A, B_tmp), C_tmp)) == check.end()) {
				q.push(make_pair(Stmp, cnt + 1));
				check.insert(make_pair(make_pair(A, B_tmp), C_tmp));
			}
		}
	}
}

int main() {
	int n;
	string s;
	//입력
	for (int i = 0; i < 3; i++) {
		cin >> n;
		//막대 A
		if (i == 0) {
			if (n == 0) {
				Init.A = "";
			}
			else {
				cin >> s;
				Init.A = s;
			}
		}
		//막대 B
		else if (i == 1) {
			if (n == 0) {
				Init.B = "";
			}
			else {
				cin >> s;
				Init.B = s;
			}
		}
		//막대 C
		else {
			if (n == 0) {
				Init.C = "";
			}
			else {
				cin >> s;
				Init.C = s;
			}
		}
	}
	int ans = bfs();
	cout << ans << '\n';
	return 0;
}