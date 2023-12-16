#include<stdio.h>
#include<stdlib.h>

struct Date{
	int day;
	int month;
	int year;
};

struct Address{
	char houseNumber[20];
	char zipCode[20];
	char state[30];
};

struct Employee{
	char name[50];
	struct Date dob;
	struct Address address;
};

void readEmployee(struct Employee *emp){
	printf("Enter employee name: ");
	scanf("%s", emp->name);
	printf("Enter DOB(dd-mm-yyyy): ");
	scanf("%d %d %d", &emp->dob.day, &emp->dob.month, &emp->dob.year);
	printf("Enter house number: ");
	scanf("%s", emp->address.houseNumber);
	printf("Enter zipcode: ");
	scanf("%s", emp->address.zipCode);
	printf("Enter state: ");
	scanf("%s", emp->address.state);
}

void displayEmployee(struct Employee *emp){
	printf("Name: %s\n", emp->name);
	printf("DOB: %d/%d/%d\n", emp->dob.day, emp->dob.month, emp->dob.year);
	printf("Address: %s, %s, %s\n", emp->address.houseNumber, emp->address.zipCode, emp->address.state);
}

int main(){
	int numEmp;
	printf("Enter no of employees: ");
	scanf("%d", &numEmp);

	struct Employee *employees = (struct Employee*)malloc(numEmp*sizeof(struct Employee));

	if (employees==NULL){
		printf("Memory allocation failed\n");
		return 1;
	}

	for (int i=0; i<numEmp; i++){
		printf("\nEnter details for employee %d:-\n", i+1);
		readEmployee(&employees[i]);
	}
	printf("\nEmployee details:-\n");
	for (int i=0;i<numEmp;i++){
		printf("\nEmployee %d:\n", i+1);
		displayEmployee(&employees[i]);
	}
	free(employees);
	return 0;
}