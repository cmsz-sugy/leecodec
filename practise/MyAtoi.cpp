#include<iostream>
using namespace std;
int myAtoi(string str) {
	if (str.empty()) return 0;
	size_t len = str.length();
	int result = 0;
	for (int i = 0; i < len; i++) {
		if (str[i]==32) continue;	
		else if (str[i] == '-' || str[i] == '+') {
			for (int j = i + 1; j < len; j++) {
				if (str[i + 1] > 57 && str[i + 1] < 48) return 0;
				else {
					if (str[j] < 58 && str[j] > 47 && str[i] == '+')
					{
						if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[j] > 55)) return INT_MAX;
						result = result * 10 + str[j] - '0';
					}
					else if (str[j] < 58 && str[j] > 47 && str[i] == '-') {
						if (result < INT_MIN / 10||(result == INT_MIN/10&& str[j]>56))
							return INT_MIN;
						result = result * 10 - str[j] + '0';
					}						
					else {
						return result;
					}
				}
			}	
			return result;
		}
		else if (str[i] > 58 || str[i] < 48) return 0;
		else if (str[i] < 58 && str[i] > 47) {
			for (int j = i; j < len; j++) {
				if (str[j] < 58 && str[j] > 47) {
					if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[j] > 55)) return INT_MAX;
					result = result * 10 + str[j] - '0';
				}
				else {
					return result;
				}
			
			}
			return result;
		}	
	}
	return result;

}
//int main() {
//	int x = myAtoi("2147483648");
//	system("pause");
//	return 0;
//}