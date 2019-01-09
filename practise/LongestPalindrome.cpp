/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。*/
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000010;
char str[maxn];//原字符串
char tmp[maxn << 1];//转换后的字符串
int Len[maxn << 1];
bool IsPalindrome(string s) {
	if (s.length() == 0) return false;
	if (s.length() == 1) return true;
	size_t len = s.length();
	for (int i = 0; i <=len/2;i++) {
		if (s[i] != s[len - 1 - i]) return false;
	}
	return true;
}
string longestPalindrome(string s) {
	size_t len = s.length();
	if (len == 0) return "";
	if (len == 1) return s;
	string result;
	string subPalindrome;
	for (int baseIndex = 0; baseIndex < len; baseIndex++) {
		for (int subStrLen = 1; subStrLen <= (len - baseIndex); subStrLen++) {
			string str = s.substr(baseIndex, subStrLen);
			if (IsPalindrome(str)) subPalindrome = str;
		}
		if (result.length() < subPalindrome.length()) result = subPalindrome;
	
	}
	return result;
}
//转换原始串
char * init(char *st,int len)
{
	int new_len = 2 * len + 2;
	char *result = new char[len];
	memset(result, 0, new_len);
	result[0] = '$';
	result[1] = '#';
	int i = 2;
	for (; i < new_len+2; i+=2) {
		result[i] = st[i / 2-1];
		result[i + 1] = '#';
	}
	result[i] = '\0';
	return result;
}
//Manacher算法计算过程
int MANACHER(char *st, int len)
{    

	if (len == 0) return 0;
	if (len == 1) return 1;
	int *p = new int[len+1];
	for (int i = 0; i < len; i++) {
		p[i] = 0;
	}
	int Pindex = 0;
	char *in = init(st, len);
	int i = 2;
	for (; i < 2 * len + 1; i += 2) {
		int j = i + 1;
		while (in[j] == in[2*i - j]) {//2*i-j是以为对称轴j的对称点。
			j++;
			p[i/2-1]++;
		}
	}
	p[i / 2 - 1] = '\0';
	int max = *max_element(p, p + len);
	return max;
}

//int main() {
//	string inStr = "";
//	char *in = new char[inStr.length()+1];
//	strcpy_s(in, inStr.length() + 1,inStr.c_str());
//	int max = MANACHER(in, inStr.length());
//	system("pause");
//	return 0;
//
//}