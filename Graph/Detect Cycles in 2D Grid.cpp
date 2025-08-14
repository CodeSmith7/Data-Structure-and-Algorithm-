//usinf dfs 
// class Solution {
// public:
//     int m, n, cycle;

//     void dfs( int row, int col, int pr, int pc, vector<vector<char>>& grid, vector<vector<int>>& color) {
//         color[row][col] = 1;

//         int delrow[] = {-1,0,1,0};
//         int delcol[] = {0,1,0,-1};


//         for ( int i = 0; i < 4;i++) {
//             int nrow = row + adelrow[i];
//             int ncol = col + delcol[i];

//             if (  nrow == pr && ncol == pc ) {
//                 continue;
//             }

//             if ( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == grid[row][col] )  {
//                 if (color[nrow][ncol] == 1) {
//                     cycle = 1;
//                     break;
//                 }
//                 if (color[nrow][ncol] == 0) {
//                     dfs(nrow,ncol, row, col, grid, color);
//                 } 
                
//             }
//         }

//         color[row][col] = 2;
//     }


//     bool containsCycle(vector<vector<char>>& grid) {
//         n = grid.size();
//         m = grid[0].size();
//         vector<vector<int>> color(n, vector<int>(m,0));

//         cycle = 0;
//         for ( int i = 0; i < n; i++) {
//             for ( int j = 0; j < m; j++) {
//                 if (color[i][j]==0) {
//                     dfs(i,j,-1,-1,grid,color);
//                 }
//             }
//         }
        
//         return cycle;
//     }
// };

// using bfs 


class Solution {
public:
    int m, n, cycle;

   


    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> color(n, vector<int>(m,0));

        cycle = 0;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        queue<pair<pair<int,int>,pair<int,int>>> q;
        
        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {
                if (color[i][j]==0) {

                    
                    
                    q.push({{i, j},{-1,-1}});

                    while (!q.empty()) {
                        auto curr = q.front();
                        int r = curr.first.first;
                        int c = curr.first.second;
                        int pr = curr.second.first;
                        int pc = curr.second.second;
                        q.pop();

                        color[r][c] = 1;

                        for ( int i = 0; i < 4; i++) {
                            int nrow = r+ delRow[i];
                            int ncol = c+ delCol[i];

                            if (nrow == pr && ncol == pc) {
                                continue;
                            }

                            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == grid[r][c]) {
                                if ( color [nrow][ncol] == 1) {
                                    return true;
                                }

                                if ( color[ nrow][ncol] == 0) {
                                    q.push({{nrow,ncol},{r,c}});
                                }
                            }
                        }

                    
                    }
                }
            }
        }
        
        return cycle;
    }
};
