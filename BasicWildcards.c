//
//  BasicWildcards.c
//  Wildcard Detection
//
//  Created by Alex Nichol on 10/25/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//

#include "BasicWildcards.h"

int bcomp (char * str1, char * str2, int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (str1[i] != str2[i]) return 1;
	}
	return 0;
}

// returns 0 on success
// 1 on fail
int strwcard (char * pattern, char * matches) {
	if (pattern && matches) {
		int j, j2, i = 0, i1;
		int len1, len2;
		len1 = strlen(pattern);
		len2 = strlen(matches);
		for (j = 0; j < len1; j++) {
			char c = pattern[j];
			int star = (c == '*' ? 1 : 0);
			if (c == '\\') {
				if (pattern[j + 1] == '\\') {
					j += 1;
				} else if (pattern[j + 1] == '*') {
					c = '*';
					j += 1;
				}
			}
			if (star == 0) {
				// check for basic match
				if (matches[i] != c) {
					return 1;
				} else i += 1;
			} else {
				char * npattern = &pattern[j + 1];
				int npatternlen = 0;
				for (j2 = j + 1; j2 < len1; j2++) {
					char c = pattern[j2];
					if (c == '*' || c == 0) {
						break;
					} else npatternlen += 1;
				}
				j += npatternlen;
				int good = 0;
				// go until end of pattern
				for (i1 = (len2 - npatternlen); i1 >= i; i1--) {
					if (bcomp(npattern, &matches[i1], npatternlen) == 0) {
						good = 1;
						i = i1 + npatternlen;
						break;
					}
				}
				if (good == 0) return 1;
			}
		}
	} else return 1;
	return 0;
}