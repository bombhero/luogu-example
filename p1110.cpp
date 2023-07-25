// Not finish yet.
#include <iostream>
#include <string>
#include <memory.h>
#include <math.h>
using namespace std;

#define MAX_LEN 500000
int a[MAX_LEN];

struct ReportItem{
    int num;
    struct ReportItem *branch;
    struct ReportItem *next;
};

struct ReportItem *p_head = NULL;
struct ReportItem *stack[MAX_LEN];

struct ReportItem* create_item()
{
    struct ReportItem *p_new = (ReportItem *)malloc(sizeof(ReportItem));
    p_new->num = 0;
    p_new->branch = NULL;
    p_new->next = NULL;
    return p_new;
}

void print_report()
{
    struct ReportItem *p;
    int stack_idx = 0;
    int i;
    p = p_head;
    while(p){
        for(i=0;i<stack_idx;i++)
            cout<<"\t";
        cout<<p->num<<endl;
        if(p->branch){
            stack[stack_idx++] = p->next;
            p=p->branch;
        }else{
            p=p->next;
        }
        if(p==NULL){
            while(stack_idx>0){
                stack_idx--;
                p=stack[stack_idx];
                if(p) break;
            }
        }
    }
    return;
}

void insert_item(int position, int val)
{
    int count=1;
    struct ReportItem *p_new;
    int stack_idx=0;
    ReportItem *p, *p_tmp;

    p=p_head;
    while(1){
        if(count == position) break;
        if(p->branch){
            stack[stack_idx] = p->next;
            stack_idx++;
            p=p->branch;
            count++;
            continue;
        }

        if(p->next == NULL){
            if(stack_idx == 0){
                cout<<"Error: position is out of items."<<position<<">"<<count<<endl;
                return;
            }else{
                stack_idx--;
                p=stack[stack_idx];
                count++;
                continue;
            }
        }

        p=p->next;
        count++;
    }

    p_new = create_item();
    p_new->num = val;
    if(p->branch == NULL){
        p->branch = p_new;
    }else{
        p_tmp = p->branch;
        while(p_tmp->next) p_tmp = p_tmp->next;
        p_tmp -> next = p_new;
    }
        
}

int export_data()
{
    struct ReportItem *p;
    int stack_idx = 0;
    int i, count=0;
    p = p_head;
    while(p){
        a[count] = p->num;
        if(p->branch){
            stack[stack_idx++] = p->next;
            p=p->branch;
        }else{
            p=p->next;
        }
        if(p==NULL){
            while(stack_idx>0){
                stack_idx--;
                p=stack[stack_idx];
                if(p) break;
            }
        }
        count++;
    }

    return count;
}

int detect_min_gap()
{
    int min_gap = -1;
    int last_num;
    int stack_idx = 0;
    struct ReportItem *p;

    return 0;
}

int main()
{
    ReportItem *p_new, *p;
    string s;
    int n, m;
    int i;
    int val, position;

    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>val;
        p_new = create_item();
        p_new->num = val;
        if(p_head == NULL) p_head = p_new;
        else{
            p = p_head;
            while(p->next) p=p->next;
            p->next = p_new;
        }
    }

    for(i=0; i<m; i++){
        cin>>s;
        if(s.find("INSERT") == 0){
            cin>>position>>val;
            insert_item(position, val);
        }

        if(s.find("MIN_GAP") == 0){

        }
    }

    print_report();
    n = export_data();
    cout<<"n="<<n<<endl;
    for(i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
