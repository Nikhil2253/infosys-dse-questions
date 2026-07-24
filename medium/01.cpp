#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int defeatmonsters(int count, int e, vector<pair<int, int>>& monsters, int n) {
    for (int i = 0; i < n; i++) {
        if (e >= monsters[i].first) {
            e += monsters[i].second;
            count++;
        }
    }
    return count;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> monsters(n);

    for (int i = 0; i < n; i++) {
        cin >> monsters[i].first;
    }

    for (int i = 0; i < n; i++) {
        cin >> monsters[i].second;
    }

    sort(monsters.begin(), monsters.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.first < b.first;
         });

    cout << defeatmonsters(0, e, monsters, n);

    return 0;
}