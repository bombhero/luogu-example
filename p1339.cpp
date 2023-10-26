// Remained 1 WA
#include <iostream>
using namespace std;

int n_node[2505];
// Contained u,v,w,used(this value decrease 1 during used)
int path_info[6205][4];
int n, m;
int path[2505], path_len=0;


void full_shortest_path(int s)
{
    int i, j;
    int update_flag = 0;
    int current_step[2505], current_count;
    int next_step[2502], next_count;
    int remained_node = n;
    int target_node;
    int length;

    current_step[0] = s;
    current_count = 1;
    while(remained_node>0)
    {
        next_count = 0;
        if(current_count==0)
            break;
        remained_node -= current_count;
        cout<<"Remained"<<remained_node<<endl;
        for(i=0; i<current_count; i++){
            for(j=1; j<=m; j++){
                if(path_info[j][3] <= 0)
                    continue;
                if(path_info[j][0] == current_step[i]){
                    target_node = path_info[j][1];
                }else if(path_info[j][1] == current_step[i]){
                    target_node = path_info[j][0];
                }else{
                    continue;
                }

                if(n_node[target_node] == -1){
                    next_step[next_count++] = target_node;
                    n_node[target_node] = n_node[current_step[i]] + path_info[j][2];
                }else{
                    length = n_node[current_step[i]] + path_info[j][2];
                    if(length<n_node[target_node])
                        n_node[target_node] = length;
                }
                path_info[j][3]--;

                cout<<current_step[i]<<" -> "<<target_node<<", length:"<<n_node[target_node]<<endl;
            }

            for(j=0; j<next_count; j++){
                current_step[j] = next_step[j];
            }
            current_count = next_count;
        }
    }
}


int main()
{
    int i;
    int s, t;

    cin>>n>>m>>s>>t;
    for(i=1; i<=m; i++){
        cin>>path_info[i][0]>>path_info[i][1]>>path_info[i][2];
        path_info[i][3] = 2;
    }
    for(i=1; i<=n; i++){
        if(i==s)
            n_node[i] = 0;
        else
            n_node[i] = -1;
    }

    full_shortest_path(s);
    cout<<n_node[t];

    return 0;
}
