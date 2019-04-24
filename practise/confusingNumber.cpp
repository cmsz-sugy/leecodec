/*给定一个数字 N，当它满足以下条件的时候返回 true：

把原数字旋转180°以后得到新的数字。

如 0, 1, 6, 8, 9 旋转 180° 以后，得到了新的数字 0, 1, 9, 8, 6 。

2, 3, 4, 5, 7 旋转 180° 后,得到的不是数字。

易混淆数字 (confusing number) 就是一个数字旋转180°以后，得到和原来不同的数字，且新数字的每一位都是有效的。*/
bool confusingNumber(int N) {
	if (N == 0) return false;
	int sign = 1;
	int n;
	if (N < 0) {
		sign = -1;
		int n = abs(N);
	}
	else{ n = N; }	
	int newN=0;
	while (n > 0) {
		int remainder = n % 10;
		if (remainder != 0 && remainder != 1 && remainder != 9 && remainder != 8 && remainder != 6) {
			return false;		
		}
		if (remainder == 9) remainder = 6;
		else if (remainder == 6) remainder = 9;
		newN *=10;
		newN += remainder;
		n /= 10;
	}
	newN *= sign;
	if (newN == N) return false;
	return true;
}