class UndergroundSystem {
public:
    map<pair<string, string>, int > sum, cnt;
    map<int, int> checkInTime;
    map<int, string> checkInStation;
    
    UndergroundSystem() {
        checkInStation.clear();
        checkInTime.clear();
        sum.clear();
        cnt.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInTime[id] = t;
        checkInStation[id] = stationName;
        
    }
    
    void checkOut(int id, string stationName, int t) {
        cnt[{checkInStation[id], stationName}]++;
        sum[{checkInStation[id], stationName}] += abs(t - checkInTime[id]);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg = (double)sum[{startStation, endStation}]/(double)cnt[{startStation, endStation}];
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */