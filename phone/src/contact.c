/*********************************************************
 * ** 文件名:  contact.c
 * ** Copyright (c) 2017 xiethon@126.com
 *
 * ** 创建人: xiethon
 * ** 日  期: 2017-12-14
 * ** 描  述: 通讯录相关操作头文件
 * ** 版  本: V1.0
 *
 * ** 修改人:
 * ** 日  期:
 * ** 修改描述:
 * ** 版  本:
 *
 * ****************************************************/
#include <stdlib.h>
#include <string.h>
#include"../inc/contact.h"
#include"../inc/console.h"


#define N 1024   

/******************************** 
函数名：contact_destroy
功能： 删除全部联系人
参数：plink_head:链表头
返回值：void 
**********************************/
void contact_destroy(plink plink_head)
{
	plink plink_tmp; //定义一个工作指针
	
	system("clear");
//	CONSOLE_MSG("正在删除全部联系人\n");
//	CONSOLE_MSG("------------------------\n");
//	CONSOLE_MSG("全部联系人已删除\n\n");

	//头指针判空
	if(plink_head == NULL)
	{
		return ;
	}

	//遍历指针，并free掉数据
	plink_tmp = plink_head->next;
	while(plink_tmp != NULL)
	{
		free(plink_tmp);
		plink_tmp = plink_tmp->next;
	}

	//工作指针和头指针的next都指向NULL
	plink_tmp = NULL;
	plink_head->next = NULL;
}


/******************************** 
函数名：contact_add
功能：增加一个联系人
参数：plink_head:链表头
返回值：void 
**********************************/
void contact_add(plink plink_head)
{
	data_t data;
	char *p = (char *)malloc(sizeof(char)*N);
	system("clear");
	CONSOLE_MSG("添加一个新的联系人\n");
	CONSOLE_MSG("-------------------\n");
	
/**********名字输入************/
	CONSOLE_MSG("请输入姓名：");
	scanf("%s",p);	//先把输入数据存入临时指针P中，防止数据溢出
	getchar(); //消除垃圾字符

	if(strlen(p) >= NAME_MAX_LEN)
	{
		strncpy(data.name,p,NAME_MAX_LEN-1); //数据拷贝
		data.name[NAME_MAX_LEN-1] = '\0';
	}
	else
	{
		strncpy(data.name,p,NAME_MAX_LEN-1); //数据拷贝
	}
	
/**********性别输入************/
	CONSOLE_MSG("请输入性别(m为男，f为女):");
	scanf("%s",p);
	getchar();
	while( !( (p[1] == '\0') && ( (p[0]=='f') || (p[0]=='m') ) ))
	{
		CONSOLE_MSG("\n");
		CONSOLE_MSG("性别输入有误请重新输入...\n");
		CONSOLE_MSG("请输入姓别(m为男，f为女):");
		scanf("%s",p);
		getchar();
	}
	data.sex = p[0];

/**********电话号码输入************/
	CONSOLE_MSG("请输入电话号码：");
	scanf("%s",p);
	getchar();	
	if(strlen(p) >= NUMBER_MAX_LEN)
	{
		strncpy(data.number,p,NUMBER_MAX_LEN-1); //数据拷贝
		data.number[NAME_MAX_LEN-1] = '\0';
	}
	else
	{
		strncpy(data.number,p,NUMBER_MAX_LEN-1); //数据拷贝
	}
	list_add_head(plink_head,data);
	CONSOLE_MSG("\n添加成功\n\n");
	free(p);
	p = NULL;
}


/******************************** 
函数名：contact_print
功能：打印所有联系人 
参数：plink_head:链表头
返回值：void
**********************************/
void contact_print(plink plink_head)
{
	system("clear");
	CONSOLE_MSG("列出全部联系人\n");
	CONSOLE_MSG("--------------------\n\n");
	list_print(plink_head);
}

/******************************** 
函数名：contact_female_print
功能：打印所有的女性名单
参数：plink_head:链表头
返回值：void
**********************************/
void contact_female_print(plink plink_head)		//打印所有女性联系人
{
	plink plink_tmp;	//定义一个工作节点
	system("clear");
	CONSOLE_MSG("列出所有的女性联系人\n");
	CONSOLE_MSG("------------------------\n\n");
	if(plink_head == NULL)
	{
		return ;
	}
	plink_tmp = plink_head->next;
	while(plink_tmp != NULL)
	{
		if(plink_tmp->data.sex == 'f')
		{
			print_data(plink_tmp->data);
		}
		plink_tmp = plink_tmp->next;
	}
}

/******************************** 
函数名：contact_man_print
功能：打印所有的男性名单
参数：plink_head:链表头
返回值：成功返回RET_OK，失败返回:RET_ERR
**********************************/
void contact_man_print(plink plink_head)		//打印所有女性联系人
{
	plink plink_tmp;	//定义一个工作节点
	system("clear");
	CONSOLE_MSG("列出所有的男性联系人\n");
	CONSOLE_MSG("------------------------\n\n");
	if(plink_head == NULL)
	{
		return ;
	}

	plink_tmp = plink_head->next;
	
	while(plink_tmp != NULL)
	{
		if(plink_tmp->data.sex == 'm')
		{
			print_data(plink_tmp->data);
		}
		plink_tmp = plink_tmp->next;
	}
}

