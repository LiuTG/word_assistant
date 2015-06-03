
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//#include <strings.h>

//定义链表元素
typedef struct Winfo
{
	//存储单词
	char word[25];
	//记录单词出现次数
	int time;
	struct Winfo *next;
}Winfo,*LinkHead;

//创建并填写链表函数
LinkHead insertLink(LinkHead head,char words[])
{
	//s指向当前正的处理节点，r指向尾节点
	Winfo *r,*s;	
	//如果未创建链表先创建链表
	if(head==NULL)
	{
		head = (Winfo*)malloc(sizeof(Winfo));
		head->next = NULL;
		r = head;
	}
	//如果不为空，将当前传入函数的节点作为起始节点，并在此后面进行添加新节点
	else
	{
		r = head;
	}
	s = (Winfo*)malloc(sizeof(Winfo));
	strcpy(s->word,words);
	r->next = s;
	r = s;
	r->next = NULL;

	//返回尾指针
	return r;

}


//输出链表值函数
void printLink(LinkHead head)
{
	Winfo *r;
	FILE *fp;
    fp = fopen("./out.txt", "w");
	if(head == NULL)
	{
		printf("The Link head is empety!\n");
	}
	else
	{
		r = head->next;
	}
	
	while(r!=NULL)
	{
		//printf("%s\n",r->word);
		//选出出现次数大于5次的单词
		
		if(r->time>10)
		{
			printf("%s    %d\n",r->word,r->time);
			//将结果输出到指定文件中
			fprintf(fp,"%s    %d\n",r->word,r->time);
    
		}

		r = r->next;
		
	}
	fclose(fp);
}

int main(void)
{
	 //创建出一个头指针
	 LinkHead head;
	 head = (Winfo*)malloc(sizeof(Winfo));
	 head->next = NULL;

	 //s指向当前正的处理节点，r指向尾节点，search为比较时使用的节点指针
	 Winfo *r,*s,*search;
	 r = head;

	 //标志位
	 int sign;
	 //指示器
	 int i,j;
	 //待读取文章
	 FILE * pFile;
	 //每次读取一行的临时存储
	 char content [100];
	 //每个单词的临时存放处
	 char temp[25];
	 pFile = fopen ("1.txt" , "r");

	 if (pFile == NULL) 
	 {
		 perror("Error opening file!\n");
	 }
     else 
	 {
		//循环读取文章，直至结束
		while(fgets(content , 100 , pFile)!= NULL )
		{

			for(i=0,j=0;i<100;i++)
			{
				//if(isspace(content[i]))
				//使用Ascii码从中跳出大小写的字母
				if(((content[i]>='a')&&(content[i]<='z'))||((content[i]>='A')&&(content[i]<='Z')))			
				{
					
					//使用tolower函数将所有大写字母转换为小写字母
					temp[j] = tolower(content[i]);
					j++;
					//printf("%c",content[i]);
					
				}
				else
				{

				
					if(temp[0]!='\0')
					{
						//每到一次要存储时，先比较链表内是否有重复单词存在
						search = head->next;
						while(search)
						{
							//相同返回0，有重复单词不存储
							if(!strcmp(search->word,temp))
							{
								search->time++;
							
								sign = 1;
								memset(temp,'\0', 25);
								j = 0;
								break;
							}
							else
							{
								sign = 0;
								search = search->next;
							}
						}
						
						if(sign != 1)
						{
							//创建链表并完成存储
							temp[i] = '\0';
							s = (Winfo*)malloc(sizeof(Winfo));
							strcpy(s->word,temp);
							//单词计数从零开始
							s->time = 1;
							r->next = s;
							r = s;
							r->next = NULL;
										
					
							//清空当前临时存储区&将临时存储区的temp的位置重新置为1
							//"\0" ASCII码为0，也就是NULL  而数字0，码值为48
							memset(temp,'\0', 25);
							j = 0;
							sign = 0;
						}
						
					}
					//首标志字符等于1，表示当前临时存储区为空不用插入链表
					else
					{

					}

					
				}

			}
		}
		fclose (pFile);
	 }

	//输出链表函数
	printLink(head);

	return 0;
}