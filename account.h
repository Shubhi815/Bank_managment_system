#include<stdio.h>

typedef enum account_status {Locked =0, unlocked}account_status_E;

typedef struct {
	char address[30];
	char city[10];
	char state[10];
	char country[10];

}Address_t;

typedef struct {
	char Account_number[30];
	char name[64];
	char phone_number[16];
	char pin[8];
	long long balance;
	account_status_E status;
	int failed_attempt;
	Address_t address;
}Account_t;


typedef struct 
{
	int id;
	int transaction_id;
}Meta_t;



int atoi_mine(const char *); 