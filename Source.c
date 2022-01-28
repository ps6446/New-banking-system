// C program to implement
// the above approach
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
// Declaring all the functions

void account(void);
void balance(void);
void deposite(void);
void withdraw(void);
void gotoxy(int x, int y)
{
  COORD c;
  c.X = x;
  c.Y = y;

  SetConsoleCursorPosition(
    GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Creating a structure to store
// data of the user
typedef struct pass {
  int date, month, year;
  char pnumber[15];
  char adharnum[20];
  char fname[20];
  char lname[20];
  char address[50];
  char account_num[20];
  float balance;
} Account_Info;

int main()
{
  int choice,ret;

  while (1)
  {
    system("cls");
    gotoxy(20, 3);

    // Creating a Main
    // menu for the user
    printf("Welcome to Banking System\n\n");
    gotoxy(18, 5);

    printf("=================================");
    gotoxy(25, 7);

    //printf("DEVELOPER-Naman kumar");

    gotoxy(20, 10);
    printf("1.CREATE A BANK ACCOUNT");
    gotoxy(20, 12);
    printf("2.DEPOSITE MONEY");
    gotoxy(20, 14);
    printf("3.WITHDRAW MONEY");
    gotoxy(20, 16);
    printf("4.CHECK BALANCE");
    gotoxy(20, 18);
    printf("5.EXIT\n\n");

    printf("\n\nENTER YOUR CHOICE:");

   ret = scanf("%d", &choice);

    switch (choice) {
    case 1:

      account();
      break;

    case 2:
       deposite();
      break;
    case 3:
      withdraw();
      break;
    case 4:
       balance();
      break;
    case 5:
      exit(0);
      break;

      ret = getch();
    }
  }
}

// Function to create accounts
// of users
void account(void)
{
   int seek = 0, ret;
  FILE* fp;
  Account_Info u1;
  // Opening file to
  // write data of a user
  fp = fopen("username.txt", "a+");

  // Inputs
  system("cls");
  printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

  printf("\n\nFIRST NAME:");
  ret = scanf("%s", &u1.fname);

  printf("\n\n\nLAST NAME:");
  ret = scanf("%s", &u1.lname);

  printf("\n\nADDRESS:");
  ret = scanf("%s", &u1.address);

  printf("\n\nDATE OF BIRTH:");
  printf("\nDATE-");
  ret = scanf("%d", &u1.date);
  printf("\nMONTH-");
  ret = scanf("%d", &u1.month);
  printf("\nYEAR-");
  ret = scanf("%d", &u1.year);

  printf("\n\nADHAR NUMBER:");
  ret = scanf("%s", u1.adharnum);

  printf("\n\nPHONE NUMBER:");
  ret = scanf("%s", u1.pnumber);

  printf("\n\nACCOUNT NUMBER:");
  ret = scanf("%s", &u1.account_num);


  printf("\n\nDEPOSITE:");
  ret = scanf("%f", &u1.balance);

  // Writing to the file
  fwrite(&u1, sizeof(u1),
    1, fp);

  // Closing file
  fclose(fp);

  // Calling another function
  // after successful creation
  // of account
  printf("ACCOUNT CREATED SUCCESSFULLY....");
  ret = getch();
}
void balance(void)
{
  system("cls");
  FILE* fp;
  char acc_num[50];
  int ret;
  struct pass u1;
  // Opening file of
  // user data
  fp = fopen("username.txt",
    "rb");

  if (fp == NULL) {
    printf("ERROR IN OPENING FILE");
  }
  gotoxy(34, 2);
  printf(" ACCOUNT BALANCE ");
  gotoxy(7, 5);
  printf("***********************************************");

  gotoxy(35, 10);
 

  // Take input
  gotoxy(35, 12);
  printf("Account Number:");
  ret = scanf("%s", &acc_num);

  gotoxy(35, 14);
  // Checking if username
  // exists in the file or not
  while (fread(&u1, sizeof(u1), 1, fp)) {
    if (strcmp(acc_num,
      u1.account_num)
      == 0) {
      printf("Account Balance:%.2f\n", u1.balance);
    }
  }

  // Closing the file
  ret = fclose(fp);
  ret = getch();
}
void withdraw(void)
{
  system("cls");
  char acc_num[50];
  int i,ret;
  float amount;
  FILE* fp;
  struct pass u1;
  // Opening file of
  // user data
  fp = fopen("username.txt",
    "r+");

  if (fp == NULL) {
    printf("ERROR IN OPENING FILE");
  }
  gotoxy(34, 2);
  printf(" Withdraw Amount ");
  gotoxy(7, 5);
  printf("***********************************************");
  gotoxy(35, 10);
  // Take input
  gotoxy(35, 12);
  printf("Account Number:");
  ret = scanf("%s", &acc_num);

  gotoxy(35, 14);
  // Checking if username
  // exists in the file or not
  i = sizeof(u1);
  while (fread(&u1, sizeof(u1), 1, fp)) {
    if (strcmp(acc_num,
      u1.account_num)
      == 0) {
      printf("Current Account Balance:%.2f\n", u1.balance);
      gotoxy(35, 16);
      printf("Withdraw:");
      ret = scanf("%f", & amount);
      gotoxy(35, 18);
      if(amount> u1.balance)
      {
        printf("Insufficient Balance\n");
      }
      else
      {
        u1.balance -= amount;
        fseek(fp, -i, SEEK_CUR);
        fwrite(&u1, sizeof(u1), 1, fp);
        printf("Updated Account Balance:%f\n", u1.balance);
      }
      break;
    }
  }
  // Closing the file
  fclose(fp);
  ret = getch();
}
void deposite(void)
{
  system("cls");
  char acc_num[50];
  int i,ret;
  float amount;
  FILE* fp;
  struct pass u1;
  // Opening file of
  // user data
  fp = fopen("username.txt",
    "r+");

  if (fp == NULL) {
    printf("ERROR IN OPENING FILE");
  }
  gotoxy(34, 2);
  printf(" Deposite Amount ");
  gotoxy(7, 5);
  printf("***********************************************");
  gotoxy(35, 10);
  // Take input
  gotoxy(35, 12);
  printf("Account Number:");
  ret = scanf("%s", &acc_num);

  gotoxy(35, 14);
  // Checking if username
  // exists in the file or not
  i = sizeof(u1);
  while (fread(&u1, sizeof(u1), 1, fp)) {
    if (strcmp(acc_num,
      u1.account_num)
      == 0) {
      printf("Current Account Balance:%.2f\n", u1.balance);
      gotoxy(35, 16);
      printf("Deposite:");
      ret = scanf("%f", &amount);
      u1.balance += amount;
      ret = fseek(fp, -i, SEEK_CUR);
      ret = fwrite(&u1, sizeof(u1), 1, fp);
      gotoxy(35, 18);
      printf("Updated Account Balance:%.2f\n", u1.balance);
      break;
    }
  }
  // Closing the file
  ret = fclose(fp);
  
  ret = getch();
}



