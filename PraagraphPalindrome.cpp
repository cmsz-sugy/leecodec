// PraagraphPalindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
vector<string>vec;
static int longestDecomposition(string text) {
	int len = text.length();
	int begin_index = 0;
	int end_index = len - 1;
	int palindra_len = 0;
	int result = 0;
	while (begin_index <= end_index) {
		if (text[begin_index] == text[end_index] && palindra_len == 0) {
			if (begin_index == end_index) {
				begin_index++;
				end_index--;
				result++;
			}
			else {
			/*	char *a = new char[1];
				a[0] = text[begin_index];
				string s(a, a + 1);
				vec.push_back(s);*/
				begin_index++;
				end_index--;
				result += 2;
			
			}
			
		}
		else {	
			if (palindra_len == len - 1) {
				return 1;
			}
			end_index--;
			palindra_len++;
			int index = 0;
			while (index <= palindra_len&&begin_index<end_index) {
				if (text[begin_index+index] == text[end_index +index]) {
					index++;
				}
				else break;
			}
			if (begin_index == end_index) {
				result++;
			}
			if (index ==  palindra_len+1) {	
				/*char *a1 = new char[index];
				for (int i = 0; i < index; i++) {
					a1[i] = text[begin_index + i];
				}
				string s1(a1, a1 + index);
				vec.push_back(s1);*/
				begin_index += index;
				end_index--;
				palindra_len = 0;
				result+=2;
			}
		}
		}
	return result;
	}

int main()
{
	cout << longestDecomposition("ghiabcdefhelloadamhelloabcdefghi")<<endl;
	for (string ve : vec) {
		cout << '\t' << ve.c_str() << endl;
	}
	//std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
