#include <bits/stdc++.h>
using namespace std;
// Function to solve 0/1 Knapsack using DP
int knapsack(int W, vector<int> &val, vector<int> &wt, int n) {
vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
// Build table dp[][] in bottom-up manner
for (int i = 1; i <= n; i++) {
for (int w = 1; w <= W; w++) {
if (wt[i - 1] <= w)
dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
else
dp[i][w] = dp[i - 1][w];
}
}
return dp[n][W];
}
int main() {
int n, W;
cout << "Enter number of items: ";
cin >> n;
vector<int> val(n), wt(n);
cout << "Enter values of items:\n";
for (int i = 0; i < n; i++) cin >> val[i];
cout << "Enter weights of items:\n";
for (int i = 0; i < n; i++) cin >> wt[i];
cout << "Enter capacity of knapsack: ";
cin >> W;
int maxVal = knapsack(W, val, wt, n);
cout << "\nMaximum value that can be obtained = " << maxVal << endl;
return 0;
}
