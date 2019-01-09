//#将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
#include<iostream>
#include<algorithm>
using namespace std;
string convert(string s, int numRows) {
	string result;
	size_t len = s.length();
	if (len < numRows|| numRows==1)  return s;
	//先输出第一行
	int column = 0;
	int b = 0;
	int index = 2 * numRows*column - b;
	while (index < len) {
		result+= s[index];
		column += 1;
		b += 2;
		index = 2 * column*numRows - b;
	}
	//cout << endl;
	column = 1;
	for (int i = 1; i < numRows-1; i++) {
		result += s[i];
		b = -2-i;
		column = 1;
		index = 2 * column*numRows + b;
			while (index < len) {
				//cout << s[index] << " ";
				result += s[index];
				b += 2*i;			
				index = 2 * column*numRows + b;
				if (index < len) {
					//cout << s[index] << " ";
					result += s[index];
					column += 1;
					b -= 2 * (i + 1);
					index = 2 * column*numRows + b;
				}
			}
			cout << endl;
	}
	//输出最后一行
	column = 1;
	b = 1;
	index = numRows - b;
	while (len > index) {
		//cout << s[index] << " ";
		result += s[index];
		column += 2;
		index =  column*(numRows - b);
	}
	return result;
}
//int main() {
//	string input = "A";
//	string s= convert(input, 1);
//	system("pause");
//	return 0;
//}