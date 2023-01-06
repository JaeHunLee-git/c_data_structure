//테스트 데이터 모두 통과
/*주사위를 n번 던져서 1이 적어도 k번 나오는 확률을 실험적으로 계산하는 함수를 작성하라*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


double prob(int N, int k) {
    srand((unsigned int)time(NULL));

    int count2 = 0;
    for (int i = 0; i < 1000000; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            int r = rand() % 6 + 1;
            if (r == 1) {
                count++;
            }
        }
        if (count >= k) {
            count2++;
        }
    }

    return (double)count2 / 1000000;

}
int main(void) {
    int N;
    int K;
    scanf("%d %d", &N, &K);
    printf("%f", prob(N, K));
}