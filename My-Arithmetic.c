#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
	//�Զ�����10��100���ڵ�2�Ĳ���������������
	FILE* fp;
	int i = 0;																//����ѭ��
	int j = 0;																//�����������ص�ѭ��
	int amount = 0;															//���ڶ�����Ŀ����
	int number1 = 0;														//������1
	int DIYnumber = 0;														//���ڶ��Ʋ�������Χ
	double DIY;																//���ڴ洢ǿת��Ĳ�����
	int number2 = 0;														//������2														
	int operation = 0;														//�Ӽ��˳�4�����
	int reoperation[500];													//�����洢�Ӽ��˳����
	int result = 0;															//�����洢�����������Ľ��
	int judge;																//���ڼ�¼�Ƿ��������
	int judgeminus;															//����������ж��Ƿ�Ϊ����
	int renumber1[500];
	int renumber2[500];														//�����洢ÿһ��ѭ����Ĳ�����1�Ͳ�����2		
	printf("����������Ҫ������������Ŀ��������");
	scanf("%d",&amount);
	printf("����������Ҫ�Ĳ�������Χ");
	scanf("%d",&DIYnumber);
	printf("���Ĳ������Ƿ���������������������1�������������������֣�");
	scanf("%d",&judge);
	DIY = (double)DIYnumber;
	for(i = 0;i < amount;i++){
loop:
		number1 = 1+(int)(DIY*rand()/(RAND_MAX+1.0));					//�����������100���ڵĲ�����
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
//�и�������

			if(judge == 1){

				switch(judgeminus){
				case 1:number1*=-1;break;
				case 2:number2*=-1;break;
				case 3:number1*=-1;number2*=-1;break;
				}
			/*	if(number1 == x&&number2 == y&&operation == k){									//������ظ�����
					i--;
					continue;
				}*/
			/*else{*/
					if(number1 + number2 > DIYnumber&&number1 - number2 > DIYnumber&&number1 * number2 > DIYnumber&&number1 / number2 > DIYnumber){//�жϽ���Ƿ񳬹���100
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
//�޸�������
			}
			else{
			/*	if(number1 == x&&number2 == y&&operation == k){									//������ظ�����
					i--;
					continue;
				}
				else{*/
					if(number1 + number2 > DIYnumber&&number1 - number2 > DIYnumber&&number1 * number2 > DIYnumber&&number1 / number2 > DIYnumber){//�жϽ���Ƿ񳬹���100
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