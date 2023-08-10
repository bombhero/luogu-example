#include <iostream>
#include <cstring>
using namespace std;

#define MAX_COUNT 1000001

struct relationship{
    int count;
    int *connection;
};
int road_list[MAX_COUNT][3];
struct relationship coutries[MAX_COUNT];

int detect_coutry_count(int coutry_id, int entry_id)
{
    int total = 0;
    int i;

    for(i=0; i<coutries[coutry_id].count; i++){
        if(coutries[coutry_id].connection[i] == entry_id)
            continue;
        total += detect_coutry_count(coutries[coutry_id].connection[i], coutry_id);
    }
    total++;
    return total;
}

int main()
{
    int n;
    int i, j;
    int s, d;
    int left_count, right_count;
    unsigned long long total_cost = 0;

    cin>>n;
    for(i=1; i<=n; i++)
        coutries[i].count = 0;
    
    for(i=1; i<=(n-1); i++){
        for(j=0; j<3; j++)
            cin>>road_list[i][j];

        for(s=0; s<2; s++){
            if(s==0)
                d=1;
            else
                d=0;
            if (coutries[road_list[i][s]].count == 0){
                coutries[road_list[i][s]].count++;
                coutries[road_list[i][s]].connection = (int *)malloc(sizeof(int)*coutries[s].count);
            }else{
                coutries[road_list[i][s]].count++;
                coutries[road_list[i][s]].connection = 
                    (int *)realloc(coutries[road_list[i][s]].connection, sizeof(int)*coutries[road_list[i][s]].count);
            }
            coutries[road_list[i][s]].connection[(coutries[road_list[i][s]].count-1)] = road_list[i][d];
        }
    }

    // for(i=1; i<=n; i++){
    //     cout<<coutries[i].count<<"|";
    //     for(j=0; j<coutries[i].count; j++)
    //         cout<<coutries[i].connection[j]<<" ";
    //     cout<<endl;        
    // }

    for(i=1; i<=(n-1); i++){
        left_count = detect_coutry_count(road_list[i][0], road_list[i][1]);
        right_count = detect_coutry_count(road_list[i][1], road_list[i][0]);
        total_cost += abs(left_count - right_count) * road_list[i][2];
    }

    cout<<total_cost<<endl;

    return 0;
}
