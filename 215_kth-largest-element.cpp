#include <stdio.h>
#include <vector>
using namespace std;

void heap_push(vector<int>& heap, int data) {
  int ipos = heap.size();
  int ppos = (ipos - 1)/2;
  heap.push_back(data);
  while (ipos > 0 && heap[ipos] > heap[ppos]) {
    swap(heap[ipos], heap[ppos]);
    ipos = ppos;
    ppos = (ipos - 1)/2;
  }
  return ;
}

void heap_pop(vector<int>& heap) {
  if (heap.empty()) return;
  swap(heap[0], heap[heap.size()-1]);
  heap.pop_back();

  int ipos = 0, lpos, rpos, mpos;
  while (1) {
    lpos = ipos * 2 + 1;
    rpos = ipos * 2 + 2;
    if (lpos < heap.size() && heap[lpos] > heap[ipos])
      mpos = lpos;
    else
      mpos = ipos;

    if (rpos < heap.size() && heap[rpos] > heap[mpos])
      mpos = rpos;

    if (mpos == ipos) {
      break;
    }
    else {
      swap(heap[ipos], heap[mpos]);
      ipos = mpos;
    }
  }
  return ;
}

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
      heap_push(res, nums[i]);
    
    for (int i = 0; i < k-1; i++)
      heap_pop(res);

    return res[0];
  }
};

int main() {
  vector<int> vec;
  heap_push(vec, 3);
  heap_push(vec, 2);
  heap_push(vec, 5);
  heap_push(vec, 1);
  heap_push(vec, 4);
  heap_push(vec, 0);
  for (int i = 0; i < vec.size(); i++)
    printf("%d ",vec[i]);
  printf("\n");

  Solution solv;
  int ret = solv.findKthLargest(vec, 3);
  printf("ret=%d\n",ret);
}
