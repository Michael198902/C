#include <stdio.h>
#include <stdlib.h>


//Link structures together in a linked list, and append them by referencing the address of the next structure.
//creates a list of elements of a type of a structure
struct point {
	int x;
	int y;
	struct point* next;//store the address of the subsequent structure.
	//next is another member of the structure struct, and it is the address of another struct point
};

void printPoints(struct point* start);// only pass the begininnig of the list
struct point* append(struct point* end, struct point* newpt);
struct point* createPoint(int x, int y);

int main(void) {
	//! showMemory(start=65520)

	struct point* start = 0;
	struct point* end = 0;
	struct point* newpt = 0;

	//user determine how many points they want to include in the list
	int num, i;
	int x, y;
	printf("Enter the number of points: ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		printf("insert x: ");
		scanf_s("%d", &x);
		printf("insert y: ");
		scanf_s("%d", &y);
		newpt = createPoint(x, y);
		if (i == 0) {
			start = end = newpt;
		}
		else {
			end = append(end, newpt);
		}
	}
		printf("You entered: ");
		printPoints(start);
		free(newpt);
	return 0;
}

void printPoints(struct point* start) {
	//! showMemory(start = 65520, cursors=[ptr])
	struct point* ptr;
	ptr = start;
	while (ptr != NULL) {
		printf("(%d, %d)\n", ptr->x, ptr->y);
		ptr = ptr->next;
	}
}

struct point* append(struct point* end, struct point* newpt) {
	end->next = newpt;
	return(end->next);
}
// function that prints all linked points of the structure whlie the pointer does not points to  NULL position

struct point* createPoint(int x, int y) {
	struct point* ptr;
ptr= (struct point*)malloc(sizeof(struct point));
ptr->x = x;
ptr->y = y;
ptr->next = NULL;
return ptr;
}
