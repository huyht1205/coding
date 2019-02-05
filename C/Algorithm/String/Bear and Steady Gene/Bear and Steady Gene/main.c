/*
 A gene is represented as a string of length  (where  is divisible by ), composed of the letters A, C, T, and G.
 It is considered to be steady if each of the four letters occurs exactly  times.
 For example, GACT and AAGTGCCT are both steady genes.

 Bear Limak is a famous biotechnology scientist who specializes in modifying bear DNA to make it steady.
 Right now, he is examining a gene represented as a string.
 It is not necessarily steady. Fortunately, Limak can choose one (maybe empty) substring of 
 and replace it with any substring of the same length.

 Modifying a large substring of bear genes can be dangerous.
 Given a string , can you help Limak find the length of the smallest possible substring that
 he can replace to make  a steady gene?

 Note: A substring of a string S is a subsequence made up of zero or more consecutive characters of S.

 Input Format

 The first line contains an interger  divisible by , denoting the length of a string .
 The second line contains a string  of length . Each character is one of the four: A, C, T, G.

 Constraints


 is divisible by
 Subtask

 in tests worth  points.
 Output Format

 On a new line, print the minimum length of the substring replaced to make  stable.

 Sample Input

 8
 GAAATAAA
 Sample Output

 5
 Explanation

 One optimal solution is to replace a substring  with, resulting in.
 The replaced substring has length , so we print  on a new line.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define A	0
#define C	1
#define G	2
#define T	3

int main()
{
	int n = 0;
	int count[4] = {0, 0, 0, 0};
	int ret = 0;
	int steadyNum = 0;
	long long pos = 0;
	char *s = NULL;

	scanf("%d", &n);
	steadyNum = n / 4;
	s = (char *) malloc( (sizeof(char) * n) + 1);
	// Go next line
	fgetpos(stdin, &pos);
	pos++;
	fsetpos(stdin, &pos);
	// Read string
	fgets(s, n+1, stdin);

	for (int i = 0; i < n; i++)
	{
		switch (s[i]) {
			case 'A':
				count[A]++;
				break;
			case 'C':
				count[C]++;
				break;
			case 'G':
				count[G]++;
				break;
			case 'T':
				count[T]++;
				break;

			default:
				break;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		ret += abs(steadyNum - count[i]);
	}
	printf("%d\n", ret);

	free(s);
	return 0;
}