#include "managesystem.h"

int main() {
    StuManSystem system;
    system.start();

    return 0;
}

// �������ʱ���ô�����ݵ��ļ���
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

// ���ȳ��Դ�data.dat�м������ݣ�֮��չʾ�˵�
void StuManSystem::start() {
    loadData();
    int select = 0;
    while (true) {
        //��ӡ����
        cout << ("\n***********ѧ�����ڹ���ϵͳ************\n");
        cout << ("\t1: ���ѧ��ȱ�μ�¼\n");
        cout << ("\t2: ��ѯѧ��ȱ�μ�¼\n");
        cout << ("\t3: �޸�ѧ��ȱ�μ�¼\n");
        cout << ("\t4: ɾ��ѧ��ȱ�μ�¼\n");
        cout << ("\t0: �˳�ϵͳ\n");
        cout << ("��ѡ��(0-5):");
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

// �����б���ȱ����Ϣ��ID������ָ�����ĵ�����retIter�����ڸ�������
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

// �������ʵ�ִӼ���¼��ȱ����Ϣ��data��������data���ļ��Ĺ���
void StuManSystem::inputData() {
    cout << ("\n************¼��ȱ�μ�¼***************\n");
    stuData data;

    cout << "������ȱ������(yyyy-mm-dd):";
    cin >> data.date;

    cout << "������γ���(���ܺ��пո�):";
    cin >> data.class_name;

    cout << "������ѧ����(���ܺ��пո�):";
    cin >> data.student_name;

    cout << "������ȱ����Ϣ(���ܺ��пո�):";
    cin >> data.message;

    stuDataLists.push_back(data);
    stuDataLists.back().id = stuDataLists.size();
    saveData();
}

// ��˳���г�����ѧ���ļ�¼�������¼���Ȼ���޸ļ�¼
void StuManSystem::changeData() {
    list<stuData> lists = findData();
    cout << ("\n************�޸�ȱ�μ�¼**************\n");
    if (lists.size() > 0) {
        cout << "������Ҫ�޸ĵļ�¼���:";
        int order;
        cin >> order;
        cin.get();
        list<stuData>::iterator iter = findDataById(order);
        if (iter != stuDataLists.end()) {
            stuData data = *iter;
            cout << "������ȱ������(yyyy-mm-dd): ";
            cin >>
                data.date;
            cout << "������ѧ������(���ܺ��пո�): ";
            cin >> data.student_name;

            cout << "������γ���(���ܺ��пո�): ";
            cin >>
                data.class_name;

            cout << "������ȱ����Ϣ (���ܺ��пո�): ";
            cin >> data.message;
            *iter = data;
            saveData();
        } else {
            cout << "�������" << endl;
        }
    } else {
        cout << "��δ��ѯ��ȱ�μ�¼��" << endl;
    }
}


// չʾ���м�¼������Ҫɾ���ļ�¼��ţ�����list::removeɾ��֮
void StuManSystem::removeData() {
    list<stuData> lists = findData();
    if (lists.size() > 0) {
        cout << "������Ҫɾ���ļ�¼���:";
        int order;
        cin >> order;
        list<stuData>::iterator iter = findDataById(order);
        if (iter != stuDataLists.end()) {
            stuDataLists.remove(*iter);
            saveData();
        } else {
            cout << "�������" << endl;
        }
    } else {
        cout << "��δ��ѯ��ȱ�μ�¼��" << endl;
    }
}

// ��˳���ӡ���е�ȱ�μ�¼���Ա���lists�ķ�ʽ
void StuManSystem::showAllData() {
    cout << "ѡ���¼������ʽ(1:����¼ID˳�� 2:��ѧ������˳�� 3:��ȱ��ʱ��˳�� 4:���γ�����˳��)�� ";
    int order;
    cin >> order;
    if (order < 1 || order > 4) {
        cout << "����ȷѡ��" << endl;
        return;
    }

    // ��Ϊlist������sort������ͨ��һ��vector�洢��Ϣ���������
    vector<stuData> vec(stuDataLists.begin(), stuDataLists.end());

    // ����ʹ��lambda���ʽ������comp����
    if (order == 1)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.id < s2.id; });
    else if (order == 2)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.student_name < s2.student_name; });
    else if (order == 3)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.date < s2.date; });
    else if (order == 4)
        sort(vec.begin(), vec.end(), [](stuData &s1, stuData &s2) { return s1.class_name < s2.class_name; });

    cout << endl << "*************���е�ȱ�μ�¼���£�************" << endl;

    vector<stuData>::const_iterator constIter = vec.cbegin();
    cout << "*���***����******ѧ����****�γ���****��ע*\n";
    for (; constIter != vec.cend(); constIter++) {
        cout << " " << constIter->id << " \t " << constIter->date << "\t" << constIter->student_name << "\t"
             << constIter->class_name << "\t"
             << constIter->message << endl;
    }
}

// ��������Ϣ������stuDataLists���򣬲����ظ�����ͬʱ��printAllData�Ĺ��ܣ���˳�����������Ϣ
list<stuData> StuManSystem::findData() {

    vector<stuData> vec(stuDataLists.begin(), stuDataLists.end());
    cout << "ѡ���¼������ʽ(1:����¼ID˳�� 2:��ѧ������˳�� 3:��ȱ��ʱ��˳�� 4:���γ�����˳��)�� ";
    int order;
    while (cin >> order && order < 1 || order > 4) {
        cout << "����ȷѡ��!" << endl;
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
    cout << "*���***����******ѧ����****�γ���****��ע*\n";
    for (; iter != vec.end(); iter++) {
        result.push_back(*iter);
        cout << " " << iter->id << " \t " << iter->date << "\t" << iter->student_name << "\t" << iter->class_name
             << "\t"
             << iter->message << endl;
    }

    return result;
}
