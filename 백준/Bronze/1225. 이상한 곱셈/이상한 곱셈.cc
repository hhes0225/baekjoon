#include <iostream>
#include <string>

using namespace std;

/*
	boj 1225

	A×B를 계산하다 지겨워진 형택이는 A×B를 새로운 방법으로 정의하려고 한다.

	A에서 한 자리를 뽑고 × B에서 임의로 한 자리를 뽑아 곱한다.

	의 가능한 모든 조합 (A가 n자리, B가 m자리 수라면 총 가능한 조합은 n×m개)을 더한 수로 정의하려고 한다.

	예를 들어 121×34는

	1×3 + 1×4 + 2×3 + 2×4 + 1×3 + 1×4 = 28

	이 된다. 이러한 형택이의 곱셈 결과를 구하는 프로그램을 작성하시오.
*/

int main(void) {
	string a, b;
	long long int result = 0;

	cin >> a >> b;

	//cout << (int)'0' << '\n';

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			//cout << (int)a[i] - (int)'0' << '\n';
			//cout << (int)b[i] - (int)'0' << '\n';

			result += ((long long int)a[i] - (long long int)'0') * ((long long int)b[j] - (long long int)'0');

			//cout << result << '\n\n';
			//cout << "몬데\n";
		}
	}

	cout << result << '\n';

	return 0;
}