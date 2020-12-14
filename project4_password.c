#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main(void) //���ް��� ���� ������ �ڷḦ ��ȯ�ϴ� �Լ�
{
	//���� 5���� �ְ� �� ������ ���� ����� ���� ��� ����
	//������ ���, Ʋ���� ����

	srand(time(NULL));
	int count = 0; //���� ���� ����
	for (int i = 1; i <= 5; i++)
	{

		// x * y = ?
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		//rintf("%d x %d = ?", num1, num2);
		showQuestion(i, num1, num2);

		int answer = -1;
		scanf_s("%d", &answer);
		if (answer == -1)
		{
			printf("���α׷��� �����մϴ�\n");
			exit(0); //�� �ڿ� � ������ �ֵ����� ������� ���α׷��� �ƿ� ����������
		}
		else if (answer == num1 * num2)
		{
			//����
			success();
			count++;
		}
		else
		{
			//����
			fail();
		}
	}

	printf("\n\n ����� 5���� ����� �� %d�� ������ϴ�\n",count);

	return 0;
}

int getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}
void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n##########3 %d ��° ��й�ȣ #######", level);
	printf("\n\t%d x %d��?\n\n", num1, num2);
	printf("#####################");
	printf("��й�ȣ�� �Է��ϼ��� (���� : -1) >>");
}

void success()
{
	printf("\n >> GOOD! �����Դϴ� \n");
}

void fail()
{
	printf("\n >> Fail! �����Դϴ� \n");
}