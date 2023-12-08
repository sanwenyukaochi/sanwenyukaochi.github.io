- [数学知识](#数学知识)
  - [试除法判定质数](#试除法判定质数)
  - [试除法分解质数](#试除法分解质数)
  - [朴素筛法求素数](#朴素筛法求素数)
  - [线性筛法求素数](#线性筛法求素数)
  - [试除法求所有约数](#试除法求所有约数)
  - [约数个数和约数之和](#约数个数和约数之和)
  - [欧几里得算法](#欧几里得算法)
  - [求欧拉函数](#求欧拉函数)
  - [筛法求欧拉函数](#筛法求欧拉函数)
  - [快速幂](#快速幂)
  - [扩展欧几里得算法](#扩展欧几里得算法)
  - [高斯消元](#高斯消元)
  - [递归法求组合数](#递归法求组合数)
  - [通过预处理逆元的方式求组合数](#通过预处理逆元的方式求组合数)
  - [Lucas定理](#lucas定理)
  - [分解质因数求组合数](#分解质因数求组合数)

# 数学知识
## 试除法判定质数
```cpp
bool is_prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0)return false;
	}
	return true;
}
```
## 试除法分解质数
## 朴素筛法求素数
primes[ ]存储所有素数，st[x]存储x是否被筛掉。
```cpp
int primes[N], cnt;
bool st[N];
void get_primes(int n) {
	for (int i = 2; i <= n; i++) {
		if (st[i]) continue;
		primes[cnt++] = i;
		for (int j = i + i; j <= n; j += i)
			st[j] = true;
	}
}
```
## 线性筛法求素数
## 试除法求所有约数
## 约数个数和约数之和
## 欧几里得算法
```cpp
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
```
## 求欧拉函数
## 筛法求欧拉函数
## 快速幂
```cpp
int qmi(int m, int k, int p) {
	int res = 1 % p, t = m;
	while (k) {
		if (k & 1)res = res * t % p;
		t = t * t % p;
		k >>= 1;
	}
	return res;
}
```
## 扩展欧几里得算法
## 高斯消元
## 递归法求组合数
## 通过预处理逆元的方式求组合数
## Lucas定理
## 分解质因数求组合数
