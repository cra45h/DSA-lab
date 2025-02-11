//Exercise 1.1
//#include<iostream>
//#include<math.h>
//using namespace std;
//class complex {
//private:
//	float re;
//	float im;
//public:
//	complex() {
//		re = 0, im = 0;
//	}
//	complex(float r, float i) {
//		re = r;
//		im = i;
//	}
//	complex(float r) {
//		re = r;
//		im = 0.0;
//	}
//	~complex() {};
//	complex mul(complex c1) {
//		complex temp;
//		temp.re = re * c1.re - im * c1.im;
//		temp.im = re * c1.im + im * c1.re;
//		return temp;
//	}
//	complex operator*(complex c1) {
//		mul(c1);
//	}
//	void display() {
//		cout << re << endl << im;
//	}
//};
//int main() {
//	complex c1(2,4), c2(2,1), result;
//	result=c1.mul(c2);
//	result.display();
//}
// Example 1.3
//#include<iostream>
//using namespace std;
//template<class T>
//T GetMax(T a, T b)
//{
//	T result;
//	result = (a > b) ? a : b;
//	return(result);
//}
//int main(){
//	int i = 5, j = 6, k;
//	long l = 10, m = 5, n;
//	k = GetMax<int>(i,j);
//	l = GetMax<long>(l, m);
//	cout << l << endl << n;
//	return 0;
//}
// Exercise 1.2
//#include<iostream>
//using namespace std;
//template <class T>
//class mypair {
//	Ta, b;
//public:
//	mypair(T first, T second) {
//		a = first;
//		b = second;
//	}
//	T getmin();
//};
//template<class T>
//T mypair<T>::getmin() {
//	T retval;
//	retval = a < b ? a: b;
//	return retval;
//}
//int main() {
//	mypair<int> myobject(22, 43);
//	cout << myobject.getmin();
//	return 0;
//}
// Exercise 1.3
//#include<iostream>
//using namespace std;
//template< class T, int N>
//class myseq {
//	T memblock[N];
//public:
//	void setmem(int x, T value);
//	T getmem(int x);
//	T getmax();
//	T getmin();
// };
//template< class T, int N>
//void myseq<T, N>::setmem(int x, T value)
//{
//	memblock[x] = value;
//}
//template<class T, int N>
//T myseq<T, N>::getmem(int x)
//{
//	return memblock[x];
//
//} 
//template<class T, int N>
//T myseq<T, N>::getmin() {
//	T temp = memblock[0];
//	for (int i = 0; i < N; i++) {
//		if (temp > memblock[i])
//			temp = memblock[i];
//	}
//	return temp;
//}
//template<class T, int N>
//T myseq<T, N>::getmax() {
//	T temp = memblock[0];
//	for (int i = 0; i < N; i++) {
//		if (temp < memblock[i])
//			temp = memblock[i];
//	}
//	return temp;
//}
//
//int main() {
//	myseq<int, 5>myints;
//	myints.setmem(0, 1);
//	myints.setmem(1, 10);
//	myints.setmem(2, 600);
//	myints.setmem(3, 500);
//	myints.setmem(4, 100);
//	cout << myints.getmin() << endl;
//	cout << myints.getmax() << endl;
//	return 0;
//}