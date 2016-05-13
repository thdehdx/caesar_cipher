#include <stdio.h>

void CaesarEncrypt(char*,int);//비밀화
void CaesarDecrypt(char*,int);//복호화

int main(void)
{
	char strBff[100];//암복호화를 위한 문자가 들어갈 배열
	int bExit=0;
	unsigned int nSel, nKey=0;

	printf("**************************\n");
	printf("**시저 암복호화 프로그램**\n");
	printf("**영문만 암복호화 가능함**\n");
	while(!bExit)
	{
		printf("**************************\n");
		printf("1.비밀화 2.복호화 3.종료\n");
		printf("원하는 동작을 선택하시오: ");
		scanf("%d", &nSel);
		while(getchar()!='\n');
		switch(nSel)
		{
		case 1:
			printf("암호화할 문장을 입력하시오: ");
			gets(strBff);
			printf("비밀키를 입력하시오(1~25): ");
			scanf("%d",&nKey);
			while(getchar()!='\n');
			CaesarEncrypt(strBff,nKey);
			printf("암호화된 문장: %s\n",strBff);
			break;
		case 2:
			printf("복호화할 문장을 입력하시오: ");
			gets(strBff);
			printf("비밀키를 입력하시오(1~25): ");
			scanf("%d",&nKey);
			while(getchar()!='\n');
			CaesarDecrypt(strBff,nKey);
			printf("복호화된 암호: %s\n",strBff);
			break;
		case 3:
			return 1;
		default:
			printf("잘못된 숫자를 입력하셨습니다.\n");
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