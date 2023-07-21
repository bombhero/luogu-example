// Not finish yet.
#include <iostream>
#include <math.h>
using namespace std;


#define MAX_AREA 10

class HighNumber
{
    public:
    const unsigned long series=10;
    const unsigned long step = (unsigned long)pow(10, series);
    const unsigned long area = MAX_AREA;
    unsigned long content[MAX_AREA];

    HighNumber()
    {
        int i;
        for(i=0; i<MAX_AREA; i++)
            this->content[i] = 0;
        return;
    }

    void add_num(unsigned long b)
    {
        int i;
        unsigned long addition_num;
        this->content[0] += b;
        for(i=0; i<this->area; i++){
            addition_num = this->content[i] / this->step;
            if(addition_num > 0){
                this->content[i+1] += addition_num;
                this->content[i] %= this->step;
            }else{
                break;
            }
        }
    }
};


class NumberMatrix
{
    public:
    unsigned int content[80][80];
    unsigned int head[80];
    unsigned int tail[80];
    unsigned int n, m;
    NumberMatrix(unsigned int n, unsigned int m)
    {
        int i, j;
        this->n = n;
        this->m = m;
        for(i=0; i<n; i++){
            head[i] = 0;
            tail[i] = m-1;
            for(j=0; j<m; j++)
                this->content[i][j] = 0;
        }
        return;
    }

    unsigned int step()
    {
        int i;
        int score = 0;
        for(i=0; i<n; i++){
            if(this->content[i][head[i]] < this->content[i][tail[i]]){
                score += this->content[i][head[i]];
                head[i]++;
            }else{
                score += this->content[i][tail[i]];
                tail[i]--;
            }
        }
        return score;
    }
};

int main()
{
    unsigned long long total_score=0;
    unsigned int one_score;
    unsigned int score_list[80];
    unsigned int n, m;
    int i, j;

    cin>>n;
    cin>>m;
    NumberMatrix *num_matrix = new NumberMatrix(n, m);

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>num_matrix->content[i][j];

    for(i=0; i<m; i++){
        one_score = num_matrix->step();
        score_list[i] = one_score;
    }

    for(i=(m-1); i>=0; --i){
        total_score = (total_score + score_list[i]) << 1;
    }
    cout<<total_score<<endl;

    return 0;
}
