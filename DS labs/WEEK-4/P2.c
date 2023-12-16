#include<stdio.h>
#include<stdlib.h>

struct Student{
	char name[50];
	int rollno;
	float cgpa;
};

void readStudent(struct Student *student){
	printf("Enter student name: ");
	scanf("%s", student->name);
	printf("Enter roll number: ");
	scanf("%d", &(student->rollno));
	printf("Enter CGPA: ");
	scanf("%f", &(student->cgpa));
}

void displayStudent(struct Student *student){
	printf("Name: %s\n", student->name);
	printf("Roll no: %d\n", student->rollno);
	printf("CGPA: %.2f\n", student->cgpa);
}

void bubbleSort(struct Student *students, int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n-i-1; j++){
			if (students[j].rollno>students[j+1].rollno){
				struct Student temp = students[j];
				students[j] = students[j+1];
				students[j+1] = temp;
			}
		}
	}
}

int main(){
	int n;
	printf("Enter no of students: ");
	scanf("%d", &n);

	struct Student *students = (struct Student*)malloc(n*sizeof(struct Student));

	if (students==NULL){
		printf("Memory allocation failed\n");
		return 1;
	}

	for (int i=0; i<n; i++){
		printf("\nEnter details for student %d\n", i+1);
		readStudent(&students[i]);
	}

	bubbleSort(students, n);

	printf("\nStdudent list (sorted by roll no):-\n");
	for (int i=0; i<n;i++){
		printf("\nStudent %d:\n", i+1);
		displayStudent(&students[i]);
	}
	free(students);
	return 0;
}