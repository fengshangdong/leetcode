#include<cstdio>
#include<vector>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		/* 返回条件 */
		if (lists.size() == 0) {
			return NULL;
		}
		if (lists.size() == 1) {
			return lists[0];
		}
		if (lists.size() == 2) {
			return mergeLists(lists[0], lists[1]);
		}

		/* 分治算法 - 类似于归并排序 */
		vector<ListNode*> v1;
		vector<ListNode*> v2;
		for (int i = 0; i < lists.size(); i++) {
			if (i < lists.size()/2)
				v1.push_back(lists[i]);
			else
				v2.push_back(lists[i]);
		}

		ListNode *s1 = mergeKLists(v1);
		ListNode *s2 = mergeKLists(v2);
		return mergeLists(s1,s2);
	}
private:
	ListNode *mergeLists(ListNode *s1, ListNode *s2) {
		/* 取新头结点head构造新链表 */
		ListNode head(0);
		ListNode *head_ptr = &head;
		/*取s1和s2所有结点*/
		while (s1 || s2) {
			/* 当s1搜索完成且s2有剩余,将s2中剩余的结点插入新链表中*/
			/* 当s2搜索完成且s1有剩余,则将s1中剩余的结点插入新链表中*/
			if (!s1) {
				while (s2) {
					head_ptr->next = s2;
					head_ptr = s2;
					s2 = s2->next;
				}
				continue;
			}
			else if (!s2) {
				while (s1) {
					head_ptr->next = s1;
					head_ptr = s1;
					s1 = s1->next;
				}
				continue;
			}

			/*比较s1和s2中,结点值大小,较小优先插入新链表中*/
			if (s1->val < s2->val) {
				head_ptr->next = s1;
				head_ptr = s1;
				s1 = s1->next;
			}
			else
			{
				head_ptr->next = s2;
				head_ptr = s2;
				s2 = s2->next;
			}
		}

		return head.next;
	}
};

void printList(ListNode *head) {
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

int main() {
	ListNode node1(1);
	ListNode node2(4);
	ListNode node3(5);
	ListNode node4(1);
	ListNode node5(3);
	ListNode node6(4);
	ListNode node7(2);
	ListNode node8(6);

	/* 1->4->5 */
	/* 1->3->4 */
	/* 2->6    */
	node1.next = &node2;
	node2.next = &node3;
	node4.next = &node5;
	node5.next = &node6;
	node7.next = &node8;
	vector<ListNode*> vec;
	vec.push_back(&node1);
	vec.push_back(&node4);
	vec.push_back(&node7);

	Solution solve;
	printList(&node1);
	printList(&node4);
	printList(&node7);
	printList(solve.mergeKLists(vec));
}
