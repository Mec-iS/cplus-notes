#include <cassert>
#include <string>
#include <vector>
#include <iostream>
using std::string;

// https://stackoverflow.com/a/34080727/2536357
const char * MONTHS[12] = {"January", "February", "March", "April",
                         "May", "June", "July", "August",
                         "September", "October", "November",
                         "December"};

class Date {
 public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);
  std::string String() const {
      return this->date_string;
  };

 private:
  bool LeapYear(int year) const;
  int DaysInMonth(int month, int year) const;
  int day_{1};
  int month_{1};
  int year_{0};
  string date_string;

};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);

    std::string date_str;
    date_str += MONTHS[this->Month() - 1];
    date_str += " ";
    date_str += std::to_string(this->Day());
    date_str += ", ";
    date_str += std::to_string(this->Year());

  this->date_string = date_str;
  
}

bool Date::LeapYear(int year) const {
  if (year % 4 != 0)
    return false;
  else if (year % 100 != 0)
    return true;
  else if (year % 400 != 0)
    return false;
  else
    return true;
}

int Date::DaysInMonth(int month, int year) const {
  if (month == 2)
    return LeapYear(year) ? 29 : 28;
  else if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  else
    return 31;
}

void Date::Day(int day) {
  if (day >= 1 && day <= DaysInMonth(Month(), Year())) day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12) month_ = month;
}

void Date::Year(int year) {
  year_ = year;
}


// Test
int main() {
  Date date(29, 8, 1981);
  std::cout << date.String() << std::endl;
  assert(date.String() == "August 29, 1981");
}
