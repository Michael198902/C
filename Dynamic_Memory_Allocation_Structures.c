#include <stdio.h>
#include <stdlib.h>


///Create numeric structures from an user input
struct coordinates{
	int x;
	int y;
};

void readPoint(struct coordinates* pointptr);
void writePoint(struct coordinates pt);
//void printTriangle(struct coordinates* ptr);
void printPoly(struct coordinates* ptr, int vertices);

	int main(void) {

		/*struct coordinates point;
		readPoint(&point);
		writePoint(point);*/

		////Dynamically allocate memory to a array of structures//
		//This section of the course explains the principles to dynamically allocate memory for an array of structures
		//Using the proint structure declared, and the read and writing functions used in previos examples
		//Suppose we wanted the user to choose how many points they want the polygon to have 
		//
		struct coordinates* polygon;

		int i, num;
		printf("how many vertices does your polygon have?: ");
		scanf_s("%d", &num);

		//use the malloc function-the space we want is the size of one struct point multiplied by the number of the number of vertices
		//the malloc funtionc returns a pointer that points to the beginning of the array
		//malloc returns a void pointer to the allocated space, or NULL if there is insufficient memory available. 
		//we cast the variable to be a pointer that points to a struct point-make it compatible
		//after calling mellos you need to free the space that was used


		polygon = (struct coordinates*)malloc(num * sizeof(struct coordinates));
		//struct coordinates triangle[3];
		
		//___________________________
		/*for (i = 0; i<3; i++) {
			readPoint(&triangle[i]);
		}
		printTriangle(triangle);
		return 0;*/
		//____________________________
		
		for (i = 0; i<num; i++) {
			readPoint(&polygon[i]);
		}
		printPoly(polygon,num);
		return 0;
		free(polygon);
}
	void readPoint(struct coordinates *pointptr) {
		printf("____CREATE NEW POINT___\n");
		printf("insert x coordinate: \n");
		scanf_s("%d", &pointptr->x); //pointer to a structure that we need to de-reference
		printf("insert y coordinate: \n");
		scanf_s("%d", &pointptr->y);
	}

	//__________________________________________________****
	/*void printTriangle(struct coordinates* ptr) {
		int j;
		printf("__the coordinates are:__\n");
		for (j = 0; j < 3; j++) {
			writePoint(ptr[j]);
		}
	}*/
		//_______________________________________________****

	void printPoly(struct coordinates* ptr, int vertices) {
		int j;
		printf("__the coordinates are:__\n");
		for (j = 0; j < vertices; j++) {
			writePoint(ptr[j]);
		}
	}

	void writePoint(struct coordinates pt) {
		printf("(%d,%d)", pt.x, pt.y);
	}

	
	

	

