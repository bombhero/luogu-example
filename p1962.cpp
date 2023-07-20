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
        this->item_size = 8*sizeof(unsigned int);
        for(i=0; i<NUM_SIZE; i++)
            this->content[i] = 0;
    }

    BigNumber128(unsigned long init_val[NUM_SIZE])
    {
        int i;
        this->item_size = 8*sizeof(unsigned int);
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
};

typedef BigNumber128 cell_t;

class Matrix
{
    private:
        cell_t *content;

    public:
    int row, col;
    Matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
        this->content = (cell_t *)malloc(row*col*sizeof(cell_t));
        memset(this->content, 0, row*col*sizeof(cell_t));
        return;
    }

    Matrix *matmul(Matrix *b)
    {
        return NULL;
    }

    cell_t get_cell(int row, int col)
    {
        return *(this->content + row * this->col + col);
    }

    void set_cell(int row, int col, cell_t val)
    {
        *(this->content + row * this->col + col) = val;
    }
};


int main()
{    
    BigNumber128 *a = new BigNumber128();
    BigNumber128 *b = new BigNumber128();
    
    a->content[0] = 0xFFFF0000;
    a->content[1] = 1;
    b->content[1] = 2;

    BigNumber128 *result = a->num_mul(b);
    cout<<hex<<result->content[0]<<endl;
    cout<<hex<<result->content[1]<<endl;
    cout<<hex<<result->content[2]<<endl;
    cout<<hex<<result->content[3]<<endl;
    return 0;
}