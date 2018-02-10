#include<stdio.h>
#include<string.h>
int count_substr(char[],char []);
int main()
{
	char string[1000],substring[200];
	int count;
	
	printf("Enter a sentence : ");
	gets(string);
	
	printf("Enter a word to be searched for : ");
	gets(substring);
	
	count = count_substr(string,substring);
	
	printf("'%s' occurs in '%s' %d times\n",substring,string,count);
	
	return 0;
	
}

int count_substr(char s1[],char s2[])
{
	int i=0,j=0,count1=0,count2=0,flag=-2;
	int ctr=0;
	char *ptr1,*ptr2;
	ptr1=s1;
	ptr2=s2;
	
	count1=strlen(s1);
	
	count2=strlen(s2);
	
	if(count2<count1)
	{
		for(i=0;i<=count1-count2;i++)
		{
			for(j=i;j<i+count2;j++)
			{
				flag=1;
				
				if(*(ptr1+j) != *(ptr2+(j-i)))
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			ctr++;
		}
	}
	return ctr;
}
