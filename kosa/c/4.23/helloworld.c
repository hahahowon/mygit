/*
�� ��: Hello world ����ϱ�
�� ��: ���ڿ��� ���
�����̸�: FileName.c
������¥: 2025. 04. 23
�ۼ���: ��ȣ��
*/

#include <stdio.h>					//stdio.h ������� ����(����)



int main(void)						// main �Լ��� ����
{
	/*
	printf �Լ��� ����ͷ� ����� �ϴ� ��쿡 ����.
	���ڷ� ���ڿ��� �����ϸ� ���ڿ��� ����Ѵ�.
	*/
	printf("Hello, World! \n");		//����ͷ� ���ڿ� ���
	return 0;						//0�� ��ȯ
}									// main �Լ��� ��
									

//;�� ������ ����
//ALU ���� ó�� FPU �Ǽ� ó��
//mac, linux�� gcc �����Ϸ� ���� ���
//�ּ��� ��ü �ڵ��� 30% �̻� �ۼ�(��꿡���� 30%�̻� ���������� ��� �ȉ�)
//C ǥ�� ���̺귯�� libc.so
// ��� ����int, �Լ��̸�main �Է�����(void)
//
//����Ʈ ���� �ּ��ޱ�
//_start_up() ���߿� ���� �̾߱�



#include <stdio.h>

int main(void)
{
	printf("Hello Everybody \n");
	printf("%d \n", 1234);
	printf("%d %d \n", 10, 20);
	return 0;

}
