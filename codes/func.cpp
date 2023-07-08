#include "func.h"
#include "class.h"
void read_id_from_user(string &id) {
    cout << "\n提示：系统当前仅支持通过id（身份证号）查找\n";
    cout << "请输入id：";
    cin >> id;
}
void print_file(string const &file_name) {
    string s;
    ifstream file(file_name);
    // 逐行读入文件，并输出到标准输入流
    while (getline(file, s)) {
        cout << s << endl;
    }
    file.close();
}
void print_menu() {
    // 打印主菜单
    cout << endl;
    print_file("greet");
    cout << "请输入您的操作编号（如 3），并按下回车键: ";
}
void print_add_tip() {
    cout << endl;
    print_file("type");
    cout << "\n请选择您要添加的学生/教师类型: ";
}
void add_info() {
    int x;
    // 定义一个空的基类指针
    Person *ps = nullptr;
    cin >> x;
    // 根据读入的数字new对应类的对象
    if (x == 1)
        ps = (new UnderGraduate);
    else if (x == 2)
        ps = (new Graduate);
    else if (x == 3)
        ps = (new Teacher);
    else if (x == 4)
        ps = (new TA);
    // 若new成功，则调用输入函数，从键盘读入教师/学生的信息
    // 体现了运行时的多态性
    if (ps != nullptr) {
        ps->inputData();
        cout << "\n信息已更新。\n\n";
    }
}
void modify_info(string const &info_id) {
    // 用哈希表判断id是否存在
    // 其他函数的相同操作不赘述
    if (table.count(info_id)) {
        table[info_id]->inputData();
        cout << "\n信息已更新。\n\n";
    } else {
        cout << "\nid不存在。\n\n";
    }
}
void del_info(string const &info_id) {
    if (table.count(info_id)) {
        string tmp;
        cout << "确定要删除吗？(y/n): ";
        cin >> tmp;
        if (tolower(tmp[0]) == 'y') {
            table.erase(info_id);
        }
        cout << "\n信息已删除。\n\n";
    } else {
        cout << "\nid不存在。\n\n";
    }
}
void search_info(string const &info_id) {
    if (table.count(info_id)) {
        table[info_id]->displayDetails();
        cout << endl;
    } else {
        cout << "\nid不存在。\n\n";
    }
}
void write_to_file() {
    // 将输出重定向到文件information
    freopen("information", "w", stdout);
    // 遍历哈希表，打印每个信息条目
    for (auto [x, y] : table) {
        y->displayDetails();
    }
    // 将输出重定向到标准输出流
    // Windows系统为"CON"
    freopen("/dev/tty", "w", stdout);
    cout << "\n信息已保存。\n\n";
}
bool exit_comfirm() {
    string tmp;
    cout << "确定要退出系统吗？(y/n): ";
    cin >> tmp;
    if (tolower(tmp[0]) == 'y') {
        cout << "\n感谢您的使用，下次再见！\n\n";
        return true;
    }
    return false;
}
