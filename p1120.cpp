//Not finish
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

int main()
{
    int *a;
    int i, count;
    int sum = 0;

    cin>>count;
    a = (int *)malloc(count*sizeof(int));
    for(i=0; i<count; i++)
        cin>>a[i];

    sort(a, a+count, greater<int>());
    for(i=0;i<count;i++)
        sum += a[i];

    
}
