#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Comparison function to sort items based on value/weight ratio
bool compare(vector<int>& a, vector<int>& b) {
double a1 = (1.0 * a[0]) / a[1];
double b1 = (1.0 * b[0]) / b[1];
return a1 > b1;
}
// Function to calculate maximum value for given capacity
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
int n = val.size();
// Create 2D vector to store value and weight
// items[i][0] = value, items[i][1] = weight
vector<vector<int>> items(n, vector<int>(2));
for (int i = 0; i < n; i++) {
items[i][0] = val[i];
items[i][1] = wt[i];
}
// Sort items based on value-to-weight ratio in descending order
sort(items.begin(), items.end(), compare);
double res = 0.0;
int currentCapacity = capacity;
// Process items in sorted order
for (int i = 0; i < n; i++) {
if (items[i][1] <= currentCapacity) {
// Take full item
res += items[i][0];
currentCapacity -= items[i][1];
} else {
// Take fractional part
res += (1.0 * items[i][0] / items[i][1]) * currentCapacity;
break; // Knapsack full
}
}
return res;
}
int main() {
int n;
cout << "Enter number of items: ";
cin >> n;
vector<int> val(n), wt(n);
for (int i = 0; i < n; i++) {
cout << "Enter value and weight of item " << i + 1 << ": ";
cin >> val[i] >> wt[i];
}
int capacity;
cout << "Enter capacity of knapsack: ";
cin >> capacity;
double maxValue = fractionalKnapsack(val, wt, capacity);
cout << "\nMaximum value we can obtain = " << maxValue << endl;
return 0;
}
