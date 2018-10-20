#include<cstdio>

/* Definition for singly-linked list. */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode*);

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode less_head(0);
		ListNode more_head(0);
		ListNode *less_ptr = &less_head;
		ListNode *more_ptr = &more_head;
		while(head) {
			if (head->val < x) {
				less_ptr->next = head;
				less_ptr = head;
			}
			else
			{
				more_ptr->next = head;
				more_ptr  = head;
			}
			head = head->next;
		}
		less_ptr->next = more_head.next;
		more_ptr->next = NULL;
		
		return less_head.next;
	}
};

void printList(ListNode *head) {
	while (head) {
		printf("%d ",head->val);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	int x = 3;
	ListNode node(1);
	ListNode node1(4);
	ListNode node2(3);
	ListNode node3(2);
	ListNode node4(5);
	ListNode node5(2);
	node.next = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	printList(&node);
	Solution solve;
	ListNode *res = solve.partition(&node, x);
	printList(res);
}
