#include <stdio.h>
#include <math.h>
int n = 5, N = 2;
double x[5] = {0, 1.26, 2.51, 3.77, 5.03}, y[5], X = 5;

int func(double x)
{
	double f = 2 + cos(x) + sin(x) + 3*cos(2*x) + 2*sin(2*x) + cos(3*x) + sin(3*x);
	return f;
}

double trigInter()
{
double a[N], b[N - 1], p;
	// a[0]
	for (int i = 0; i < n; i++)
		a[0] += y[i];
	a[0] = a[0] / n;
	
	// a[i]
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= n; j++){
			a[i] += y[j] * cos((2 * 3.14 * i * j)/n);
		}
		a[i] = a[i] / n;
	}
	
	// b[i]
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= n; j++){
			b[i] += y[j] * sin((2 * 3.14 * i * j)/n);
		}
		b[i] = b[i] / n;
	}	
	
	for (int i = 1; i <= N; i++)
		p += a[i] * cos(i * X) + b[i] * sin(i * X);
	p += a[0]/2;
		
	return p;
}

int main()
{
double p;	
	for (int i = 0; i < n; i++){
		y[i] = func(x[i]);
	}
		printf("x: ");
	for (int i = 0; i < n; i++)
		printf("%.2f ", x[i]);
	printf("\ny: ");
	for (int i = 0; i < n; i++)
		printf("%.2f ", y[i]);
	
	printf("\n");
	p = trigInter();
	printf("P[%.2f] = %.2f\n", X, p);

return 0;
}
