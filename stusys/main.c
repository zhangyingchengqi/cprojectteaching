#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


//bye

//hello


void aboutUs();

void myexit();   //�Զ�����˳�����

void login();    //��¼

//����ȫ�ֱ������������׼�û���������. 
char *realusername="12345678";
char *realpassword="aaaaaaaa";

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
		scanf("%d",&choice);
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
		gets( username);
		//��������
		printf("����������:");
		gets( password);
		//�ж�������û����������Ƿ����׼��һ��      strcom()  
		if( strcmp( username, realusername)==0   &&   strcmp( password,realpassword)==0   ){
			//    ����ͬ������ʾ��¼�ɹ�
			printf("��¼�ɹ�����ӭ������\n");
			getch();
		}else{
			//    �粻��ͬ�� ����ʾ"�û�������������㻹n�λ���..
			printf("�û������������,������%d���������...��������ϧ\n", (3-i) );
			printf("�����������\n");
			getch();
		}	
	}
	if( i>3){   // 
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