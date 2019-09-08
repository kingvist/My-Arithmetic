#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
	//自动生成10道100以内的2的操作数的四则运算
	FILE* fp;
	int i = 0;																//用于循环
	int j = 0;																//用于下面剔重的循环
	int amount = 0;															//用于定制题目数量
	int number1 = 0;														//操作数1
	int DIYnumber = 0;														//用于定制操作数范围
	double DIY;																//用于存储强转后的操作数
	int number2 = 0;														//操作数2														
	int operation = 0;														//加减乘除4种情况
	int reoperation[500];													//用来存储加减乘除情况
	int result = 0;															//用来存储两个操作数的结果
	int judge;																//用于记录是否包含负数
	int judgeminus;															//产生随机数判断是否为负数
	int renumber1[500];
	int renumber2[500];														//用来存储每一次循环后的操作数1和操作数2		
	printf("请输入您需要的四则运算题目的数量：");
	scanf("%d",&amount);
	printf("请输入您需要的操作数范围");
	scanf("%d",&DIYnumber);
	printf("您的操作数是否包括负数如果包括请输入1不包括请输入其他数字：");
	scanf("%d",&judge);
	DIY = (double)DIYnumber;
	for(i = 0;i < amount;i++){
loop:
		number1 = 1+(int)(DIY*rand()/(RAND_MAX+1.0));					//随机生成两个100以内的操作数
		number2 = 1+(int)(DIY*rand()/(RAND_MAX+1.0));
		operation = 1+(int)(4.0*rand()/(RAND_MAX+1.0));
		judgeminus = 1+(int)(3.0*rand()/(RAND_MAX+1.0));
		renumber1[i] = number1;
		renumber2[i] = number2;
		reoperation[i] = operation;
		if(i != 0){
			for(j = 0;j >= i;j++){
				if(renumber1[i] == renumber1[j] || renumber2[i] == renumber2[j] ||reoperation[i] == reoperation[j])
					goto loop;
				else break;
			}

		}


//**********************************************************************************************************************************************************************************
//有负数部分

			if(judge == 1){

				switch(judgeminus){
				case 1:number1*=-1;break;
				case 2:number2*=-1;break;
				case 3:number1*=-1;number2*=-1;break;
				}
			/*	if(number1 == x&&number2 == y&&operation == k){									//如果有重复运算
					i--;
					continue;
				}*/
			/*else{*/
					if(number1 + number2 > DIYnumber&&number1 - number2 > DIYnumber&&number1 * number2 > DIYnumber&&number1 / number2 > DIYnumber){//判断结果是否超过了100
						i--;
						continue;
					}
					else{
	
						switch(operation){
						case 1: printf("%d\t+\t%d\t=\t\n",number1,number2);break;
						case 2: printf("%d\t-\t%d\t=\t\n",number1,number2);break;
						case 3: printf("%d\t*\t%d\t=\t\n",number1,number2);break;
						case 4: printf("%d\t/\t%d\t=\t\n",number1,number2);break;
						}
					}
				/*}*/

//**********************************************************************************************************************************************************************************
//无负数部分
			}
			else{
			/*	if(number1 == x&&number2 == y&&operation == k){									//如果有重复运算
					i--;
					continue;
				}
				else{*/
					if(number1 + number2 > DIYnumber&&number1 - number2 > DIYnumber&&number1 * number2 > DIYnumber&&number1 / number2 > DIYnumber){//判断结果是否超过了100
						i--;
						continue;
					}
					else{

						switch(operation){
						case 1: printf("%d\t+\t%d\t=\t\n",number1,number2);break;
						case 2: printf("%d\t-\t%d\t=\t\n",number1,number2);break;
						case 3: printf("%d\t*\t%d\t=\t\n",number1,number2);break;
						case 4: printf("%d\t/\t%d\t=\t\n",number1,number2);break;
						}
					}
				/*}*/

			}


		
			fp = fopen("D://result.txt","a");
			fprintf(fp,"%d\t",number1);
			switch(operation){
			case 1:fprintf(fp,"+\t");break;
			case 2:fprintf(fp,"-\t");break;
			case 3:fprintf(fp,"*\t");break;
			case 4:fprintf(fp,"/\t");break;
			}
			fprintf(fp,"%d\t",number2);
			fprintf(fp,"=\t");
			fprintf(fp,"\n");
			fclose(fp);


	}

}