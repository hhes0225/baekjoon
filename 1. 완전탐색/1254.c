#include <stdio.h>
#include<string.h>
#pragma warning(disable:4996)
bool isTrue(char* str, int len);

int main(void) {
	char str[1000];
	char pel[1000];

	int strNum = 0;
	int minNum = 0;
	int idx = 0;

	scanf("%s", str);
	
	strNum = strlen(str);
	minNum = strNum;

	strcpy(pel, str);

	bool tof = 1;
	tof = isTrue(str, strNum);

	if (tof) {
		printf("%d", strNum);
		return 0;
	}

	else {
		while (1) {
			strcpy(pel, str);
			tof = 1;
			idx++;
			for (int i = idx-1; i >=0; i--) {
				pel[strNum - 1 + idx-i] = str[i];
			}
			
			tof = isTrue(pel, minNum + idx);

			if (tof) {
				printf("%d", minNum+idx);
				return 0;
			}
		}
	}



	return 0;
}
bool isTrue(char* str, int len) {
	bool tof = 1;
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]){
			tof = 0;
			break;
		}
	}

	return tof;
}
