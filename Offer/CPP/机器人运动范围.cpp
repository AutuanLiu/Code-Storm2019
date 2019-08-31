// 机器人运动范围
// 回溯算法

class Solution {
private:
    int rows1, cols1, the;
    bool* visited;

public:
    // 求两个数各位数字之和
    int get_sum(int a, int b)
    {
        int ret = 0;
        while (a) {
            ret += a % 10;
            a /= 10;
        }

        while (b) {
            ret += b % 10;
            b /= 10;
        }

        return ret;
    }

    int count(row, col)
    {
        // 可以访问 就访问上下左右
        if ((row >= 0 && row < rows && col >= 0 && col < cols)
            && (get_sum(row, col) <= the && !visited[row * cols + col])) {
            visited[row * cols + col] = true;

            return 1 + count(row - 1, col) + count(row + 1, col) + count(row, col - 1) + count(row, col + 1);
        }
        return 0;
    }

    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0 || (rows < 0 && cols < 0))
            return 0;
        // 属性赋值
        rows1 = rows;
        cols1 = cols;
        the = threshold;
        visited = new int[rows * cols];
        memset(visited, false, rows * cols);
        int ret = count(0, 0);
        if (visited != nullptr)
            delete[] visited;
        return ret;
    }
};