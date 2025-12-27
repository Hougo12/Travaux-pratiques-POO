#include <iostream>
#ifndef DATE_H
#define DATE_H


class Date
{
public:
	Date(int year = 2025, int month = 1, int day = 1);
	int year() const;
	int month() const;
	int day() const;
private:
	int year_;
	int month_;
	int day_;
	
};
bool is_date(int year, int month, int day);
std::string date_to_string(const Date& date);

#endif // !1
