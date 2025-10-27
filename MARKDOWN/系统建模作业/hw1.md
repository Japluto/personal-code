<h3 style="text-align:center; font-size:16pt;">作业一 张韶恒  自动化三班</h3>

---
#### 第一种方法：
**采取蒲丰投针实验**：
具体参数设置为`针长为1，间距为1`， 代码如下所示：
```
% 蒲丰投针实验(Buffon's Needle)的MATLAB仿真
function pi_estimate_buffon = estimate_pi_buffon(n)
    % n: 投针的总次数
    fprintf('开始蒲丰投针实验仿真...\n');
    fprintf('总投针次数: %d\n', n);
    a = 1; % 平行线之间的距离
    L = 1; % 针的长度 (L <= a)
    % 初始化相交计数器
    hits = 0;
    % --- 开始仿真循环 ---
    for i = 1:n
        % 1. 随机生成针中心的y坐标到最近线的距离 x
        % 相当于在 [0, a/2] 区间内均匀取样
        x = rand * (a / 2);
        % 2. 随机生成针与平行线的夹角 theta
        % 相当于在 [0, pi/2] 区间内均匀取样
        theta = rand * (pi / 2);
        % 3. 判断是否相交
        % 相交条件: x <= (L/2) * sin(theta)
        if x <= (L / 2) * sin(theta)
            hits = hits + 1;
        end
    end
    % --- 计算pi的估计值 ---
    if hits == 0
        pi_estimate_buffon = NaN; % 避免除以零
        fprintf('警告: 没有一次投掷与线相交。\n');
    else
        % 公式: pi ≈ (2 * L * n) / (a * hits)
        pi_estimate_buffon = (2 * L * n) / (a * hits);
    end
    fprintf('仿真结束。\n');
    fprintf('相交次数: %d\n', hits);
    fprintf('Pi 的估计值为: %f\n', pi_estimate_buffon);
end

% 调用函数  estimate_pi_buffon(10000000);
```
**测试输入: `estimate_pi_buffon(10000000);`**  


___  


#### 第二种方法：
**采取蒙特卡洛投点实验**：
具体参数设置为`正方形边长为2，内切圆为单位圆`， 代码如下所示：
```
% 蒙特卡洛投点法的MATLAB仿真
function pi_estimate_monte_carlo = estimate_pi_monte_carlo(n)
    % n: 投点的总数量
    fprintf('开始蒙特卡洛投点法仿真...\n');
    fprintf('总投点数: %d\n', n);
    % 初始化落在圆内的点计数器
    m = 0;
    % --- 开始仿真循环 ---
    for i = 1:n
        % 1. 在[-1, 1]区间内随机生成点的x, y坐标
        x = 2 * rand - 1; % 生成一个[-1, 1]的随机数
        y = 2 * rand - 1; % 生成一个[-1, 1]的随机数

        % 2. 判断点是否在单位圆内
        % 条件: x^2 + y^2 <= 1
        if x^2 + y^2 <= 1
            m = m + 1;
        end
    end
    % --- 计算pi的估计值 ---
    % 公式: pi ≈ 4 * m / n
    pi_estimate_monte_carlo = 4 * m / n;
    fprintf('仿真结束。\n');
    fprintf('落在圆内的点数: %d\n', m);
    fprintf('Pi 的估计值为: %f\n',pi_estimate_monte_carlo); 
end

% 调用函数  estimate_pi_monte_carlo(10000000);
```
**测试输入: `estimate_pi_monte_carlo(10000000);`**




```mermaid
graph TD
    A[开始] --> B{行列式是否接近零?};
    B -- 是 --> C[抛出&quot;矩阵奇异,无法求逆&quot;异常];
    B -- 否 --> D[创建原矩阵的副本temp和单位矩阵inv];
    D --> E{For 循环 &#40;i 从 0 到 3&#41;};
    E -- 遍历每一列 --> F[在列 i 中寻找绝对值最大的主元];
    F --> G[交换当前行 i 与主元行<br/>(在 temp 和 inv 中同步操作)];
    G --> H[将新的主元行 i 归一化<br/>(该行所有元素除以主元 temp[i][i])];
    H --> I[消去列 i 中的其他所有元素<br/>(通过行变换使它们变为 0)];
    I --> E;
    E -- 循环结束 --> J[返回结果矩阵 inv];
    J --> K[结束];
    C --> K;
```