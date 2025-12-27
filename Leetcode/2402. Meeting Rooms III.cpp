class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> duration(n, 0);  
        vector<int> freq(n, 0);
        
        for(int j = 0; j < meetings.size(); j++) {
            long long start = meetings[j][0];
            long long end = meetings[j][1];
            int selected_room = -1;
            for(int i = 0; i < n; i++) {
                if(duration[i] <= start) {
                    selected_room = i;
                    break;  
                }
            }

            if(selected_room != -1) {
                duration[selected_room] = end;
                freq[selected_room]++;
            }
            else {
                auto min_it = min_element(duration.begin(), duration.end());
                int min_index = distance(duration.begin(), min_it);

                long long meeting_duration = end - start;
                duration[min_index] = duration[min_index] + meeting_duration;
                freq[min_index]++;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << freq[i] << ',';
        }
        auto max_it = max_element(freq.begin(), freq.end());
        int ans = distance(freq.begin(), max_it);
        
        return ans;
    }
};
