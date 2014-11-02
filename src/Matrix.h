typedef void* Matrix_ElemType;
typedef struct Matrix
{
	Matrix_ElemType data[][];
	int width;
	int height;
}Matrix;

Matrix* Matrix_new(Matrix_ElemType data[][],int width,int height);
Matrix_ElemType* Matrix_get(Matrix *matrix, int i,int j);
Matrix_ElemType* Matrix_setCopy(Matrix *matrix, int i,int j, Matrix_ElemType * e);
void Matrix_clear(Matrix *matrix,void (*ElemType_free)(Matrix_ElemType*));
int Matrix_width(Matrix *matrix);
int Matrix_height(Matrix *matrix);
