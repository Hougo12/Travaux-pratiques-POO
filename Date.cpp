#include "Date.h"
#include <string>

Date::Date(int year, int month, int day): year_(year), month_(month), day_(day){
	if (!is_date(year, month, day)) {
		throw std::invalid_argument("Invalid date: "
			+ std::to_string(day) + "/"
			+ std::to_string(month) + "/"
			+ std::to_string(year));
	}
}
int Date::year() const{
	return year_;
}
int Date::month() const {
	return month_;
}
int Date::day() const {
	return day_;
}

bool is_date(int year, int month, int day) {
	if (year < 0) return false;
	if ((day < 1) || (day > 31)) return false;
	if ((month < 1) || (month > 12)) return false;
	if ((month == 2) && (day > 28)) return false;
	if (((month == 4) || (month == 6) || (month == 9)
		|| (month == 11)) && (day > 30)) return false;
	return true;
}
std::string date_to_string(const Date& date) {
	std::string day = std::to_string(date.day());
	std::string month = std::to_string(date.month());
	if (day.length() < 2) day.insert(0, 1, '0');
	if (month.length() < 2) month.insert(0, 1, '0');
	return day + "/" + month + "/" + std::to_string(date.year());
}
