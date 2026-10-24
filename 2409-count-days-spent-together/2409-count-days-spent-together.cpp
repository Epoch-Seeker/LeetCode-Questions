class Solution {
public:
    vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> monthDaysPS; //starts with 0 as first element instead of monthDays[0]

    int dateToDay(string date){
        int day = 0;
        
        int month = stoi(date.substr(0,2));

        day += monthDaysPS[month - 1];
        day += stoi(date.substr(3,2));

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int sum = 0;
        for(int i:monthDays){
            monthDaysPS.push_back(sum);
            sum += i;
        }

        int aad = dateToDay(arriveAlice), ald = dateToDay(leaveAlice);
        int bad = dateToDay(arriveBob), bld = dateToDay(leaveBob);

        return max((min(ald,bld) - max(aad,bad) + 1),0);
    }
};