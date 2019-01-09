#include<iostream>
#include<vector>
using namespace std;
int jump(vector<int>& nums) {
	vector<int> numsAll = nums;
	if (numsAll.size() == 0) return 0;
	size_t len = numsAll.size();
	int index = -1;
	int result = 0;
	while (len > 1) {
		bool findIndex = false;
		for (int i = len - 2; i >= 0; i--) {		
			if (numsAll[i] >= len - 1 - i) {			
				index = i;
				findIndex = true;
			}
			if (!findIndex&&i==0) return 0;
		}
		len = index + 1;
		result++;
	}
	return result;
}
int main() {
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	int a = jump(nums);
	return 0;
}