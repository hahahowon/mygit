/*
�迭 �̸��� ������ó��, �����͸� �迭 �̸�ó�� Ȱ���ϴ� ���� ����
������ ����:: �����Ͱ� ���ϴ� ���� ���� Ȥ�� ���ҽ�Ű�� �������ǹ�
ptr++;
prt1 +=3;
--ptr;
ptr2=ptr1+2;
�� ���꿡 ���� �ؼ��ϱ�
*/

#include <stdio.h>

int main(void)
{
	int* ptr1 = 0x0010;
	double* ptr2 = 0x0010;
	printf("%p %p \n", ptr1, ptr2);
	
	printf("%p %p \n", ptr1 + 1, ptr1 + 2);
	printf("%p %p \n", ptr2 + 1, ptr2 + 2);

	printf("%p %p \n", ptr1, ptr2);
	ptr1++;
	ptr2++;
	printf("%p %p \n", ptr1, ptr2);
	return 0;
}
//�����Ϳ� ++�����ڸ� ���� ��Ҹ� ������Ų�� �� int�� �������� 4����Ʈ, double�� ������ 8����Ʈ �����Ѵ�.
//sizeof(int) ũ�⸸ŭ, sizeof(double) ũ�⸸ŭ ����

#include <stdio.h>

int main(void)
{
	int arr[3] = { 11, 22, 33 };// ex) �� �迭�� �ּ� 0x001000, 0x001004, 0x001008 ���� (int�� �̱⿡ �ּҰ� 4����Ʈ�� ����.)
	int* ptr = arr; //int *ptr=&arr[0]; �� ���� ����
	printf("%d %d %d \n", *ptr, *(ptr + 1), *(ptr + 2));// ù ��° �ּ�, �� ��° �ּ�, �� ��° �ּ� ���

	printf("%d ", *ptr); ptr++; //�ּ� ���� ���:: 22
	printf("%d ", *ptr); ptr++; //�ּ� ���� ���:: 33
	printf("%d ", *ptr); ptr--; //�ּ� ���� ���:: 22
	printf("%d ", *ptr); ptr--; //�ּ� ���� ���:: 11
	printf("%d ", *ptr); printf("\n");
	return 0;

}
//���ذ� �ȵǸ� �迭�� �ٲپ ¥����, �� �Ǹ� �����ͷ� ������ Ȯ���غ���


//299p~~~ 300p���� ���� Ǯ��� ::���� ����
int main(void)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = &arr[0];//ptr// �ε��� 0���� �� ���� �˾ƿ���
	for (int i = 0; i < 5; i++) {
		*(ptr + 2);
		}
	for (int j = 0; j < 5;j++) {
		printf("%d : %d\n", arr[j], ptr[j]);
	}

	return 0;
}