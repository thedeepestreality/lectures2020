#pragma once
extern int global_var;
//prints 'hello' to console
void print_hello();
//prints num to console
//num -- argument to print
void print_num(const int num);
//calculates sum of two operands
//a -- first operand
//b -- second operand
//returns sum of a and b
int sum(int a, int b);

void Swap(int* a, int* b);
void Swap(int& a, int& b);

int mpow(int val, int deg);
double mpow(double val, int deg);
double mpow(double val, double deg);