#include <stdio.h>

int money, duration;
double r, rate; //���� ����
void calculate(void); //�Լ� ����

int main(void)
{
	printf("* * * ���� ���� ���� ��� ���α׷��Դϴ�. * * *\n"); //���α׷� ����
	printf("������ �Է����ּ���: "); //���ݾ� �Է� �䱸
	scanf_s("%d", &money); //���ݾ� ���� money�� ����

	printf("�������� �Է����ּ���(�ۼ�Ʈ ����): "); //������ �Է� �䱸
	scanf_s("%lf", &r); //������ r�� ����

	rate = r * 0.01; //������ %���� �Ҽ������� ��ȯ �� rate�� ����

	printf("���� �Ⱓ�� �Է����ּ���(�� ����): "); //���� �Ⱓ �Է� �䱸
	scanf_s("%d", &duration); //���� �Ⱓ ���� duration�� ����

	calculate(); //�Լ� ȣ��

	return 0;
}

void calculate(void)
{
	int simple, month, annual, i; //���� ����
	double month_rate = (1 + (rate/12)), annual_rate = (1 + rate); //���� ����(��� �����ϰ� �ϱ� ���� ������ ������ �Ҵ�)

	simple = rate * duration * money; //�ܸ� ���

	for (i = 0; i < (duration * 12 - 1); i++) //�������� ������ ����� ���� �ݺ���
	{
		month_rate = month_rate * (1 + (rate / 12));
	}
	month = money * month_rate - money; //�������� �� ���ھ� ���

	for (i = 0; i < duration - 1; i++) //�������� ������ ����� ���� �ݺ���
	{
		annual_rate = annual_rate * (1 + rate);
	}
	annual = money * annual_rate - money; //�������� �� ���ھ� ���

	printf("---------------------------------------\n");
	printf("���� : %d��\n", money);
	printf("�ܸ� ����: %d��\n", simple);
	printf("������ ����: %d��\n", month);
	printf("������ ����: %d��\n", annual);
	printf("---------------------------------------\n"); //���� �� ���� ���� ���

	return;
}