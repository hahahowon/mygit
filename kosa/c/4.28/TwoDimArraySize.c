#include <stdio.h>

int main(void)
{
	int arr1[3][4];
	int arr2[7][9];
	printf("����3, ����4: %d \n", sizeof(arr1));
	printf("����7, ����9: %d \n", sizeof(arr2));
	return 0;
}
//�����12ĭ * 4����Ʈ = 48,:: 252, ����Ʈ ������ ���� 

#include <stdio.h>
int main(void)
{
	int villa[4][2];
	int popu, i, j;

	/*������ �����ο� �Է¹ޱ�*/
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d�� %dȣ �α���: ", i + 1, j + 1);
			scanf("%d", &villa[i][j]);
		}
	}

	/*���� ���� �α��� ���*/
	for (i = 0; i < 4; i++) {
		popu = 0;
		popu += villa[i][0];
		popu += villa[i][1];
		printf("%d �� �α���: %d \n", i + 1, popu);
	}

	/*���� �� �α����� ��� ���ұ�*/

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
		printf("�� �α��� %d: ", popu);//���� �� �α��� ���غ���

	}
	return 0;
}




#include <stdio.h>
int main(void)
{
	int  i, j;
	//2 ���� �迭 �ʱ�ȭ ���� 1��
	int arr1[3][3] = { { 1, 2, 3 },
					   { 4, 5, 6 },
					   { 7, 8, 9 } };

	//2 ���� �迭 �ʱ�ȭ ���� 2��
	int arr2[3][3] = { { 1},
					   { 4, 5 },
					   { 7, 8, 9 } };


	//2 ���� �迭 �ʱ�ȭ ���� 3��
	int arr3[3][3] = { 1, 2, 3, 4, 5, 6, 7 };


	/*������ �����ο� �Է¹ޱ�*/
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
//���� 1��
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

//������ Ǯ��
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

