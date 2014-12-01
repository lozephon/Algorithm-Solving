#include<stdio.h>
#include<string.h>
int main(void)
{
	freopen("input.in","r", stdin);

	char s[102];
	int change=1;

	scanf("%s", s);

	int n = strlen(s);

	for(int i=1; i<n; i++)
	{
		if(s[i]>'Z')
		{
			change=0;
			break;
		}
		change=1;
	}

	if(change==0)
		printf("%s", s);
	if(change==1)
	{
		for(int i=0; i<n; i++)
		{
			if(s[i]<='Z')
				printf("%c", s[i]+'a'-'A');
			else
				printf("%c", s[i]-'a'+'A');
		}
	}


}