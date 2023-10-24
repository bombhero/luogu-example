#include <iostream>
using namespace std;

typedef double cell_t;
#define MATRIX_SIZE 3

class Matrix
{
    public:
    cell_t content[MATRIX_SIZE][MATRIX_SIZE];
    Matrix()
    {
        int i, j;
        for(i=0; i<MATRIX_SIZE; i++)
            for(j=0; j<MATRIX_SIZE; j++)
                content[i][j] = 0;
        return;
    }

    Matrix operator* (const Matrix &b) const
    {
        Matrix result;
        int row_idx, col_idx, i;
        
        for(row_idx=0; row_idx<MATRIX_SIZE; row_idx++){
            for(col_idx=0; col_idx<MATRIX_SIZE; col_idx++){
                result.content[row_idx][col_idx] = 0;
                for(i=0; i<MATRIX_SIZE; i++)
                    result.content[row_idx][col_idx] += content[row_idx][i] * b.content[i][col_idx];
            }            
        }

        return result;
    }
};

Matrix matrix_pow(Matrix a, int n)
{
    Matrix out_m, middle_m;

    if(n==1){
        return a;
    }

    middle_m = matrix_pow(a, n/2);
    out_m = middle_m * middle_m;
    if(n%2 == 1){        
        out_m = out_m * a;
    }

    return out_m;
}

int main()
{
    int n, m;
    int i;
    cell_t d, A1, An;
    cell_t a, b, c, A2, Am;
    Matrix calc_m, final_m;

    cin>>n>>m;
    cin>>d>>A1>>An;

    calc_m.content[0][0] = -2;
    calc_m.content[1][0] = 1;
    calc_m.content[2][0] = 2;
    calc_m.content[0][1] = 1;
    calc_m.content[2][2] = 1;

    if(n==1){
        printf("%.3f", A1);
    }

    if(n==2){
        if(m==1) printf("%.3f", A1);
        else printf("%.3f", An);
    }

    // if n>=3
    final_m = matrix_pow(calc_m, n-2);
    a = final_m.content[0][0];
    b = final_m.content[1][0];
    c = final_m.content[2][0];

    A2 = (An - b*A1 - c*d) / a;

    for(i=3; i<=m; i++){
        Am = -2*A2 + A1 + 2*d;
        A1 = A2;
        A2 = Am;
    }

    printf("%.3f", Am);

    return 0;
}