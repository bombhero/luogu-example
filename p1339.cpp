#include <iostream>
using namespace std;

int n_node[2505];
// Contained u,v,w
int path_info[6205][3];
int n, m;
int path[2505], path_len=0;

int detect_short_path(int s, int t, int from_node)
{
    int i;
    int short_length=0;
    int new_length;
    if(n_node[s] != 0)
        return n_node[s];
    for(i=0; i<path_len; i++){
        printf("%d->", path[i]);
        if(path[i] == s && i>0){
            return 1001;
        }
    }
    path[path_len++] = s;
    printf("\n");
    for(i=1; i<=m; i++){        
        new_length = 0;
        if(((path_info[i][0] == s) && (path_info[i][1] == t)) || ((path_info[i][1] == s) && (path_info[i][0] == t))){
            new_length = path_info[i][2];
        }
        if(path_info[i][0] == s && path_info[i][1] != t){
            new_length = detect_short_path(path_info[i][1], t, s) + path_info[i][2];
        }
        if(path_info[i][1] == s && path_info[i][0] != t){
            new_length = detect_short_path(path_info[i][0], t, s) + path_info[i][2];
        }
        if(new_length > 0)
            if(short_length == 0)
                short_length = new_length;
            else if(new_length < short_length)
                short_length = new_length;
    }
    path_len--;
    return short_length;
}

int main()
{
    int i;
    int s, t;

    cin>>n>>m>>s>>t;
    for(i=1; i<=m; i++){
        cin>>path_info[i][0]>>path_info[i][1]>>path_info[i][2];
        n_node[i] = 0;
    }

    cout<<detect_short_path(s, t, 0);

    return 0;
}
