// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int V = points.size();

//         priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (wt, u)
//         vector<bool> mst(V, false);
        
//         int src = 0;
//         pq.push(make_pair(0, src));
        
//         int minCost = 0;

//         while(!pq.empty()) {
//             int u = pq.top().second;
//             int wt = pq.top().first;
//             pq.pop();

//             if(!mst[u]) {
//                 mst[u] = true;
//                 minCost += wt;
                
//                 // Since every point can be connected with each other point and we have n (=V) point and can connect with every other point therefore it can connect with n-1 points (which means v-1) 
//                 for(int v=0; v<V; v++) {
//                     if(u != v) { // Which means source is not equal to destination. In short the point can't connect with itself but can with rest.
//                         if(!mst[v]) {
//                             int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
//                             pq.push(make_pair(wt, v));
//                         }
//                     }
//                 }
//             }
//         }

//         return minCost;
//     }
// };