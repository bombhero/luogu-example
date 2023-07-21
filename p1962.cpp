#include <iostream>
using namespace std;


typedef unsigned long long cell_t;
cell_t base_num = 1000000007;


class Matrix
{
    public:
    cell_t content[2][2];
    Matrix()
    {
        int i, j;
        for(i=0; i<2; i++)
            for(j=0; j<2; j++)
                content[i][j] = 0;
        return;
    }

    Matrix operator* (const Matrix &b) const
    {
        Matrix result;
        
        result.content[0][0] = (content[0][0] * b.content[0][0] + content[0][1] * b.content[1][0]) % base_num;
        result.content[0][1] = (content[0][0] * b.content[0][1] + content[0][1] * b.content[1][1]) % base_num;
        result.content[1][0] = (content[1][0] * b.content[0][0] + content[1][1] * b.content[1][0]) % base_num;
        result.content[1][1] = (content[1][0] * b.content[0][1] + content[1][1] * b.content[1][1]) % base_num;

        return result;
    }

};


Matrix matpow(Matrix mat_s, unsigned long long n)
{
    Matrix mat_r, mat_t;

    if(n==1)
        return mat_s;

    if(n==2){
        mat_r = mat_s * mat_s;
        return mat_r;
    }

    if(n&1){
        mat_t = matpow(mat_s, n/2);
        mat_r = mat_t * mat_t * mat_s;
    }else{
        mat_t = matpow(mat_s, n/2);
        mat_r = mat_t * mat_t;
    }

    return mat_r;
}


int main()
{
    unsigned long long n;
    Matrix mat_base, mat_result;

    mat_base.content[0][0] = 1;
    mat_base.content[0][1] = 1;
    mat_base.content[1][0] = 1;
    mat_base.content[1][1] = 0;
    
    cin>>n;

    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    mat_result = matpow(mat_base, n-1);

    cout<<mat_result.content[0][0]<<endl;

    return 0;
}