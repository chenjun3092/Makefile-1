/*********************************************************
 * ** 文件名:list.h
 * ** Copyright (c) 2017 xiethon@126.com
 *
 * ** 创建人: xiethon
 * ** 日  期: 2017-12-13
 * ** 描  述: 双向链表相关操作头文件
 * ** 版  本: V1.0
 *
 * ** 修改人:
 * ** 日  期:
 * ** 修改描述:
 * ** 版  本:
 *
 * ****************************************************/
#ifndef __LIST_H__
#define __LIST_H__

#define RET_OK 1		 //函数返回值
#define RET_ERR 0

#define NAME_MAX_LEN 20 //名字最大长度
#define NUMBER_MAX_LEN 20

typedef struct _contact 
{
	char name[NAME_MAX_LEN];		//姓名
	char sex;						//性别
	char number[NUMBER_MAX_LEN];				//电话号码
}contact,*pcontact;

typedef contact data_t;	//链表数据类型定义
typedef struct _link
{
	data_t data;
	struct _link *next;
}link,*plink;


/******************************** 
函数名：list_create
功能：创建一个空链表
参数：无
返回值：成功返回链表头，失败返回NULL.
**********************************/
extern plink list_create();	


/******************************** 
函数名：list_add_tail
功能：向链表尾部添加一个数据
参数：plink_head:链表头指针,data:添加的数据
返回值：成功返回0，失败返回1.
**********************************/
extern int list_add_tail(plink plink_head,data_t data);//链表尾插入一个元素


/******************************** 
函数名：list_add_head
功能：向链表头部添加一个数据
参数：plink_head:链表头，data:插入的数据
返回值：成功返回:RET_OK，失败返回:RET_ERR
**********************************/
extern int list_add_head(plink plink_head,data_t data);

/******************************** 
函数名：list_print
功能：打印链表数据
参数：plink_head:链表头
返回值：void
**********************************/
extern void list_print(plink plink_head); 

/******************************** 
函数名：list_serch
功能：向链表中查找一个数据
参数：plink_head:链表头，data_t:插入的数据
返回值：成功返回:RET_OK，失败返回:RET_ERR
**********************************/
extern void list_serch(plink plink_head,data_t data); //


/******************************** 
函数名：list_destroy
功能：销毁链表
参数：plink_head:链表头
返回值：成功返回RET_OK，失败返回:RET_ERR
**********************************/
extern int list_destroy(plink plink_head);


/******************************** 
函数名：list_delete
功能：删除链表中的数据
参数：plink_head:链表头，data:要销毁的数据
返回值：成功返回RET_OK，失败返回:RET_ERR
**********************************/
extern void list_delete(plink plink_head,data_t data);


/******************************** 
函数名：print_data
功能：打印数据
参数：data:需要打印的数据
返回值：void 
**********************************/
extern void print_data(data_t data);



#endif
