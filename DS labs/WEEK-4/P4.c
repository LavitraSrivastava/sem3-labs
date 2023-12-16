#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct DOB{
	int day;
	int *month;
	int year;
};

struct STU_INFO{
	int reg_no;
	char *name;
	char address[50];
};

struct COLLEGE{
	char *college_name;
	char university_name[50];
};

struct STUDENT{
	struct DOB *dob;
	struct STU_INFO stu_info;
	struct COLLEGE college;
};

int main(){

	struct STUDENT* student = (struct STUDENT*)malloc(sizeof(struct STUDENT));
	if (student == NULL){
		printf("Memory allocation failed\n");
		return 1;
	}
	student->dob = (struct DOB*)malloc(sizeof(struct DOB));
	student->dob->month = (int*)malloc(sizeof(int));
	student->stu_info.name= (char*)malloc(50*sizeof(char));
	student->college.college_name = (char*)malloc(50*sizeof(char));

	printf("Enter student's DOB: ");
	scanf("%d %d %d", &(student->dob->day), (student->dob->month), &(student->dob->year));
	printf("Enter reg no: ");
	scanf("%d", &(student->stu_info.reg_no));
	printf("Enter name: ");
	scanf("%s", (student->stu_info.name));
	printf("Enter address: ");
	scanf("%s", (student->stu_info.address));
	printf("Enter college name: ");
	scanf("%s", (student->college.college_name));
	printf("Enter university name: ");
	scanf("%s", (student->college.university_name));

	printf("\nPrinting student details:-\n");
	printf("DOB: %d/%d/%d\n", student->dob->day, *(student->dob->month), student->dob->year);
	printf("Reg no: %d\n", student->stu_info.reg_no);
	printf("Name: %s\n", student->stu_info.name);
	printf("Address: %s\n", student->stu_info.address);
	printf("College: %s\n", student->college.college_name);
	printf("University: %s\n", student->college.university_name);
	
	free(student->college.college_name);
	free(student->stu_info.name);
	free(student->dob->month);
	free(student->dob);
	free(student);
	return 0;
}