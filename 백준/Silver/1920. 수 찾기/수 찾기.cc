#include<iostream>
#include<vector>
#include<algorithm>
//#include <map>

using namespace std;

/*
	boj1920
	N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

	TRY 무려 4번의 주인공... 그동안 나는 발전한건가?
*/

//TRY 4
int main(void) {
	int fromCase, toCase;
	vector<int> fromList, toList;
	int tmp;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> fromCase;

	for (int i = 0; i < fromCase; i++) {
		cin >> tmp;
		fromList.push_back(tmp);
	}
	
	/*for (int i = 0; i < fromCase; i++) {
		cout << fromList[i] << endl;
	}*/

	cin >> toCase;

	for (int i = 0; i < toCase; i++) {
		cin >> tmp;
		toList.push_back(tmp);
	}
	

	/*
	★★★★★★★★★
	binary_search 사용 시 주의점
	이진탐색 이전에 반드시 값을 탐색할 대상 배열의 정렬을 해줘야한다!!
	★★★★★★★★★
	*/

	sort(fromList.begin(), fromList.end());


	for (int i = 0; i < toList.size(); i++) {
		//cout << toList[i] << " turn\n";
		if (binary_search(fromList.begin(), fromList.end(), toList[i])) {//존재하면
			//if (find(fromList.begin(), fromList.end(), toList[i])!=fromList.end()) {//존재하면, 시간초과
			//cout << toList[i] << " exist!\n";
			cout << "1\n";
		}
		else {
			//cout << toList[i] << " not exist...\n";
			cout << "0\n";
		}
	}


	return 0;
}

//TRY 3
//int main(void) {
//	int listNum;
//	int givenNum;
//	int input;
//	vector<int> list;
//	map <int, int> given;
//
//
//	cin >> listNum;
//
//	for (int i = 0; i < listNum; i++) {
//		cin >> input;
//		list.push_back(input);
//	}
//
//	cin >> givenNum;
//
//	for (int i = 0; i < givenNum; i++) {
//		cin >> input;
//
//		//cout << input << endl;
//
//		given.insert(make_pair(input, 0));
//	}
//
//	/*for (auto it = given.begin(); it != given.end(); it++) {
//		cout << it->first << " ";
//		cout << it->second << "\n";
//	}*/
//
//	for (int i = 0; i < listNum; i++) {
//		if (given.find(list[i]) != given.end()) {//존재하면
//			given[list[i]]++;
//		}
//	}
//
//	for (auto it = given.begin(); it != given.end(); it++) {
//		//cout << it->first << " ";
//		cout << it->second << "\n";
//	}
//
//	return 0;
//}


//TRY 1
//int main(void) {
//	int N;
//	int M;
//	vector<int> A;
//	vector<int> inputs;
//	vector<int> answer;
//	int tmpIn;
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> tmpIn;
//		A.push_back(tmpIn);
//	}
//	
//	//sort(A.begin(), A.end());
//
//	cin >> M;
//
//	for (int i = 0; i < M; i++) {
//		cin >> tmpIn;
//		inputs.push_back(tmpIn);
//		answer.push_back(0);
//	}
//	
//	int start = 0;
//	int end = A.size();
//	bool searchComplete = false;
//
//	
//
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < N; j++) {
//			if (A[j] == inputs[i]) {
//				answer[i]++;
//				break;
//			}
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		cout << answer[i] << endl;
//	}
//
//	return 0;
//}


//TRY 2
//int main(void) {
//	int N;
//	int M;
//	vector<int> A;
//	vector<int> inputs;
//	int tmpIn;
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> tmpIn;
//		A.push_back(tmpIn);
//	}
//
//	sort(A.begin(), A.end());
//
//	cout << "정렬 후: ";
//	for (int i = 0; i < N; i++) {
//		cout << A[i]<<" ";
//	}
//
//	cout << endl;
//	
//	cin >> M;
//
//	for (int i = 0; i < M; i++) {
//		cin >> tmpIn;
//		inputs.push_back(tmpIn);
//	}
//
//	sort(inputs.begin(), inputs.end());
//
//	cout << "정렬 후: ";
//	for (int i = 0; i < M; i++) {
//		cout << inputs[i] << " ";
//	}
//
//	cout << endl;
//
//	int Astart = 0;
//	int Aend = A.size()-1;
//	int inputStart = 0;
//	int inputEnd = inputs.size()-1;
//
//	for (int i = 0; i < A.size(); i++) {
//		if (inputs[0] <= A[i]) {
//			Astart = i;
//			break;
//		}
//	}
//
//	for (int i = A.size()-1; i >=0 ; i--) {
//		if (inputs[inputs.size()-1] >= A[i]) {
//			Aend = i;
//			break;
//		}
//	}
//
//	for (int i = 0; i < inputs.size(); i++) {
//		if (A[0] <= inputs[i]) {
//			inputStart = i;
//			break;
//		}
//	}
//
//	for (int i = inputs.size()-1; i >=0 ; i--) {
//		if (A[A.size()-1] >= inputs[i]) {
//			inputEnd = i;
//			break;
//		}
//	}
//
//	cout << Astart << " " << Aend << endl;
//	cout << inputStart << " " << inputEnd << endl;
//
//
//	//bool searchComplete = false;
//
//	for (int i = Astart; i <=Aend; i++) {
//		for (int j = inputStart; j <= inputEnd; j++) {
//			if (A[i] == inputs[j]) {
//				inputs[j] = -1;
//				break;
//			}
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		cout << inputs[i] << " ";
//	}
//
//	cout << endl;
//
//	//for (int i = 0; i < M; i++) {
//	//	cin >> tmpIn;
//	//	for (int j = 0; j < A.size(); j++) {
//	//		if (tmpIn > A[pivot]) {//오른쪽
//	//			pivot = (pivot + A.size()) / 2;
//
//	//		}
//	//		else if(tmpIn ==A[pivot]) {
//	//			searchComplete = true;
//	//			break;
//	//		}
//	//		else {//왼쪽
//	//			pivot = pivot / 2;
//	//		}
//	//	}
//
//	//	if (searchComplete) {
//	//		cout << 1 << endl;
//	//		searchComplete = false;
//	//	}
//	//	else
//	//		cout << 0 << endl;
//	//}
//
//	
//
//	return 0;
//}