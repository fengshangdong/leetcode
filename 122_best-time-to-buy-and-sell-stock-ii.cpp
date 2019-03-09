#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty())
      return 0;

    int count = 0;
    int minflag = prices[0];
    int maxflag = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      if (maxflag < prices[i]) {
        maxflag = prices[i];
      }
      else {
        count += maxflag - minflag;
        minflag = prices[i];
        maxflag = prices[i];
      }
    }
    count += maxflag - minflag;
    return count;
  }
};

int main() {
  int arr[] = {1,2,3,4,5};
  vector<int> vec;
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    vec.push_back(arr[i]);
  }

  Solution solve;
  printf("%d\n", solve.maxProfit(vec));
}
