
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//#include <strings.h>

//��������Ԫ��
typedef struct Winfo
{
	//�洢����
	char word[25];
	//��¼���ʳ��ִ���
	int time;
	struct Winfo *next;
}Winfo,*LinkHead;

//��������д������
LinkHead insertLink(LinkHead head,char words[])
{
	//sָ��ǰ���Ĵ���ڵ㣬rָ��β�ڵ�
	Winfo *r,*s;	
	//���δ���������ȴ�������
	if(head==NULL)
	{
		head = (Winfo*)malloc(sizeof(Winfo));
		head->next = NULL;
		r = head;
	}
	//�����Ϊ�գ�����ǰ���뺯���Ľڵ���Ϊ��ʼ�ڵ㣬���ڴ˺����������½ڵ�
	else
	{
		r = head;
	}
	s = (Winfo*)malloc(sizeof(Winfo));
	strcpy(s->word,words);
	r->next = s;
	r = s;
	r->next = NULL;

	//����βָ��
	return r;

}


//�������ֵ����
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
		//ѡ�����ִ�������5�εĵ���
		
		if(r->time>10)
		{
			printf("%s    %d\n",r->word,r->time);
			//����������ָ���ļ���
			fprintf(fp,"%s    %d\n",r->word,r->time);
    
		}

		r = r->next;
		
	}
	fclose(fp);
}

int main(void)
{
	 //������һ��ͷָ��
	 LinkHead head;
	 head = (Winfo*)malloc(sizeof(Winfo));
	 head->next = NULL;

	 //sָ��ǰ���Ĵ���ڵ㣬rָ��β�ڵ㣬searchΪ�Ƚ�ʱʹ�õĽڵ�ָ��
	 Winfo *r,*s,*search;
	 r = head;

	 //��־λ
	 int sign;
	 //ָʾ��
	 int i,j;
	 //����ȡ����
	 FILE * pFile;
	 //ÿ�ζ�ȡһ�е���ʱ�洢
	 char content [100];
	 //ÿ�����ʵ���ʱ��Ŵ�
	 char temp[25];
	 pFile = fopen ("1.txt" , "r");

	 if (pFile == NULL) 
	 {
		 perror("Error opening file!\n");
	 }
     else 
	 {
		//ѭ����ȡ���£�ֱ������
		while(fgets(content , 100 , pFile)!= NULL )
		{

			for(i=0,j=0;i<100;i++)
			{
				//if(isspace(content[i]))
				//ʹ��Ascii�����������Сд����ĸ
				if(((content[i]>='a')&&(content[i]<='z'))||((content[i]>='A')&&(content[i]<='Z')))			
				{
					
					//ʹ��tolower���������д�д��ĸת��ΪСд��ĸ
					temp[j] = tolower(content[i]);
					j++;
					//printf("%c",content[i]);
					
				}
				else
				{

				
					if(temp[0]!='\0')
					{
						//ÿ��һ��Ҫ�洢ʱ���ȱȽ��������Ƿ����ظ����ʴ���
						search = head->next;
						while(search)
						{
							//��ͬ����0�����ظ����ʲ��洢
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
							//����������ɴ洢
							temp[i] = '\0';
							s = (Winfo*)malloc(sizeof(Winfo));
							strcpy(s->word,temp);
							//���ʼ������㿪ʼ
							s->time = 1;
							r->next = s;
							r = s;
							r->next = NULL;
										
					
							//��յ�ǰ��ʱ�洢��&����ʱ�洢����temp��λ��������Ϊ1
							//"\0" ASCII��Ϊ0��Ҳ����NULL  ������0����ֵΪ48
							memset(temp,'\0', 25);
							j = 0;
							sign = 0;
						}
						
					}
					//�ױ�־�ַ�����1����ʾ��ǰ��ʱ�洢��Ϊ�ղ��ò�������
					else
					{

					}

					
				}

			}
		}
		fclose (pFile);
	 }

	//���������
	printLink(head);

	return 0;
}