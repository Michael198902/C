struct student* createStudent(char studentName[], int studentAge) {
	struct student* ptr;
	ptr = (struct student*)malloc(sizeof(struct student));
	copyStr(studentName, ptr->name);
	ptr->age = studentAge;
	ptr->next = NULL;
	return ptr;
}

void copyStr(char* source, char* target) {
	int i = 0;
	while (source[i] != '\0') {
		target[i] = source[i];
		i++;
	}
	target[i] = '\0';
}

struct student* append(struct student* end, struct student* newStudptr) {
	end->next = newStudptr;
	return(end->next);
}

void printStudent(struct student* start) {
	struct student* ptr = start;
	while (ptr != NULL) {
	printf("%s is %d years old.\n", ptr->name, ptr->age);
	ptr = ptr->next;
	}
}
