//
//  main.c
//  Riche_Rich
//
//  Created by Hoàng Trung Huy on 8/24/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define BUFFER_LENGTH		100000

int main(){
	int n;
	int k;
	int strLen = 0;
	int strHalfLen = 0;
	char number[BUFFER_LENGTH];
	int diffPos[BUFFER_LENGTH];
	int diffPosIndex = 0;

	scanf("%d %d",&n,&k);
	scanf("%s",number);

	strLen = (int) strlen(number);
	strHalfLen = (int) strLen / 2;

	diffPosIndex = 0;
	for (int i = 0; (i < strHalfLen) && (k >= 0); i++)
	{
		if (number[i] != number[strLen - 1 - i])
		{
			int max = number[i] >= number[strLen - 1 - i] ? number[i] : number[strLen - 1 - i];
			diffPos[diffPosIndex] = i;
			diffPosIndex++;

			number[i] = max;
			number[strLen - 1 - i] = max;
			k--;
		}
	}

	for (int i = 0; (i < k) && (i < diffPosIndex); i++)
	{
		if (number[diffPos[i]] != '9')
		{
			number[diffPos[i]] = '9';
			number[strLen - 1 - diffPos[i]] = '9';
			k--;
		}
	}

	if (k >= 0)
	{
		printf("%s\n", number);
	}
	else
	{
		printf("%d\n", (-1));
	}

	return 0;
}
