// Not finish yet.
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

struct ReportItem{
    unsigned int num;
    ReportItem *branch;
    ReportItem *next;
};

struct ReportItem *p_head = NULL;

void print_report()
{
    struct ReportItem *p;
    p = p_head;
    while(p){
        cout<<p->num<<" ";
        p=p->next;
    }
    return;
}


int main()
{
    ReportItem *p_new, *p;
    string s;
    int n, m;
    int i;
    unsigned int val;

    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>val;
        p_new = (struct ReportItem *)malloc(sizeof(struct ReportItem));
        memset(p_new, 0, sizeof(struct ReportItem));
        p_new->num = val;
        if(p_head == NULL) p_head = p_new;
        else{
            p = p_head;
            while(p->next) p=p->next;
            p->next = p_new;
        }
    }

    print_report();

    return 0;
}
