class Solution
{
  public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> result;
        if (row == 0 || col == 0)
            return result;
        int left = 0, right = col - 1, top = 0, btm = row - 1;
        while (left <= right && top <= btm)
        {
            for (int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            if (top < btm)
                for (int i = top + 1; i <= btm; i++)
                    result.push_back(matrix[i][right]);
            if (top < btm && left < right)
                for (int i = right - 1; i >= left; i--)
                    result.push_back(matrix[btm][i]);
            if (top + 1 < btm && left < right)
                for (int i = btm - 1; i >= top + 1; i--)
                    result.push_back(matrix[i][left]);
            left++;
            right--;
            top++;
            btm--;
        }
        return result;
    }
};

class Solution
{
  public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        while (row > start * 2 && col > start * 2)
        {
            for (int i = start; i <= col - 1 - start; i++)
            {
                ans.push_back(matrix[start][i]);
            }
            if (start < row - start - 1)
            {
                for (int i = start + 1; i <= row - 1 - start; i++)
                {
                    ans.push_back(matrix[i][col - 1 - start]);
                }
            }
            if (start < col - start - 1 && start < row - start - 1)
            {
                for (int i = col - 2 - start; i >= start; i--)
                {
                    ans.push_back(matrix[row - start - 1][i]);
                }
            }
            if (start < col - start - 1 && start < row - start - 2)
            {
                for (int i = row - 2 - start; i >= start + 1; i--)
                {
                    ans.push_back(matrix[i][start]);
                }
            }
            start++;
        }
        return ans;
    }
};

class Solution
{
  public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        int layer = (min(m, n) - 1) / 2 + 1;
        for (int i = 0; i < layer; i++)
        {
            for (int j = i; j < m - i; j++)
            {
                res.push_back(matrix[i][j]);
            }
            for (int k = i + 1; k < n - i; k++)
            {
                res.push_back(matrix[k][m - i - 1]);
            }
            for (int p = m - i - 2; (p > i - 1) && (n - i - 1 != i); p--)
            {
                res.push_back(matrix[n - i - 1][p]);
            }
            for (int q = n - i - 2; (q > i) && (m - i - 1 != i); q--)
            {
                res.push_back(matrix[q][i]);
            }
        }
        return res;
    }
};
