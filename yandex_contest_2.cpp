#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
//https://contest.yandex.ru/contest/23869/problems/B/
enum Periodity {
    WEEK,
    MONTH,
    QUARTER,
    YEAR,
    LAST_SUNDAY_OF_YEAR
};
struct Date {
    int year;
    int month;
    int day;
};

ostream& operator<<(ostream& output, const Date& date)
{
    output << date.year << '-' << date.month << '-' << date.day;
    return output;
}
istream& operator>>(istream& input, Date& date)
{  
    int day, month, year;
    char ch1, ch2;
    if (input >> skipws >> year >> ch1 >> month >> ch2 >> day) {
        date = Date{year, month, day};
    }
    return input;
}
bool operator<(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);
}
bool operator<=(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) <= tie(rhs.year, rhs.month, rhs.day);
}
bool operator==(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);
}

using PartitionInfo = vector<string>;

class DateManager {
    Periodity datePeriodity;
    Date start_date, end_date;
public:
    void ReadQuery(istream& input);
    PartitionInfo GetPartitions();
    void OutputResults(PartitionInfo result, ostream& output);
    Date NextDay(const Date& start);
    Date NextWeek(const Date& start);
    Date NextMonth(const Date& start);
    Date NextQuarter(const Date& start);
    Date NextYear(const Date& start);
    Date NextLastSundayOfYear(const Date& start);
};

int main() {
    DateManager manager;
    manager.ReadQuery(cin);
    PartitionInfo result = manager.GetPartitions();
    manager.OutputResults(result, cout);
}
PartitionInfo DateManager::GetPartitions() {
    PartitionInfo result;
    switch (datePeriodity)
    {
    case Periodity::WEEK:
        break;
    case Periodity::MONTH:
        break;
    case Periodity::QUARTER:
        break;
    case Periodity::YEAR:
      
        break;
    case Periodity::LAST_SUNDAY_OF_YEAR:
        break;
    default:
        break;
    }
    return result;
}
Date DateManager::NextDay(const Date& start) {
    Date nextDay;
    return nextDay;
}
Date DateManager::NextWeek(const Date& start) {
    Date nextWeek;
    return nextWeek;
}
Date DateManager::NextMonth(const Date& start) {
    Date nextMonth;
    return nextMonth;
}
Date DateManager::NextQuarter(const Date& start) {
    Date nextQuarter;
    return nextQuarter;
}
Date DateManager::NextYear(const Date& start) {
    Date nextYear;
    return nextYear;
}
Date DateManager::NextLastSundayOfYear(const Date& start) {
    Date nextLastSundayOfYear;
    return nextLastSundayOfYear;
}
void DateManager::OutputResults(PartitionInfo result, ostream& output) {
    output << result.size() << endl;
    for (const auto interval : result) {
        output << interval << endl;
    }
}
void DateManager::ReadQuery(istream& input) {
        string per;
        getline(input, per);
        if (per == "WEEK") {
            datePeriodity = WEEK;
        }
        else if (per == "MONTH") {
            datePeriodity = MONTH;
        }
        else if (per == "QUARTER") {
            datePeriodity = QUARTER;
        }
        else if (per == "YEAR") {
            datePeriodity = YEAR;
        }
        else if (per == "LAST_SUNDAY_OF_YEAR") {
            datePeriodity = LAST_SUNDAY_OF_YEAR;
        }
        input >> start_date >> end_date;
    }