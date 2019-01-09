#include<iostream>
using namespace std;
bool isZero(string str) {
	if (str.empty()) return false;
	size_t len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == '0') return true;	
	}
	return false;
}




//int main() {
//	string input = "001012";
//	int len = input.length();
//	int i = atoi(input.c_str());
//	int sum = 0;
//	//没有零
//	if (!isZero(input)) {
//		if (len == 1) {
//			cout << 1;
//			system("pause");
//			return 0;
//		}
//		if (len == 0) {
//			sum = 1;
//			system("pause");
//			return 0;
//		}
//		int j = 0;
//		sum++;//1已经计算过了
//		int i = 2;
//		while (j < len) {
//			if ((len - j) >= i) {
//				int num = atoi(input.substr(j, i).c_str());
//				if (num > 0 && num < 26) {
//					sum++;
//				}
//				j++;
//			}
//			else {
//				break;
//			}
//		}
//	}
////如果有零
//	else {
//		if (len == 1 || len == 0) {
//			cout << 0 << endl;
//			system("pause");
//			return 0;
//		}
//		int i = 2;
//		sum = 0;
//		for (; i <= len; i++) {
//			int j = 0;
//			while (j < len) {
//				if ((len - j) >= i) {
//					if (!isZero(input.substr(0, j))) {
//						int num = atoi(input.substr(j, i).c_str());
//						if (num > 0 && num < 26) {
//							if (!isZero(input.substr(j + i, len - i - j))) {
//								sum++;
//							}
//						}						
//					}
//					j++;
//				}
//					else {
//						break;
//					}
//
//				
//			}
//		}
//	}
//	cout << sum<<endl;
//	system("pause");
//	return 0;
//
//
//
//}