class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size())return false;

        if(arr[start] == 0)return true;

        // Already visited
        if (arr[start] == -1)
            return false;

        // Mark visited
        int jump = arr[start];
        arr[start] = -1;

        bool left = canReach(arr , start - jump);
        bool right = canReach(arr , start + jump);

        return left || right;
    }
};