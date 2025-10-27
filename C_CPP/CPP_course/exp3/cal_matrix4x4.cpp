#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <vector>

class Matrix_4x4
{
private:
    double matrix[4][4];

public:
    // 默认构造函数：初始化为单位矩阵
    Matrix_4x4()
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                matrix[i][j] = (i == j) ? 1.0 : 0.0; // 对角线为1，其余为0
            }
        }
    }

    // 带参数构造函数，用一个4x4的二维数组初始化
    Matrix_4x4(const double data[4][4])
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                matrix[i][j] = data[i][j];
            }
        }
    }

    // 拷贝构造函数
    Matrix_4x4(const Matrix_4x4 &other)
    {
        for (int i = 0; i < 4; ++i) //  先++i再++j,都把第0项扔掉
        {
            for (int j = 0; j < 4; ++j) //  内层循环遍历矩阵的列
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    // 允许以 matrix[i][j] 的形式对矩阵元素进行非 const 访问
    double *operator[](int i)
    {
        return matrix[i];
    }

    // 允许对矩阵元素进行 const 访问
    const double *operator[](int i) const
    {
        return matrix[i];
    }

    // 将另一个矩阵赋值给当前矩阵
    Matrix_4x4 &operator=(const Matrix_4x4 &other)
    {
        if (this == &other)
        {
            return *this;
        }
        for (int i = 0; i < 4; ++i) // 遍历矩阵的行
        {
            for (int j = 0; j < 4; ++j) // 遍历矩阵的列
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        return *this;
    }

    // 使用高斯消去法计算行列式
    double determinant() const // 返回一个double类型的行列式值，如果是奇异矩阵那么返回0.0
    {
        Matrix_4x4 temp = *this;
        double det = 1.0; // 初始化行列式值为1.0 （单位阵）

        for (int i = 0; i < 4; ++i)
        {
            // 为当前列寻找主元，也就是绝对值最大的
            int zhuyuan = i;
            for (int j = i + 1; j < 4; ++j)
            {
                if (std::abs(temp[j][i]) > std::abs(temp[zhuyuan][i])) // 固定列，变行值，取绝对值进行比较，std::abs()
                {
                    zhuyuan = j;
                }
            }

            if (zhuyuan != i)
            {
                for (int k = 0; k < 4; ++k) // 交换两行
                {
                    std::swap(temp[i][k], temp[zhuyuan][k]); // 偷懒用个交换模板
                }
                det *= -1.0; // 行交换使行列式变号
            }

            if (std::abs(temp[i][i]) < 1e-9) // 如果存在某一个主元接近0，说明矩阵是奇异的，行列式为0（double 0.0）
            {
                return 0.0; // 矩阵为奇异矩阵
            }

            // 纠结了一下，感觉这里直接乘主元就行，因为消元步骤本质是为了帮助后续的操作，也就是求下一个主元
            det *= temp[i][i]; // 行列式是上三角矩阵对角线元素的乘积

            for (int j = i + 1; j < 4; ++j) // 对当前行下方的所有行进行消元操作, 把下面行的当前列元素均变成0，目标是为了获得上三角矩阵
            {
                double factor = temp[j][i] / temp[i][i]; // 计算消元因子
                for (int k = i; k < 4; ++k)
                {
                    temp[j][k] -= factor * temp[i][k];
                }
            }
        }
        return det; // 返回计算得到的行列式值
    }

    // 返回矩阵的转置
    Matrix_4x4 transpose() const
    {
        Matrix_4x4 trans;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                trans.matrix[i][j] = matrix[j][i]; // 转置赋值，对称的把矩阵内元素赋过去
            }
        }
        return trans;
    }

    // 使用高斯-若尔消元法返回矩阵的逆
    Matrix_4x4 inverse() const
    {
        if (std::abs(this->determinant()) < 1e-9) // 验证一下行列式是不是非零，如果是零，说明矩阵是奇异的，无法求逆
        {
            throw std::runtime_error("矩阵是奇异的，无法求逆"); // 抛出异常终止
        }

        Matrix_4x4 temp = *this; // 创建当前矩阵的副本和初始为单位矩阵的逆矩阵
        Matrix_4x4 inv;          // 初始为单位矩阵

        for (int i = 0; i < 4; ++i) // 使用高斯-约当消元法计算逆矩阵
        {
            int zhuyuan = i;
            for (int j = i + 1; j < 4; ++j)
            {
                if (std::abs(temp[j][i]) > std::abs(temp[zhuyuan][i]))
                {
                    zhuyuan = j;
                }
            }
            for (int k = 0; k < 4; k++) // 交换当前行和主元所在行，在原始矩阵和逆矩阵中同时进行
            {
                std::swap(temp[i][k], temp[zhuyuan][k]);
                std::swap(inv[i][k], inv[zhuyuan][k]);
            }

            double div = temp[i][i];
            for (int k = 0; k < 4; ++k)
            {
                temp[i][k] /= div;
                inv[i][k] /= div;
            }

            for (int j = 0; j < 4; ++j) // 遍历每一列，执行高斯消元法
            {
                if (i != j) // 如果不是主对角线元素，则执行消元操作
                {
                    double mult = temp[j][i]; // 计算需要消去的倍数
                    for (int k = 0; k < 4; ++k)
                    {
                        temp[j][k] -= mult * temp[i][k];
                        inv[j][k] -= mult * inv[i][k];
                    }
                }
            }
        }
        return inv; // 返回计算得到的逆矩阵
    }
};

