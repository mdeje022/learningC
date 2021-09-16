#include"calendar.h"
/* This file contains count function and 
some relevant functions
*/
int count(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {
	int count = 0;
 	int isInverse = compareTo(fromMonth, fromDay, fromYear, toMonth, toDay, toYear);

	//check order of dates
	if(isInverse < 0){
		//count years
		for(int i = fromYear; i < toYear; i++){
 			count += 365 + isLeapYear(i); 
		}
		//months
		for (int i = fromMonth; i < toMonth; i++){
			count += monthDays(i, toYear);
		}
	} else if (isInverse > 0){
		//years inverse order 
		for(int i = toYear; i < fromYear; i++){
 			count += 365 + isLeapYear(i);
		}
		//months inverse order
		for (int i = toMonth; i < fromMonth; i++){
			count += monthDays(i, fromYear);
		}
		count = count * -1; 
	} else {
		count = 0;
	}

	//then count days
	count += (toDay - fromDay);
	printf("count: %d\n", count);
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

	char monthData_1[3];
	char dayData_1[3];
	char yearData_1[5];
	char monthData_2[3];
	char dayData_2[3];
	char yearData_2[5];

	getData(monthData_1, 3);
	int month_1 = getMonth(monthData_1);
	getData(dayData_1, 3);
	int day_1 = getDay(dayData_1);
	getData(yearData_1, 5);
	int year_1 = getYear(yearData_1);
	getData(monthData_2, 3);
	int month_2 = getMonth(monthData_2);
	getData(dayData_2, 3);
	int day_2 = getDay(dayData_2);
	getData(yearData_2, 5);
	int year_2 = getYear(yearData_2);

	if (!isValidDate(month_1, day_1, year_1) || !isValidDate(month_2, day_2, year_2)){
		printf("invalid date. Try again count (mm/dd/yyyy) (mm/dd/yyyy)\n");
		return;
	}
	
	count(month_1, day_1, year_1, month_2, day_2, year_2);
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