//DFS
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,int oldColor, int newColor)
    {
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != oldColor)
        {
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,oldColor,newColor);
        dfs(image,i+1,j,oldColor,newColor);
        dfs(image,i,j-1,oldColor,newColor);
        dfs(image,i,j+1,oldColor,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int oldColor= image[sr][sc];
        dfs(image,sr,sc,oldColor,newColor);
        return image;
    }
};

//BFS
class Solution {
public:
    vector<vector<int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
     int t=image[sr][sc];
     image[sr][sc]=newColor;
     queue<pair<int,int>> q;
     int ROWS = image.size();
     int COLS = image[0].size();
     vector<vector<bool>> seen(ROWS, vector<bool>(COLS, false));
        q.push({sr,sc});
        seen[sr][sc] = true;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            for(auto& dir : dir) {
                int dr = dir[0] + r;
                int dc = dir[1] + c;
                if(dr < 0 || dr >= ROWS) continue;
                if(dc < 0 || dc >= COLS) continue;
                if(seen[dr][dc]) continue; 
                seen[dr][dc] = true;
                if(image[dr][dc]==t)
                image[dr][dc]=newColor;
                else
                continue;    
                q.push({dr, dc});
            }
        }  
     return image;   
    }
};