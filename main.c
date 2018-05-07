#include <stdio.h>
#include <math.h>

#define n 2
#define pi 3.1415926535

int m = (n + 1) / 2;
double x[n + 1] = {1, 2, 3}, y[n + 1] = {1, 8, 1}; 

double b(int j)
{
double b;
	for (int i = 0; i <= n - 1; i++){
		b += y[i] * cos(2 * pi * j * i / n);
	}
	b = b / n;
return b;
}

double a(int j)
{
double a;
	for (int i = 0; i <= n - 1; i++){
		a += y[i] * sin(2 * pi * i * j / n);
	}
	a = a / n;
return a;
}

double TrigInter(double X)
{
double h = x[1] - x[0];
double p;
	for (int i = 1; i <= m; i++){
		p += b(i) * cos(2 * pi * (X - x[0]) / n * h);
		p += a(i) * sin(2 * pi * (X - x[0]) / n * h);
	}
	p += b(0);
return p;	
}

int main()
{
double X[10] = {0}, B, A, p;
	
	for (int i = 0; i < 10; i++){
		X[i] = X[i - 1] + 0.5;
		p = TrigInter(X[i]);
		printf("P(%.1f) = %.3f\n", X[i], p);
	}

return 0;
}
