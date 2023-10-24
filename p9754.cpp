// Not finish yet.
#include <iostream>
#include <cstring>
using namespace std;

struct DataMember{
    char member_name[32];
    char member_type[32];
};

struct DataStruct{
    char name[32];
    int member_count;
    int struct_align_size;
    int struct_total_size;
    struct DataMember members[100];
};

struct DataVal{
    char type_name[32];
    char val_name[32];
};

struct DataStruct ds[100];
int ds_count=0;
struct DataVal val[100];
int vs_count=0;

int is_basic_type(char *type_name)
{
    if(strcmp(type_name, "byte") && strcmp(type_name, "short") && strcmp(type_name, "int") && strcmp(type_name, "long"))
        return 1;
    else
        return 0;
}

int trans_type_to_size(char *type_name)
{
    int i;

    if(strcmp(type_name, "byte") == 0)
        return 1;
    else if(strcmp(type_name, "short") == 0)
        return 2;
    else if(strcmp(type_name, "int") == 0)
        return 4;
    else if(strcmp(type_name, "long") == 0)
        return 8;

    for(i=0; i<ds_count; i++)
        if(strcmp(ds[i].name, type_name) == 0)
            return ds[i].struct_total_size;

    return 0;
}

int trans_type_to_align(char *type_name)
{
    int i;

    if(strcmp(type_name, "byte") == 0)
        return 1;
    else if(strcmp(type_name, "short") == 0)
        return 2;
    else if(strcmp(type_name, "int") == 0)
        return 4;
    else if(strcmp(type_name, "long") == 0)
        return 8;

    for(i=0; i<ds_count; i++)
        if(strcmp(ds[i].name, type_name) == 0)
            return ds[i].struct_align_size;
    
    return 0;
}

void define_ds(struct DataStruct *p_ds)
{
    char ds_name[32];
    char type_name[8];
    int i;
    int align_size=0, total_size=0;
    int member_align_size;

    cin>>ds_name;
    strcpy(p_ds->name, ds_name);
    cin>>p_ds->member_count;

    for(i=0; i<p_ds->member_count; i++){
        cin>>p_ds->members[i].member_type;
        cin>>p_ds->members[i].member_name;
        member_align_size = trans_type_to_align(p_ds->members[i].member_type);
        if(member_align_size > align_size)
            align_size = member_align_size;
        total_size += (member_align_size - total_size % member_align_size) % member_align_size + trans_type_to_size(p_ds->members[i].member_type);
    }

    p_ds->struct_align_size = align_size;
    p_ds->struct_total_size = total_size;
    cout<<total_size<<" "<<align_size<<endl;

    return;
}

void define_val(struct DataVal *p_val)
{
    cin>>p_val->type_name;
    cin>>p_val->val_name;
}

void show_val_addr(int val_id)
{
    int i;
    int addr=0;
    int type_size;
    int align_size;

    if(val_id == 0){
        cout<<addr<<endl;
        return;
    }

    for(i=0; i<val_id; i++){
        type_size = trans_type_to_size(val[i].type_name);
        align_size = trans_type_to_align(val[i].type_name);
        addr += (align_size - addr % align_size) % align_size + type_size;
    }

    align_size = trans_type_to_align(val[val_id].type_name);
    addr +=  (align_size - (addr % align_size)) % align_size;
    cout<<addr<<endl;
}

int main()
{
    int n;
    int i, op;

    cin>>n;
    for(i=1; i<=n; i++){
        cin>>op;
        switch (op)
        {
            case 1:
                define_ds(&ds[ds_count]);
                ds_count++;
                break;
            case 2:
                define_val(&val[vs_count]);
                show_val_addr(vs_count);
                vs_count++;
                break;
            case 3:
                break;
            case 4:
                break;
            
            default:
                break;
        }
    }

    return 0;
}

