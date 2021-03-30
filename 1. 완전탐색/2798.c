#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main(void) {
	//int cnt;
	int N, M;
	int* card;
	int result = 0;
	int max = 0;

	scanf("%d %d", &N, &M);
	card = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				result = card[i] + card[j] + card[k];
				if (M-result >= 0) {
					if (result > max)
						max = result;
				}
			}
		}
	}

	printf("%d", max);

	free(card);
	return 0;
}
