#include <stdio.h>

int main(void)
{
	int arr1[3][4];
	int arr2[7][9];
	printf("세로3, 가로4: %d \n", sizeof(arr1));
	printf("세로7, 가로9: %d \n", sizeof(arr2));
	return 0;
}
//결과는12칸 * 4바이트 = 48,:: 252, 바이트 단위로 나옴 

#include <stdio.h>
int main(void)
{
	int villa[4][2];
	int popu, i, j;

	/*가구별 거주인원 입력받기*/
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d층 %d호 인구수: ", i + 1, j + 1);
			scanf("%d", &villa[i][j]);
		}
	}

	/*빌라 층별 인구수 출력*/
	for (i = 0; i < 4; i++) {
		popu = 0;
		popu += villa[i][0];
		popu += villa[i][1];
		printf("%d 층 인구수: %d \n", i + 1, popu);
	}

	/*빌라 총 인구수는 어떻게 구할까*/

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2;j++) {
			popu = 0;
			popu += villa[0][i];
			popu += villa[1][i];
			popu += villa[2][i];
			popu += villa[3][i];
		}
		popu += villa[i][0];
		popu += villa[i][1];
		printf("총 인구수 %d: ", popu);//빌라 총 인구수 구해보자

	}
	return 0;
}




#include <stdio.h>
int main(void)
{
	int  i, j;
	//2 차원 배열 초기화 예시 1번
	int arr1[3][3] = { { 1, 2, 3 },
					   { 4, 5, 6 },
					   { 7, 8, 9 } };

	//2 차원 배열 초기화 예시 2번
	int arr2[3][3] = { { 1},
					   { 4, 5 },
					   { 7, 8, 9 } };


	//2 차원 배열 초기화 예시 3번
	int arr3[3][3] = { 1, 2, 3, 4, 5, 6, 7 };


	/*가구별 거주인원 입력받기*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//16-1
//문제 1번
#include <stdio.h>
int main(void)
{
	int a, b, c;
	int j;
	int arr[3][9];
	scanf("%d", &a);
	for (int i = 1;i < 10; i++) {
		int gugu = a * i;
	}
	printf("%d ", arr[0][i]);
}

//교수님 풀이
#include <stdio.h>

int main(void)
{
	int arr[3][9];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			arr[i][j] = (i + 2) * (j + 1);
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

