class UndergroundSystem {
    unordered_map<int, pair<string, int>> passenger;
    unordered_map<string, unordered_map<string, pair<int, int>>> mem;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        passenger[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> last = passenger[id];
        string from = last.first;
        int start = last.second;
        
        passenger.erase(id);
        
        if (mem.count(from) == 0 || mem[from].count(stationName) == 0) {
            mem[from][stationName] = {t - start, 1};
        }
        else {
            mem[from][stationName].first += t - start;
            mem[from][stationName].second++;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> tmp = mem[startStation][endStation];
        return (double) tmp.first / tmp.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */