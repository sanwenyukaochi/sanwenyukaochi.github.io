#include <iostream>
using namespace std;
const int N = 10;
int n;
char g[N][N]; //存储棋盘中每一个位置上是`.`还是`Q`
bool col[N], dg[2 * N], udg[2 * N]; //用来标记当前位置[u, i]的列col[i]、对角线dg[u + i]、反对角线udg[n - u + i]上是否存在皇后
//因为在对角线y = -x + b上的点，截距 b = y + x，因此可以用 y + x 来作为同一条对角线的下标；
//因为在反对角线y = x + b上的点，截距 b = y - x,由于下标不能为负数，因此可以使用 y - x + n来作为同一条反对角线的下标。	
void dfs(int u) {//深搜第 u 行的哪一列能够放皇后
    if (u == n) {// 当u = n时，表明前n行都已放好皇后，将前n行进行输出
        for (int i = 0; i < n; i++) {
            puts(g[i]);
            /*for (int j = 0; j < n; j++) {
                if (g[i][j] == 'Q')cout << i << j;
            }*/
        }
        puts("");
        return;
    }
    for (int i = 0; i < n; i++) //遍历第u行的每一个位置
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {//当前位置所在列、对角线、反对角线都没放皇后时,在该位置放上皇后，然后处理下一行
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false; //恢复现场
            g[u][i] = '.';
        }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.'; //将每一个位置初始化为`.`
    dfs(0);
    return 0;
}