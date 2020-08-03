class Solution {
public:
    double angleClock(int hour, int minutes) {  
        int oneMinuteAngle = 360 / 60;
        int oneHourAngle = 360 / 12;
        
        double minutesAngle = minutes * oneMinuteAngle;
        double hourAngle = (hour % 12) * oneHourAngle + oneHourAngle * minutes / 60.0;
        double dif = abs(minutesAngle - hourAngle);
        
        return min(360 - dif, dif);
    }
};