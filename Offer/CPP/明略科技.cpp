#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

string calculateStringDistance(string str1, string str2)
{
    ll m = str1.size(), n = str2.size();
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
    for (ll j = 1; j <= n; j++) {
        dp[0][j] = j;
    }
    for (ll i = 1; i <= m; i++) {
        dp[i][0] = i;
    }

    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    return "1/" + to_string(dp[m][n] + 1);
}

int main(void)
{
    string str1, str2;
    while (cin >> str1 >> str2) {
        string ret = calculateStringDistance(str1, str2);
        cout << ret << endl;
    }
    return 0;
}
