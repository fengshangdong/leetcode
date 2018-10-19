#include<vector>
#include<cstdio>
#include<cstdlib>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		/* 额外插入一个头结点,便于取前置结点prev */
		ListNode *sentine = new ListNode(0);
		sentine->next = head;
		head = sentine;

		/* res保留原头结点 */
		ListNode *res = head;

		/* prev为m位置的前置结点 */
		ListNode *prev = head;
		for (int i = 0; i < m; i++) {
			prev = head;
			head = prev->next;
		}
		/* new_head是m..n的逆置后的头 */
		/* new_tail是m..n的逆置后的尾 */
		ListNode *new_tail = head;
		ListNode *new_head = NULL;
		for (int j = m; j <= n; j++) {
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}

		/* 此时的head是n位置的后置结点 */
		prev->next = new_head;
		new_tail->next = head;

		res = res->next;
		free(sentine);
		return res;        
	}
};

void printList(ListNode *head) {
	while(head) {
		printf("%d ", head->val);
		ListNode *next = head->next;
		head = next;
	}
	printf("\n");
}

int main()
{
	ListNode node1(1);
	ListNode node2(2);
	node1.next = &node2;
	printList(&node1);

	Solution solve;
	ListNode *NewList = solve.reverseBetween(&node1, 1, 2);
	printList(NewList);
}
