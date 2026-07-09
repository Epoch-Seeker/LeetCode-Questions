class Solution {
public:
    void solve(vector<int>& arr , vector<vector<int>>& ans , vector<int>& temp , int idx, int k , int n){
        if(n == 0 && k == 0){
            ans.push_back(temp);
            return;
        }

        if(k==0 || idx == arr.size())return;

        for(int i =idx ; i< arr.size() ; i++){
            if(arr[i] > n)break;

            temp.push_back(arr[i]);
            solve(arr , ans , temp , i+1 , k-1 , n - arr[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1 , 2, 3, 4, 5, 6, 7, 8, 9};

        vector<vector<int>> ans;
        vector<int> temp;

        solve(arr , ans , temp , 0 , k , n);

        return ans;
    }
};