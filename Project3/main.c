#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;

}element;
typedef struct {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;//유효 항 수!

}SparseMatrix;

SparseMatrix m_t2(SparseMatrix a) {//동적메모리할당을 

	SparseMatrix *b;
	b = (SparseMatrix*)malloc(sizeof(SparseMatrix));


	int bindex;
	(*b).rows = a.rows;
	(*b).cols = a.cols;
	(*b).terms = a.terms;
	if (a.terms > 0) {
		bindex=0;
		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					(*b).data[bindex].row = a.data[i].col;
					(*b).data[bindex].col = a.data[i].row;
					(*b).data[bindex].value = a.data[i].value;
					bindex++;

				}
			}
		}
	}
	return *b;
}

void matrix_print(SparseMatrix a) {

	printf("=================\n");
	for (int i = 0; i < a.terms; i++) {
		printf("%d,%d,%d\n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("=================\n");
}

int main() {
	SparseMatrix m;

	int rows_size, cols_size, nzt_size;
	int col, row, value;


	printf("Enter the size of rows and colume, the number of non-zero terms");
	scanf_s("%d %d %d", &rows_size,&cols_size,&nzt_size);

	m.rows = rows_size;
	m.cols = cols_size;
	m.terms = nzt_size;


	printf("Enter row,column, and value pairs in order:");

	for (int i = 0; i < nzt_size; i++) {
		scanf_s("%d %d %d", &row, &col, &value);
		m.data[i].col = col;
		m.data[i].row = row;
		m.data[i].value = value;

	}

	

	SparseMatrix result;
	result = m_t2(m);
	matrix_print(result);
	return 0;


}




