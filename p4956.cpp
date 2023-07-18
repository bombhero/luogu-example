#include <iostream>
using namespace std;

int main()
{
    int n;
    int x, k;

    cin>>n;
    for(k=1; k*1092<n; k++){
        x = (n-1092*k)/364;
        if(x>100) continue;
        if((n-1092*k) % x == 0) break;
    }
    cout<<x<<"\n";
    cout<<k;
    return 0;
}