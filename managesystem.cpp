#include "managesystem.h"

int main() {
    StuManSystem system;
    system.start();

    return 0;
}

// 构造对象时设置存放数据的文件名
StuManSystem::StuManSystem() {
    FileName = "data.txt";
}

void StuManSystem::loadData() {
    fstream fin(FileName, ios::in);
    if (fin.is_open()) {
        stuData data;
        while (fin.peek() != EOF) {
            fin >> data.id >> data.student_name >> data.date >> data.class_name >> data.message;
            if (fin.eof())
                break;
            stuDataLists.push_back(data);
        }
        fin.close();
    }
}

void StuManSystem::saveData() {
    fstream fout(FileName, ios::out);
    if (fout.is_open()) {
        stuData data;
        list<stuData>::const_iterator iter = stuDataLists.begin();
        for (; iter != stuDataLists.end(); iter++) {
            data = *iter;
            fout << data.id <<" " << data.student_name << " " <<data.date << " " << data.class_name << " " << data.message << endl;
        }
        fout.close();
    }
}

// 首先尝试从data.dat中加载数据，之后展示菜单
void StuManSystem::start() {
    loadData();
    int select = 0;
    while (true) {
        //打印界面
        cout << ("\n***********学生考勤管理系统************\n");
        cout << ("\t1: 添加学生缺课记录\n");
        cout << ("\t2: 查询学生缺课记录\n");
        cout << ("\t3: 修改学生缺课记录\n");
        cout << ("\t4: 删除学生缺课记录\n");
        cout << ("\t0: 退出系统\n");
        cout << ("请选择(0-5):");
        cin >> select;
        cin.get();
        switch (select) {
            case 1:
                inputData();
                break;
            case 2:
                showAllData();
                break;
            case 3:
                changeData();
                break;
            case 4:
                removeData();
                break;
            default:
                exit(EXIT_SUCCESS);
        }
    }
}

// 给出列表中缺课信息的ID，返回指向它的迭代器retIter，属于辅助方法
list<stuData>::iterator StuManSystem::findDataById(int id) {
    list<stuData>::iterator retIter = stuDataLists.end();
    list<stuData>::iterator iter = stuDataLists.begin();
    for (; iter != stuDataLists.end(); iter++) {
        if (id == iter->id) {
            retIter = iter;
            break;
        }
    }

    return retIter;
}

// 这个方法实现从键盘录入缺课信息到data，并保存data到文件的功能
void StuManSystem::inputData() {
    cout << ("\n************录入缺课记录***************\n");
    stuData data;

    cout << "请输入缺课日期(yyyy-mm-dd):";
    cin >> data.date;

    cout << "请输入课程名(不能含有空格):";
    cin >> data.class_name;

    cout << "请输入学生名(不能含有空格):";
    cin >> data.student_name;

    cout << "请输入缺课信息(不能含有空格):";
    cin >> data.message;

    stuDataLists.push_back(data);
    stuDataLists.back().id = stuDataLists.size();
    saveData();
}

// 按顺序列出所有学生的记录，输入记录编号然后修改记录
void StuManSystem::changeData() {
    list<stuData> lists = findData();
    cout << ("\n************修改缺课记录**************\n");
    if (lists.size() > 0) {
        cout << "请输入要修改的记录序号:";
        int order;
        cin >> order;
        cin.get();
        list<stuData>::iterator iter = findDataById(order);
        if (iter != stuDataLists.end()) {
            stuData data = *iter;
            cout << "请输入缺课日期(yyyy-mm-dd): ";
            cin >>
                data.date;
            cout << "请输入学生名称(不能含有空格): ";
            cin >> data.student_name;

            cout << "请输入课程名(不能含有空格): ";
            cin >>
                data.class_name;

            cout << "请输入缺课信息 (不能含有空格): ";
            cin >> data.message;
            *iter = data;
            saveData();
        } else {
            cout << "输入错误！" << endl;
        }
    } else {
        cout << "暂未查询到缺课记录！" << endl;
    }
}


// 展示所有记录，输入要删除的记录序号，调用list::remove删除之
void StuManSystem::removeData() {
    list<stuData> lists = findData();
    if (lists.size() > 0) {
        cout << "请输入要删除的记录序号:";
        int order;
        cin >> order;
        list<stuData>::iterator iter = findDataById(order);
        if (iter != stuDataLists.end()) {
            stuDataLists.remove(*iter);
            saveData();
        } else {
            cout << "输入错误！" << endl;
        }
    } else {
        cout << "暂未查询到缺课记录！" << endl;
    }
}

// 按顺序打印所有的缺课记录，以遍历lists的方式
void StuManSystem::showAllData() {
    cout << "选择记录的排序方式(1:按记录ID顺序 2:按学生名称顺序 3:按缺课时间顺序 4:按课程名称顺序)： ";
    int order;
    cin >> order;
    if (order < 1 || order > 4) {
        cout << "请正确选择" << endl;
        return;
    }

    // 因为list不能用sort，所以通过一个vector存储信息并排序输出
    vector<stuData> vec(stuDataLists.begin(), stuDataLists.end());

    // 下面使用lambda表达式代替了comp函数
    if (order == 1)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.id < s2.id; });
    else if (order == 2)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.student_name < s2.student_name; });
    else if (order == 3)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.date < s2.date; });
    else if (order == 4)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.class_name < s2.class_name; });

    cout << endl << "*************所有的缺课记录如下：************" << endl;

    vector<stuData>::const_iterator constIter = vec.cbegin();
    cout << "*编号***日期******学生名****课程名****备注*\n";
    for (; constIter != vec.cend(); constIter++) {
        cout << " " << constIter->id << " \t " << constIter->date << "\t" << constIter->student_name << "\t"
             << constIter->class_name << "\t"
             << constIter->message << endl;
    }
}

// 将保存信息的链表stuDataLists排序，并返回该链表；同时起到printAllData的功能，按顺序输出所有信息
list<stuData> StuManSystem::findData() {

    vector<stuData> vec(stuDataLists.begin(), stuDataLists.end());
    cout << "选择记录的排序方式(1:按记录ID顺序 2:按学生名称顺序 3:按缺课时间顺序 4:按课程名称顺序)： ";
    int order;
    while (cin >> order && order < 1 || order > 4) {
        cout << "请正确选择!" << endl;
    }
    if (order == 1)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.id < s2.id; });
    else if (order == 2)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.student_name < s2.student_name; });
    else if (order == 3)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.date < s2.date; });
    else if (order == 4)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.class_name < s2.class_name; });

    list<stuData> result;
    vector<stuData>::const_iterator iter = vec.begin();
    cout << "*编号***日期******学生名****课程名****备注*\n";
    for (; iter != vec.end(); iter++) {
        result.push_back(*iter);
        cout << " " << iter->id << " \t " << iter->date << "\t" << iter->student_name << "\t" << iter->class_name
             << "\t"
             << iter->message << endl;
    }

    return result;
}
