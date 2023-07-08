// main.cpp
#include "class.h"
#include "func.h"
int main() {
    string id;
    int user_num;
    // 打印主菜单
    print_menu();
    while (cin >> user_num) {
        // 添加
        if (user_num == 1) {
            // 打印二级菜单
            print_add_tip();
            add_info();
        }
        // 修改
        else if (user_num == 2) {
            // 读取id
            read_id_from_user(id);
            modify_info(id);
        }
        // 删除
        else if (user_num == 3) {
            read_id_from_user(id);
            del_info(id);
        }
        // 查找
        else if (user_num == 4) {
            read_id_from_user(id);
            search_info(id);
        }
        // 写入文件
        else if (user_num == 5) {
            write_to_file();
        }
        // 退出系统
        else if (user_num == 0) {
            // 确认
            if (exit_comfirm())
                break;
        }
        print_menu();
    }
    // 释放指针指向的空间。
    for (auto [x, y] : table)
        delete y;
    return 0;
}
