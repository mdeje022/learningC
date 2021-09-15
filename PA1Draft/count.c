#include"calendar.h"
/* This file contains count function and 
some relevant functions
*/
int count(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {
	/* Your code comes here */
	int mCount1 = 0;
	int mCount2 = 0;
	int count = 0;

	//count years 
	count += (toYear - fromYear) * 365;
	//count leap years in between them
	count += countLeapYears(toYear, toMonth) - countLeapYears(fromYear, fromMonth);
	
	//count months
	for (int i = 0; i < fromMonth; i++){
		mCount1 += monthDays(i, fromYear);
	}
	for (int i = 0; i < toMonth; i++){
		mCount2 += monthDays(i, toYear);
	}
	count += mCount2 - mCount1;
	
	//then count days
	count += (toDay - fromDay);
	return count;
}
int getMonth(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' || token[1] < '0' || token[1]> '9')
		return 0;//error in retrieving the month
	n = 10 * (token[0] - '0') + token[1] - '0';
	if (n > 12)
		return 0;//error, month should be from 1 and 12...
	return n;
}

int getDay(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' || token[1] < '0' || token[1]> '9')
		return 0;//error in retrieving the day
	n = 10 * (token[0] - '0') + token[1] - '0';
	if (n > 31)
		return 0;//error, month should be from 1 and 12...
	return n;
}

int getYear(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' ||
		token[1] < '0' || token[1]> '9' ||
		token[2] < '0' || token[2]> '9' ||
		token[3] < '0' || token[3]> '9')
		return 0;//error in retrieving the year
	n = 1000 * (token[0] - '0') + 100 * (token[1] - '0') + 10 * 
	(token[2] - '0') + token[3] - '0';
	return n;
}
void handleCount(void) {
	/* Your code comes here */
}
int monthDays(int month, int year) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	return -1;
}
int isValidDate(int month, int day, int year) {
	return year >= 1 && month >= 1 && month <=12 && day >= 1 && day <= monthDays(month, year);
}
int compareTo(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {
	//returns negative int if from date < to date
	//return zero if from date == to date
	//returns positive int otherwise
	if (fromYear != toYear)
		return fromYear - toYear;
	if (fromMonth != toMonth)
		return fromMonth - toMonth;
	return fromDay - toDay;
}
int isLeapYear(int year) //97 leap years in every 400 years... 365 days + 97/400
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);//2000, 2020, 1600, 2024, 2016,... are leap years...
	//1900, 1800, 1700, 2100, 2002, 2019,... are not leap years...
}

int countLeapYears(int year, int month) //returns all the leap years that have happend until the year of input
{
	int count;
	if(month <= 2) //checking if current year should be considered for leap year
		year--;
	
	count = (year/4) - (year/100) + (year/400);
	return count;
}