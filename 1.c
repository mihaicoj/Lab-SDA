#include <stdio.h>

typedef struct Maraton{
    int id;
    char name[50];
    int age;
    int gender;
    int height;
}Maraton;

void read_maraton(Maraton participants[50], int * number_of_participants) {

    printf("How many people will participate at the Marathon? \n");
    scanf("%d", number_of_participants);

}

void read_participant(Maraton participants[50], int number_of_participants) {
    for (int i = 0; i < number_of_participants; i++){
    printf("Input info for the %d participant :\n", i+1);
    printf("Input ID: ");
    scanf("%d", &participants[i].id);
    printf("Name: ");
    scanf("%s", participants[i].name);
    printf("Age: ");
    scanf("%d", &participants[i].age);
    printf("Gender(0 for male | 1 for female): ");
    scanf("%d", &participants[i].gender);
    printf("Height: ");
    scanf("%d", &participants[i].height);
    }

}


void show(Maraton participants[50], int number_of_participants) {

        for (int i = 0; i < number_of_participants; i++)
    {
        printf("\n Participant %d:\n", i +1);
        printf("ID: %d\n", participants[i].id);
        printf("Name %s\n", participants[i].name);
        printf("Age: %d\n", participants[i].age);
        if (participants[i].gender == 0)
            {
                printf("The gender of the participant is male.\n");
            }
            else
            {
                printf("The gender of the participant is female.n ");
            }
        printf("Height: %d\n", participants[i].height);
    }
}

void search(Maraton participants[50], int number_of_participants) {
    int searched_id;
    printf("\nWhat's the ID of the person you are searching?");
    scanf("%d", &searched_id);

    int found = 0;
    for (int i =0; i < number_of_participants; i++) {
        if (participants[i].id == searched_id) {
            found = 1;
            printf("\nThe participant with ID %d was found: \n", searched_id);
            printf("Name: %s\n", participants[i].name);
            printf("Age: %d\n", participants[i].age);
            if (participants[i].gender == 0)
            {
                printf("The gender of the participant is male.\n");
            }
            else
            {
                printf("The gender of the participant is female.n ");
            }
            printf("Height: %d cm.\n", participants[i].height);
            break;
        }
    }
}


int main() {
    Maraton participants[50];
    int number_of_participants;
    

    int option;

do{
        printf("\n1. Read the elements of the array. \n");
        printf("2. Show all the elements of the array. \n");
        printf("3. Search by ID. \n");
        printf("0. Exit. \n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
            read_maraton(participants, &number_of_participants);
            read_participant(participants, number_of_participants);
            break;
            case 2:
            show(participants, number_of_participants);
            break;
            case 3:
            search(participants, number_of_participants);
            break;
            case 0:
            printf("End \n");
            break;
        }
    } while (option != 0);

    return 0;

}