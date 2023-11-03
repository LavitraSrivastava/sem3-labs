#include<stdio.h>

struct Complex{
	float real;
	float imag;
};

struct Complex addComplex(struct Complex *c1, struct Complex *c2){
	struct Complex result;
	result.real = c1->real + c2->real;
	result.imag = c1->imag + c2->imag;
	return result;
}

struct Complex subtractComplex(struct Complex *c1, struct Complex *c2){
	struct Complex result;
	result.real = c1->real - c2->real;
	result.imag = c1->imag - c2->imag;
	return result;
}

struct Complex multiplyComplex(struct Complex *c1, struct Complex *c2){
	struct Complex result;
	result.real = (c1->real*c2->real)-(c1->imag*c2->imag);
	result.imag = (c1->imag*c2->real) + (c1->real*c2->imag);
	return result;
}

int main(){
	struct Complex num1, num2;
	printf("Enter real and imag parts of num1: ");
	scanf("%f %f", &num1.real, &num1.imag);
	printf("Enter real and imag parts of num2: ");
	scanf("%f %f", &num2.real, &num2.imag);

	struct Complex sum = addComplex(&num1, &num2);
	struct Complex diff = subtractComplex(&num1, &num2);
	struct Complex prod = multiplyComplex(&num1, &num2);

	printf("Sum: (%.1f) + (%.1f)i\n", sum.real, sum.imag);
	printf("Diff: (%.1f) + (%.1f)i\n", diff.real, diff.imag);
	printf("Product: (%.1f) + (%.1f)i\n", prod.real, prod.imag);

	return 0;
}