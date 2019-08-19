#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int sum = 0;
    int size = prices.size();

    if (size < 2)
      return 0;

    for (int i = 1; i < size; i++)
      sum += std::max(0, prices[i]-prices[i-1]);
    return sum;
  }
};

int main() {
  int arr[] = {7,1,5,3,6,4};
  vector<int> vec;
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    vec.push_back(arr[i]);
  }

  Solution solve;
  printf("%d\n", solve.maxProfit(vec));
}
