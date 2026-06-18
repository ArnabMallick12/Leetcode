class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mpos = minutes*6;
        double hpos = (hour%12)*30+ (double(minutes)/12.0) * 6;
        return min(abs(hpos-mpos),360 - (abs(hpos-mpos)));
    }
};