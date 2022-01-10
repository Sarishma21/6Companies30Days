#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
          // DP of Transaction Count vs Price
        vector<vector<int>> TP(K+1, vector<int>(N+1, 0));

        for(int t = 1; t <= K; ++t) {
            for(int p = 1; p <= N; ++p) {
                TP[t][p] = TP[t][p - 1];
                for(int i = 0; i < p; ++i) {
                    TP[t][p] = max(TP[t][p], TP[t-1][i] + A[p-1] - A[i]);
                }
            }
        }
        return TP.back().back();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}