class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int ans = 0;

        int left = 0;
        int right = n-1;

        int leftmx = height[left];
        int rightmx = height[right];

        while(left < right){
            if(leftmx < rightmx){

                ans += leftmx - height[left];

                left++;

                leftmx = max(leftmx , height[left]);
            }else{
                ans += rightmx - height[right];

                right--;

                rightmx = max(rightmx , height[right]);
            }
        }

        return ans;
    }
};