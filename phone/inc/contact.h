/*********************************************************
 * ** 文件名:  contact.h
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
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include "list.h"


void contact_delete(plink plink_head);				// 删除一个联系人
void contact_add(plink plink_head);					//添加一个联系人
void contact_print(plink plink_head);				//打印所有联系人
void contact_serch(plink plink_head);				//查找一个联系人		
void contact_destroy(plink plink_head);				//删除全部联系人	
void contact_man_print(plink plink_head);			//打印所有男性联系人
void contact_female_print(plink plink_head);		//打印所有女性联系人
void contact_serch_name(plink plink_head);			//按照名字查找联系人
void contact_serch_number(plink plink_head);		//按照电话号码查找联系人
void contact_delete_number(plink plink_head);		//按照电话号码删除联系人
void contact_delete_name(plink plink_head);			//按照名字删除联系人
void contact_write(plink plink_head);
void contact_read(plink plink_head);
#endif
