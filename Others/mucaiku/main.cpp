#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <thread>

using namespace std;

class Board
{
    public:
        
        string kind;
        double len;
        double wid;

        Board(const string& _kind) : kind(_kind), len(0.0), wid(0.0) {}

         //增添，修改木材种类和尺寸
        void set_kind(string Kind)
        {
            kind = Kind;
        }
        void set_len(double Len)
        {
            len = Len;
        }
        void set_wid(double Wid)
        {
            wid = Wid;
        }
};

// 创建等待函数
void Wait(int time)
{
    chrono::seconds duration(time);
    this_thread::sleep_for(duration);
}

// 创建输入(验证)函数
double Input_Double()
{
    double value;
    while (!(cin >> value)) {
        cout << "输入无效，请重新输入数字：" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}


// 查询木材信息
void Query(const vector<Board> boards, bool show_header) 
{
    if (show_header)
    {
        cout << "-----------查询木材信息-----------" << endl;
    }
    if (boards.size() != 0)
    {
        for (int i = 0; i < boards.size(); i++)
        {
            cout << i+1 << "号 "<< boards[i].kind << "的长是:" << boards[i].len << " 宽是:" << boards[i].wid << endl;
        }
        if (show_header)
        {
            Wait(2);
        }
    }
    else 
    {
        cout << "当前不存在木材，请先添加木材！" << endl;
    }
    if (show_header)
    {
        cout << "即将返回主菜单..." << endl;
        Wait(1);
    }
}

// 添加木材
void Add(vector<Board>& boards)
{
    cout << "-----------添加木材-----------" << endl;
    cout << "请输入添加木材的种类：" << endl;
    string kind;
    cin >> kind;
    boards.push_back(Board(kind));

    int n = boards.size() - 1;

    cout << "请输入添加木材的长：" << endl;
    double len = Input_Double();
    boards[n].set_len(len);

    cout << "请输入添加木材的宽：" << endl;
    double wid = Input_Double();
    boards[n].set_wid(wid);
    cout << "添加成功！" << endl;
    Wait(0.5);
    cout << "即将返回主菜单..." << endl;
    Wait(1);
}

// 修改木材
void Set(vector<Board>& boards)
{
    begin:
    cout << "-----------修改木材-----------" << endl;
    if (boards.size() != 0)
    {
        Query(boards, false);
        cout << "请输入想修改木材的编号：" << endl;
        int n;
        while (!(cin >> n) || n > boards.size())
        {
        cout << "输入无效，请重新输入数字：" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (true)
        {
            cout << "-----------修改木材-----------" << endl;
            cout << "您要修改的木材是：" << boards[n-1].kind << endl;
            cout << "修改木材类型\t\t[输入1]" << endl;
            cout << "修改木材长\t\t[输入2]" << endl;
            cout << "修改木材宽\t\t[输入3]" << endl;
            cout << "结束修改\t\t[输入4]" << endl;
            cout << "返回上一步\t\t[输入5]" << endl;
            int keyboard_input;
            cin >> keyboard_input;
            if (keyboard_input == 1)
            {
                cout << "请输入木材类型：" << endl;
                string kind;
                cin >> kind;
                boards[n-1].set_kind(kind);
                cout << "修改成功！" << endl;
                Wait(1);
            }
            else if (keyboard_input == 2)
            {
                cout << "请输入木材长：" << endl;
                double len = Input_Double();
                boards[n-1].set_len(len);
                cout << "修改成功！" << endl;
                Wait(1);
            }
            else if (keyboard_input == 3)
            {
                cout << "请输入木材宽：" << endl;
                double wid = Input_Double();
                boards[n-1].set_wid(wid);
                cout << "修改成功！" << endl;
                Wait(1);
            }
            else if (keyboard_input == 4)
            {
                break;
            }
            else if (keyboard_input == 5)
            {
                goto begin;
            }
            else
            {
                cout << "输入错误，请重新输入!" << endl;
                Wait(1);
            }
        }
    }
    else 
    {
        cout << "当前不存在木材，请先添加木材！" << endl;
    }
    cout << "即将返回主菜单..." << endl;
    Wait(2);
}

// 删除木材
void Del(vector<Board>& boards)
{
    cout << "-----------删除木材-----------" << endl;
    if (boards.size() != 0)
    {
        Query(boards, false);
        cout << "请输入想删除木材的编号：" << endl;
        int n;
        while (!(cin >> n) || n > boards.size())
        {
        cout << "输入无效，请重新输入数字：" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        vector<Board>::iterator it = boards.begin() + n - 1;
        boards.erase(it);
        cout << "删除成功！" << endl;
        Wait(1);
    }
    else 
    {
        cout << "当前不存在木材，请先添加木材！" << endl;
    }
    cout << "即将返回主菜单..." << endl;
    Wait(2);
}

int main()
{
    vector<Board> boards;
    while (true)
    {
        cout << "-------------主菜单-------------" << endl;
        cout << "欢迎来到简易木材库管理系统。请选择操作：" << endl;
        cout << "查询木材信息\t\t[输入1]" << endl;
        cout << "添加木材\t\t[输入2]" << endl;
        cout << "修改木材\t\t[输入3]" << endl;
        cout << "删除木材\t\t[输入4]" << endl;
        cout << "退出\t\t\t[输入5]" << endl;
        
        int keyboard_input;
        cin >> keyboard_input;
        if (keyboard_input == 1)
        {
            Query(boards,true);
            continue;
        }
        else if (keyboard_input == 2)
        {
            Add(boards);
            continue;
        }
        else if (keyboard_input == 3)
        {
            Set(boards);
            continue;
        }
        else if (keyboard_input == 4)
        {
            Del(boards);
            continue;
        }
        else if (keyboard_input == 5)
        {
            cout << "退出程序" << endl;
            break;
        }
        else
        {
            cout << "输入错误，请重新输入!" << endl;
            Wait(1);
        }
    }
    return 0;
}