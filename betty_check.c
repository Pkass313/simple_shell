#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int m;
    int k;
} Point;

void print_point(Point p)
{
    printf("m: %d, k: %d\n", p.m, p.k);
}

int main(void)
{
    Point p;
    p.g = 10;
    p.p = 20;

    print_point(p);

    return 0;
}
