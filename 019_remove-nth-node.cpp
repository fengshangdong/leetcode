#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || n <= 0) return NULL;

    ListNode *newhead = new ListNode(0);
    newhead->next = head;
    int len = length(newhead);
    ListNode *ptr = newhead;
    for (int i = 0; i < len-n-1; i++) {
      ptr = ptr->next;
    }

    ptr->next = ptr->next->next;
    return newhead->next;
  }

  int length(ListNode* head) {
    if (!head)
      return 0;

    int count = 0;
    while (head) {
      head = head->next;
      count ++;
    }

    return count;
  }
};

int main() {
  return 0;
}

