#include <stdio.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next)
      return head;
    
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* head2 = even;

    while (even->next && odd->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      if (odd->next) {
        even = even->next;
      }
    }

    odd->next = head2;
    return head;
  }
};

int main() {
  ListNode head(0);
  ListNode nod1(1);
  ListNode nod2(2);
  ListNode nod3(3);
  ListNode nod4(4);
  ListNode nod5(5);
  ListNode nod6(6);
  ListNode nod7(7);

  head.next = &nod1;
  nod1.next = &nod2;
  nod2.next = &nod3;
  nod3.next = &nod4;
  nod4.next = &nod5;
  nod5.next = &nod6;
  nod6.next = &nod7;

  Solution solv;
  ListNode* res = solv.oddEvenList(&head);
  while (res) {
    printf("%d ",res->val);
    res = res->next;
  }
  printf("\n");
}
