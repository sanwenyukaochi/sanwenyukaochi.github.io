#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
void sync_with_stdio() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
const int N = 10005;
int e[N], l[N], r[N], idx;
void init() {
    r[0] = 1, l[1] = 0;
    idx = 2;
}
void add(int k, int x) {
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx++;
}
void remove(int k) {
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}
void p() {
    for (int i = r[0]; i != 1; i = r[i]) {  // 从左向右遍历
        if (r[i] == 1) cout << e[i];
        else cout << e[i] << " -> ";
    }
    cout << endl;
}
int main()
{

    int m;
    cin >> m;

    init();  // 初始化别搞忘了！！！

    string s;
    int k, x;
    while (m--) {
        cin >> s;
        if (s == "L") {
            cin >> x;
            add(0, x);
            p();
        }
        else if (s == "R") {
            cin >> x;
            add(l[1], x);
            p();
        }
        else if (s == "D") {
            cin >> k;
            remove(k + 1);  // k + 1 是因为头节点和尾节点占用了两个，idx从2开始 
            p();
        }
        else if (s == "IL") {
            cin >> k >> x;
            add(l[k + 1], x);
            p();
        }
        else if (s == "IR") {
            cin >> k >> x;
            add(k + 1, x);
            p();
        }
    }

    p();
    return 0;
}
/*
    输入
    10
    R 7
    D 1
    L 3
    IL 2 10
    D 3
    IL 2 7
    L 8
    R 9
    IL 4 7
    IR 2 2
*/
/*
    输出
    7

    3
    10 -> 3
    3
    7 -> 3
    8 -> 7 -> 3
    8 -> 7 -> 3 -> 9
    8 -> 7 -> 7 -> 3 -> 9
    8 -> 7 -> 7 -> 3 -> 2 -> 9
    8 -> 7 -> 7 -> 3 -> 2 -> 9
*/