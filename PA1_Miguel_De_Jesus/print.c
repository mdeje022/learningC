#include"calendar.h"
void print(int MM, int YYYY) {
	/* Your code comes here */
	int currentDay; 
	int currentWeekday; //0 to 6 (0 = Sunday, 6 is Saturday)
	int monthStartDay = dayOfWeek(MM, 1, YYYY);

	printf("Sun\tMon\tTue\tWed\tThurs\tFri\tSat\n");

	for(currentWeekday = 0; currentWeekday < monthStartDay; currentWeekday++){
		printf(" \t");
	}

	for (currentDay = 1;  currentDay <= monthDays(MM, YYYY); currentDay++){
		printf("%d\t", currentDay);
		currentWeekday++;

		if(currentWeekday > 6){
			printf("\n");
			currentWeekday = 0;
		}
	}
	printf("\n");

}
void handlePrint(void) {
	char monthData[3];
	char yearData[5];
	/* Your code comes here */

	getData(monthData, 3);
	int month = getMonth(monthData);

	getData(yearData, 5);
	int year = getYear(yearData);

	if (!isValidDate(month, 1, year)){
		printf("invalid date input. Try again (mm/yyyy)\n");
		return;
	}
	print(month, year);
}

//algorithm to find which day of week a date lands
int dayOfWeek(int month, int day, int year){
	int a, y, m;
	a = (14-month) / 12;
	y = year - a;
	m = month + (12 * a) -2;
	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 *m) /12)) % 7;
}

void getData (char c[], int arraySize){
	c[arraySize];
	int i;
	for (i = 0; i < arraySize; i++){
		if ( (c[i] = getchar()) != ' ' && c[i] != '\n' && c[i] != '/'){
		} else {
			break;
		}
	}
	c[i] = '\0';
}
