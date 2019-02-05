//
//  main.c
//  String_Construction
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

#define LIST_LENGTH		30

typedef enum _availability {
	available,
	unavailable
} availability;

int main(){
	int n;

	scanf("%d",&n);
	for(int a0 = 0; a0 < n; a0++){
		char *s = (char *)malloc( (100000 + 1) * sizeof(char) );
		char *ptr = s;
		int strLen = 0;
		unsigned int cost = 0;
		availability alphabetList[LIST_LENGTH];

		scanf("%s",s);

		for (int i = 0; i < LIST_LENGTH; i++)
		{
			alphabetList[i] = unavailable;
		}
		strLen = (int) strlen(s);

		for (int i = 0; i < strLen; i++)
		{
			if (unavailable == alphabetList[*ptr - 97])
			{
				alphabetList[*ptr - 97] = available;
				cost++;
			}
			ptr++;
		}

		printf("%d\n", cost);
	}
	return 0;
}


