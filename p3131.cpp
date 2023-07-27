#include <iostream>
using namespace std;

int main()
{
    int n;
    int i;
    int val;
    int sum = 0;
    int max_len = -1;
    int remain[7], max_record[7];

    for(i=0; i<7; i++){
        remain[i] = -1;
        max_record[i] = -1;
    }

    cin>>n;
    for(i=0; i<n; i++){
        cin>>val;
        sum += val;
        sum = sum % 7;
        if(remain[sum] == -1){
            remain[sum] = i;
        }else{
            if((i-remain[sum]) > max_record[sum])
                max_record[sum] = i-remain[sum];
        }
        if(sum==0) max_record[sum] = i;
    }

    max_record[0]++;
    for(i=0; i<7; i++)
        if(max_record[i] > max_len)
            max_len = max_record[i];
    cout<<max_len<<endl;
    return 0;
}
