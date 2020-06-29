#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;


// ʹ��string��ʾ�ַ�������������C����ַ���
struct stuData {
public:
    int		id; //ȱ����Ϣ��ID����1��ʼ����

    string	student_name; // ȱ��ѧ����
    string 	date; // ȱ������
    string	class_name; // ȱ�ογ���
    string  message; // ȱ����Ϣ��ע
    // ����Ϊ��ʵ��list��removeɾ������������ģ�����һ��==�����
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