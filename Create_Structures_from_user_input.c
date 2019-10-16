#include <stdio.h>
#include <stdlib.h>

struct coordinates{
	int x;
	int y;
};

void readPoint(struct coordinates* pointptr);
void writePoint(struct coordinates pt);

	int main(void) {
		struct coordinates point;
		readPoint(&point);
		writePoint(point);
		return 0;
}
	void readPoint(struct coordinates *pointptr) {
		printf("____CREATE NEW POINT___\n");
		printf("insert x coordinate: \n");
		scanf_s("%d", &pointptr->x); //pointer to a structure that we need to de-reference
		printf("insert y coordinate: \n");
		scanf_s("%d", &pointptr->y);
	}

	void writePoint(struct coordinates pt) {
		printf("the coordinates are (%d,%d)", pt.x, pt.y);
	}
