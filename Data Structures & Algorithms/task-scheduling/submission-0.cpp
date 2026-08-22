class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> c(26);

        for(char it : tasks){
            c[it-'A']++;
        }

        priority_queue<pair<int, char>> pq;

        for(int i = 0; i<26; i++){
            if(c[i] > 0)
            pq.push({c[i], 'A'+i});
        }

        int mF = pq.top().first;
        int cnt = 0;

        while(!pq.empty() && pq.top().first == mF){
            pq.pop();
            cnt++;
        }

        int minPossibility = (mF-1)*(n+1)+cnt;

        return max(minPossibility, (int)tasks.size());
    }
};
