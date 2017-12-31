/*********************************************************
 * ** 文件名: 程序入口 main.c
 * ** Copyright (c) 2017 xiethon@126.com
 *
 * ** 创建人: xiethon
 * ** 日  期: 2017-12-13
 * ** 描  述: 程序入口
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
#include"../inc/console.h"
#include"../inc/list.h"
#include"../inc/contact.h"

#define N 128
void menu_print();

/******************************** 
函数名：list_print
功能:打印链表数据
参数：plink_node链表头
返回值：void
**********************************/
int main(int argc, const char *argv[])
{
	int cmd = -1;
	char *p = (char *)malloc(sizeof(char)*N); //存放输入的数据
	contact data[] = {"zhangsan",'f',"6620110","lisi",'m',"6620111"};	//预存数据
	
	//创建一个头节点
	plink plink_head = list_create();
	if(plink_head == NULL)
	{
		DEBUG("list create failed!\n");
		exit(0);
	}
	
//	contact_read(plink_head); //从文件中读取结构体数据
		
#if 1	
	//把数组预存数据加载到链表
	list_add_head(plink_head,data[0]); //头插
	list_add_tail(plink_head,data[1]); //尾插
	contact_write(plink_head);
#endif 

#if 1
	while(cmd != 0)
	{
		menu_print();
		scanf("%s",p);
		getchar();
		if(p[1] == '\0')
		{
			cmd =p[0] - 48;
		}
		else
		{
			cmd = -1;
		}
		switch(cmd)
		{
			case 1:contact_print(plink_head);		break;	//打印所有联系人
			case 2:contact_add(plink_head);			break;  //添加一个新的联系人
			case 3:contact_delete(plink_head); 		break;  //删除一个联系人
			case 4:contact_serch(plink_head);		break;  //查找一个联系人
			case 5:contact_destroy(plink_head);		break;  //删除全部联系人
			case 6:contact_man_print(plink_head);	break;  //打印所有男性联系人
			case 7:contact_female_print(plink_head);break;  //打印所有女性联系人
			case 0:{ 
				   		system("clear");
						contact_write(plink_head);
						contact_destroy(plink_head);						
					  	exit(0); 						
						break;
				   }
			default:{
						system("clear");
						CONSOLE_MSG("输入有误!\n");
				   		break;
					}
		}
		CONSOLE_MSG("按回车键继续...");
		gets(p);
	}
	contact_write(plink_head);
	contact_destroy(plink_head);
#endif
	return 0;
}

/******************************** 
函数名：menu_print 
功能：打印主菜单 
参数：void 
返回值：void 
**********************************/
void menu_print(void)
{
	system("clear");
	CONSOLE_MSG("--------------------------\n");
	CONSOLE_MSG("欢迎使用简易通讯录\n");
	CONSOLE_MSG("--------------------------\n");
	CONSOLE_MSG("1:输出全部联系人\n");
	CONSOLE_MSG("2:插入新的联系人\n");
	CONSOLE_MSG("3:删除一个联系人\n");
	CONSOLE_MSG("4:查找某个联系人\n");
	CONSOLE_MSG("5:清空全部联系人\n");
	CONSOLE_MSG("6:筛选所有男姓联系人\n");
	CONSOLE_MSG("7:筛选所有女姓联系人\n");
	CONSOLE_MSG("0:退出\n\n");
	CONSOLE_MSG("\n请选择要执行的操作:");
}


