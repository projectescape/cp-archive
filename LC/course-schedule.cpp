bool dfsHelper(unordered_map<int, list<int>> &adjList, vector<bool> &visited, vector<bool> &stack, int curr) {
    stack[curr] = true;
    visited[curr] = true;

    for (auto i : adjList[curr]) {
        if (stack[i]) return true;
        if (visited[i]) continue;
        if (dfsHelper(adjList, visited, stack, i)) return true;
    }
    stack[curr] = false;
    return false;
}

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, list<int>> adjList;
        vector<bool> visited(numCourses, false);
        vector<bool> stack(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++) adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        for (int i = 0; i < numCourses; i++) {
            if (visited[i]) continue;
            if (dfsHelper(adjList, visited, stack, i)) return false;
        }
        return true;
    }
};

// class Solution {
//    public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> inDegree(numCourses, 0);
//         vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
//         for (auto i : prerequisites) {
//             for (int j = 0; j < i.size() - 1; j++) {
//                 if (graph[i[j]][i[j + 1]] == false) {
//                     inDegree[i[j + 1]]++;
//                     graph[i[j]][i[j + 1]] = true;
//                 }
//             }
//         }

//         stack<int> s;
//         for (int i = 0; i < numCourses; i++) {
//             if (inDegree[i] == 0) s.push(i);
//         }
//         int curr;
//         int ans = numCourses;
//         while (!s.empty()) {
//             ans--;
//             curr = s.top();
//             s.pop();
//             for (int i = 0; i < numCourses; i++) {
//                 if (graph[curr][i] == true) {
//                     inDegree[i]--;
//                     if (inDegree[i] == 0) {
//                         s.push(i);
//                     }
//                 }
//             }
//         }
//         if (ans == 0) return true;
//         return false;
//     }
// };