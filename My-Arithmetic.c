#include<stdio.h>
#include<stdlib.h>
void main(){
	//�Զ�����10��100���ڵ�2�Ĳ���������������
	FILE* fp;
	int i = 0;																//����ѭ��
	int amount = 0;															//���ڶ�����Ŀ����
	int number1 = 0;														//������1
	int DIYnumber = 0;														//���ڶ��Ʋ�������Χ
	double DIY;																//���ڴ洢ǿת��Ĳ�����
	int number2 = 0;														//������2														
	int operation = 0;														//�Ӽ��˳�4�����
	int result = 0;															//�����洢�����������Ľ��
	int x,y,k;																//���ڱ�������ظ�
	int judge;																//���ڼ�¼�Ƿ��������
	int judgeminus;															//����������ж��Ƿ�Ϊ����
	printf("����������Ҫ������������Ŀ��������");
	scanf("%d",&amount);
	printf("����������Ҫ�Ĳ�������Χ");
	scanf("%d",&DIYnumber);
	printf("���Ĳ������Ƿ���������������������1�������������������֣�");
	scanf("%d",&judge);
	DIY = (double)DIYnumber;
	for(i = 0;i < amount;i++){
//**********************************************************************************************************************************************************************************
//�и�������
		if(judge == 1){
			number1 = 1+(int)(DIY*rand()/(RAND_MAX+1.0));					//�����������100���ڵĲ�����
			number2 = 1+(int)(DIY*rand()/(RAND_MAX+1.0));
			operation = 1+(int)(4.0*rand()/(RAND_MAX+1.0));
			judgeminus = 1+(int)(3.0*rand()/(RAND_MAX+1.0));
			switch(judgeminus){
			case 1:number1*=-1;break;
			case 2:number2*=-1;break;
			case 3:number1*=-1;number2*=-1;break;
			}
			if(number1 == x&&number2 == y&&operation == k){									//������ظ�����
				i--;
				continue;
			}
			else{
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
			}
			x = number1;
			y = number2;													//�Ѳ������洢���������������ж��ظ�
			k = operation;													//�洢��������Ĵ洢
//**********************************************************************************************************************************************************************************
//�޸�������
		}
		else{
			number1 = 1+(int)(DIY*rand()/(RAND_MAX+1.0));					//�����������100���ڵĲ�����
			number2 = 1+(int)(DIY*rand()/(RAND_MAX+1.0));
			operation = 1+(int)(4.0*rand()/(RAND_MAX+1.0));
			if(number1 == x&&number2 == y&&operation == k){									//������ظ�����
				i--;
				continue;
			}
			else{
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
			}
			x = number1;
			y = number2;													//�Ѳ������洢���������������ж��ظ�
			k = operation;													//�洢��������Ĵ洢
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
		}

		fclose(fp);


	}
