/*
ÃâÃ³ : hackkerank Algorithms>Implementation>Climbing the Leaderboard (Medium)
https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
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
int *result;
typedef struct info {
	int rank;
	int index;
} INFO;
INFO tmp;
int rank = 1;

void get_rank(int* scores, int n, int score, int total)
{
	int i;
	int before = -1;

	for (i = n; i<total; i++) {
		if (scores[i]>score) break;
		if (before != scores[i]) {
			rank--;
			before = scores[i];
		}
	}
	tmp = (INFO){ rank, i };
}

int comp_int(int* a, int* b)
{
	return *a - *b;
}

//main function
int* climbingLeaderboard(int scores_count, int* scores, int alice_count, int* alice, int* result_count) {
	int before = -1;
	int i, n;
	
	*result_count = alice_count;
	qsort(scores, scores_count, sizeof(int), comp_int);

	for (i = 0; i<scores_count; i++) {
		if (before != scores[i]) {
			rank++;
			before = scores[i];
		}
	}
	result = malloc(alice_count * sizeof(int));

	n = 0;
	for (i = 0; i<alice_count; i++) {
		get_rank(scores, n, alice[i], scores_count);
		result[i] = tmp.rank;
		n = tmp.index;
	}

	return result;
}

int main()
{
	FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

	char* scores_count_endptr;
	char* scores_count_str = readline();
	int scores_count = strtol(scores_count_str, &scores_count_endptr, 10);

	if (scores_count_endptr == scores_count_str || *scores_count_endptr != '\0') { exit(EXIT_FAILURE); }

	char** scores_temp = split_string(readline());

	int* scores = malloc(scores_count * sizeof(int));

	for (int i = 0; i < scores_count; i++) {
		char* scores_item_endptr;
		char* scores_item_str = *(scores_temp + i);
		int scores_item = strtol(scores_item_str, &scores_item_endptr, 10);

		if (scores_item_endptr == scores_item_str || *scores_item_endptr != '\0') { exit(EXIT_FAILURE); }

		*(scores + i) = scores_item;
	}

	char* alice_count_endptr;
	char* alice_count_str = readline();
	int alice_count = strtol(alice_count_str, &alice_count_endptr, 10);

	if (alice_count_endptr == alice_count_str || *alice_count_endptr != '\0') { exit(EXIT_FAILURE); }

	char** alice_temp = split_string(readline());

	int* alice = malloc(alice_count * sizeof(int));

	for (int i = 0; i < alice_count; i++) {
		char* alice_item_endptr;
		char* alice_item_str = *(alice_temp + i);
		int alice_item = strtol(alice_item_str, &alice_item_endptr, 10);

		if (alice_item_endptr == alice_item_str || *alice_item_endptr != '\0') { exit(EXIT_FAILURE); }

		*(alice + i) = alice_item;
	}

	int result_count;
	int* result = climbingLeaderboard(scores_count, scores, alice_count, alice, &result_count);

	for (int i = 0; i < result_count; i++) {
		fprintf(fptr, "%d", *(result + i));

		if (i != result_count - 1) {
			fprintf(fptr, "\n");
		}
	}

	fprintf(fptr, "\n");

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

		if (!line) { break; }

		data_length += strlen(cursor);

		if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

		size_t new_length = alloc_length << 1;
		data = realloc(data, new_length);

		if (!data) { break; }

		alloc_length = new_length;
	}

	if (data[data_length - 1] == '\n') {
		data[data_length - 1] = '\0';
	}

	data = realloc(data, data_length);

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
