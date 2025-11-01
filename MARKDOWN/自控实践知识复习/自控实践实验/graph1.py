import matplotlib.pyplot as plt
import numpy as np
import matplotlib

# 设置中文字体，确保图表能正确显示中文
# 请根据您的环境选择一个可用的中文字体
# 例如 'SimHei', 'Microsoft YaHei', 'Arial Unicode MS'
matplotlib.rcParams['font.sans-serif'] = ['SimHei']  # 'SimHei' 是黑体
matplotlib.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 实验数据 (来自表 3-2-2)
v_data = np.array([256.2, 253.4, 248.4, 245.3, 239.5, 234.7, 232.5, 228.6, 219.3, 218.4, 215.6])
T_data = np.array([0.0395, 0.0439, 0.0484, 0.0528, 0.0573, 0.0617, 0.0661, 0.0706, 0.0750, 0.0794, 0.0839])

# 为了让 polyfit 更好地工作，我们将 x 轴(速度)数据翻转为升序
v_sorted = np.flip(v_data)
T_sorted = np.flip(T_data)

# 计算多项式拟合 (例如3次多项式), T = f(v)
coeffs = np.polyfit(v_sorted, T_sorted, 3)
poly = np.poly1d(coeffs)

# 创建平滑的拟合曲线 x 轴(速度)范围
v_fit = np.linspace(v_sorted.min(), v_sorted.max(), 300)
# 计算拟合的 y 轴(转矩)值
T_fit = poly(v_fit)

# 绘图
plt.figure(figsize=(10, 6))

# 绘制原始的、未排序的数据点
plt.scatter(v_data, T_data, color='blue', marker='*', label='实验数据点')

# 绘制拟合曲线
plt.plot(v_fit, T_fit, 'r-', label='T-v 拟合曲线')

# 设置图表标题和坐标轴标签 (标准坐标轴)
plt.title('T-v 特性曲线 (转矩-速度特性)')
plt.xlabel('速度 v (r/min)')
plt.ylabel('动态转矩 T (N·m)')
plt.legend()
plt.grid(True)

# 不再反转任何坐标轴
plt.show()