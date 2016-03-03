#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//定义数组的长度
#define NUM 5


void aboutUs();

void myexit();   //自定义的退出函数

void login();    //登录

void showMainMenu();   //显示主菜单

void record();    //录入学生信息

void show();  //显示所有学生信息

//声明全局变量，用来存标准用户名和密码. 
//使用字符指针指向了一个字符串
//  char *指针名="字符串值";
char *realusername="1";
char *realpassword="a";

//声明一个结构体,一个结构体只能存一个学生. 
struct Student{
	char *name;
	int math;
	int physics;
	int c;
};
//数据类型   x数组名[长度]
//int x[10];

struct Student students[NUM];   //存学生信息的数组
int stuNum=0;   //表示真正存了几个学生



int main(){
	//compile  -> 编译   -> 语法
	//build  -> 构建
	// execute -> 运行
	//printf("hello world!");
	//定义变量 :   类型 变量名;
	int choice;
	do{
		system("cls");
		printf("**********************************************\n");
		printf("\t湖南皇家工学院学生成绩管理系统\n");
		printf("\t版本:v1.0\n");
		printf("\t1.登录\n");
		printf("\t2.关于我们\n");
		printf("\t3.关机\n");
		printf("**********************************************\n");
		printf("请输入您的选项(1,2,3):\n");
		scanf("%d",&choice);     // 1回车
		//作业: 
		//清屏
		//   判断:   if()   if()...esle if()     switch()
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
				printf("您输入的选项错误，请按任意键确认后继续...");
				getch();
		}
	}while(  1   );
}

//显示所有学生信息
void show(){
	int i;
	int sum;
	int avg;
	system("cls");
	if( stuNum<=0 ){
		printf("本系统还是个小白,暂无任何学生信息...\n");
		printf("按任意键继续...\n");
		getch();
		return;
	}
	printf("\t\t\t学生信息如下\n");
	printf("\t\t学生姓名\t数学\t物理\tc\t总分\t平均分\n");
	for(  i=0;i<stuNum;i++){
		sum=students[i].math+students[i].physics+students[i].c;
		avg=sum/3;
		printf("\t\t%s\t%d\t%d\t%d\t%d\t%d\n", &students[i].name, students[i].math, students[i].physics, students[i].c, sum, avg );
	}
	printf("按任意键继续...\n");
	getch();
	
}

//录入学生信息
void record(){
	char choice='y';
	system("cls");
	do{
		//判断当前的结构体数组是否已经存满了
		if( stuNum>= NUM ){
			printf("数组已经存满了,不能继续存储了...");
			printf("按任意键继续...");
			getch();
			break;
		}
		printf("请输入学生姓名:");
		//录入学生姓名
		scanf("%s",&students[stuNum].name );       // stuNum实际上是一个下标.    %s 字符串
		printf("请输入数学:");
		scanf("%d",&students[stuNum].math);        // %d 整数
		printf("请输入物理:");
		scanf("%d",&students[stuNum].physics);
		printf("请输入c:");
		scanf("%d",&students[stuNum].c);   // 100 回车
		//学生数量加一
		stuNum++;
		//提醒用户是否要继续
		fflush( stdin);   //清空缓冲区
		printf("是否继续录入(y/n):");
		scanf("%c",&choice);
	}while(    choice=='y'      );
}

//显示主菜单
void showMainMenu(){
	int choice=0;
	do{
		system("cls");
		printf("**********************************************\n");
		printf("\t成绩管理系统\n");
		printf("\t1.录入学生成绩信息\n");
		printf("\t2.显示所有学生信息\n");
		printf("\t3.按平均成绩降序显示学生信息\n");
		printf("\t4.返回上一级\n");
		printf("**********************************************\n");
		printf("请输入您的选项(1,2,3,4):\n");
		scanf("%d",&choice);     // 1回车
		switch( choice){
				case 1:
					printf("*******开始录入学生信息********");
					getch();
					record();
					break;
				case 2:
					printf("*******显示所有学生信息********");
					getch();
					show();
					break;
				case 3:
					printf("*******按平均成绩降序显示学生信息********");
					getch();
					break;		
		}
		if( choice==4){
			printf("*******返回上一级********\n");
			getch();
			system("cls");
			break;
		}
	}while(1);
}

void login(){
	//只能最多三次输入用户名及密码，多于三次，则关闭程序. 
	int i;
	//声明局部变量   用来存用户输入的用户名和密码
	char username[9];   //要定义长度为9, 留一位给 \0
	char password[9];
	for( i=1;i<=3;i++){
		fflush(stdin);   //清空缓冲区
		//输入用户名    -》输入字符串
		printf("请输入用户名:");
		gets(    username );   //  以回车当成一个字符串的结束
		//输入密码
		printf("请输入密码:");
		gets( password);
		//判断输入的用户名和密码是否与标准的一样      strcom()  
		if( strcmp( username, realusername)==0  &&   strcmp( password,realpassword)==0  ){   // 0&&0          0->false
			//    如相同，则显示登录成功
			printf("登录成功，欢迎您归来,按任意键继续...\n");
			getch();
			system("cls");

			showMainMenu();


		}else{
			//    如不相同， 则显示"用户名或密码错误，你还n次机会..
			printf("用户名或密码错误,您还有%d次输入机会...且行且珍惜\n", (3-i) );
			printf("按任意键继续\n");
			getch();
		}	
	}
	if( i>3 ){   // 
		//非法用户， 
		printf("\n已经输入了三次，系统为了安全，自动关机...\n");
		myexit();
	}
}



void aboutUs(){
	printf("*****************************\n");
	printf("\t请随意copy...\n");
	printf("*****************************\n");
	printf("按任意键继续...");
	getch();
}

  
//实现退出
void myexit(){
	int i;
	printf("\n程序正常退出");
	for( i=0;i<10;i++){
		printf("..");
		Sleep( 200 );
	}
	printf("\n");
	exit( 0);   //调用系统函数完成退出
}	