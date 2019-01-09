#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
   vector<int> twoSum(vector<int>& nums, int target) {
	   vector<int> indexOfSortTwoSum;
	   vector<int> indexOfTwoSum;
	   vector<int> s = nums;
	   size_t len = nums.size();
	   if (len == 0) return indexOfTwoSum;
	   sort(s.begin(), s.end());
	   size_t i = 0, j = len - 1;
	   int sum = 0;
	   for (; i < j;) {
		   sum = s[i] + s[j];
		   if (sum > target) j--;
		   if (sum == target) {
			   indexOfSortTwoSum.push_back(s[i]);
			   indexOfSortTwoSum.push_back(s[j]);
			   i++; j--;
		   }
		   if (sum < target) i++;	   
	   }
	   int indexNums = 0;
	   vector<int>::iterator it;

	   it = indexOfSortTwoSum.begin();
	   for (int num : nums) {
		   if (indexOfSortTwoSum.size() > 0)
		   {
			   for (it = indexOfSortTwoSum.begin(); it != indexOfSortTwoSum.end();) {
				   if (*it == num) {
					   indexOfTwoSum.push_back(indexNums);
					   it=indexOfSortTwoSum.erase(it);
					   break;
				   }
				   else {
					   ++it;
				   }
			   }
			   indexNums++;
		   }
		   else {
			   break;
		   }
	   }
	   return   indexOfTwoSum;

}
//int main() {
//   
//	vector<int>input;
//	vector<int>out;
//	input.push_back(3);
//	input.push_back(2);
//	input.push_back(4);
//	input.push_back(6);
//	out = twoSum(input, 7);
//	for (int a : out) {
//		cout << a << " ";
//	}
//	system("pause");
//	return  0;
//
//}