/******************************** 
函数名：contact_serch 
功能：查找联系人 
参数：plink_head:链表头
返回值：void 
**********************************/
void contact_serch(plink plink_head)		//查找一个联系人
{
	char *p = (char *)malloc(sizeof(char)*N);
	system("clear");
	CONSOLE_MSG("查找一个联系人...\n");
	CONSOLE_MSG("----------------------\n\n");
	CONSOLE_MSG("1:按姓名查找\n");
	CONSOLE_MSG("2:按电话号码查找\n");
	CONSOLE_MSG("\n请选择查找方式：");
	scanf("%s",p);
	getchar();
	while( !( (p[1] == '\0') && ( (p[0]=='1') || (p[0]=='2')) ))
	{
		CONSOLE_MSG("\n输入有误，请重新输入\n");
		CONSOLE_MSG("请选择查找方式：");
		scanf("%s",p);
		getchar();
	}
	if( p[0]==  '1')
		contact_serch_name(plink_head);
	else 
		contact_serch_number(plink_head);
	free(p);
	p = NULL;
}

/******************************** 
函数名：contact_delete 
功能：删除联系人 
参数：plink_head:链表头
返回值：void 
**********************************/
void contact_delete(plink plink_head)		//查找一个联系人
{
	char *p = (char *)malloc(sizeof(char)*N);
	system("clear");
	CONSOLE_MSG("删除一个联系人\n");
	CONSOLE_MSG("----------------------\n\n");
	CONSOLE_MSG("1:按姓名删除\n");
	CONSOLE_MSG("2:按电话号码删除\n");
	CONSOLE_MSG("\n请选择删除方式：");
	scanf("%s",p);
	getchar();
	while( !( (p[1] == '\0') && ( (p[0]=='1') || (p[0]=='2') ) ))
	{
		CONSOLE_MSG("\n输入有误，请重新输入\n");
		CONSOLE_MSG("请选择查找方式：");
		scanf("%s",p);
		getchar();
	}
	if( p[0]==  '1')
		contact_delete_name(plink_head);
	else 
		contact_delete_number(plink_head);
	free(p);
	p = NULL;
}


/******************************** 
函数名：contact_serch_name 
功能：按照名字查找联系人
参数：plink_head:链表头
返回值：void 
**********************************/
void contact_serch_name(plink plink_head)
{
	char *p = (char *)malloc(sizeof(char)*N);
	data_t data = {0};
	data.sex = 1; //按姓名查找，用sex作为 name 和 number 的区分
	CONSOLE_MSG("输入姓名：");
	scanf("%s",p);
	getchar();

	if(strlen(p) >= NAME_MAX_LEN)
	{
		CONSOLE_MSG("\n未找到此人\n");
	}
	else
	{
		strncpy(data.name,p,NUMBER_MAX_LEN-1); //数据拷贝
		list_serch(plink_head,data);
	}
	free(p);
	p = NULL;
}


/******************************** 
函数名：contact_serch_number 
功能：按照电话号码查找
参数：plink_head:链表头
返回值：void 
**********************************/
void contact_serch_number(plink plink_head)
{
	char *p = (char *)malloc(sizeof(char)*N);
	data_t data = {0};
	data.sex = 2; //按号码查找

	CONSOLE_MSG("输入电话号码：");
	scanf("%s",p);
	getchar();

	if(strlen(p) >= NUMBER_MAX_LEN)
	{
		CONSOLE_MSG("\n未找到此人\n");
	}
	else
	{
		strncpy(data.number,p,NUMBER_MAX_LEN-1); //数据拷贝
		list_serch(plink_head,data);
	}
	free(p);
	p = NULL;
}


/******************************** 
函数名：contact_delete_name 
功能：按照名字删除联系人 
参数：plink_head:链表头
返回值：void 
**********************************/
void contact_delete_name(plink plink_head)
{
	char *p = (char *)malloc(sizeof(char)*N);
	data_t data = {0};
	data.sex = 1; //按姓名查找
	CONSOLE_MSG("输入姓名：");
	scanf("%s",p);
	getchar();

	if(strlen(p) >= NAME_MAX_LEN)
	{
		CONSOLE_MSG("\n未找到此人\n");
	}
	else
	{
		strncpy(data.name,p,NUMBER_MAX_LEN-1); //数据拷贝
		list_delete(plink_head,data);
	}
	free(p);
	p = NULL;
}


/******************************** 
函数名：contact_delete_number 
功能：按照电话号码删除联系人 
参数：plink_head:链表头
返回值：void 
**********************************/
void contact_delete_number(plink plink_head)
{
	char *p = (char *)malloc(sizeof(char)*N);
	data_t data = {0};
	data.sex = 2; //按号码查找

	CONSOLE_MSG("输入电话号码：");
	scanf("%s",p);
	getchar();

	if(strlen(p) >= NUMBER_MAX_LEN)
	{
		CONSOLE_MSG("\n未找到此人\n");
	}
	else
	{
		strncpy(data.number,p,NUMBER_MAX_LEN-1); //数据拷贝
		list_delete(plink_head,data);
	}
	free(p);
	p = NULL;
}


void contact_write(plink plink_head)
{
	plink plink_tmp = NULL;
	FILE *fp = fopen("contact.txt","w");
	if((NULL==fp) || (NULL==plink_head))
	{
		DEBUG("fp error\n");
		return ;
	}
	plink_tmp = plink_head->next;

	while(plink_tmp != NULL)
	{
		DEBUG("----\n");
		fwrite((void *)(&(plink_tmp->data)),sizeof(data_t),1,fp);
		plink_tmp = plink_tmp->next;
	}
	fclose(fp);
}

void contact_read(plink  plink_head)
{
	data_t data; //通讯录结构体
	int data_len = sizeof(data_t);

	FILE *fp = fopen("contact.txt","r");
	
	if((NULL==fp) || (NULL==plink_head))
	{
		DEBUG("read err\n");
		return 	;
	}
	
	while(data_len == fread(&data,1,data_len,fp))
	{
		DEBUG("read len:%d\n",data_len);
		list_add_head(plink_head,data);
	}
	fclose(fp);
}


















