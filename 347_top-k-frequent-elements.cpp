#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
  struct Node {
    int val;
    int cnt;
    Node(int value, int count): val(value), cnt(count) { }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    vector<Node> v;
    int val, cnt;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); /**/) {
      cnt = 0;
      val = nums[i];
      while (i < nums.size() && nums[i] == val)
        i++, cnt++;

      v.push_back(Node(val, cnt));
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < k; i++)
      res.push_back(v[i].val);
    return res;
  }

  static bool cmp(const Node& left, const Node& right) {
    return left.cnt > right.cnt;
  }
};

int main() {
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(2);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(1);
  vec.push_back(3);
  vec.push_back(1);
  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(7);
  for (int i = 0; i < vec.size(); i++)
    printf("%d ", vec[i]);
  printf("\n");

  Solution solv;
  vector<int> res = solv.topKFrequent(vec, 3);
  for (int i = 0; i < res.size(); i++)
    printf("%d ", res[i]);
  printf("\n");

}
