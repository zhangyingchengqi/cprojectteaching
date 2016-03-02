#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


//bye

//hello


void aboutUs();

void myexit();   //自定义的退出函数

void login();    //登录

//声明全局变量，用来存标准用户名和密码. 
char *realusername="12345678";
char *realpassword="aaaaaaaa";

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
		scanf("%d",&choice);
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
		gets( username);
		//输入密码
		printf("请输入密码:");
		gets( password);
		//判断输入的用户名和密码是否与标准的一样      strcom()  
		if( strcmp( username, realusername)==0   &&   strcmp( password,realpassword)==0   ){
			//    如相同，则显示登录成功
			printf("登录成功，欢迎您归来\n");
			getch();
		}else{
			//    如不相同， 则显示"用户名或密码错误，你还n次机会..
			printf("用户名或密码错误,您还有%d次输入机会...且行且珍惜\n", (3-i) );
			printf("按任意键继续\n");
			getch();
		}	
	}
	if( i>3){   // 
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