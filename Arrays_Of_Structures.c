#include <stdio.h>
#include <stdlib.h>

struct point {
	int x;
	int y;
};

void readPoint(struct point* pntptr);
void printPoint(struct point pt);
void printTriangle(struct point* ptr);

int main(void) {
	struct point triangle[3];
	int i;
	for (i = 0; i < 3; i++) {
		readPoint(&triangle[i]);
	}
	printTriangle(triangle);//triangle is an array of points contained in a structure form
	return 0;
}

void readPoint(struct point* pntptr) {
	printf("____New Point____\n");
	printf("insert x coordinate: ");
	scanf_s("%d", &pntptr->x);
	printf("insert y coordinate: ");
	scanf_s("%d", &pntptr->y);
}
void printTriangle(struct point* ptr) {
	int i;
	for (i = 0; i < 3; i++) {
		printPoint(ptr[i]);
	}
}
void printPoint(struct point pt) {
	printf("(%d, %d)", pt.x, pt.y);
	}
