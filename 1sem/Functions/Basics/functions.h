//#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/// <summary> global variable </summary>
int global_var;

/// <summary> prints 'hello' to console </summary>
void print_hello();

/// <summary> prints num </summary>
/// <param name="num"> number to print </param>
void print_num(const int num);

/// <summary> calculates sum </summary>
/// <param name="num"> first operand </param>
/// <returns> sum of a and b </returns>
int sum(int a, int b);

//test comment -- will also be used by intellisense
void Swap(int* a, int* b);
void Swap(int& a, int& b);

int mpow(int val, int deg);
double mpow(double val, int deg);
double mpow(double val, double deg);

int count_calls();

#endif