#include <iostream>

// 定义日期结构体
struct Date
{
    int year;
    int month;
    int day;
};

// 判断是否为闰年
bool isrunyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算该日在本年中是第几天
int getDayOfYear(Date date)
{
    // 存储非闰年每个月的天数
    // daysInMonth[0]不用，让月份和索引对应
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int totalDays = 0;

    // 4. 累加前几个月的天数
    for (int i = 1; i < date.month; ++i)
    {
        totalDays += daysInMonth[i];
    }

    // 加上当月的天数
    totalDays += date.day;

    // 如果是闰年且月份在2月之后，总天数加1
    if (isrunyear(date.year) && date.month > 2)
    {
        totalDays++;
    }

    return totalDays;
}

int main()
{
    Date inputDate;

    std::cout << "请输入年份: ";
    std::cin >> inputDate.year;
    std::cout << "请输入月份: ";
    std::cin >> inputDate.month;
    std::cout << "请输入日期: ";
    std::cin >> inputDate.day;

    // 调用函数计算
    int dayNumber = getDayOfYear(inputDate);

    std::cout << inputDate.year << "年" << inputDate.month << "月" << inputDate.day << "日是这一年的第 "
              << dayNumber << " 天。" << std::endl;

    return 0;
}