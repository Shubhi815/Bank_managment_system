#include"stdio.h"
#include"account.h"

Meta_t load_meta(){
    FILE *meta_dat;
    Meta_t meta;
    meta_dat = fopen("meta.dat","r");
    if (meta_dat == NULL){
        meta_dat = fopen("meta.dat","w+");
        fputs("100",meta_dat);
        fputs("\n",meta_dat);
        fputs("100",meta_dat);
        fputs("\n",meta_dat);
        fclose(meta_dat);
        meta.id = 100;
        meta.transaction_id = 100;
    }
    else{
        char data[50];
        int i=0;
        while (fgets(data,50,meta_dat)!=NULL)
        {
            if (i ==0){
                meta.id = atoi_mine(data);
            }
            else{
                meta.transaction_id = atoi_mine(data);
            }
            i++;
        }
        fclose(meta_dat);
    }
}
int main(){
    Meta_t meta;
    printf("id is %d\n",meta.id);
    printf("transaction_id is %d\n",meta.transaction_id);
    return 0;
}
