#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// The count of cow in one pastures.
int pastures[1001];
// The count of cow can arrive this pastures.
int result[1001];
// The pasture is passed.
char vis[1001];
// The connection of road.
vector<int> connections[1001];

void dfs(int pasture_id, int cow_count)
{
    int i;

    result[pasture_id] += cow_count;
    vis[pasture_id] = 1;
    for(i=0; i<connections[pasture_id].size(); i++){
        if(!vis[connections[pasture_id][i]]){
            dfs(connections[pasture_id][i], cow_count);
        }
    }
    return;
}

int main()
{
    int k, n, m;
    int i, pasture_id;
    int s_id, d_id;
    int total = 0;

    cin>>k;
    cin>>n;
    cin>>m;

    memset(pastures, 0, sizeof(int)*(n+1));
    memset(result, 0, sizeof(int)*(n+1));
    for(i=1; i<=k; i++){
        cin>>pasture_id;
        pastures[pasture_id]++;
    }

    for(i=1; i<=m; i++){
        cin>>s_id>>d_id;
        connections[s_id].push_back(d_id);
    }

    for(i=1; i<=n; i++){
        if(pastures[i] == 0)
            continue;
        memset(vis, 0, sizeof(vis));
        vis[i] = 1;
        dfs(i, pastures[i]);        
    }

    for(i=1; i<=n; i++){
        if(result[i] == k){
            // cout<<i<<" ";
            total++;
        }
    }
    // cout<<endl;

    cout<<total;

    return 0;
}