/*
A robot on an infinite XY-plane starts at point `(0, 0)` facing north. The robot receives an array of integers `commands`, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:

	- `-2`: Turn left `90` degrees.

	- `-1`: Turn right `90` degrees.

	- `1 th` obstacle is at grid point `obstacles[i] = (xi, yi)`. If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.

Return the **maximum squared Euclidean distance** that the robot reaches at any point in its path (i.e. if the distance is `5`, return `25`).

**Note:**

	- There can be an obstacle at `(0, 0)`. If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to `(0, 0)` due to the obstacle.

	- North means +Y direction.

	- East means +X direction.

	- South means -Y direction.

	- West means -X direction.

Example 1:**

**Input:** commands = [4,-1,3], obstacles = []

**Output:** 25

**Explanation: **

The robot starts at `(0, 0)`:

	- Move north 4 units to `(0, 4)`.

	- Turn right.

	- Move east 3 units to `(3, 4)`.

The furthest point the robot ever gets from the origin is `(3, 4)`, which squared is `32 + 42 = 25` units away.

Example 2:**

**Input:** commands = [4,-1,4,-2,4], obstacles = [[2,4]]

**Output:** 65

**Explanation:**

The robot starts at `(0, 0)`:

	- Move north 4 units to `(0, 4)`.

	- Turn right.

	- Move east 1 unit and get blocked by the obstacle at `(2, 4)`, robot is at `(1, 4)`.

	- Turn left.

	- Move north 4 units to `(1, 8)`.

The furthest point the robot ever gets from the origin is `(1, 8)`, which squared is `12 + 82 = 65` units away.

Example 3:**

**Input:** commands = [6,-1,-1,6], obstacles = [[0,0]]

**Output:** 36

**Explanation:**

The robot starts at `(0, 0)`:

	- Move north 6 units to `(0, 6)`.

	- Turn right.

	- Turn right.

	- Move south 5 units and get blocked by the obstacle at `(0,0)`, robot is at `(0, 1)`.

The furthest point the robot ever gets from the origin is `(0, 6)`, which squared is `62 = 36` units away.

**Constraints:**

	- `1 4`

	- `commands[i]` is either `-2`, `-1`, or an integer in the range `[1, 9]`.

	- `0 4`

	- `-3 * 104 i, yi 4`

	- The answer is guaranteed to be less than `231`.
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int dir = 0; // 0: North, 1: East, 2: South, 3: West
        int maxDist = 0;
        
        // Directions: dx, dy for North, East, South, West
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        
        // Store obstacles in a set for O(1) lookup
        // Encode (x, y) into a single integer to use in unordered_set
        // Since coordinates can be negative, we offset or use a string
        // A common trick: x * 10000 + y might collide if ranges are large
        // Safer: use a set of pairs or encode with a large base
        // LeetCode constraints: -1000 <= x, y <= 1000
        // So we can use x * 2000 + (y + 1000) to make it unique and positive
        unordered_set<int> obstacleSet;
        for (auto& obs : obstacles) {
            int ox = obs[0];
            int oy = obs[1];
            // Encode to unique integer
            int encoded = ox * 2000 + (oy + 1000);
            obstacleSet.insert(encoded);
        }
        
        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                // Move forward cmd steps
                for (int step = 0; step < cmd; ++step) {
                    int nextX = x + dx[dir];
                    int nextY = y + dy[dir];
                    
                    // Check if next position has an obstacle
                    int encodedNext = nextX * 2000 + (nextY + 1000);
                    if (obstacleSet.find(encodedNext) != obstacleSet.end()) {
                        break; // Blocked
                    }
                    
                    // Move robot
                    x = nextX;
                    y = nextY;
                    
                    // Update max squared distance
                    int currentDist = x * x + y * y;
                    if (currentDist > maxDist) {
                        maxDist = currentDist;
                    }
                }
            }
        }
        
        return maxDist;
    }
};