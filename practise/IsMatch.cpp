#include<iostream>
using namespace std;
bool isMatch(string s, string p) {
	if (s.empty() || p.empty()) return false;
	size_t lenS = s.length();
	size_t lenP = p.length();
	bool isPerfectMatch = false;
	for (int pIndex = 0; pIndex < lenP; pIndex++) {
		size_t pIndexTem = pIndex;
		for (int  sIndex = 0; sIndex < lenS; sIndex++) {
			if (s[sIndex] == p[pIndexTem] || p[pIndexTem] == '.') {
				if (sIndex == lenS - 1)
					return  true;
				pIndexTem++;
				continue;
			}
			if (p[pIndexTem] == '*') {
				if (s[sIndex] == p[pIndexTem + 1]  ) {
					if (sIndex == lenS - 1)
					return  true;			
						pIndexTem += 2;	
					if (pIndexTem > (lenP - 1)) return false;
					continue;
				}
				else if (s[sIndex] == p[pIndexTem - 1] ) {
					if (sIndex == lenS - 1) {
						return  true;
					}
					continue;
				}
				else if (p[pIndexTem - 1] == '.') {
					if (sIndex == lenS - 1&& pIndexTem==lenP-1) {
						return  true;
					}
				}
				else if (p[pIndexTem + 1] == '.') {
					if (sIndex == lenS - 1)
						return  true;
					pIndexTem += 2;
					if (pIndexTem > (lenP - 1)) return false;
				}
			
				else {
					break;
				}
			}	
			break;
		}
	}
	return false;
}
//int main() {
//	bool res = isMatch("aaa","aaaa");
//	return 0;
//}