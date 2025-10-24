class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, int> dependencyCountOfCourse;
        unordered_map<int, set<int>> courseToDependencySet;

        for (int i = 0; i < numCourses; i++)
        {
            dependencyCountOfCourse[i] = 0;
            courseToDependencySet[i] = {};
        }

        for (auto i : prerequisites)
        {
            dependencyCountOfCourse[i[0]]++;
            courseToDependencySet[i[0]].insert(i[1]);
        }

        bool changeMade = true;
        while (changeMade)
        {
            changeMade = false;
            for (auto &i : dependencyCountOfCourse)
            {
                if (i.second == 0)
                {
                    i.second = -1;
                    for (auto &depGraph : courseToDependencySet)
                    {
                        int prevSize = depGraph.second.size();
                        depGraph.second.erase(i.first);
                        if (depGraph.second.size() != prevSize)
                        {
                            changeMade = true;
                            dependencyCountOfCourse[depGraph.first]--;
                        }
                    }
                }
            }
        }

        bool answer = true;
        for (auto i : dependencyCountOfCourse)
        {
            if (i.second > 0)
            {
                answer = false;
                break;
            }
        }
        return answer;
    }
};
