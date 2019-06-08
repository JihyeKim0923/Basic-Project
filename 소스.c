#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>


//수입,지출,잔액 다른 파일
//날짜입력
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
		printf("가계부 파일 생성\n");

	printf("현재 자산 입력: ");
	if (!(scanf("%d", &money))) {
		printf("올바른 값 입력해라\n");
		exit(1);
	}
	if (money > 10000000)
		printf("너무 큰 값을 입력했습니다.");

	fprintf(balance_file, "잔액:%d \n", money);

	while (1) {
		sel = intro();
		printf("날짜: ");
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
			printf("잘못된 값 입력됨");
			clear();
			break;

		}
	}
}
void clear() {

	puts("*********************************************");
	puts("아무키나 누르면 화면을 초기화 합니다.");
	getch();
	system("cls");
}

void program_exit() {
	exit(1);
}

void print_money(int money, FILE* bal_file, int Date) {
	
	if (bal_file != NULL) {
		fprintf(bal_file, "%d\n", Date);
		fprintf(bal_file, "잔액 :%d\n", money);
	}
	printf("현재 잔액은 %d입니다\n", money);
}

int export_money(int money, FILE* ex_file, int Date) {
	int export;

	if (ex_file != NULL) {
		printf("지출된 돈을 입력하세요 >>");
		scanf("%d", &export);
		fprintf(ex_file, "%d\n", Date);
		fprintf(ex_file, "지출 :%d\n", export);
		money -= export;
	}
	return money;

}

int income_money(int money, FILE* in_file, int Date) {
	int income;

	if (in_file != NULL) {
		printf("들어온 돈을 입력하세요 >>");
		scanf("%d", &income);
		money += income;
		fprintf(in_file, "%d\n", Date);
		fprintf(in_file, "수입 : %d\n", income);
	}
	return money;
}

int intro() {

	int num;

	puts("*********************************************");
	puts("*        가계부 관리 프로그램 v0.1         *");
	puts("*********************************************");
	puts("* 1.  수  입           *");
	puts("* 2.  지  츨           *");
	puts("* 3.  잔액조회        *");
	puts("* 4.  종  료           *");
	puts("*********************************************");
	printf("Input >>");
	if (!(scanf("%d", &num))) {
		printf("올바른 값을 입력하세요\n");
		exit(1);
	}
	return num;
}