// Not finish yet. 3 TLE
#include <iostream>
#include <cstring>
using namespace std;

#define N 10000002

struct PaintSize{
    int n;
    int m;
};

unsigned int paint[N];
struct PaintSize paint_size;

void op0(int x, int c)
{
    int i;

    for(i=0; i<paint_size.m; i++)
        paint[x*paint_size.m+i] = c;
}

void op1(int x, int c)
{
    int i;

    for(i=0; i<paint_size.n; i++)
        paint[i*paint_size.m+x] = c;
}

int main()
{
    int n, m, q, x, c, t;
    int i, op;
    int t_idx, r_idx, c_idx;

    cin>>t;
    for(t_idx=0; t_idx<t; t_idx++){
        cin>>paint_size.n>>paint_size.m>>q;
        memset(paint, 0, (paint_size.n*paint_size.m*sizeof(unsigned int)));
        for(i=0; i<q; i++){
            cin>>op>>x>>c;
            switch (op)
            {
                case 0:
                    op0(x-1, c);
                    break;
                case 1:
                    op1(x-1, c);
                    break;
                default:
                    break;
            }
        }

        for(r_idx=0; r_idx<paint_size.n; r_idx++){
            for(c_idx=0; c_idx<paint_size.m; c_idx++){
                cout<<paint[r_idx*paint_size.m + c_idx];
                if(c_idx == (paint_size.m-1))
                    printf("\n");
                else
                    cout<<" ";
            }
        }
    }
    return 0;
}