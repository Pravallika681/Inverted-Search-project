#include "inverted_search.h"
int main(int argc , char *argv[])
{
    system("clear");
    Wlist *head[27] = {NULL};

    //validate CLA 
    if(argc <= 1)
    {
	printf("Enter valid no.of arguments\n");
	printf("./Slist.exe file1.txt file2.txt.....");
	return 0;
    }
    //declare file head pointer
    Flist *f_head = NULL;

    //valdate the file
    file_validation_n_file_list(&f_head,argv);

    if(f_head == NULL)
    {
        printf("No files are added to file linked list\n");
        printf("Hence process got terminated\n");
        return 1;
    }
int choice;
char opt;
char word[WORD_SIZE];
do
{
    printf("1.Create Database\n 2.Display Database\n 3.Update Database\n 4.Search\n 5.Save Database\n 6.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: create_database(f_head,head);
        break;
        case 2: display_database(head);
        break;
        case 3: update_database(head , &f_head);
        break;
        case 4:
                printf("Enter the word\n");
                scanf("%s", word);
                int index = tolower(word[0]) % 97 ;
                search(head[index] , word);
                break;
        case 5: save_database(head);
        break;
        case 6:
          return 0;
        default:
        printf("Invalid choice\n");
    }
    printf("Do you want to continue? Enter 'y/Y' to continue or 'n/N' to discontinue\n: ");
    scanf(" %c",&opt);
} while(opt == 'y' || opt == 'Y');

return 0;
}
