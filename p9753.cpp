// Not finish yet.
#include <iostream>
using namespace std;

char org_str[2000005];

int check_drop_str(int current, int length, int *p_start, int *p_end)
{
    int sub_count = 0;
    int start_idx = current;
    int end_idx = current+1;

    while (start_idx>=0 && end_idx<length)
    {
        if(org_str[start_idx] == org_str[end_idx]){
            sub_count++;
            start_idx -= 1;
            end_idx += 1;
        }else{
            break;
        }
    }
    
    *p_start = start_idx + 1;
    *p_end = end_idx;
    return sub_count;
}

int main()
{
    int n, i, j;
    int start_idx, end_idx;
    int sub_n, last_n;
    int total_count = 0, sub_count;

    cin>>n;
    sub_n = n;
    last_n = 0;
    for(i=0; i<n; i++){
        cin>>org_str[i];
    }

    while((sub_n > 0) && (sub_n != last_n)){
        for(i=0; i<(sub_n-1); i++){
            sub_count = check_drop_str(i, sub_n, &start_idx, &end_idx);
            if(sub_count > 0){
                total_count += sub_count;
                for(j=0; (end_idx+j) < sub_n; j++)
                    org_str[start_idx+j] = org_str[end_idx+j];
                last_n = sub_n;
                sub_n -= (end_idx-start_idx);
                break;
            }
        }
    }

    if(sub_n == 0) total_count++;
    cout<<total_count<<endl;
    return 0;
}