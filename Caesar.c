#include <stdio.h>

void CaesarEncrypt(char*,int);//���ȭ
void CaesarDecrypt(char*,int);//��ȣȭ

int main(void)
{
	char strBff[100];//�Ϻ�ȣȭ�� ���� ���ڰ� �� �迭
	int bExit=0;
	unsigned int nSel, nKey=0;

	printf("**************************\n");
	printf("**���� �Ϻ�ȣȭ ���α׷�**\n");
	printf("**������ �Ϻ�ȣȭ ������**\n");
	while(!bExit)
	{
		printf("**************************\n");
		printf("1.���ȭ 2.��ȣȭ 3.����\n");
		printf("���ϴ� ������ �����Ͻÿ�: ");
		scanf("%d", &nSel);
		while(getchar()!='\n');
		switch(nSel)
		{
		case 1:
			printf("��ȣȭ�� ������ �Է��Ͻÿ�: ");
			gets(strBff);
			printf("���Ű�� �Է��Ͻÿ�(1~25): ");
			scanf("%d",&nKey);
			while(getchar()!='\n');
			CaesarEncrypt(strBff,nKey);
			printf("��ȣȭ�� ����: %s\n",strBff);
			break;
		case 2:
			printf("��ȣȭ�� ������ �Է��Ͻÿ�: ");
			gets(strBff);
			printf("���Ű�� �Է��Ͻÿ�(1~25): ");
			scanf("%d",&nKey);
			while(getchar()!='\n');
			CaesarDecrypt(strBff,nKey);
			printf("��ȣȭ�� ��ȣ: %s\n",strBff);
			break;
		case 3:
			return 1;
		default:
			printf("�߸��� ���ڸ� �Է��ϼ̽��ϴ�.\n");
		}
	}
	return 0;
}

void CaesarEncrypt(char *pstrBff,int nKey)
{
	int count;
	for(count=0;pstrBff[count]!='\0';count++)
	{
		if((pstrBff[count]>='A'&&pstrBff[count]<='Z')||(pstrBff[count]>='a'&&pstrBff[count]<='z'))
		{
			pstrBff[count]+=nKey;
			if(pstrBff[count]>'Z' && pstrBff[count]<'a')
				pstrBff[count]-=26;
			else if(pstrBff[count]>'z')
				pstrBff[count]-=26;
		}
	}
}
void CaesarDecrypt(char *pstrBff,int nKey)
{
	int count;
	for(count=0;pstrBff[count]!='\0';count++)
	{
		if((pstrBff[count]>='A'&&pstrBff[count]<='Z')||(pstrBff[count]>='a'&&pstrBff[count]<='z'))
		{
			pstrBff[count]-=nKey;
			if(pstrBff[count]<'A')
				pstrBff[count]+=26;
			else if(pstrBff[count]>'Z'&&pstrBff[count]<'a')
				pstrBff[count]+=26;
		}
	}
}//A=65,Z=90,a=97,z=122