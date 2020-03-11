class Solution {
public:
    int daysBetweenDates(string date1, string date2) {        
        vector<int> from_date = generate_date(date1);
        vector<int> to_date = generate_date(date2);
        
        int from = from_date[2] + days_in_month(from_date[0], from_date[1]);
        int to = to_date[2] + days_in_month(to_date[0], to_date[1]);
        
        for (int i = 1971; i < from_date[0]; i++) from += days_in_year(i);
        for (int i = 1971; i < to_date[0]; i++) to += days_in_year(i);
        
        return abs(from - to);
    }
    
    vector<int> generate_date(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        return {year, month, day};
    }
    
    bool is_leap(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }
    
    int days_in_year(int year) {
        return is_leap(year) ? 366 : 365;
    }
    
    int days_in_month(int year, int month) {
        int res = 0;
        
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (is_leap(year)) {
            months[1]++;
        }
        
        for (int i = 0; i < month - 1; i++) {
            res += months[i];
        }
        
        return res;
    }
};