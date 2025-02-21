#include<iostream>
using namespace std;

// Exercise 3.1
// int power(int x, int n) {
//	if (n == 0)
//		return 1;
//	else
//		return power(x, n - 1) * x;
//}
//int main() {
//	int num = 2;
//	for (int i = 0; i <= 20; i++) {
//		cout << num << "^" << i << " = " << power(num, i) << endl;
//	}
//}
//
// Exercise 3.2
// int ackerman(int m, int n) {
//	if (m == 0)
//		return n + 1;
//	else if (m > 0 && n == 0)
//		return ackerman(m - 1, 1);
//	else if (m > 0 && n > 0)
//		return ackerman(m - 1, ackerman(m, n - 1));
//}
//int main() {
//	cout<<ackerman(3, 4);
//}
// 
 //Exercise 3.3
//void print(int n) {
//	if (n == 0)
//		cout << "0";
//	else {
//		cout << n << endl;
//		print(n - 1);
//	}
//}
//int cbc(int n, int k) {
//	if (n == k)
//		return 1;
//	else if (k == 0)
//		return 1;
//	else if (n > 1 && k > 0)
//		return cbc(n - 1, k - 1) + cbc(n - 1, k);
//}
//bool isPrime(int n, int i = 2)
//{
//	if (n <= 2)
//		return (n == 2) ? true : false;
//	if (n % i == 0)
//		return false;
//	if (i * i > n)
//		return true;
//	return isPrime(n, i + 1);
//}
//int main() {
//	int num = 20;
//	int nB = 4, kB = 5;
//	cout << isPrime(kB) << endl;
//	cout<<"Binomial computation: " << cbc(nB, kB);
//	print(num);
//}
