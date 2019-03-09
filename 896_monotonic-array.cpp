#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  bool isMonotonic(vector<int>& A) {
    if(A.size()<=2) return true;
    int trend = 0,pre = trend;
    for(int i = 1; i < A.size(); i++){
      trend = A[i]-A[i-1];
      if(trend == 0) continue;
      if(pre*trend < 0) return false;
      pre = trend;
    }
    return true;
  }
};

int main()
{
  int arr[] = {6,5,4,4};
  vector<int> vec;
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    vec.push_back(arr[i]);
  }

  Solution solve;
  printf("%d\n", solve.isMonotonic(vec));
}
