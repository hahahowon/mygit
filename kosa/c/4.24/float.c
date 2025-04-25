#include <stdio.h>

int main(void)
{
	float f = 0.0f;
	int i = 0;
	for (f = 0.0; f < 100.0f; f += 0.1f, i++) {
		printf("f:%f\n", f);
		//f로 다른 작업 수행

	}
	printf("i : %d\n", i);
	return 0;
}

//컴퓨터는 실수를 100% 정확하게 표현하지 못한다. 근사치를 표현

