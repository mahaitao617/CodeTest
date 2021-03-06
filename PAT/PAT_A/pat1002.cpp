﻿/*
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*/

#include <stdio.h>


int main()
{
	int k1, k2, k3;
	float a1[10], a2[10], a3[20];
	int n1[10], n2[10], n3[20];
	int p1, p2;


	scanf("%d", &k1);


	for(int i=0; i<k1; i++)
	{	
		scanf("%d %f", &n1[i], &a1[i]);
	}


	scanf("%d", &k2);


	for(int i=0; i<k2; i++)
	{
		scanf("%d %f", &n2[i], &a2[i]);
	}


	p1 = k1-1;
	p2 = k2-1;


	int count = 0;


	while( p1>=0 && p2>=0)
	{
		if( n1[p1] == n2[p2])
		{
			n3[count] = n1[p1];
			a3[count] = a1[p1] + a2[p2];
			if( a3[count] != 0.f)
			{
				count++;
			}
			p1 --;
			p2 --;
		}
		else if( n1[p1] < n2[p2])
		{
			n3[count] = n1[p1];
			a3[count] = a1[p1];
			count++;
			p1 --;
		}
		else
		{	
			n3[count] = n2[p2];
			a3[count] = a2[p2];
			count++;
			p2--;
		}


	}


	if( p1 >= 0)
	{
		for( int i=p1; i>=0; i--)
		{
			n3[count] = n1[i];
			a3[count] = a1[i];
			count++;
		}
	}
	else
	{
		for( int i=p2; i>=0; i--)
		{
			n3[count] = n2[i];
			a3[count] = a2[i];
			count++;
		}
	}
	
	printf("%d", count);
	if(count > 0)
	{
		printf(" ");
	}
	for( int i=count-1; i>=0; i--)
	{
		printf("%d %.1f", n3[i], a3[i]);
		if( i>0)
		{
			printf(" ");
		}
	}


	return 0;




}
