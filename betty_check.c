#include <stdio.h>

#define MAX_SIZE 100

{
	int m;
	int k;
}

/**
 * print_point   - A function that prints a point
 * @p: the point
 */

void print_point(Point p)
{
	printf("m: %d, k: %d\n", p.m, p.k);
}

/**
 * main - Entry point
 * Return: Nothing
 */

int main(void)
{
	Point p;

	p.g = 10;
	p.p = 20;

print_point(p);

	return (0);
}
