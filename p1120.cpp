//Not finish
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int *a, *usage;

int detect_map(int start_idx, int max_idx, int target_len, int first_item)
{
    int i;
    int result=0;

    for(i=start_idx; i<max_idx; i++){
        if((a[i] <= target_len) && (usage[i] == 0)){
            if((target_len - a[i]) == 0){
                usage[i] = 1;
                result = 1;
                break;
            }else{
                usage[i] = 1;
                if(detect_map(i+1, max_idx, target_len-a[i], 0) != 1){
                    usage[i] = 0;
                }else{
                    result = 1;
                    break;
                }
            }
        }

        if((result==0) && (first_item==1))
            break;
    }
    
    return result;
}

int main()
{
    int i, count, target_len, result;
    int sum = 0;

    cin>>count;
    a = (int *)malloc(count*sizeof(int));
    usage = (int *)malloc(count*sizeof(int));

    for(i=0; i<count; i++){
        cin>>a[i];
        sum += a[i];
    }

    sort(a, a+count, greater<int>());
    // for(i=0; i<count; i++) cout<<a[i]<<" ";
    for(target_len=a[0]; target_len<=sum; target_len++){
        memset(usage, 0, count*sizeof(int));
        result = 1;
        for(i=0; i<count; i++){
            if(usage[i]) continue;
            if(detect_map(i, count, target_len, 1) == 0){
                result = 0;
                break;
            }
        }

        if(result)
            break;
    }

    cout<<target_len<<endl;

    return 0;
}
