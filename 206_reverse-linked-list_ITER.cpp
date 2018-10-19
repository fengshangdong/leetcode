#include<vector>
#include<cstdio>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode *new_head = NULL;
		/* 每次取头结点构成新的逆序列表 */
		while(head) {
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}

		return new_head;
	}
};

/* 打印链表 */
void printNode(ListNode *head) {
	while(head) {
		ListNode *next = head->next;
		printf("%d ", head->val);
		head = next;
	}
	printf("\n");
}

int main()
{
	ListNode node1(3);
	ListNode node2(4);
	ListNode node3(5);
	ListNode node4(6);
	ListNode node5(7);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	printNode(&node1);

	Solution solve;
	ListNode* new_head = solve.reverseList(&node1);
	printNode(new_head);
}
