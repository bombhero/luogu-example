#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unsigned int m, n;
    unsigned int *a;
    unsigned int *p;
    int i, j, min_result;
    unsigned int sum;

    min_result = 0;
    cin>>n>>m;
    a = (unsigned int *)malloc(n*sizeof(unsigned int));
    for(i=0; i<n; i++) cin>>*(a+i);

    if(n == m){
        min_result = 0;
        for(i=0; i<n; i++) min_result += *(a+i);
    }else{
        for(i=0; i<(n-m); i++){
            sum = 0;
            for(j=0; j<m; j++)
                sum += *(a+i+j);
            if(min_result == 0){
                min_result = sum;
                continue;
            }

            if(sum<min_result){
                min_result = sum;
            }
        }
    }
    cout<<min_result<<endl;
}