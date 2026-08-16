class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {

        int idx = -1;
        int mini = INT_MAX;
        
        for(int i = 0; i < drones.size(); i++){
            int u = drones[i][0];
            int v = drones[i][1];
            int d = drones[i][2];

            int manhattanDistance = abs(target[0] - u) + abs(target[1] - v);

            if(manhattanDistance <= d && manhattanDistance < mini){
                mini = manhattanDistance;
                idx = i;
            }
        }

        return idx;
    }
};