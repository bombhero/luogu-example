#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    float s, v;
    int t;
    char hour[4];
    cin >> s >> v;
    t = int(s/v) + 10;
    sprintf(hour,"%02d\0", t);
    printf("%s", hour);
}
