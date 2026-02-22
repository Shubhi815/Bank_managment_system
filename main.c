#include"stdio.h"
#include"account.h"

Meta_t load_meta(){
    FILE *meta_dat;
    Meta_t meta;
    meta_dat = fopen("meta.dat","rb");
    if (meta_dat == NULL){
        meta.id = 100;
        meta.transaction_id =100;
        meta_dat = fopen("meta.dat","wb+");
        fwrite(&meta, sizeof(meta), 1, meta_dat);
        fclose(meta_dat);
    }
    else{
        fread(&meta, sizeof(meta), 1, meta_dat);
        fclose(meta_dat);

    }
    
    return meta;
}


int main(){
    Meta_t meta = load_meta();
    printf("id is %d\n",meta.id);
    printf("transaction_id is %d\n",meta.transaction_id);
    
    
    return 0;
}
