#include"stdio.h"
#include"account.h"
#include"stdlib.h"
#include"string.h"
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

void next_account_number(Meta_t *meta){
    meta->id = meta->id+1;
    meta->transaction_id=meta->transaction_id+1;
}
void store_account_number(Meta_t *meta){
    FILE *meta_dat=fopen("meta.dat","wb");
    fwrite(meta,sizeof(*meta),1,meta_dat);
    fclose(meta_dat);
}
int generate_dummy_account(Meta_t *meta){
    FILE *account_dat=fopen("account.dat","ab");
    if (account_dat == NULL){
        printf("error occured");
        return 0;
    }
    Account_t *new_account = malloc(sizeof(Account_t));
    sprintf(new_account->Account_number,"AC00%d",meta->id );
    //new_account->Account_number = meta->id;
    new_account->balance = 0.00;
    new_account->failed_attempt =0;
    strcpy(new_account->name,"random");
    strcpy(new_account->phone_number,"8053754642");
    strcpy(new_account->pin,"3098");
    new_account->status = unlocked;
    strcpy(new_account->address.city,"blr");
    strcpy(new_account->address.country,"india");
    strcpy(new_account->address.state,"india");
    strcpy(new_account->address.address,"some random address");
    fwrite(new_account,sizeof(Account_t),1,account_dat);
    fclose(account_dat);
    return 1;

}
int see_account(){
    FILE *account_dat=fopen("account.dat","rb");
    if (account_dat == NULL){
        printf("error occured");
        return 0;
    }
    Account_t account;
    int i =0;
    while(fread(&account,sizeof(Account_t),1,account_dat)==1){
        printf("%d account holder is %s\n",i,account.Account_number);
        i++;
        }
    fclose(account_dat);
}
void print_account(Account_t *account){
    printf("%s\n",account->Account_number);
    printf("%s\n",account->address.address);
    printf("%s\n",account->address.city);
    printf("%s\n",account->address.country);
    printf("%s\n",account->address.state);
    printf("%lld\n",account->balance);
    printf("%d\n",account->failed_attempt);
    printf("%s\n",account->name);
    printf("%s\n",account->phone_number);
    printf("%s\n",account->pin);
    printf("%d\n",account->status);
}
long int finding_account_number(char data[]){
    Account_t account;
    FILE *fptr = fopen("account.dat","rb");
    if (fptr == NULL){
        printf("error occured");
        //return 0;
    }
    int found_flag =0;
    while(fread(&account,sizeof(account),1,fptr)==1){
        //printf("%s",account.Account_number);
        if(strcmp(data,account.Account_number)==0){
            printf("pointer pos is %ld\n",ftell(fptr));
            long int pos=ftell(fptr) -sizeof(Account_t);
            //print_account(&account);
            found_flag =1;
            return pos;
        }
    }
    if (found_flag ==0){
        printf("not able to find");
        return 0;
    }
    fclose(fptr);
}
void deposit(long int pos){
    Account_t account;
    FILE *fptr = fopen("account.dat","rb+");
    fseek(fptr,pos,SEEK_SET);
    fread(&account,sizeof(account),1,fptr);
    fseek(fptr,pos,SEEK_SET);
    account.balance=account.balance+500;
    fwrite(&account,sizeof(Account_t),1,fptr);
    print_account(&account);
}
int main(){
    Meta_t meta = load_meta();
    char data[20];
    printf("see account");
    see_account();
    printf("which account id u want to find ..?\n");
    scanf("%s",data);
    printf("finding account number %s\n",data);
    long int pos = finding_account_number(data);
    deposit(pos);

    // int ret=generate_dummy_account(&meta);
    // if (ret == 1){
    //     next_account_number(&meta);
    //     store_account_number(&meta);}
    // printf("%d id is \n", meta.id);
    // see_account();
    return 0;
}
