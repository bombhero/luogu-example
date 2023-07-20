#include <iostream>
using namespace std;

int main()
{
    int num[100];
    int n;
    int i, j, l;
    int count=0;
    int found;

    cin>>n;
    for(i=0;i<n;i++){
        cin>>num[i];
    }

    for(i=0; i<n; i++){
        found = 0;
        for(j=0; j<n; j++){
            if(i==j) continue;
            for(l=(j+1); l<n; l++){
                if(i==l || j==l) continue;
                if(num[i] == (num[j] + num[l])){
                    found=1;
                    count++;
                    break;
                }
            }
            if(found) break;
        }
    }

    cout<<count<<endl;
}
