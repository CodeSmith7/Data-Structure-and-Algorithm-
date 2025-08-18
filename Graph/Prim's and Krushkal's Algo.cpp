//Prim's Algorithm 
// class Solution {
//   public:
//     typedef pair<int,int> p;
//     int spanningTree(int V, vector<vector<int>>& edges) {
//         // code here
//         vector<vector<pair<int,int>>> graph(V);
        
//         for (auto it : edges) {
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
            
//             graph[u].push_back ({v,wt});
//             graph[v].push_back ({u,wt});
//         }
        
//         priority_queue<pair<int, p> ,vector<pair<int,p>>, greater<pair<int,p>>> pq;
        
//         vector <int> visited(V,0);
//         int sum = 0;
        
//         pq.push({0,{0,-1}});
//         vector<p> mst;
        
//         while (!pq.empty()) {
//             auto it = pq.top();
//             pq.pop();
//             int wt = it.first;
//             int node = it.second.first;
//             int par = it.second.second;
//             if (visited[node]) {
//                 continue;
//             }
//             visited[node] = 1;
//             sum = sum + wt;
//             if (par != -1) {
//                 mst.push_back({par,node});
//             }
            
            
            
//             for ( auto it : graph[node]) {
//                 int adjNode = it.first;
//                 int adjWt = it.second;
                
//                 if (!visited[adjNode] ) {
//                     pq.push({adjWt,{adjNode,node}});
//                 }
                
//             }
            
//         }
        
        
        
//         return sum;
//     }
// };


//Krushkal's algo 

class DSU {
    vector<int> rank, parent;
    public:
    DSU(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for ( int i = 0; i <  n ; i++) {
            parent[i] = i;
        }
    }
    int findUpar ( int node) {
        if (node == parent[node] ) {
            return node;
        }
        
        return parent[node] = findUpar(parent[node]);
    }
    void unionByRank(int u , int v) {
        int ulp_u = parent[u];
        int ulp_v = parent[v];
        if (ulp_u  == ulp_v) return;
        
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
  public:
    typedef pair<int,int> p;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, pair<int,int>>> ed;
        
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            ed.push_back({wt,{u,v}});
        }
        
        sort (begin(ed), end(ed));
        int mstWt = 0;
        
        DSU ds(V);
        for ( auto it : ed) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if (ds.findUpar(u) != ds.findUpar(v) ) {
                mstWt += wt;
                ds.unionByRank(u,v);
            }
        }
        return mstWt;
    }
};
