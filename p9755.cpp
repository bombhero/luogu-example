// Not finish yet. 2AC
#include <iostream>
#include <vector>
using namespace std;

#define N 100002
// #define DEBUG

struct Node{
    unsigned long long a;
    unsigned int b;
    int c;
    unsigned long long tall;
};

struct Path{
    int v;
    int w;
};

struct Node node_list[N]; // from 1

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
    int paint_id, remained_x, max_paint_id, max_remained_x;
    bool done=true;
    vector<struct Path> path_vec;

    cin>>n;
    for(i=1; i<=n; i++){
        cin>>node_list[i].a>>node_list[i].b>>node_list[i].c;
        node_list[i].tall = 0;
    }
    for(i=1; i<n; i++){
        struct Path new_path;
        cin>>new_path.v>>new_path.w;
        path_vec.push_back(new_path);
    }

    node_list[1].tall += growup_one_day(1, node_list[1]);
    for(x=2; ;x++){
        done = true;
        max_paint_id = 0;
        max_remained_x = 0;
        for(i=0; i<path_vec.size(); i++){
            if(node_list[path_vec[i].v].tall>0 && node_list[path_vec[i].w].tall==0){
                paint_id = path_vec[i].w;
                remained_x = calc_grow_days(x, node_list[path_vec[i].w]);
            }else if(node_list[path_vec[i].v].tall==0 && node_list[path_vec[i].w].tall>0){
                paint_id = path_vec[i].v;
                remained_x = calc_grow_days(x, node_list[path_vec[i].v]);
            }else{
                continue;
            }

            if(max_remained_x < remained_x){
                max_paint_id = paint_id;
                max_remained_x = remained_x;
            }
        }

#ifdef DEBUG
        cout<<"Day "<<x<<": ";
#endif
        for(i=1; i<=n; i++){
            if(i==max_paint_id || node_list[i].tall>0){
                node_list[i].tall += growup_one_day(x, node_list[i]);
            }
#ifdef DEBUG
            cout<<node_list[i].tall<<" ";
#endif
            if(node_list[i].tall < node_list[i].a)
                done = false;
        }
#ifdef DEBUG
        cout<<endl;
#endif

        if(done)
            break;

        for(i=0; i<path_vec.size(); i++){
            if(node_list[path_vec[i].v].tall>0 && node_list[path_vec[i].w].tall>0){
                path_vec.erase(path_vec.begin() + i);
                break;
            }
        }
    }

    cout<<x;

    return 0;
}