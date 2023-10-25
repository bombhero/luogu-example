// Not finish yet.
#include <iostream>
#include <cstring>
using namespace std;

#define T 10
#define N 100001

struct PaintSize{
    int n;
    int m;
};

unsigned int *paint[T];
struct PaintSize paint_size[T];

void op0(int t_idx, int x, int c)
{
    int i;

    for(i=1; i<=paint_size[t_idx].m; i++)
        paint[t_idx][x][i] = c;
}

void op1(int t_idx, int x, int c)
{
    int i;

    for(i=1; i<=paint_size[t_idx].n; i++)
        paint[t_idx][i][x] = c;
}

int main()
{
    int n, m, q, x, c, t;
    int i, op;
    int t_idx, r_idx, c_idx;

    memset(paint, 0, T*N*N*sizeof(unsigned int));

    cin>>t;
    for(t_idx=0; t_idx<t; t_idx++){
        cin>>paint_size[t_idx].n>>paint_size[t_idx].m>>q;
        for(i=0; i<q; i++){
            cin>>op>>x>>c;
            switch (op)
            {
                case 0:
                    op0(t_idx, x, c);
                    break;
                case 1:
                    op1(t_idx, x, c);
                    break;
                default:
                    break;
            }
        }
    }

    for(t_idx=0; t_idx<t; t_idx++){
        for(r_idx=1; r_idx<=paint_size[t_idx].n; r_idx++){
            for(c_idx=1; c_idx<=paint_size[t_idx].m; c_idx++){
                cout<<paint[t_idx][r_idx][c_idx];
                if(c_idx==paint_size[t_idx].m)
                    cout<<endl;
                else
                    cout<<" ";
            }
        }
    }
    return 0;
}