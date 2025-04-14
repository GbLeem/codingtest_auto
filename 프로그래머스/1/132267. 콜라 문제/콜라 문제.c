#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n)
{
	int answer = 0;

	while (n >= a)
	{
		int temp = (n / a) * b;
		answer += temp;
		n = temp + (n % a);
	}

	return answer; 
}