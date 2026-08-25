class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);
        vector<int> soln;
        //vector<int> eA;
        
        for(int i = 0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
    
        for(int i = 0; i<numCourses; i++){
            for(auto it : adj[i]){
                inDeg[it]++;
            }
        }
        
        for(int i = 0; i<numCourses; i++){
            if(inDeg[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int nodeVal = q.front();
            q.pop();
            soln.push_back(nodeVal);
            
            for(auto it : adj[nodeVal]){
                inDeg[it]--;
                
                if(inDeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        int cC = soln.size();

        if(cC == numCourses)
        return soln;

        return {};
    }
};
