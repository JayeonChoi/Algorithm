/*
출처 : hackerrank -Connected Cells in a Grid(난이도 : medium(50) )
https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem?h_r=internal-search
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
int** matrix;
struct xy {
	int r, c;
};
struct xy que[15 * 15 * 10];
int wp, rp;
int dr[] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int BFS(int sr, int sc, int r, int c)
{
	int nr, nc, i;
	struct xy out;

	wp = rp = 0;
	que[wp].r = sr;
	que[wp].c = sc;
	wp++;
	matrix[sr][sc] = 0;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 8; i++) {
			nr = out.r + dr[i];
			nc = out.c + dc[i];
			if (nr<0 || nc<0 || nr >= r || nc >= c) continue;
			if (matrix[nr][nc] == 1) {
				matrix[nr][nc] = 0;
				que[wp].r = nr;
				que[wp].c = nc;
				wp++;
			}
		}
	}
	return rp;
}

int get_max(int R, int C) {
	int i, j;
	int max = 0;
	int tmp;

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (matrix[i][j] == 1) {
				tmp = BFS(i, j, R, C);
				if (tmp > max) max = tmp;
			}
		}
	}
	return max;
}

int connectedCell(int matrix_rows, int matrix_columns) {
	int sol = get_max(matrix_rows, matrix_columns);
	return sol;
}

int main()
{
	FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

	char* n_endptr;
	char* n_str = readline();
	int n = strtol(n_str, &n_endptr, 10);

	if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

	char* m_endptr;
	char* m_str = readline();
	int m = strtol(m_str, &m_endptr, 10);

	if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

	matrix = malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		*(matrix + i) = malloc(m * (sizeof(int)));

		char** matrix_item_temp = split_string(readline());

		for (int j = 0; j < m; j++) {
			char* matrix_item_endptr;
			char* matrix_item_str = *(matrix_item_temp + j);
			int matrix_item = strtol(matrix_item_str, &matrix_item_endptr, 10);

			if (matrix_item_endptr == matrix_item_str || *matrix_item_endptr != '\0') { exit(EXIT_FAILURE); }

			*(*(matrix + i) + j) = matrix_item;
		}
	}

	int matrix_rows = n;
	int matrix_columns = m;

	int result = connectedCell(matrix_rows, matrix_columns);

	fprintf(fptr, "%d\n", result);

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
