# 多重背包问题 III(解读lys大佬解读yxc的代码的代码)

## 代码解读

首先上代码

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 20010;

int dp[N], pre[N], q[N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        memcpy(pre, dp, sizeof(dp));
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = 0; j < v; ++j) {
            int head = 0, tail = -1;					// 单调队列里存什么？
            for (int k = j; k <= m; k += v) {

                if (head <= tail && k - s*v > q[head])	// 什么时候需要弹出队头元素？
                    ++head;

                while (head <= tail && pre[q[tail]] - (q[tail] - j)/v * w <= pre[k] - (k - j)/v * w)
                    --tail;								// 如何还原存储的值？

                if (head <= tail)						// 如何更新dp[k]
                    dp[k] = max(dp[k], pre[q[head]] + (k - q[head])/v * w);

                q[++tail] = k;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
```

### 几个要点

**基本概念**

- `dp[x]`相当于`dp[i][x]`，使用前`i`种物品，体积不超过`x`
- `pre[x]`相当于`dp[i - 1][x]`，备份“上一层”，使用前`i - 1`种物品，体积不超过`x`

**公式推导**

- ```cpp
  dp[j]    =     dp[j]
  dp[j+v]  = max(dp[j] +  w,  dp[j+v])
  dp[j+2v] = max(dp[j] + 2w,  dp[j+v] +  w, dp[j+2v])
  dp[j+3v] = max(dp[j] + 3w,  dp[j+v] + 2w, dp[j+2v] + w, dp[j+3v])
  ...
  等号左边是在前 i 个物品中选，右边是前 i - 1，在代码中，左边对应了dp数组（更新最大值时的左侧），右边对应了pre数组（更新单调队列时）
  ```

- 上述转移方程可以改写成：(个人认为这是最重要最奇幻的一步=-=)

  ```cpp
  dp[j]    =     dp[j]
  dp[j+v]  = max(dp[j], dp[j+v] - w) + w
  dp[j+2v] = max(dp[j], dp[j+v] - w, dp[j+2v] - 2w) + 2w
  dp[j+3v] = max(dp[j], dp[j+v] - w, dp[j+2v] - 2w, dp[j+3v] - 3w) + 3w
  ...
  这样，每次用以判断是否入队的值是 dp[j + λ*v] - λ*w
  ```

**单调队列有关内容**

- 单调队列里存什么？—— 单调队列里存储的是`dp[]`数组的下标，每次入队的值是容量值 $j + λ * v$，在代码中这个表达式体现为`k`。 而单调队列的队头存储的是能够使得$dp[ j + λ * v ] - λ * w$最大的值$j + λ_{best} * v$。（使用`λ`是为了和代码中的`k`区别开）
- 如何还原存储的值？—— 需要取用单调队列的最大值时，需要一定的处理，还原为$dp[ j + λ_{best} * v ] - λ_{best} * w$。而假如已知单调队列存储的值`t`，则可以求出`λ`，即$\frac {t - j}{v}$，所以原始值$dp[ j + λ * v ] - λ * w = dp[t] - \frac {t - j}{v}*w$。另外在比较队尾时，给定`体积k`时也同理
- 什么时候需要弹出队头元素呢？—— 判断队列首尾元素是否相差超过了`s`个(原始状态是`r, r + v, r + 2v, ...`)，因为滑动窗口里的元素最多为`s + 1`个，即`if((k - q[head]）/ v) > s)`;

**dp数组的更新**

- 如何更新`dp[k]`(此处的k是代码中的k，代表体积)？—— 假设`k = j + μv`，则
  $$
  \begin{align} 
  dp[k] &= \max (dp[k], dp[ j + λ_{best} * v ] - λ_{best} * w + μ*w) \\
  &= \max (dp[k],dp[ q_{head} ] - \frac {q_{head} - j}{v} * w +  \frac {k - j}{v}*w)\\
  &= \max (dp[k],dp[ q_{head} ] + \frac {k - q_{head}}{v} *w)
  \end{align}
  $$

  ![image-20220218193504486](https://s2.loli.net/2022/02/18/OfGHhms2aQvYWyM.png)