class Solution {
private:
    char *matrix1, *str1;
    int rows1, cols1;
    bool* visited;

public:
    bool findNext(int row, int col, int& paths)
    {
        // 递归出口
        if (str1[paths] == '\0')
            return true;
        bool hasPath = false;
        // 当前行号列号没有超出边界并且矩阵元素等于比较元素且还未被访问
        if ((row >= 0 && row < rows1 && col >= 0 && col < cols1)
            && (matrix1[col + row * cols1] == str1[paths] && !visited[col + row * cols1])) {
            paths++; // 访问下一个字符
            visited[col + row * cols1] = true; // 当前元素已经访问

            // 继续访问下一个 上下左右
            hasPath = findNext(row - 1, col, paths)
                || findNext(row + 1, col, paths)
                || findNext(row, col - 1, paths)
                || findNext(row, col + 1, paths);

            // 如果下一个元素不满足条件，就回溯
            if (!hasPath) {
                paths--;
                visited[col + row * cols1] = false;
            }
        }

        return hasPath;
    }

    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (rows < 1 || cols < 1 || matrix == nullptr || str == nullptr)
            return false;
        // 类属性赋值
        matrix1 = matrix;
        str1 = str;
        rows1 = rows;
        cols1 = cols;
        visited = new bool[rows * cols];
        memset(visited, false, rows * cols); // initialize

        // 先要找到遍历的入口 随便进入
        int paths = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (findNext(i, j, paths))
                    return true;
            }
        }

        // 内存清理
        if (visited != nullptr)
            delete[] visited;
        return false;
    }
};