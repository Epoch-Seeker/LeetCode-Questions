class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n , 0);

        vector<int> right(n , 0);

        int mx = 0;

        for(int i=0;i<n;i++){
            if(height[i] > mx){
                mx = height[i];
            }
            left[i] = mx;
        }

        mx = 0;

        for(int i=n-1;i>=0;i--){
            if(height[i] > mx){
                mx = height[i];
            }
            right[i] = mx;
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            ans += min(left[i] , right[i]) - height[i];
        }

        return ans;
    }
};