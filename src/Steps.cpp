/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->211
	->22
	So total number of ways is 4

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"
#include<stdio.h>
#include<malloc.h>

int cal_2count(int arr[], int len)
{
	int i = 0, count_2 = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == 2)
			count_2++;
	}
	return count_2;
}
int fact(int num)
{
	if (num == 0)
		return 1;
	else
	{
		int prod = 1;
		while (num > 0)
		{
			prod *= num;
			num--;
		}
		return prod;
	}
}
int generateSeqUsing1and2(int x, int arr[], int curr_sum, int curr_idx, int *ans)
{
	// If current sum is equal to x, then we found a sequence
	if (curr_sum == x)
	{
		int x1;
		x1 = cal_2count(arr, curr_idx);
		int numerator = fact(curr_idx);
		int den1 = fact(x1);
		int den2 = fact((curr_idx - x1));
		int denominator = den1*den2;
		int y = numerator / denominator;
		*ans = *ans + y;
		return *ans;
	}

	int num = 1;
	while (num <= x - curr_sum && (curr_idx == 0 || num <= arr[curr_idx - 1]))
	{
		arr[curr_idx] = num;
		generateSeqUsing1and2(x, arr, curr_sum + num, curr_idx + 1, ans);
		num++;
		if (num == 3)
		{
			return *ans;
		}
	}
	return *ans;
}

int get_steps(int s)
{
	if (s == 0)
		return 0;
	int an = 0;
	int* arr = (int*)malloc(s * sizeof(int));
	int sol = generateSeqUsing1and2(s, arr, 0, 0, &an);
	return sol;
}