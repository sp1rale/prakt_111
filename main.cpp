#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int operator-(const Date& other) const {
        const int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        int days = 0;

        for (int i = other.year; i < year; ++i) {
            days += isLeapYear(i) ? 366 : 365;
        }

        for (int i = 1; i < month; ++i) {
            days += days_in_month[i];
        }
        days += day;

        for (int i = 1; i < other.month; ++i) {
            days -= days_in_month[i];
        }
        days -= other.day;

        return days;
    }

    Date operator+(int days) const {
        Date result = *this;
        result.day += days;

        while (result.day > daysInMonth(result.month, result.year)) {
            result.day -= daysInMonth(result.month, result.year);
            ++result.month;

            if (result.month > 12) {
                result.month = 1;
                ++result.year;
            }
        }

        return result;
    }

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const {
        const int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (m == 2 && isLeapYear(y))
            return 29;
        return days_in_month[m];
    }

    void display() const {
        std::cout << year << "-" << month << "-" << day;
    }
};

int main() {
    int day1, month1, year1;
    int day2, month2, year2;

    std::cout << "Enter the first date (day month year): ";
    std::cin >> day1 >> month1 >> year1;
    Date date1(day1, month1, year1);

    std::cout << "Enter the second date (day month year): ";
    std::cin >> day2 >> month2 >> year2;
    Date date2(day2, month2, year2);

    char choice;

    std::cout << "Choose an operation (- for difference, + for addition): ";
    std::cin >> choice;

    int result;

    if (choice == '-') {
        result = date1 - date2;
        std::cout << "Difference in days: " << result << std::endl;
    }
    else if (choice == '+') {
        int daysToAdd;
        std::cout << "Enter the number of days to add: ";
        std::cin >> daysToAdd;
        Date newDate = date1 + daysToAdd;
        std::cout << "New date after addition: ";
        newDate.display();
        std::cout << std::endl;
    }
    else {
        std::cerr << "Error: Invalid operation." << std::endl;
        return 1;
    }

    return 0;
}
