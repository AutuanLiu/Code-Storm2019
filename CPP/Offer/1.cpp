class Solution
{
  public:
    bool Find(int target, vector<vector<int>> array)
    {
        // bool found = false;
        if (array.size() != 0)
        {
            int row = 0;
            int col = array[0].size() - 1;
            while (row < array.size() && col >= 0)
            {
                if (array[row][col] == target)
                    return true;
                else if (array[row][col] > target)
                    --col;
                else
                    ++row;
            }
        }
        return false;
    }
};

class Solution
{
  public:
    bool Find(int target, vector<vector<int>> array)
    {
        int row = array.size();
        int col = array[0].size();
        int i, j;
        for (i = row - 1, j = 0; i >= 0 && j < col;)
        {
            if (target == array[i][j])
                return true;
            else if (target < array[i][j])
            {
                i--;
                continue;
            }
            else
            {
                j++;
                continue;
            }
        }
        return false;
    }
};
