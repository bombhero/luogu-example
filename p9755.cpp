// Not finish yet
#include <iostream>
using namespace std;

#define N 100002

struct Node{
    unsigned long long a;
    unsigned int b;
    int c;
    int tall;
};

struct Node node_list[N]; // from 1
int plant_list[N]; // from 1
int path_list[N][2]; // from 1

int growup_one_day(int x, struct Node node)
{
    int grow;

    grow = node.b + x * node.c;
    if(grow<1) grow=1;

    return grow;
}

int calc_grow_days(int current_x, struct Node node)
{
    unsigned long long tall=0;
    int x=current_x;
    while(1){
        tall += growup_one_day(x, node);
        if(tall >= node.a)
            break;
        x++;
    }

    return x - current_x;
}

int main()
{
    int n, i, x;
    int next_count;
    int next_node_list[N];

    cin>>n;
    for(i=1; i<=n; i++){
        cin>>node_list[i].a>>node_list[i].b>>node_list[i].c;
        node_list[i].tall = 0;
    }
    for(i=1; i<n; i++){
        cin>>path_list[i][0]>>path_list[i][1];
    }
    next_count = 1;
    next_node_list[1]=1;

    for(x=1; ;x++){
    }    

    return 0;
}