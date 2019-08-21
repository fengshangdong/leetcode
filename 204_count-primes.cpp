#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    int count=1;
    if(n<3) return 0;
    for(int i=3;i<n;i+=2)
    {
      if(isPrime(i))
        count++;
    }
    return count;
  }

  bool isPrime(int n) {
    if(n==2)
      return true;
    if(n%2==0)
      return false;

    for (int i = 3; i <= sqrt(n); i+=2) {
      if (n%i == 0)
        return false;
    }
    return true;
  }
};

class Solution2 {
public:
  int countPrimes(int n) {
    if(n<=1){
      return 0;
    }

    //初始化为素数，这样可以把所有元素都初始化为false。
    //bool a[n] = {false};
    vector<bool> a(n,false);
    int count = 0;
    //素数的倍数，都不是素数
    for(int i = 2; i<n; i++){
      if(!a[i]){//素数
        count++;//第一个数是2，一定是素数
        for(int j=2;j*i<n;j++){
          a[j*i] = true;
        }
      }
    }
    return count;
  }
};

int main() {
  int n = 10;
  Solution solv;
  int ret = solv.countPrimes(n);
  printf("ret=%d\n", ret);
}

