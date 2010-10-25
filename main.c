//
//  main.c
//  Wildcard Detection
//
//  Created by Alex Nichol on 10/25/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include "BasicWildcards.h"

char * readline (FILE * fp) {
	fflush(stdout);
	char * str = (char *)malloc(1);
	int s = 0, t;
	while ((t = fgetc(fp))) {
		if (t == EOF || t == '\n') {
			break;
		} else if (t != '\r') {
			char * stemp = (char *)calloc(s + 2, sizeof(char));
			memcpy(stemp, str, s);
			stemp[s] = t;
			stemp[s + 1] = 0;
			free(str);
			str = stemp;
			s += 1;
		}
	}
	return str;
}

int main (int argc, const char * argv[]) {

	// insert code here...
	printf("Enter phrase: ");
	char * phrase = readline(stdin);
	printf("Enter wildcarded phrase: ");
	char * wcard = readline(stdin);
	if (strwcard(wcard, phrase) == 0) {
		printf("Matches.\n");
	} else {
		printf("No match.\n");
	}
	free(phrase);
	free(wcard);
	
    return 0;
}

