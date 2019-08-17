#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

long long minArea(int& n)
{
    long long minx = INT64_MAX, miny = INT64_MAX, maxx = INT64_MIN, maxy = INT64_MIN;

    // 读入数据的时候就计算
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }

    // 计算结果
    long long edge = max(abs(maxx - minx), abs(maxy - miny));
    return edge * edge;
}

int main()
{
    // 读入数据
    int n;
    cin >> n;
    cout << minArea(n) << endl;
    return 0;
}
