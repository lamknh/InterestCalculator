#include <stdio.h>

int money, duration;
double r, rate; //변수 설정
void calculate(void); //함수 설정

int main(void)
{
	printf("* * * 정기 예금 이자 계산 프로그램입니다. * * *\n"); //프로그램 설명
	printf("원금을 입력해주세요: "); //예금액 입력 요구
	scanf_s("%d", &money); //예금액 변수 money에 저장

	printf("이자율을 입력해주세요(퍼센트 단위): "); //이자율 입력 요구
	scanf_s("%lf", &r); //이자율 r에 저장

	rate = r * 0.01; //이자율 %에서 소수점으로 변환 후 rate에 저장

	printf("예금 기간을 입력해주세요(년 단위): "); //예금 기간 입력 요구
	scanf_s("%d", &duration); //예금 기간 변수 duration에 저장

	calculate(); //함수 호출

	return 0;
}

void calculate(void)
{
	int simple, month, annual, i; //변수 설정
	double month_rate = (1 + (rate/12)), annual_rate = (1 + rate); //변수 설정(계산 용이하게 하기 위해 계산식을 변수에 할당)

	simple = rate * duration * money; //단리 계산

	for (i = 0; i < (duration * 12 - 1); i++) //월복리의 제곱근 계산을 위한 반복문
	{
		month_rate = month_rate * (1 + (rate / 12));
	}
	month = money * month_rate - money; //월복리의 순 이자액 계산

	for (i = 0; i < duration - 1; i++) //연복리의 제곱근 계산을 위한 반복문
	{
		annual_rate = annual_rate * (1 + rate);
	}
	annual = money * annual_rate - money; //연복리의 순 이자액 계산

	printf("---------------------------------------\n");
	printf("원금 : %d원\n", money);
	printf("단리 이자: %d원\n", simple);
	printf("월복리 이자: %d원\n", month);
	printf("연복리 이자: %d원\n", annual);
	printf("---------------------------------------\n"); //원금 및 각각 이자 출력

	return;
}