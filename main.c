#include <stdio.h>
#include <ctype.h>
int main(void)
{
	 //指示器
	 int i;
	 FILE * pFile;
	 char content [100];

	 pFile = fopen ("1.txt" , "r");
	 if (pFile == NULL) 
		 perror("Error opening file");
     else 
	 {
		
		while(fgets(content , 100 , pFile)!= NULL )
		{
			for(i=0;i<100;i++)
			{
				//if(isspace(content[i]))
				if(((content[i]>='a')&&(content[i]<='z'))||((content[i]>='A')&&(content[i]<='Z')))			
				{
					printf("%c",content[i]);
					
				}
				else if(content[i]==' ')
				{
					printf("\n");
				}

			}
		}
		fclose (pFile);
	 }

}
