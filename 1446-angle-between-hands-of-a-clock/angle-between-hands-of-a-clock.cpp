class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour%12;
        minutes = minutes%60;

        double minuteAngle = minutes*6.0;

        double hourAngle = (hour * 30.0) + (minutes/2.0);

        double angleBtw = abs(hourAngle - minuteAngle);

        double minAngle = min(angleBtw,360.0-angleBtw);

        return minAngle;
    }
};