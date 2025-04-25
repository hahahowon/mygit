#include <stdio.h>

int main(void)
{
	int x1, y1;
	int x2, y2;
	int area;
	printf("ÁÂ »ó´Ü ÁÂÇ¥ ÀÔ·Â :");
	scanf_s("%d %d", &x1, &y1);
	printf("¿ì ÇÏ´Ü ÁÂÇ¥ ÀÔ·Â :");
	scanf_s("%d %d", &x2, &y2);

	printf(" ÁÂ »ó´ÜÀÇ x, y ÁÂÇ¥: %d %d", x1, y1);
	printf(" ¿ì ÇÏ´ÜÀÇ x, y ÁÂÇ¥: %d %d", x2, y2);
	
	printf(" µÎ Á¡ÀÌ ÀÌ·ç´Â Á÷»ç°¢ÇüÀÇ ³ÐÀÌ´Â %dÀÔ´Ï´Ù.", (x2 - x1) * (y2 - y1));
	return 0;
	
}

int main(void)
{
	int a;
	scanf_s("%d", & a);
	printf("%c", a);
		return 0;

}

int main(void)
{
	char ch;
	scanf_s("%c", &ch);
	printf("%c", ch);
	return 0;

}
