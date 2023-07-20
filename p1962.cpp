// Not finish yet
#include <iostream>
#include <memory.h>
using namespace std;

#define NUM_SIZE 4

class BigNumber128
{
    private:
        int item_size;
        unsigned long item_mask = 0xFFFFFFFF;
    public:
    unsigned long content[4];

    BigNumber128()
    {
        int i;
        this->item_size = 8*sizeof(unsigned long);
        for(i=0; i<NUM_SIZE; i++)
            this->content[i] = 0;
    }

    BigNumber128(unsigned long init_val[NUM_SIZE])
    {
        int i;
        this->item_size = 8*sizeof(unsigned long);
        for(i=0; i<NUM_SIZE; i++)
            this->content[i] = init_val[i];
    }

    BigNumber128(BigNumber128 *init_num)
    {
        int i;
        this->item_size = 8*sizeof(unsigned long); 
        for(i=0; i<NUM_SIZE; i++)
            this->content[i] = init_num->content[i];
    }

    BigNumber128 *num_mul(BigNumber128 *b)
    {
        BigNumber128 *result = new BigNumber128();
        unsigned long long tmp;
        unsigned long long addition_val, sum_val;
        int i, j;

        for(i=(NUM_SIZE/2); i<NUM_SIZE; i++){
            if((this->content[i] != 0) || (b->content[i] != 0))
                cout<<"The number is out of memory."<<endl;
        }

        for(i=0; i<NUM_SIZE/2; i++){
            addition_val = 0;
            for(j=0; j<NUM_SIZE/2; j++){
                tmp = (unsigned long long)this->content[i] * (unsigned long long)b->content[j] + addition_val;
                addition_val = tmp >> this->item_size;
                sum_val = (unsigned long long)result->content[i+j] + (unsigned long long)(tmp & this->item_mask);
                result->content[i+j] = sum_val & this->item_mask;
                result->content[i+j+1] += (sum_val >> this->item_size);
            }
            result->content[i+j] += addition_val;
        }
        return result;
    }

    BigNumber128 *num_add(BigNumber128 *b)
    {
        BigNumber128 *result = new BigNumber128();
        unsigned long long addition_val, sum_val;
        int i;

        addition_val = 0;
        for(i=0; i<NUM_SIZE; i++){
            sum_val = (unsigned long long)this->content[i] + (unsigned long long)b->content[i] + addition_val;
            addition_val = sum_val >> this->item_size;
            result->content[i] = sum_val & this->item_mask;
        }
        return result;
    }
};

typedef BigNumber128 cell_t;

class Matrix
{
    private:
        cell_t **content;

    public:
    int row_count, col_count;
    Matrix(int row, int col)
    {
        int row_idx, col_idx;
        this->row_count = row;
        this->col_count = col;
        this->content = (cell_t **)malloc(row*col*sizeof(cell_t *));
        for(row_idx=0; row_idx<this->row_count; row_idx++){
            for(col_idx=0; col_idx<this->col_count; col_idx++){
                *(this->content+(row_idx*this->row_count+col_idx)) = new BigNumber128();
            }
        }
        return;
    }

    Matrix *matmul(Matrix *b)
    {
        if(this->row_count != b->col_count){
            cout<<this->row_count<<" cannot match "<<b->col_count<<endl;
            return NULL;
        }

        return NULL;
    }

    cell_t *get_cell(int row, int col)
    {
        return *(this->content + row * this->col_count + col);
    }
};


int main()
{    
    Matrix *m1 = new Matrix(2, 3);
    Matrix *m2 = new Matrix(3, 2);

    Matrix *result = m1->matmul(m2);

    return 0;
}