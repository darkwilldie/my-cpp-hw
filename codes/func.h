// func.h
#include "class.h"
#ifndef FUNC_H
#define FUNC_H
// 从键盘读入用户输入的id
void read_id_from_user(string &id);
// 打印文件的全部内容
void print_file(string const &file_name);
// 打印主菜单
void print_menu();
// 打印添加信息前的提示文字
void print_add_tip();
// 添加
void add_info();
// 修改
void modify_info(string const &info_id);
// 删除
void del_info(string const &info_id);
// 查询
void search_info(string const &info_id);
// 写入文件
void write_to_file();
// 退出确认
bool exit_comfirm();
#endif
