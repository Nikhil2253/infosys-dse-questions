#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10000;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> prev(n + 1, 1), curr(n + 1, 0);

    for (int len = 2; len <= k; len++) {
        fill(curr.begin(), curr.end(), 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                curr[j] = (curr[j] + prev[i]) % MOD;
            }
        }

        prev = curr;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + prev[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}