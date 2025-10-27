// 给出一个百分制的成绩，要求输出成绩等级‘A'，‘B'，’C'，‘D'，’E‘。90分以上为'A’，80~89分为‘B’，70~79分为'C‘，60~69分为’D‘，60 分以下为'E’。
#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "请输入成绩：";
    cin >> score;
    char grade;
    if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'E';

    cout << "成绩等级为：" << grade << endl;
    return 0;
}