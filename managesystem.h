#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;


// 使用string表示字符串，彻底摒弃C风格字符串
struct stuData {
public:
    int		id; //缺课信息的ID，从1开始递增

    string	student_name; // 缺课学生名
    string 	date; // 缺课日期
    string	class_name; // 缺课课程名
    string  message; // 缺课信息备注
    // 这是为了实现list的remove删除操作所必需的：重载一个==运算符
    bool operator==(const stuData& other) const {
        if (this == &other)
            return true;
        return !(this->id != other.id || this->class_name != other.class_name || this->date != other.date ||
                 this->student_name != other.student_name || this->message != other.message);
    }
};

class StuManSystem
{
public:
    StuManSystem();
    ~StuManSystem() = default;
    void loadData();
    void saveData();
    void start();
    void inputData();
    void changeData();
    void removeData();

    void showAllData();
    list<stuData> findData();
    list<stuData>::iterator findDataById(int id);
private:
    list<stuData> stuDataLists;
    string FileName;
};