class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(costBoth < cost1 + cost2){
            if(need1 > need2){
                return min((long long)costBoth*need2 + (long long)(need1 - need2)*cost1 , (long long)costBoth*need1);
            }else{
                return min((long long)costBoth*need1 + (long long)(need2 - need1)*cost2 , (long long)costBoth*need2);
            }
        }
        return (long long)cost1*need1 + (long long)cost2*need2;
    }
};