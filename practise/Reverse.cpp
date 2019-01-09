#include<iostream>
# include <stdlib.h>
using namespace std;
int reverse(int x) {
	int rev = 0;
	while (x != 0) {
		int pop = x % 10;//各位数字
		x /= 10;
		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
		rev = rev * 10 + pop;//将数字反向推入rev中
	}
	return rev;

}
//int main() {
//	int in = 1534236469;
//	int s = reverse(in);
//	system("pause");
//	return 0;
//}