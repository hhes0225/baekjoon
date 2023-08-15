#include <iostream>
#include <string>

using namespace std;

//문자열 s가 있을 때, f(s)는 s를 무한번 붙인 문자열로 정의한다.
//예를 들어, s = "abc" 인 경우에 f(s) = "abcabcabcabc..."가 된다.
//
//다른 문자열 s와 t가 있을 때, f(s)와 f(t)가 같은 문자열인 경우가 있다.
//예를 들어서, s = "abc", t = "abcabc"인 경우에 f(s)와 f(t)는 같은 문자열을 만든다.
//
//s와 t가 주어졌을 때, f(s)와 f(t)가 같은 문자열을 만드는지 아닌지 구하는 프로그램을 작성하시오.

//틀린 testcase:
//input
//abcde
//e
//output
//1(원래는 0이어야함)
//input
//e
//abcde
//output
//1(원래는 0이어야함)

//이유:
//find해서 찾은 위치가 0이 아닌 경우, 앞에 찾을 문자열을 제외한 다른 문자열이 있다는 의미.
//따라서 찾은위치 0인 경우 = 찾을 문자열 제외한 뒤 문자열만, 
//0이 아닌 경우 = 찾을 문자열 제외한 앞뒤 문자열
//추출해야 함


int main(void) {
	string sString, tString;
	int trueOrFalse = 1;

	cin >> sString >> tString;

	while (true)
	{
		if (sString.size()==0 || tString.size()==0) {
			//cout << "size 0\n";
			trueOrFalse = 1;
			break;
		}


		if (tString.size() > sString.size()) {
			if(tString.find(sString) != string::npos) {//찾는 문자열이 있으면
				//cout << "tString이 더 긺->tString에서 sString을 찾을게\n";

				if (tString.find(sString) == 0)
					tString = tString.substr(tString.find(sString) + sString.size(), tString.size());
				else {
					string tmp1 = tString.substr(0, tString.find(sString));
					string tmp2 = tString.substr(tString.find(sString) + sString.size(), tString.size());
					tString = tmp1 + tmp2;
				}

				//cout << "tString: " << tString << '\n';
			}
			else {//없으면
				//cout << "tString에서 sString을 찾을 수 없음\n";
				trueOrFalse = 0;
				break;
			}
		}
		else {
			if (tString == sString) {
				//cout << "tString과 sString이 같음\n";
				trueOrFalse = 1;
				break;
			}
			else if (sString.find(tString) != string::npos) {//찾는 문자열이 있으면
				//cout << "sString이 더 긺->sString에서 tString을 찾을게\n";
				//cout << "sString position: " << sString.find(tString) << '\n';
				//cout << "sString position: " << sString.find(tString) + tString.size() << '\n';

				if(sString.find(tString)==0)
					sString = sString.substr(sString.find(tString) + tString.size(), sString.size());
				else {
					string tmp1 = sString.substr(0, sString.find(tString));
					string tmp2= sString.substr(sString.find(tString) + tString.size(), sString.size());
					sString = tmp1 + tmp2;
				}
				
				//cout << "sString: " << sString << '\n';
			}
			else {//없으면
				//cout << "sString에서 tString을 찾을 수 없음\n";
				trueOrFalse = 0;
				break;
			}
		}
	}

	cout << trueOrFalse << '\n';

	return 0;
}