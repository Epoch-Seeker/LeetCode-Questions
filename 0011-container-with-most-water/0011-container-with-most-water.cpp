class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxi = 0;

        int i=0 , j = height.size()-1;

        while(i<j){
            int len = j-i;

            int temp = len*min(height[i] , height[j]);

            maxi = max(maxi , temp);

            if(height[i] > height[j]){
                j--;
            }else i++;
        }

        return maxi;
    }
};