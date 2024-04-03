#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<string, int> day_of_months = {
    {"January", 31},
    {"February", 28},
    {"March", 31},
    {"April", 30},
    {"May", 31},
    {"June", 30},
    {"July", 31},
    {"August", 31},
    {"September", 30},
    {"October", 31},
    {"November", 30},
    {"December", 31}
};

unordered_map<string, int> day2num = {
    {"Monday", 0},
    {"Tuesday", 1},
    {"Wednesday", 2},
    {"Thursday", 3},
    {"Friday", 4},
    {"Saturday", 5},
    {"Sunday", 6}
};

unordered_map<int, string> num2day = {
    {0, "Monday"},
    {1, "Tuesday"},
    {2, "Wednesday"},
    {3, "Thursday"},
    {4, "Friday"},
    {5, "Saturday"},
    {6, "Sunday"}
};


vector<string> months = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int main() {

    int n, year;
    cin >> n >> year;

    int num_days = 365;
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
        day_of_months["February"] = 29;
        ++num_days;
    }
    
    unordered_map<string, int> accumulated_day_of_months;
    int count = 0;
    for (auto& month : months) {
        accumulated_day_of_months[month] = count;
        count += day_of_months[month];
    }

    unordered_set<int> holidays;
    int day;
    string month;
    for (int i = 0; i < n; ++i) {
        cin >> day >> month;
        holidays.insert(accumulated_day_of_months[month] + day - 1);
    }

    string first_day;
    cin >> first_day;

    vector<int> counts(7);
    day = day2num[first_day];
    for (int i = 0; i < num_days; ++i) {
        day %= 7;
        if (holidays.find(i) == holidays.end())
            ++counts[day];
        ++day;
    }

    cout << num2day[distance(counts.begin(), max_element(counts.begin(), counts.end()))] << ' '
         << num2day[distance(counts.begin(), min_element(counts.begin(), counts.end()))] << endl;

    return 0;
}
