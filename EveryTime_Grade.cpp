#include<iostream>
#include<string>
#include "Control_CSV.h"
#include "EveryTime_Grade.h"
using namespace std;

#define GradeCOL 12
#define FirstGradeCOL 4

//�ش� �б� ���� �Է�
double Grade::SemGrade()
{
    int SubjectCnt;
    int SumCredit = 0;
    cout << "���� ���� �� �Է�: ";
    cin >> SubjectCnt;
    double AllSub_sum = 0;   //��� ������ credit * grade ��
    for (int i = 0; i < SubjectCnt; i++)
    {
        int credit;
        double grade;
        cout << "���� �Է�(1 ~ 3): ";
        cin >> credit;
        SumCredit += credit;
        cout << "���� �Է�(0.5 ~ 4.5): ";
        cin >> grade;

        if (((int)(grade * 10) % 5) == 0 && grade <= 4.5 && grade >= 0.0 && credit <= 3 && credit >= 1)
        {
            AllSub_sum += credit * grade;
        }
        else
        {
            i--;
            cout << "�ùٸ� �Է��� �ƴմϴ�." << endl;
        }
    }
    return AllSub_sum / SumCredit;
}

double Grade::ConvertTatalGrade()   //�� ���� ȯ��
{
    double Grade_sum = 0;   //������
    int sem_cnt = 0;   //�Է��� ���� ��
    for (int i = FirstGradeCOL; i < GradeCOL; i++)
    {
        string sem_grade = CSV::returnToCSV(row, i);
        if (sem_grade != "null")
        {
            Grade_sum += stod(sem_grade);
            sem_cnt++;
        }
    }
    return Grade_sum / sem_cnt;
}
void Grade::Cal()   //��������
{
    //���� �б� ����
    CheckGrade();
    int semester;
    do
    { 
        if (CSV::returnToCSV(row, GradeCOL) == "null")
        {
            cout << "������ ������ �����ϴ�." << endl;
            return;
        }
        cout << "������ ������ �б�(�׸��Է�: 0): ";
        cin >> semester;
        if (semester == 0) {
            system("cls");
            break;
        }

        if (semester <= 8 && semester >= 1)
        {
            if (CSV::returnToCSV(row, semester + FirstGradeCOL - 1) != "null")
            {
                //�б⺰ ���� �Է�
                CSV::writeToCSV(row, semester + (FirstGradeCOL - 1), to_string(SemGrade()));
                CSV::writeToCSV(row, GradeCOL, to_string(ConvertTatalGrade()));
            }
            else
            {
                system("cls");
                cout << "������ ������ �����ϴ�." << endl;
                semester = 0;
            }
        }
        else
            cout << "1 ~ 8���� ���ڸ� �Է��ϼ���." << endl;
    } while (semester != 0);
}
void Grade::Cal(int input)   //��������
{
    system("cls");
    //���� �б� ����
    int semester;
    while(true)
    {
        cout << "������ �Է��� �б�(�׸��Է�: 0): ";
        cin >> semester;
        if (semester == 0) {
            system("cls");
            break;
        }
            
        if (semester <= 8 && semester >= 1)
        {
            if (CSV::returnToCSV(row, semester + FirstGradeCOL - 1) == "null")
            {
                //�б⺰ ���� �Է�
                CSV::writeToCSV(row, semester + (FirstGradeCOL - 1), to_string(SemGrade()));
                CSV::writeToCSV(row, GradeCOL, to_string(ConvertTatalGrade()));
            }
            else {
                system("cls");
                cout << "�̹� ������ �Է��ϼ̽��ϴ�." << endl;
            }
        }
        else if (semester > 8 && semester < 1)
            cout << "1 ~ 8���� ���ڸ� �Է��ϼ���." << endl;
        else
        {
            break;
            semester = 0;
        }
    }  
}
void Grade::CheckGrade()
{
    system("cls");
    for (int i = FirstGradeCOL; i < GradeCOL; i++)
    {
        if (CSV::returnToCSV(row, i) != "null")
            cout << i - (FirstGradeCOL - 1) << "�б� ����: " << CSV::returnToCSV(row, i) << endl;
        else
            continue;
    }
    if (CSV::returnToCSV(row, GradeCOL) == "null")
        cout << "������ �Էµ��� �ʾҽ��ϴ�." << endl;
    else
        cout << "��������: " << CSV::returnToCSV(row, GradeCOL) << endl;
}
void Grade::grade()
{
    
    int input;
    do
    {
        cout << "������ �����ϼ̽��ϴ�." << endl;
        cout << "1. ��ȸ" << endl << "2. �Է�" << endl << "3. ����" << endl << "4. ����" << endl << ">> ";
        cin >> input;

        if (input == 4) {
            system("cls");
            break;
        }            
        else if (input == 1)   //��ȸ
            CheckGrade();
        else if (input == 2)   //���� �Է�
            Cal(input);
        else if (input == 3)   //���� ��ȸ
            Cal();
        else
            cout << "�߸��� �Է�" << endl;
    } while (input != 4);
}