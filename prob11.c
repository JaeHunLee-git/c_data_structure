//테스트 데이터 모두 통과
/*
n을 입력 받고 n개의 숫자를 입력 받아 오름차순으로 정렬하되 선택정렬을 사용하라
버블정렬을 사용해선 안된다.
*/
#include <stdio.h>
int main(void) {
	int data[100];
	int n;
	int x;
	int large;
	int count;
	scanf("%d", &n);
	count = n;
	int check;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	//large == 가장 큰 값
	for (int j = n - 1; j > -1; j--) {
		large = -2147483647;  //int의 최소값
		for (int i = 0; i < count; i++) {//최대값
			if (data[i] > large) {
				large = data[i];
				check = i;
			}
		}
		if (data[j] < large) {
			x = data[check];
			data[check] = data[j];
			data[j] = x;

		}
		count--;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}


	return 0;
}