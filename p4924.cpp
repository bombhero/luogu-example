#include <iostream>
using namespace std;

#define MAX_LEN 500

int a[501][501], b[501][501];

void print_matrix(int n)
{
    int i, j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return;
}

void transfer_matrix(int n, int x, int y, int r, int z)
{
    int order_count = 2*r+1;
    int i, j;
    int init_x, init_y;

    init_x = x-r-1;
    init_y = y-r-1;
    if(z){
        for(i=1; i<=order_count; i++)
            for(j=1; j<=order_count; j++)
                b[order_count-j+1+init_x][i+init_y] = a[i+init_x][j+init_y];
    }else{
        for(i=1; i<=order_count; i++)
            for(j=1; j<=order_count; j++)
                b[j+init_x][order_count-i+1+init_y] = a[i+init_x][j+init_y];
    }

    for(i=1; i<=order_count; i++)
        for(j=1; j<=order_count; j++)
            a[i+init_x][j+init_y] = b[i+init_x][j+init_y];
}

int main()
{
    int n, m;
    int i, j;
    int x, y, r, z;

    cin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            a[i][j] = (i-1)*n+j;

    for(i=1; i<=m; i++){
        cin>>x>>y>>r>>z;
        transfer_matrix(n, x, y, r, z);
    }
    print_matrix(n);
    return 0;
}