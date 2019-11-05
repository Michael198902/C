#include <stdio.h>
#include <stdlib.h>

struct digit {
	int num;
	struct digit* next;
};

struct digit* createDigit(int dig);
struct digit* append(struct digit* end, struct digit* newDigptr);
void printNumber(struct digit* start);
void freeNumber(struct digit* start);
struct digit* readNumber();

int main(void) {
	//! stack = showMemory(start=65520)
	struct digit* start;
	printf("Please enter a number: ");
	start = readNumber();
	printNumber(start);
	freeNumber(start);
	return 0;
}

struct digit* createDigit(int dig) {
	struct digit* ptr;
	//use malloc function to reserve space in memory for every new digit of the list
	ptr = (struct digit*)malloc(sizeof(struct digit));
	ptr->num = dig;
	ptr->next = NULL;
		return ptr;
	}

struct digit* append(struct digit* end, struct digit* newDigptr) {
	end->next = newDigptr;
	return (end->next);
}

void printNumber(struct digit* start) {
	struct digit* ptr = start;
	while (ptr != NULL) {
		printf("%d", ptr->num);
		ptr = ptr->next;
	}
}

struct digit* readNumber() {
	struct digit* end = 0;
	struct digit * start, * newPtr;
	// We need to read each digit as a an individual character with its ascii code
	char c = 0;
	int d =0;
	// initially the pointer start to struct stores a NULL value
	start = NULL;
	scanf_s("%c", &c, sizeof(c) == 1);
	while (c != '\n') {// while the user does not hit the enter key the loop keep storing the next digit in character form
		d = c - 48;
		newPtr = createDigit(d);
		if (start == NULL) {
			start = newPtr;
			end = start;

		}
		else {
			end = append(end, newPtr);
			scanf_s("%c", &c, sizeof(c) == 1);
		}
	}
	return start;
}

	

void freeNumber(struct digit* start) {
	struct digit* temp;
	struct digit *ptr=start;
		while (ptr != NULL) {
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
}
