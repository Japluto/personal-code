#include <iostream>
#include <vector>
#include <numeric> // std::iota

// 作业第一道题为约瑟夫问题的变种
// n: 总人数
// m: 报到m的人出局 (本题中是3)
int josephus(int n, int m)
{
    if (n <= 0 || m <= 0)
    {
        return -1; // 输入无效
    }

    // 创建一个从1到n的列表
    std::vector<int> people(n);
    std::iota(people.begin(), people.end(), 1); // 使用iota快速填充1, 2, ..., n

    int index = 0; // 当前报数人的索引
    int count = 1; // 报数计数器

    while (people.size() > 1)
    {
        // 如果报数到了 m
        if (count == m)
        {
            // 从列表中移除这个人
            people.erase(people.begin() + index);
            // 重置计数器
            count = 1;
            // 因为删除了一个元素，下一个报数的人就是当前索引的元素，所以index不需要增加
            // 但需要处理索引越界的情况
            if (index >= people.size() && !people.empty())
            {
                index = 0;
            }
        }
        else
        {
            // 移动到下一个人
            index++;
            count++;
            // 如果索引到达末尾，回到开头形成环
            if (index >= people.size())
            {
                index = 0;
            }
        }
    }

    // 返回最后剩下的人的编号
    return people[0];
}

int main()
{
    int n;
    std::cout << "请输入总人数 n: ";
    std::cin >> n;

    int last_person_number = josephus(n, 3);

    if (last_person_number != -1)
    {
        std::cout << "最后留下的人原来排在第 " << last_person_number << " 号。" << std::endl;
    }
    else
    {
        std::cout << "输入的人数无效。" << std::endl;
    }

    return 0;
}