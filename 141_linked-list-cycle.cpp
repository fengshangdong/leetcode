#include<cstdio>

/* Definition for singly-linked list. */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *s1 = head;
		ListNode *s2 = head;
		/* s2比s1快,如果有环一定会相遇 */
		while (s1 && s2 && s2->next) {
			s1 = s1->next;
			s2 = s2->next->next;

			if (s1 == s2) {
				return true;
			}
		}

		return false;
	}
};

void printList(ListNode *head, int length) {
	while(head && length) {
		printf("%d ",head->val);
		head = head->next;
		length--;
	}
	printf("\n");
}

int main() 
{
	ListNode node(2);
	ListNode node1(3);
	ListNode node2(4);
	ListNode node3(5);
	ListNode node4(6);
	ListNode node5(7);

	/* 2, 3, 4, 5, 6, 7, 5 ... */
	node.next = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node3;

	int length = 7;
	printList(&node, length);
	Solution solve;
	printf("%d\n", solve.hasCycle(&node));
}
