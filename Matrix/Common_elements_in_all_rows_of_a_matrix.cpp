void findCommon(vector<vector<int>> const &mat)
{
    if (mat.size() == 0) {
        return;
    }
 
    unordered_map<int, int> map;
 
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (i == 0) {
                map[mat[0][j]] = 1;
            }
            if (i > 0 && map[mat[i][j]] == i)
            {
                map[mat[i][j]] = i + 1;
                if (i == mat.size() - 1) {
                    cout << mat[i][j] << " ";
                }
            }
        }
    }
}