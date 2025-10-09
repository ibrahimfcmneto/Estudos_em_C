#include <stdio.h>

//typedef char user[25];

typedef struct
{
    char name[25];
    char password[12];
    int id;
} User;

int main()
{
    User user1 = {"bro", "password123", 3245343};
    User user2 = {"bru bru", "password321", 4444444};

    printf(user1.name);

    return 0;
}