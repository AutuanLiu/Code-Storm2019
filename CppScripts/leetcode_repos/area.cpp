#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

long long minArea(int& n)
{
	long long minx = INT64_MAX, miny = INT64_MAX, maxx = INT64_MIN, maxy = INT64_MIN;

	// �������ݵ�ʱ��ͼ���
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
	}

	// ������
	long long x = abs(maxx - minx), y = abs(maxy - miny);
	long long edge = max(x, y);
	return edge * edge;
}

int main()
{
	// ��������
	int n;
	cin >> n;
	cout << minArea(n) << endl;
	return 0;
}