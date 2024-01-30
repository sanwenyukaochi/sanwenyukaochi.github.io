#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
void sync_with_stdio() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
const int N = 10005;
// head存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表⽰当前⽤到了哪个节点
int head, e[N], ne[N], idx;
void init() {
    head = -1; idx = 0;
}
//将x插到头节点
void add_to_head(int x) {
    e[idx] = x; ne[idx] = head; head = idx++;
}
//将头节点删掉
void remove_to_head() {
    head = ne[head];
}
//将x插到下标是k的点后面
void add(int k, int x) {
    e[idx] = x; ne[idx] = ne[k]; ne[k] = idx++;
}
//将下标是k的点后面的点删掉
void remove(int k) {
    ne[k] = ne[ne[k]];
}
void print_f() {
    cout << "head -> ";
    for (int i = head; i != -1; i = ne[i]) {
        cout << setw(3) << e[i] << " -> ";
    }cout << setw(3) << "无" << "[链表]" << endl;
    cout << setw(4) << head << " -> ";
    for (int i = head; i != -1; i = ne[i]) {
        cout << setw(3) << i << " -> ";
    }cout << setw(3) << "-1" << "[对应下标idx]" << endl;
    cout << setw(4) << ne[head] << " -> ";
    for (int i = head; i != -1; i = ne[i]) {
        cout << setw(3) << ne[i] << " -> ";
    }cout << setw(3) << ne[-1] << "[对应下标idx指向的下一个的指针位置]" << endl;
    cout << endl;
}
int main()
{
    init();
    print_f();
    add_to_head(9); print_f();
    add(1 - 1, 1); print_f();
    remove(1 - 1); print_f();
    remove_to_head(); print_f();
    add_to_head(6); print_f();
    add(3 - 1, 6); print_f();
    add(4 - 1, 5); print_f();
    add(4 - 1, 5); print_f();
    add(3 - 1, 4); print_f();
    remove(6 - 1); print_f();
    add_to_head(777); print_f();
    add_to_head(666); print_f();
    add_to_head(555); print_f();
    return 0;
}

/*
head -> 无[链表]
  -1 -> 无[对应下标idx]
   0 -> 无[对应下标idx指向的下一个的指针位置]

head ->   9 -> 无[链表]
   0 ->   0 -> 无[对应下标idx]
  -1 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head ->   9 ->   1 -> 无[链表]
   0 ->   0 ->   1 -> 无[对应下标idx]
   1 ->   1 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head ->   9 -> 无[链表]
   0 ->   0 -> 无[对应下标idx]
  -1 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head -> 无[链表]
  -1 -> 无[对应下标idx]
   0 -> 无[对应下标idx指向的下一个的指针位置]

head ->   6 -> 无[链表]
   2 ->   2 -> 无[对应下标idx]
  -1 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head ->   6 ->   6 -> 无[链表]
   2 ->   2 ->   3 -> 无[对应下标idx]
   3 ->   3 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head ->   6 ->   6 ->   5 -> 无[链表]
   2 ->   2 ->   3 ->   4 -> 无[对应下标idx]
   3 ->   3 ->   4 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head ->   6 ->   6 ->   5 ->   5 -> 无[链表]
   2 ->   2 ->   3 ->   5 ->   4 -> 无[对应下标idx]
   3 ->   3 ->   5 ->   4 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head ->   6 ->   4 ->   6 ->   5 ->   5 -> 无[链表]
   2 ->   2 ->   6 ->   3 ->   5 ->   4 -> 无[对应下标idx]
   6 ->   6 ->   3 ->   5 ->   4 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head ->   6 ->   4 ->   6 ->   5 -> 无[链表]
   2 ->   2 ->   6 ->   3 ->   5 -> 无[对应下标idx]
   6 ->   6 ->   3 ->   5 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head -> 777 ->   6 ->   4 ->   6 ->   5 -> 无[链表]
   7 ->   7 ->   2 ->   6 ->   3 ->   5 -> 无[对应下标idx]
   2 ->   2 ->   6 ->   3 ->   5 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

head -> 666 -> 777 ->   6 ->   4 ->   6 ->   5 -> 无[链表]
   8 ->   8 ->   7 ->   2 ->   6 ->   3 ->   5 -> 无[对应下标idx]
   7 ->   7 ->   2 ->   6 ->   3 ->   5 ->  -1 -> 无[对应下标idx指向的下一个的指针位置]

*/
