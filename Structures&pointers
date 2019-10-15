#include <stdio.h>
#include <stdlib.h>

struct student {
	int age;
	double grade;
	char name[10];
	char lastName[20];
};

void printStudent(struct student stud);
void readStudent(struct student* studptr);

int main(void) {
	//struct student learner;
	/*printf("Insert age:");
	scanf_s("%d", &learner.age);
	printf("Insert grade:");
	scanf_s("%lf", &learner.grade);
	printf("Insert name:");
	scanf_s("%9s", learner.name, (unsigned)_countof(learner.name));  //Reads formatted data from the standard input stream. These versions of scanf, _scanf_l, wscanf, _wscanf_l have security enhancements, as described in Security Features in the CRT.
	printf("Insert last name:");
	scanf_s("%9s", learner.lastName, (unsigned)_countof(learner.lastName));*/
  

	//____________Pass structures to functions directly _____Second part of the C course
	// Call a function that does the printing for us, a copy of the structure definition is made

	/*struct student me={33, 4.5, "Michael", "Levkovsky"};
	struct student you = { 59, 5.0, "Maria","Mateus" };

	printStudent(me);
	printStudent(you);*/

	//_____Pass a structure to a function by reference in memory______

	struct student me;
	readStudent(&me);
	printStudent(me);
	return 0;
}
void readStudent(struct student *studptr) {
	printf("_____New Student record_____\n");
	printf("Insert age:");
	scanf_s("%d", &(*studptr).age);
	printf("Insert grade:");
	scanf_s("%lf",&(*studptr).grade); //The & reads the integer of the address variable
	printf("Insert name:");
	scanf_s("%9s", (*studptr).name, (unsigned)_countof((*studptr).name));  //Reads formatted data from the standard input stream. These versions of scanf, _scanf_l, wscanf, _wscanf_l have security enhancements, as described in Security Features in the CRT.
	printf("Insert last name:");
	scanf_s("%19s", (*studptr).lastName, (unsigned)_countof((*studptr).lastName));
}
void printStudent(struct student stud) {
	printf("The name of the student is: %s %s \n", stud.name, stud.lastName);
	printf("The age of the student is: %d \n", stud.age);
	printf("The average grade of the student is: %lf \n", stud.grade);
	}
//Everything declared in the structure definition is copied in memory. For efficiency purposes is better to pass a pointer of the structure definition
//A pointer is a location in memory that points to the location of the structure in memory
