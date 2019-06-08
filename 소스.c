#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>


//����,����,�ܾ� �ٸ� ����
//��¥�Է�
int intro();
int income_money(int money, FILE* in_file,int Date);
int export_money(int money, FILE* ex_file, int Date);
void print_money(int money, FILE* bal_file, int Date);
void program_exit();
void clear();

void main() {
	int date;
	int money = 0, sel;
	FILE *income_file;
	FILE *export_file;
	FILE *balance_file;

	income_file = fopen("income.txt", "w");
	export_file = fopen("export.txt", "w");
	balance_file = fopen("balance.txt", "w");

	if (balance_file)
		printf("����� ���� ����\n");

	printf("���� �ڻ� �Է�: ");
	if (!(scanf("%d", &money))) {
		printf("�ùٸ� �� �Է��ض�\n");
		exit(1);
	}
	if (money > 10000000)
		printf("�ʹ� ū ���� �Է��߽��ϴ�.");

	fprintf(balance_file, "�ܾ�:%d \n", money);

	while (1) {
		sel = intro();
		printf("��¥: ");
		scanf("%d", &date);

		switch (sel) {
		case 1:
			money = income_money(money, income_file,date);
			clear();
			break;

		case 2:
			money = export_money(money, export_file, date);
			clear();
			break;

		case 3:
			print_money(money, balance_file, date);
			clear();
			break;
		case 4:
			program_exit(export_file, income_file, balance_file);
			break;
		default:
			printf("�߸��� �� �Էµ�");
			clear();
			break;

		}
	}
}
void clear() {

	puts("*********************************************");
	puts("�ƹ�Ű�� ������ ȭ���� �ʱ�ȭ �մϴ�.");
	getch();
	system("cls");
}

void program_exit() {
	exit(1);
}

void print_money(int money, FILE* bal_file, int Date) {
	
	if (bal_file != NULL) {
		fprintf(bal_file, "%d\n", Date);
		fprintf(bal_file, "�ܾ� :%d\n", money);
	}
	printf("���� �ܾ��� %d�Դϴ�\n", money);
}

int export_money(int money, FILE* ex_file, int Date) {
	int export;

	if (ex_file != NULL) {
		printf("����� ���� �Է��ϼ��� >>");
		scanf("%d", &export);
		fprintf(ex_file, "%d\n", Date);
		fprintf(ex_file, "���� :%d\n", export);
		money -= export;
	}
	return money;

}

int income_money(int money, FILE* in_file, int Date) {
	int income;

	if (in_file != NULL) {
		printf("���� ���� �Է��ϼ��� >>");
		scanf("%d", &income);
		money += income;
		fprintf(in_file, "%d\n", Date);
		fprintf(in_file, "���� : %d\n", income);
	}
	return money;
}

int intro() {

	int num;

	puts("*********************************************");
	puts("*        ����� ���� ���α׷� v0.1         *");
	puts("*********************************************");
	puts("* 1.  ��  ��           *");
	puts("* 2.  ��  ��           *");
	puts("* 3.  �ܾ���ȸ        *");
	puts("* 4.  ��  ��           *");
	puts("*********************************************");
	printf("Input >>");
	if (!(scanf("%d", &num))) {
		printf("�ùٸ� ���� �Է��ϼ���\n");
		exit(1);
	}
	return num;
}