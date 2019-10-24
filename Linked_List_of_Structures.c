#include <stdio.h>
#include <stdlib.h>


//Link structures together in a linked list
//creates a list of elements of a type of a structure
struct point {
	int x;
	int y;
	struct point * next;//store the address of the subsequent address of the list
	//next is another member of the structure struct and it is the address of another struct point
};

void printPoints(struct point* ptr);

int main(void) {

	struct point pt1 = { 1,2, NULL };
	struct point pt2 = { 3,4, NULL };
	struct point pt3 = { 5,6, NULL };
	//instead of NULL we want to use the address of pt2 in pt1 and so on
	
	struct point* start;//pointer that points to the address where the first structure starts
	start = &pt1;
	pt1.next = &pt2;
	pt2.next = &pt3;

	/*ptr = start;
	while (ptr != NULL) {
		printf("(%d, %d)\n", ptr->x, ptr->y);
		ptr = ptr->next;
	}*/
	printPoints(start);
	return 0;
}

void printPoints(struct point* ptr) {
	struct point* start;
	start = ptr;
	while (start != NULL) {
		printf("(%d, %d)\n", start->x, start->y);
		start = start->next;
	}
}// function that prints all linked points of the sturcture whlie the pointer does not points to  NULL position
