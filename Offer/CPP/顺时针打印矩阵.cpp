// 顺时针打印矩阵.cpp
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ret;
        if (row == 0 || col == 0)
            return ret;
        int left = 0, right = col - 1, top = 0, btm = row - 1;
        while (left <= right && top <= btm) {
            for (int i = left; i <= right; i++)
                ret.push_back(matrix[top][i]);
            if (top < btm)
                for (int i = top + 1; i <= btm; i++)
                    ret.push_back(matrix[i][right]);
            if (top < btm && left < right)
                for (int i = right - 1; i >= left; i--)
                    ret.push_back(matrix[btm][i]);
            if (top + 1 < btm && left < right)
                for (int i = btm - 1; i >= top + 1; i--)
                    ret.push_back(matrix[i][left]);
            left++;
            right--;
            top++;
            btm--;
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> ret;
        int n = matrix.size();
        int m = matrix[0].size();
        int layer = (min(m, n) - 1) / 2 + 1;
        for (int i = 0; i < layer; i++) {
            for (int j = i; j < m - i; j++)
                ret.push_back(matrix[i][j]);
            for (int k = i + 1; k < n - i; k++)
                ret.push_back(matrix[k][m - i - 1]);
            for (int p = m - i - 2; (p > i - 1) && (n - i - 1 != i); p--)
                ret.push_back(matrix[n - i - 1][p]);
            for (int q = n - i - 2; (q > i) && (m - i - 1 != i); q--)
                ret.push_back(matrix[q][i]);
        }
        return ret;
    }
};

// 使用翻转矩阵的思路
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> ret;
        while (matrix.size() > 0) {
            for (int i = 0; i < matrix[0].size(); i++)
                ret.push_back(matrix[0][i]); // 取出第一行
            matrix.erase(matrix.begin()); // 删除第一行
            if (matrix.size() <= 0 || matrix[0].size() <= 0)
                break;
            matrix = turn(matrix);
        }
        return ret;
    }

    vector<vector<int>> turn(vector<vector<int>> matrix)
    {
        vector<vector<int>> newmat;
        for (int i = matrix[0].size() - 1; i >= 0; i--) {
            vector<int> tmp;
            for (int j = 0; j < matrix.size(); j++)
                tmp.push_back(matrix[j][i]);
            newmat.push_back(tmp);
        }
        return newmat;
    }
};
