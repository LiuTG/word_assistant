#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	 //指示器
	 int i;
	 FILE * pFile;
	 //每次读取一行的临时存储
	 char content [100];

	 pFile = fopen ("1.txt" , "r");

	 if (pFile == NULL) 
		 perror("Error opening file");
     else 
	 {
		//循环读取文章，直至结束
		while(fgets(content , 100 , pFile)!= NULL )
		{
			for(i=0;i<100;i++)
			{
				//if(isspace(content[i]))
				//使用Ascii码从中跳出大小写的字母
				if(((content[i]>='a')&&(content[i]<='z'))||((content[i]>='A')&&(content[i]<='Z')))			
				{
					char temp [30];
					printf("%c",content[i]);
					
				}
				else
				{

					printf("\n");
				}

			}
		}
		fclose (pFile);
	 }

}
