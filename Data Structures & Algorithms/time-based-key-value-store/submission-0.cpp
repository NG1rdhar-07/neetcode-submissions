class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> mp;
    
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string soln = "";
        int n = mp[key].size();

        int l = 0;
        int h = n-1;

        while(l <= h)
        {
            int m = l + (h-l)/2;
            int crntTS = mp[key][m].second;

            if(crntTS <= timestamp)
            {
                soln = mp[key][m].first;
                l = m+1;
            }
            else
            h = m-1;
        }

        return soln;
    }
};
