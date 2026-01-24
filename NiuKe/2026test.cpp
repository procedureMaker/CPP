// 测试函数是否可以修改全局变量
// 测试结果：
// 修改前：global_num = 10
// 修改前：global_str = 初始值

// 修改后：global_num = 100
// 修改后：global_str = 初始值 - 被函数修改后
#include <iostream>
using namespace std;

// 定义全局变量：所有函数均可访问/修改
int global_num = 10;          // 全局整型变量
string global_str = "初始值"; // 全局字符串变量

// 函数1：修改全局整型变量
void modifyInt()
{
    global_num = 100; // 直接修改全局变量，无需传参
}

// 函数2：修改全局字符串变量，并做拼接操作
void modifyString()
{
    global_str += " - 被函数修改后";
}

int main()
{
    // 修改前的全局变量值
    cout << "修改前：global_num = " << global_num << endl;
    cout << "修改前：global_str = " << global_str << endl;

    // 调用函数修改全局变量
    modifyInt();
    modifyString();

    // 修改后的全局变量值（验证修改生效）
    cout << "\n修改后：global_num = " << global_num << endl;
    cout << "修改后：global_str = " << global_str << endl;

    return 0;
}