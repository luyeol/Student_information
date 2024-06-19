#include<iostream>
#include<string>
#include "Control_CSV.h"
#include "EveryTime_Grade.h"
using namespace std;

#define GradeCOL 12
#define FirstGradeCOL 4

//해당 학기 성적 입력
double Grade::SemGrade()
{
    int SubjectCnt;
    int SumCredit = 0;
    cout << "수강 과목 수 입력: ";
    cin >> SubjectCnt;
    double AllSub_sum = 0;   //모든 과목의 credit * grade 합
    for (int i = 0; i < SubjectCnt; i++)
    {
        int credit;
        double grade;
        cout << "학점 입력(1 ~ 3): ";
        cin >> credit;
        SumCredit += credit;
        cout << "성적 입력(0.5 ~ 4.5): ";
        cin >> grade;

        if (((int)(grade * 10) % 5) == 0 && grade <= 4.5 && grade >= 0.0 && credit <= 3 && credit >= 1)
        {
            AllSub_sum += credit * grade;
        }
        else
        {
            i--;
            cout << "올바른 입력이 아닙니다." << endl;
        }
    }
    return AllSub_sum / SumCredit;
}

double Grade::ConvertTatalGrade()   //총 성적 환산
{
    double Grade_sum = 0;   //성적합
    int sem_cnt = 0;   //입력한 과목 수
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
void Grade::Cal()   //성적계산기
{
    //수강 학기 선택
    CheckGrade();
    int semester;
    do
    { 
        if (CSV::returnToCSV(row, GradeCOL) == "null")
        {
            cout << "수정할 성적이 없습니다." << endl;
            return;
        }
        cout << "성적을 수정할 학기(그만입력: 0): ";
        cin >> semester;
        if (semester == 0) {
            system("cls");
            break;
        }

        if (semester <= 8 && semester >= 1)
        {
            if (CSV::returnToCSV(row, semester + FirstGradeCOL - 1) != "null")
            {
                //학기별 성적 입력
                CSV::writeToCSV(row, semester + (FirstGradeCOL - 1), to_string(SemGrade()));
                CSV::writeToCSV(row, GradeCOL, to_string(ConvertTatalGrade()));
            }
            else
            {
                system("cls");
                cout << "수정할 성적이 없습니다." << endl;
                semester = 0;
            }
        }
        else
            cout << "1 ~ 8사이 숫자를 입력하세요." << endl;
    } while (semester != 0);
}
void Grade::Cal(int input)   //성적계산기
{
    system("cls");
    //수강 학기 선택
    int semester;
    while(true)
    {
        cout << "성적을 입력할 학기(그만입력: 0): ";
        cin >> semester;
        if (semester == 0) {
            system("cls");
            break;
        }
            
        if (semester <= 8 && semester >= 1)
        {
            if (CSV::returnToCSV(row, semester + FirstGradeCOL - 1) == "null")
            {
                //학기별 성적 입력
                CSV::writeToCSV(row, semester + (FirstGradeCOL - 1), to_string(SemGrade()));
                CSV::writeToCSV(row, GradeCOL, to_string(ConvertTatalGrade()));
            }
            else {
                system("cls");
                cout << "이미 성적을 입력하셨습니다." << endl;
            }
        }
        else if (semester > 8 && semester < 1)
            cout << "1 ~ 8사이 숫자를 입력하세요." << endl;
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
            cout << i - (FirstGradeCOL - 1) << "학기 학점: " << CSV::returnToCSV(row, i) << endl;
        else
            continue;
    }
    if (CSV::returnToCSV(row, GradeCOL) == "null")
        cout << "성적이 입력되지 않았습니다." << endl;
    else
        cout << "종합학점: " << CSV::returnToCSV(row, GradeCOL) << endl;
}
void Grade::grade()
{
    
    int input;
    do
    {
        cout << "성적을 선택하셨습니다." << endl;
        cout << "1. 조회" << endl << "2. 입력" << endl << "3. 수정" << endl << "4. 종료" << endl << ">> ";
        cin >> input;

        if (input == 4) {
            system("cls");
            break;
        }            
        else if (input == 1)   //조회
            CheckGrade();
        else if (input == 2)   //성적 입력
            Cal(input);
        else if (input == 3)   //성적 조회
            Cal();
        else
            cout << "잘못된 입력" << endl;
    } while (input != 4);
}