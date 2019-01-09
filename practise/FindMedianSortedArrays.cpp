#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	double result=0.0;
	vector<int>vecCombination  ;
	size_t lenNum1 = nums1.size();
	size_t lenNum2 = nums2.size();

	vecCombination.resize(lenNum1 + lenNum2);
	vector<int> nums1_buf = nums1;
	vector<int> nums2_buf = nums2;
	if ((lenNum1 + lenNum2) == 0) return result;
	if (lenNum1 > 0) sort(nums1_buf.begin(), nums1_buf.begin()+lenNum1);
	if (lenNum2 > 0) sort(nums2_buf.begin(), nums2_buf.begin() + lenNum2);
	merge(nums1_buf.begin(), nums1_buf.end(), nums2_buf.begin(), nums2_buf.end(), vecCombination.begin());
	
	size_t lenvecCombination = vecCombination.size();
	if (lenvecCombination % 2 == 0) result = (double)(vecCombination[lenvecCombination / 2] + vecCombination[lenvecCombination / 2 - 1]) / 2;
	else {
		result = vecCombination[lenvecCombination / 2];
	}
	return result;



}
//int main() {
//	vector<int> nums1_buf;
//	nums1_buf.push_back(1);
//	nums1_buf.push_back(2);
//
//	vector<int> nums2_buf;
//	nums2_buf.push_back(3);
//	nums2_buf.push_back(4);
//	cout<<findMedianSortedArrays(nums1_buf, nums2_buf)<<endl;
//	system("pause");
//	return 0;
//}