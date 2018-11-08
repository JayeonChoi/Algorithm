/*
출처 : 해커랭크(hackerrank) 난이도 Medium-Greedy Florist
https://www.hackerrank.com/challenges/greedy-florist/problem
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

int getMinimumCost(int k, int c_count, int* c) {
	//sorting
	int i, j;
	int tmp;
	int cost = 0;
	int mul = 0;
	int f = 0;

	for (i = 0; i<c_count - 1; i++) {
		for (j = i + 1; j<c_count; j++) {
			if (c[i]<c[j]) {
				tmp = c[i]; c[i] = c[j]; c[j] = tmp;
			}
		}
	}

	//get_ans
	for (i = 0; i<c_count; i++) {
		cost += c[i] * (mul + 1);
		f++;
		if (f >= k) {
			f = 0;
			mul++;
		}
	}

	return cost;
}

int main()
{
	FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

	char** nk = split_string(readline());

	char* n_endptr;
	char* n_str = nk[0];
	int n = strtol(n_str, &n_endptr, 10);

	if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

	char* k_endptr;
	char* k_str = nk[1];
	int k = strtol(k_str, &k_endptr, 10);

	if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

	char** c_temp = split_string(readline());

	int* c = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		char* c_item_endptr;
		char* c_item_str = *(c_temp + i);
		int c_item = strtol(c_item_str, &c_item_endptr, 10);

		if (c_item_endptr == c_item_str || *c_item_endptr != '\0') { exit(EXIT_FAILURE); }

		*(c + i) = c_item;
	}

	int c_count = n;

	int minimumCost = getMinimumCost(k, c_count, c);

	fprintf(fptr, "%d\n", minimumCost);

	fclose(fptr);

	return 0;
}

char* readline() {
	size_t alloc_length = 1024;
	size_t data_length = 0;
	char* data = malloc(alloc_length);

	while (true) {
		char* cursor = data + data_length;
		char* line = fgets(cursor, alloc_length - data_length, stdin);

		if (!line) {
			break;
		}

		data_length += strlen(cursor);

		if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
			break;
		}

		alloc_length <<= 1;

		data = realloc(data, alloc_length);

		if (!line) {
			break;
		}
	}

	if (data[data_length - 1] == '\n') {
		data[data_length - 1] = '\0';

		data = realloc(data, data_length);
	}
	else {
		data = realloc(data, data_length + 1);

		data[data_length] = '\0';
	}

	return data;
}

char** split_string(char* str) {
	char** splits = NULL;
	char* token = strtok(str, " ");

	int spaces = 0;

	while (token) {
		splits = realloc(splits, sizeof(char*) * ++spaces);

		if (!splits) {
			return splits;
		}

		splits[spaces - 1] = token;

		token = strtok(NULL, " ");
	}
	return splits;
}
