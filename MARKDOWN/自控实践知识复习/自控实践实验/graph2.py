import matplotlib.pyplot as plt
import numpy as np
import matplotlib

# 设置中文字体
matplotlib.rcParams['font.sans-serif'] = ['SimHei']
matplotlib.rcParams['axes.unicode_minus'] = False

# 实验数据 (来自表 3-2-2)
f_raw = np.array([170800, 168933, 165600, 163533, 159667, 156467, 155000, 152400, 146200, 145600, 143733])
T_data = np.array([0.0395, 0.0439, 0.0484, 0.0528, 0.0573, 0.0617, 0.0661, 0.0706, 0.0750, 0.0794, 0.0839])

# 为了匹配指导书中的x轴单位 (x 10^4 Hz)
f_scaled = f_raw / 10000

# 为了让 polyfit 更好地工作，我们将 x 轴(频率)数据翻转为升序
f_sorted = np.flip(f_scaled)
T_sorted = np.flip(T_data)

# 计算多项式拟合 (例如3次多项式), T = f(f)
coeffs = np.polyfit(f_sorted, T_sorted, 3)
poly = np.poly1d(coeffs)

# 创建平滑的拟合曲线 x 轴(频率)范围
f_fit = np.linspace(f_sorted.min(), f_sorted.max(), 300)
# 计算拟合的 y 轴(转矩)值
T_fit = poly(f_fit)

# 绘图
plt.figure(figsize=(10, 6))

# 绘制原始的、未排序的数据点
plt.scatter(f_scaled, T_data, color='blue', marker='*', label='实验数据点')

# 绘制拟合曲线
plt.plot(f_fit, T_fit, 'r-', label='矩频拟合曲线')

# 设置图表标题和坐标轴标签 (标准坐标轴)
plt.title('矩频特性曲线')
plt.xlabel('脉冲频率 f ($\times 10^4$ Hz)')
plt.ylabel('动态转矩 T (N·m)')
plt.legend()
plt.grid(True)

# 不再反转任何坐标轴
plt.show()