// class Info {
// public:

//     int u;
//     int cost;
//     int stops; //Stops required to reach from src to u

//     Info(int u, int c, int s) {
//         this->u = u;
//         this->cost = c;
//         this->stops = s;
//     }
// };

// //Modified BFS + Edge-Relaxation Step
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         // Total number of vertices = n (which is number of cities)
//         queue<Info> q;
//         vector<int> dist(n, INT_MAX);

//         q.push(Info(src, 0, -1));
//         dist[src] = 0;

//         //Modified BFS Approach
//         while(!q.empty()) {
//             Info currFlight = q.front();
//             q.pop();

//             // Looking for neighbours
//             for(int i=0; i<flights.size(); i++) {
//                 if(flights[i][0] == currFlight.u ) {
//                     int v = flights[i][1];
//                     int wt = flights[i][2];
//                     if(currFlight.stops+1 <= k && dist[v] > currFlight.cost + wt) {
//                         dist[v] = currFlight.cost + wt;
//                         q.push(Info(v, dist[v], currFlight.stops+1));
//                     }
//                 }
//             }
//         }

//         return (dist[dst] == INT_MAX)? -1 : dist[dst];
//     }
// };