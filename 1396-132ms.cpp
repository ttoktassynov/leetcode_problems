//https://leetcode.com/problems/design-underground-system/
class UndergroundSystem {
    unordered_map<int, pair<int, string> > checkinMap;
    unordered_map<string, pair<double,int> > avetimeMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkinMap[id] = make_pair(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStationName = checkinMap.at(id).second;
        int timeSpent = t - checkinMap.at(id).first;
        string forward = startStationName + stationName;

        pair<double,int>& oldStat = avetimeMap[forward];
        int newTripCnt = oldStat.second + 1;
        double newAveTime = (oldStat.first * oldStat.second + timeSpent) / newTripCnt;
        oldStat.second = newTripCnt;
        avetimeMap[forward] = make_pair(newAveTime, newTripCnt);

        checkinMap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return avetimeMap.at(startStation + endStation).first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */