#include <stdio.h>
#include <stdlib.h>

struct date {
	int year;
	int month;
	int day;
};

static int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/* function prototypes */
void readDate(struct date* dteptr);
void printDate(struct date tday);
struct date advanceDay(struct date);

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printf("days in month %d \n", days_in_month[01]);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

void readDate(struct date* dteptr) {
	scanf_s("%04d %02d %02d", &dteptr->year, &dteptr->month, &dteptr->day);
}


void printDate(struct date tday) {
	printf(" The date is: %02d/%02d/%04d \n", tday.month, tday.day, tday.year);
}

struct date advanceDay(struct date now) {
    if (now.day >= days_in_month[now.month] && now.month != 12){
			now.day= 01;
			now.month = now.month + 1;
			now.year = now.year;
			
	}
	else if (now.month == 12 && now.day == 31) {
		now.day = 01;
		now.month = 01;
		now.year = now.year + 1;
	}
	return now;
}
	
