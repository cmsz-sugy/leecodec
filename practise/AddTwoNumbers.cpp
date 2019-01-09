#include<iostream>
using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *newLinkNode = new ListNode(0);
	ListNode *result = new ListNode(0);
	newLinkNode = result;
	ListNode *newLinkNode1 = l1;
	ListNode *newLinkNode2 = l2;
	int carryFlag = 0;
	int l_num1 = 0;
	int l_num2 = 0;
	while (newLinkNode1 != nullptr || newLinkNode2 != nullptr) {
		if (newLinkNode1 != nullptr) l_num1 = newLinkNode1->val;
		if (newLinkNode2 != nullptr)
			l_num2 = newLinkNode2->val;
		int sum = l_num1 + l_num2 + carryFlag;
		carryFlag = 0;
		if (sum >= 10) {
			sum -= 10;
			carryFlag = 1;
		}
		newLinkNode->val = sum;
		sum = 0;
		newLinkNode = newLinkNode->next;
		newLinkNode = new ListNode(0);
		newLinkNode1 = newLinkNode1->next;
		newLinkNode2 = newLinkNode2->next;
	}
	if (carryFlag > 0) {
		newLinkNode = new ListNode(carryFlag);
	}
	return result;
}
//int main() {
//	ListNode *l1 = NULL;
//	l1 = new ListNode(1);
//	l1->next = new ListNode(9);
//
//	ListNode *l2 = NULL;
//	l2 = new ListNode(9);
//	l2->next = new ListNode(0);
//
//	cout << l2->next->val << endl;
//	ListNode *result=addTwoNumbers(l1, l2);
//
//	system("pause");
//	return 0;
//
//}

