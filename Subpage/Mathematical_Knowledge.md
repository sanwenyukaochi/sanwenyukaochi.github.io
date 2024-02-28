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
  - [求子集](#求子集)
  - [数组去重](#数组去重)
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
最后判断一次 x > 1 ; 表示大于sqrt(x)的质因子
```cpp
void divide(int x) {
	for (int i = 2; i <= x/i; i++) {
		if (x % i == 0) {
			int s = 0;
			while (x % i == 0) x /= i, s++;
			cout << i << ' ' << s << endl;
		}
	}
	if (x > 1) cout << x << ' ' << 1 << endl;
	cout << endl;
}
```
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
解释： i % primes[j] == 0 -> break; 因为我们只删除最小质因子，例如i=4删8(2\*4),下一步时删(3\*4)但实际上12应该由6去删;
```cpp
int primes[N], cnt;
bool st[N];
void get_primes(int n) {
	for (int i = 2; i <= n; i++) {
		if (!st[i]) primes[cnt++] = i;
		for (int j = 0; primes[j] <= n / i; j++) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0)break;
		}
	}
}
```
## 试除法求所有约数
```cpp
vector<int>get_divisors(int x) {
	vector<int>res;
	for (int i = 1; i <= x / i; i++) {
		if (x % i == 0) {
			res.push_back(i);
			if (i != x / i)res.push_back(x / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}
```
## 约数个数和约数之和
```cpp
//2*2*2*3*3 -> 72
//1 2 3 4 6 8 9 12 18 24 36 72 -> 195
//2^3*3^2 -> 4*3 -> 12
//(2^0+2^1+2^2+2^3)*(3^0+3^1+3^2) -> (1+2+4+8)*(1+3+9) -> 15*13 -> 195
如果 		N = p1^c1 * p2^c2 * ... * pk^ck
约数个数：	(c1 + 1) * (c2 + 1) * ... * (ck + 1)
约数之和：	(p1^0 + p1^1 + ... + pk^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
一般可以用 unordered_map<int, int>primes; 存 p1 , c1 ;
```
```cpp
遍历 for (auto prime : primes)res = res * (prime.second + 1) % mod;
```
关于 p1^0 + p1^1 + ... + pk^c1 ;
```cpp
int p = prime.first, c = prime.second;
long long t = 1;
while (c--)t = (t * p + 1) % mod;
```
## 欧几里得算法
```cpp
//gcd最大公约数
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
//lcm最小公倍数
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
```
## 求欧拉函数
欧拉函数的定义：1~N中与N互质的数的个数被称为欧拉函数，记为Φ(N)。例如Φ(6)=2(1,5与6互为质数)
```cpp
int phi(int x) {
	int res = x;
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0) {
			res = res / i * (i - 1);
			while (x % i == 0)x /= i;
		}
	}
	if (x > 1)res = res / x * (x - 1);
	return res;
}
```
## 筛法求欧拉函数
```cpp
int primes[N], cnt;	//primes[]存所有素数
int euler[N];		//euler[]存储每个数的欧拉函数
bool st[N];			//st[x]存储x是否被筛掉
void get_eulers(int n) {
	euler[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!st[i]) {
			primes[cnt++] = i;
			euler[i] = i - 1;
		}
		for (int j = 0; primes[j] <= n / i; j++) {
			int t = primes[j] * i;
			st[t] = true;
			if (i % primes[j] == 0) {
				euler[t] = euler[i] * primes[j];
				break;
			}
			euler[t] = euler[i] * (primes[j] - 1);
		}
	}
}
```
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
## 求子集
```cpp
void allPossibleSubset(int arr[], int n){
	int  count = pow(2, n);
	for (int i = 0; i < count; i++){
		for (int j = 0; j < n; j++){
			if (i >> j & 1){
				cout << arr[j] << " ";
			}
		}cout << "\n";
	}
}
```
## 数组去重
```cpp
arr.erase(unique(arr.begin(), arr.end()), arr.end());
/*
int a[] = { 1,1,2,2,3,3,4,4 };
int m = unique(a, a + 8) - a;
此时a[] = 1,2,3,4(m),3,3,4,4
*/
```