//recursion + Binary search
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        // Sort events by start time
        sort(events.begin(), events.end());
        
        // Create an array to store max value from i to end
        vector<int> maxFromHere(n + 1);
        
        // Precompute max values from the end
        maxFromHere[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxFromHere[i] = max(events[i][2], maxFromHere[i + 1]);
        }
        
        // Find next non-overlapping event using binary search
        vector<int> nextValid(n, n);
        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n - 1;
            int target = events[i][1] + 1; // Next must start at end + 1
            
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][0] >= target) {
                    nextValid[i] = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        
        int maxSum = 0;
        
        // Try taking each event as first event
        for (int i = 0; i < n; i++) {
            // Take only this event
            maxSum = max(maxSum, events[i][2]);
            
            // Take this event and find next non-overlapping event
            int nextIdx = nextValid[i];
            if (nextIdx < n) {
                maxSum = max(maxSum, events[i][2] + maxFromHere[nextIdx]);
            }
        }
        
        return maxSum;
    }
};
