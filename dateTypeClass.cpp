#include <iostream>

class dateType {
public:
    dateType(int month = 1, int day = 1, int year = 1900) {
        setDate(month, day, year);
    }

    void setDate(int month, int day, int year) {
        if (year >= 1900 && month >= 1 && month <= 12 && day >= 1 && day <= getDaysInMonth(month, year)) {
            this->month = month;
            this->day = day;
            this->year = year;
        }
        else {
            this->month = 1;
            this->day = 1;
            this->year = 1900;
            std::cout << "Date invalid, setting to 1/1/1900" << std::endl;
        }
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void printDate() const {
        std::cout << month << "-" << day << "-" << year << std::endl;
    }

private:
    int month;
    int day;
    int year;

    bool isLeapYear(int year) const {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    int getDaysInMonth(int month, int year) const {
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        else {
            return 31;
        }
    }
};

int main() {
    // Test scenarios based on the guidance document
    dateType defaultDate;
    std::cout << "Testing default constructor ... ";
    defaultDate.printDate();

    dateType leapYearDate(2, 29, 2016);
    std::cout << "Testing constructor with parameters ... ";
    leapYearDate.printDate();

    dateType invalidYearDate;
    std::cout << "Setting date with invalid year (1000) ... ";
    invalidYearDate.setDate(1, 1, 1000);
    invalidYearDate.printDate();

    dateType invalidMonthDate;
    std::cout << "Setting date with invalid month (13) ... ";
    invalidMonthDate.setDate(13, 1, 1900);
    invalidMonthDate.printDate();

    dateType invalidDayDate;
    std::cout << "Setting date with invalid day (4 31) ... ";
    invalidDayDate.setDate(4, 31, 1900);
    invalidDayDate.printDate();

    dateType invalidLeapYearDate;
    std::cout << "Setting invalid date: Feb 29 2015 ... ";
    invalidLeapYearDate.setDate(2, 29, 2015);
    invalidLeapYearDate.printDate();

    dateType validNonLeapYearDate;
    std::cout << "Setting valid date: Feb 28 2015 ... ";
    validNonLeapYearDate.setDate(2, 28, 2015);
    validNonLeapYearDate.printDate();

    dateType validDate;
    std::cout << "Setting valid date (August 15 2016) ... ";
    validDate.setDate(8, 15, 2016);
    validDate.printDate();

    return 0;
}
