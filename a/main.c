#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//��������ĳ���
#define NUM 5


void aboutUs();

void myexit();   //�Զ�����˳�����

void login();    //��¼

void showMainMenu();   //��ʾ���˵�

void record();    //¼��ѧ����Ϣ

void show();  //��ʾ����ѧ����Ϣ

//����ȫ�ֱ������������׼�û���������. 
//ʹ���ַ�ָ��ָ����һ���ַ���
//  char *ָ����="�ַ���ֵ";
char *realusername="1";
char *realpassword="a";

//����һ���ṹ��,һ���ṹ��ֻ�ܴ�һ��ѧ��. 
struct Student{
	char *name;
	int math;
	int physics;
	int c;
};
//��������   x������[����]
//int x[10];

struct Student students[NUM];   //��ѧ����Ϣ������
int stuNum=0;   //��ʾ�������˼���ѧ��



int main(){
	//compile  -> ����   -> �﷨
	//build  -> ����
	// execute -> ����
	//printf("hello world!");
	//������� :   ���� ������;
	int choice;
	do{
		system("cls");
		printf("**********************************************\n");
		printf("\t���ϻʼҹ�ѧԺѧ���ɼ�����ϵͳ\n");
		printf("\t�汾:v1.0\n");
		printf("\t1.��¼\n");
		printf("\t2.��������\n");
		printf("\t3.�ػ�\n");
		printf("**********************************************\n");
		printf("����������ѡ��(1,2,3):\n");
		scanf("%d",&choice);     // 1�س�
		//��ҵ: 
		//����
		//   �ж�:   if()   if()...esle if()     switch()
		switch( choice){
			case 1:
				login();
				break;
			case 2:
				aboutUs();
				break;
			case 3:
				myexit();
				break;
			default:
				printf("�������ѡ������밴�����ȷ�Ϻ����...");
				getch();
		}
	}while(  1   );
}

//��ʾ����ѧ����Ϣ
void show(){
	int i;
	int sum;
	int avg;
	system("cls");
	if( stuNum<=0 ){
		printf("��ϵͳ���Ǹ�С��,�����κ�ѧ����Ϣ...\n");
		printf("�����������...\n");
		getch();
		return;
	}
	printf("\t\t\tѧ����Ϣ����\n");
	printf("\t\tѧ������\t��ѧ\t����\tc\t�ܷ�\tƽ����\n");
	for(  i=0;i<stuNum;i++){
		sum=students[i].math+students[i].physics+students[i].c;
		avg=sum/3;
		printf("\t\t%s\t%d\t%d\t%d\t%d\t%d\n", &students[i].name, students[i].math, students[i].physics, students[i].c, sum, avg );
	}
	printf("�����������...\n");
	getch();
	
}

//¼��ѧ����Ϣ
void record(){
	char choice='y';
	system("cls");
	do{
		//�жϵ�ǰ�Ľṹ�������Ƿ��Ѿ�������
		if( stuNum>= NUM ){
			printf("�����Ѿ�������,���ܼ����洢��...");
			printf("�����������...");
			getch();
			break;
		}
		printf("������ѧ������:");
		//¼��ѧ������
		scanf("%s",&students[stuNum].name );       // stuNumʵ������һ���±�.    %s �ַ���
		printf("��������ѧ:");
		scanf("%d",&students[stuNum].math);        // %d ����
		printf("����������:");
		scanf("%d",&students[stuNum].physics);
		printf("������c:");
		scanf("%d",&students[stuNum].c);   // 100 �س�
		//ѧ��������һ
		stuNum++;
		//�����û��Ƿ�Ҫ����
		fflush( stdin);   //��ջ�����
		printf("�Ƿ����¼��(y/n):");
		scanf("%c",&choice);
	}while(    choice=='y'      );
}

//��ʾ���˵�
void showMainMenu(){
	int choice=0;
	do{
		system("cls");
		printf("**********************************************\n");
		printf("\t�ɼ�����ϵͳ\n");
		printf("\t1.¼��ѧ���ɼ���Ϣ\n");
		printf("\t2.��ʾ����ѧ����Ϣ\n");
		printf("\t3.��ƽ���ɼ�������ʾѧ����Ϣ\n");
		printf("\t4.������һ��\n");
		printf("**********************************************\n");
		printf("����������ѡ��(1,2,3,4):\n");
		scanf("%d",&choice);     // 1�س�
		switch( choice){
				case 1:
					printf("*******��ʼ¼��ѧ����Ϣ********");
					getch();
					record();
					break;
				case 2:
					printf("*******��ʾ����ѧ����Ϣ********");
					getch();
					show();
					break;
				case 3:
					printf("*******��ƽ���ɼ�������ʾѧ����Ϣ********");
					getch();
					break;		
		}
		if( choice==4){
			printf("*******������һ��********\n");
			getch();
			system("cls");
			break;
		}
	}while(1);
}

void login(){
	//ֻ��������������û��������룬�������Σ���رճ���. 
	int i;
	//�����ֲ�����   �������û�������û���������
	char username[9];   //Ҫ���峤��Ϊ9, ��һλ�� \0
	char password[9];
	for( i=1;i<=3;i++){
		fflush(stdin);   //��ջ�����
		//�����û���    -�������ַ���
		printf("�������û���:");
		gets(    username );   //  �Իس�����һ���ַ����Ľ���
		//��������
		printf("����������:");
		gets( password);
		//�ж�������û����������Ƿ����׼��һ��      strcom()  
		if( strcmp( username, realusername)==0  &&   strcmp( password,realpassword)==0  ){   // 0&&0          0->false
			//    ����ͬ������ʾ��¼�ɹ�
			printf("��¼�ɹ�����ӭ������,�����������...\n");
			getch();
			system("cls");

			showMainMenu();


		}else{
			//    �粻��ͬ�� ����ʾ"�û�������������㻹n�λ���..
			printf("�û������������,������%d���������...��������ϧ\n", (3-i) );
			printf("�����������\n");
			getch();
		}	
	}
	if( i>3 ){   // 
		//�Ƿ��û��� 
		printf("\n�Ѿ����������Σ�ϵͳΪ�˰�ȫ���Զ��ػ�...\n");
		myexit();
	}
}



void aboutUs(){
	printf("*****************************\n");
	printf("\t������copy...\n");
	printf("*****************************\n");
	printf("�����������...");
	getch();
}

  
//ʵ���˳�
void myexit(){
	int i;
	printf("\n���������˳�");
	for( i=0;i<10;i++){
		printf("..");
		Sleep( 200 );
	}
	printf("\n");
	exit( 0);   //����ϵͳ��������˳�
}	