// 重载 + 实现矩阵加法
Matrix_4x4 operator+(const Matrix_4x4 &a, const Matrix_4x4 &b)
{
    Matrix_4x4 result;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

// 重载 - 实现矩阵减法
Matrix_4x4 operator-(const Matrix_4x4 &a, const Matrix_4x4 &b)
{
    Matrix_4x4 result;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

// 重载 * 实现矩阵乘法
Matrix_4x4 operator*(const Matrix_4x4 &a, const Matrix_4x4 &b)
{
    Matrix_4x4 result; // 定义一个4x4的矩阵用于存储结果
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < 4; ++k)
            {
                result[i][j] += a[i][k] * b[k][j]; // 行与对应列的元素相乘后累加
            }
        }
    }
    return result;
}

// 重载 ^ 实现矩阵幂运算
Matrix_4x4 operator^(const Matrix_4x4 &a, int exp) // 计算4x4矩阵的幂运算，支持正整数幂和零次幂（返回单位矩阵），对于负指数则先计算矩阵的逆矩阵再进行正指数幂运算。
{
    if (exp == 0)
    {
        return Matrix_4x4(); // 返回单位矩阵
    }
    if (exp < 0)
    {
        return a.inverse() ^ (-exp);
    }

    Matrix_4x4 result = a;
    for (int i = 1; i < exp; ++i)
    {
        result = result * a;
    }
    return result;
}

// 重载 << 实现格式化输出
std::ostream &operator<<(std::ostream &os, const Matrix_4x4 &mat)
{
    os << std::fixed << std::setprecision(1);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            double val = mat[i][j];
            if (std::abs(val) < 1e-9)
            {
                val = 0.0; // 将非常接近0的值显示为0.0
            }
            os << std::setw(10) << val;
        }
        os << std::endl;
    }
    return os;
}

// 重载 >> 实现矩阵输入
std::istream &operator>>(std::istream &is, Matrix_4x4 &mat)
{
    std::cout << "请输入一个4x4矩阵的16个值：" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            is >> mat[i][j];
        }
    }
    return is;
}

int main()
{
    double m[4][4] = {
        {1, 2, 3, 4},
        {8, 6, 7, 9},
        {4, 10, -4, 12},
        {-13, 14, 45, 28}};

    std::cout << "--- 测试构造函数和输出 ---" << std::endl;
    Matrix_4x4 a;
    std::cout << "a (默认构造 - 单位矩阵):" << std::endl
              << a << std::endl;

    Matrix_4x4 b(a);
    std::cout << "b (a的拷贝):" << std::endl
              << b << std::endl;

    Matrix_4x4 c(m);
    std::cout << "c (从二维数组 m 初始化):" << std::endl
              << c << std::endl;

    Matrix_4x4 d;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            d[i][j] = m[i][j];
        }
    }
    std::cout << "d (通过 operator[] 从 m 赋值):" << std::endl
              << d << std::endl;

    std::cout << "--- 测试运算符重载 ---" << std::endl;
    d = a + c;
    std::cout << "d = a + c:" << std::endl
              << d << std::endl;

    d = d - a;
    std::cout << "d = d - a (结果应与 c 相同):" << std::endl
              << d << std::endl;

    Matrix_4x4 id_test = d * d.inverse();
    std::cout << "d * d.inverse() (结果应为单位矩阵):" << std::endl
              << id_test << std::endl;

    std::cout << "--- 测试幂运算和其他函数 ---" << std::endl;
    Matrix_4x4 a_pow_3 = a ^ 3;
    std::cout << "a ^ 3 (单位矩阵的立方仍是单位矩阵):" << std::endl
              << a_pow_3 << std::endl;

    d = c.transpose();
    std::cout << "d = c.transpose():" << std::endl
              << d << std::endl;
    std::cout << "原始矩阵 c 保持不变:" << std::endl
              << c << std::endl;

    // 使用另一个矩阵测试幂运算以显示奇异矩阵报错结果
    double p_data[4][4] = {{1, 2, 1, 0}, {0, 1, 2, 1}, {1, 0, 1, 2}, {2, 1, 0, 1}};
    Matrix_4x4 p(p_data);
    std::cout << "新矩阵 p:" << std::endl
              << p << std::endl;

    Matrix_4x4 p_cubed = p ^ 3;
    std::cout << "p ^ 3:" << std::endl
              << p_cubed << std::endl;

    try
    {
        Matrix_4x4 p_inv_2 = p ^ -2;
        std::cout << "p ^ -2:" << std::endl
                  << p_inv_2 << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "错误: " << e.what() << std::endl;
    }

    return 0;
}