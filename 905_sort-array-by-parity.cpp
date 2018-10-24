#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int i = -1;
		int k = A.size();
		/* 快排的原理 */
		/* 分别从头部和尾部遍历,进行交换 */
		while (1) {
			do {
				i++;
			} while (A[i] % 2 == 0);

			do {
				k--;
			} while (A[k] % 2 == 1);

			if (i >= k) {
				break;
			}
			else {
				std::swap(A[i], A[k]);
			}
		}

		return A;
	}
};

int main()
{
	int arr[] = {3, 1, 5, 6, 2, 4};
	vector<int> v;
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		v.push_back(arr[i]);
	}

	Solution solve;
	solve.sortArrayByParity(v);
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}
