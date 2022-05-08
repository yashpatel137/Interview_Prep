/*
    Time Complexity: O(N^4)
    Space Complexity: O(N^2),

    where N is the number of nodes.
*/
int findDeterminant(vector<vector<int>> Matrix)
{
    // Variable to store the determinant value
    int det = 0;
    if (Matrix.size() == 1)
    {
        return Matrix[0][0];
    }

    else if (Matrix.size() == 2)
    {
        det = (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
        return det;
    }

    else
    {

        for (int p = 0; p < Matrix[0].size(); p++)
        {
            vector<vector<int>> tempMatrix;
            for (int i = 1; i < Matrix.size(); i++)
            {
                vector<int> row;
                for(int j = 0; j < Matrix[i].size(); j++)
                {
                    if (j != p)
                    {
                        row.push_back(Matrix[i][j]);
                    }

                }

                if (row.size() > 0)
                {
                    tempMatrix.push_back(row);
                }

            }

            det = det + Matrix[0][p] * pow(-1, p) * findDeterminant(tempMatrix);

        }

        return det;
    }

}




int spanningTrees(vector<vector<int>> &adjMatrix, int n, int m)
{

    // Degree of each node will be stored in this
    int degree[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                // Calculating degree of each node
                degree[i]++;
            }

        }

    }

    // Updating the values of primary diagonal with degree of the node
    for (int i = 0; i < n; i++)
    {
        adjMatrix[i][i] = degree[i];
    }

    // Replacing all 1 in the matrix which are not present on primary diagonal with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i != j) and adjMatrix[i][j] == 1)
            {
                adjMatrix[i][j] = -1;
            }

        }

    }

    // Submatrix of size (n-1)*(n-1) in which 1st row and 1st column values will not be there
    vector<vector<int>>submatrix(n - 1, vector<int>(n - 1));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            submatrix[i - 1][j - 1] = adjMatrix[i][j];
        }

    }

    // This will be the answer as (-1)^(1+1) will be equal to 1 only
    return  findDeterminant(submatrix);
}