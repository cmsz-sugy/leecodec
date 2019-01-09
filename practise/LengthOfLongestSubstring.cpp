#include<iostream>
using namespace std;
bool charIsNotEualSubStr(char a, string in) {
	size_t len = in.length();
	for (int i = 0; i < len; i++) {
		if (a == in[i]) return false;
	}
	return true;
}
int lengthOfLongestSubstring(string s) {
	if (s == "") return 0;
	if (s.length() == 1) return 1;
	int max = 1;
	size_t len = s.length();
	int baseIndex = 0;
	for (int baseIndex = 0; baseIndex < len; baseIndex++) {
		int lenSubStr = 1;
		for (int lenSub = 1; lenSub < (len- baseIndex); lenSub++) {
			string subStr = s.substr(baseIndex, lenSub);
			if (charIsNotEualSubStr(s[baseIndex + lenSub], subStr)) {	
				lenSubStr++;
				 continue;
			}
			else {
				break;
			}
		}
		if (lenSubStr > max) max = lenSubStr;
	}
	return max;
}

//int main() {
//	string in = "bbbbb";
//	cout<<lengthOfLongestSubstring(in)<<endl;
//	system("pause");
//	return 0;
//}