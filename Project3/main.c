#include <stdio.h>

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
	int terms;

}SparseMatrix;

SparseMatrix m_t2(SparseMatrix a) {

	SparseMatrix b;
	int bindex;
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;
	if (a.terms > 0) {

	}
}
int main() {
	printf("Enter row,column, and value pairs in order:");

}



