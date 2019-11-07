#include <stdio.h>
#include <stdlib.h>

struct digit {
	int num;
	struct digit* next;
};

// Write your prototypes here
struct digit* createDigit(int dig);
struct digit* append(struct digit* end, struct digit* newDigptr);
void printNumber(struct digit* start);
void freeNumber(struct digit* start);
struct digit* readNumber(void);
int divisibleByThree(struct digit* start);
//additional section that count the number of times the number 3 appeared and change it for 9 and return the number of times it was found
int changeThrees(struct digit* start);

int main(void) {
	struct digit* start;
	start = readNumber();
	/*printf("The number ");
	printNumber(start);
	if (divisibleByThree(start))
		printf("is divisible by 3.\n");
	else
		printf("is not divisible by 3.\n");
	freeNumber(start);*/




	printf("The number ");
	printNumber(start);
	printf("was modified in %d places.\n", changeThrees(start));

	printf("The new number is ");
	printNumber(start);
	freeNumber(start);



	return 0;
}

struct digit* createDigit(int dig) {
	struct digit* ptr;
	ptr = (struct digit*) malloc(sizeof(struct digit));
	ptr->num = dig;
	ptr->next = NULL;
	return ptr;
}

struct digit* append(struct digit* end, struct digit* newDigptr) {
	end->next = newDigptr;
	return(end->next);
}

void printNumber(struct digit* start) {
	struct digit* ptr = start;
	while (ptr != NULL) {
		printf("%d", ptr->num);
		ptr = ptr->next;
	}
	printf("\n");
}

void freeNumber(struct digit* start) {
	struct digit* ptr = start;
	struct digit* tmp;
	while (ptr != NULL) {
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

struct digit* readNumber(void) {
	char c;
	int d;
	struct digit* start;
	struct digit* end = 0; 
	struct digit * newptr;
	start = NULL;
	scanf_s("%c", &c, sizeof(c));
	while (c != '\n') {
		d = c - 48;
		newptr = createDigit(d);
		if (start == NULL) {
			start = newptr;
			end = start;
		}
		else {
			end = append(end, newptr);
		}
		scanf_s("%c", &c, sizeof(c));
	}
	return(start);
}

int divisibleByThree(struct digit* start) {
	struct digit* ptr = start;
	struct digit* temp;
	int num = 0;
	while (ptr != NULL) {
		temp = ptr->next;
		num += ptr->num;
		ptr = temp;
		if ((num % 3) == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int changeThrees(struct digit* start) {
	struct digit* ptr = start;
	int changes = 0;
	while ((ptr != NULL)) {
		if (ptr->num == 3) {
			ptr->num = 9;
			changes++;
			
		}
		ptr = ptr->next;
	}
	return changes;
}
