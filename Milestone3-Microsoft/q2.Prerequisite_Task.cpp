class Solution {
public:

    bool completeTask(int target, vector<vector<int>> &tasks, vector<int> &state) {

        if(state[target] == 2) {
            return true;
        }
        else if(state[target] == 1) {
            return false;
        }

        state[target] = 1; // visited

        for(auto task: tasks[target]) {
            bool done = completeTask(task, tasks, state);
            if(!done) {
                return false;
            }
        }

        state[target] = 2; // completed

        return true;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> tasks(N);
	    vector<int> state(N, 0);

	    for(auto task_pair: prerequisites) {
	        tasks[task_pair.first].push_back(task_pair.second);
	    }

        for(int i = 0; i < N; ++i) {
            bool done = completeTask(i, tasks, state);
            if(!done) {
                return false;
            }
        }

	    return true;
	}
};