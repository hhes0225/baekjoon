#include <stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define DNUM 9

int main(void) {
	int dwarf[DNUM];
	int dwarfSum = 0;
	int fake[2] = { 0, };
	bool result = 0;

	for (int i = 0; i < DNUM; i++) {
		scanf("%d", &dwarf[i]);
		dwarfSum += dwarf[i];
	}

	for (int i = 0; i < DNUM; i++) {
		for (int j = i + 1; j < DNUM; j++) {
			if (dwarfSum-(dwarf[i]+dwarf[j]) == 100){
				fake[1] = dwarf[j];
				result = 1;
				break;
			}
		}
		if (result){
			fake[0] = dwarf[i];
			break;
		}
	}

	
	for (int i = 0; i < DNUM; i++) {
		if (dwarf[i] != fake[0] && dwarf[i] != fake[1]){
			printf("%d\n", dwarf[i]);
		}
	}


	return 0;
}
