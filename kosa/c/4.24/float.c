#include <stdio.h>

int main(void)
{
	float f = 0.0f;
	int i = 0;
	for (f = 0.0; f < 100.0f; f += 0.1f, i++) {
		printf("f:%f\n", f);
		//f�� �ٸ� �۾� ����

	}
	printf("i : %d\n", i);
	return 0;
}

//��ǻ�ʹ� �Ǽ��� 100% ��Ȯ�ϰ� ǥ������ ���Ѵ�. �ٻ�ġ�� ǥ��

