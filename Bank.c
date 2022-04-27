#include<stdio.h>

struct acc
{
    char user[15];
    char pass[15];
    int bal;
};

struct acc signup(void);

int main(void)
{
    struct acc user1 = signup();
    printf("Username: %s\n",user1.user);
    printf("Password: %s\n",user1.pass);
    printf("Balance: %d\n",user1.bal);
    return 0;
}

struct acc signup(void)
{
    struct acc name;
    printf("Enter username (no longer than 15 characters):\n");
    scanf("%s",name.user);
    printf("Create a password for your account (15 characters limit):\n");
    scanf("%s",name.pass);
    printf("Thank you. Your account will be given $50 to start with.\n\n");
    name.bal=50;
    return name;
}
