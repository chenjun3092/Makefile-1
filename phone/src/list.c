/*********************************************************
 * ** 文件名: list.c 
 * ** Copyright (c) 2017 xiethon@126.com
 *
 * ** 创建人: xiethon
 * ** 日  期: 2017-12-13
 * ** 描  述: 双向链表相关操作源文件
 * ** 版  本: V1.0
 *
 * ** 修改人:
 * ** 日  期:
 * ** 修改描述:
 * ** 版  本:
 *
 * ****************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../inc/list.h"
#include"../inc/console.h"



/******************************** 
函数名：list_create
功能：创建一个链表头
参数：无
返回值：链表头指针
**********************************/
plink list_create()
{
	plink plink_head = (plink)malloc(sizeof(link));
	if(plink_head == NULL)
	{
		return NULL;
	}
	plink_head->next = NULL;

	return plink_head;
}

/******************************** 
函数名：list_add_head
功能：向链表头部添加一个数据
参数：plink_head:链表头节点.data:插入的数据 
返回值：成功返回RET_OK，失败返回RET_ERR.
**********************************/
int list_add_head(plink plink_head,data_t data)
{
	//malloc一个新节点
	plink plink_node = (plink )malloc(sizeof(link));

	//参数合法性检查
	if((NULL == plink_head) || (NULL==plink_node))
	{
		return RET_ERR;
	}
	
	//结构体数据拷贝
	memcpy( (void*)(&plink_node->data),(void *)(&data),sizeof(data_t));
	
	//链表头插
	plink_node->next = plink_head->next;
	plink_head->next = plink_node;
	
	return RET_OK;
}


/******************************** 
函数名：list_add_tail
功能：向链表尾部添加一个数据
参数：plink_head:链表头节点 data：需要插入的数据
返回值：成功返回RET_OK，失败返回RET_ERR.
**********************************/
int list_add_tail(plink plink_head,data_t data)
{
	plink plink_node = (plink )malloc(sizeof(link)); //malloc一个新节点
	plink plink_tmp = plink_head; //定义一个工作指针

	//参数合法性检查
	if((NULL == plink_head) || (NULL==plink_node))
	{
		return RET_ERR;
	}
	
	//结构体数据拷贝
	memcpy( (void*)(&plink_node->data),(void *)(&data),sizeof(data_t));
	
	//移动工作指针到链表尾节点
	while(plink_tmp->next != NULL)
	{
		plink_tmp = plink_tmp->next;
	}
	
	//新节点插入链表尾部
	plink_node->next = NULL;
	plink_tmp->next = plink_node;
	
	return RET_OK;
}

/******************************** 
函数名：list_print
功能:打印链表数据
参数：plink_node链表头
返回值：void
**********************************/
void list_print(plink plink_head)
{
	plink plink_tmp ;//定义一个工作节点

	if(plink_head == NULL)
	{
		return;
	}
	
	plink_tmp = plink_head->next;
	
	//遍历链表打印
	while(plink_tmp != NULL)
	{
		print_data(plink_tmp->data);
		plink_tmp = plink_tmp->next;
	}
}


/******************************** 
函数名：print_data
功能:打印数据
参数：data,要打印的数据
返回值：void
**********************************/
void print_data(data_t data)
{
	CONSOLE_MSG("姓名：%s\n",data.name);
	CONSOLE_MSG("性别：");
	if(data.sex == 'f')
	{
		CONSOLE_MSG("女\n");
	}
	else
	{
		CONSOLE_MSG("男\n");
	}
	CONSOLE_MSG("电话号码：%s\n\n",data.number);
}

/******************************** 
函数名：list_serch
功能  :查找数据 
参数：plink_node链表头，data:要查找的数据
返回值：void
**********************************/
void list_serch(plink plink_head,data_t data)
{
	plink plink_tmp ; //定义一个工作指针
	if(plink_head == NULL)
	{
		CONSOLE_MSG("\n未找到此人\n");
		return;
	}
	plink_tmp = plink_head->next;
	
	//按名字查找
	if(data.sex == 1)
	{
		while(plink_tmp != NULL)
		{
			if(strcmp(data.name,plink_tmp->data.name) == 0)
			{
				print_data(plink_tmp->data);
				return;
			}
			plink_tmp = plink_tmp->next;
		}
		CONSOLE_MSG("\n未找到此人\n");
	}
	else if(data.sex == 2)	//按电话号码查找
	{
		while(plink_tmp != NULL)
		{
			if( strcmp(data.number,plink_tmp->data.number) == 0)
			{
				print_data(plink_tmp->data);
				return;
			}
			plink_tmp = plink_tmp->next;
		}
		CONSOLE_MSG("\n未找到此人\n");
	}
}


/******************************** 
函数名：list_delete
功能: 删除链表中的数据
参数：plink_node链表头，data:删除的数据
返回值：void
**********************************/
void list_delete(plink plink_head,data_t data)
{
	plink plink_tmp,plink_tmp2 ; //定义二个工作指针
	if(plink_head == NULL)
	{
		CONSOLE_MSG("\n未找到此人\n");
		return;
	}
	plink_tmp = plink_head->next;
	plink_tmp2 = plink_head;
	
	//按名字删除
	if(data.sex == 1)
	{
		while(plink_tmp != NULL)
		{
			if(strcmp(data.name,plink_tmp->data.name) == 0)
			{
				//删除该联系人
				plink_tmp2->next  = plink_tmp->next;
				free(plink_tmp);
				plink_tmp = NULL;
				return;
			}
			plink_tmp2 = plink_tmp;
			plink_tmp = plink_tmp->next;
		}
		CONSOLE_MSG("\n未找到此人\n");
	}
	else if(data.sex == 2) //按电话号码查找
	{
		while(plink_tmp != NULL)
		{
			if( strcmp(data.number,plink_tmp->data.number) ==0)
			{
				plink_tmp2->next = plink_tmp->next;
				free(plink_tmp);
				plink_tmp = NULL;
				return;
			}
			plink_tmp2 = plink_tmp;
			plink_tmp = plink_tmp->next;
		}
		CONSOLE_MSG("\n未找到此人\n");
	}
}








