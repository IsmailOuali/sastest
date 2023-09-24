#include<stdio.h>
#include<string.h>
#include<time.h>

int  j, n, tacheid =1, searchid = 0;
int size = 0;
char choice;
char choice2;
char updatechoice;
char statut[20];
char s[100];


typedef struct
{
    int id;
    char titre[30];
    char description[100];
    int deadline;
    int status;
}tache;
tache t[100];
tache tab[100];

void displaymenu()
{
    printf("--------- Menu ---------\n\n");
    printf("\n 1. Ajouter une tache");
    printf("\n 2. Afficher la liste de toutes les taches");
    printf("\n 3. Trier les taches");
    printf("\n 4. Modifier une tache");
    printf("\n 5. Supprimer une tache");
    printf("\n 6. Rechercher une tache");
    printf("\n 7. Statistique");
    printf("\n#. Quitter\n");
    scanf(" %c", &choice);
}
void displaytask(tache t[100], int i)
{
    if (t[i].status == 1)
    {
        strcpy(statut, "A realiser");
    }
    else if(t[i].status == 2)
    {
        strcpy(statut, "En cours");
    }
    else
        strcpy(statut, "Finalise");
    printf("%d ) Titre: %s, Description: %s, Deadline: %d Statut(%s)\n", t[i].id, t[i].titre, t[i].description, t[i].deadline, statut);

}
void addtask(tache t[100])
{
    for (int i = 0; i < n; i++)
    {
        tache temp;
        temp.id=size+1;
        printf("Entrer le titre de la tache: ");
        scanf(" %99[^\n]", &temp.titre);
        printf("Entrer la description de la tache: ");
        scanf(" %99[^\n]", &temp.description);
        printf("Entrer le deadline de la tache en jrs: ");
        scanf("%d", &temp.deadline);
        printf("Entrer le status de tache\n1=> A realiser\t 2=> En cours de realiser\t 3=> Done  ");
        scanf("%d", &temp.status);
        t[size]=temp;
        size++;
       }
}
void displaysortmenu()
{
    printf("&&&&& Sort Menu &&&&&\n");
    printf("\n 1) Trier par alphabetic");
    printf("\n 2) Trier par deadline");
    printf("\n 3) Trier par deadline");
    printf("\n 4) Retourner au menu principal");
    printf("\n #) Quitter\n");
    scanf(" %c", &choice2);

}
void sortalpha(tache t[100]){
    for (int i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            int result = strcmp(t[j].titre, t[j+1].titre);
            if (result > 0)
            {
                tache temp;
                temp = t[j+1];
                t[j+1] = t[j];
                t[j] = temp; 
            }
            
        }
    }
    printf("Les taches sont trier on alphabetic");
}

void updatesumenu()
{
    printf("-*-*-*-*-( Menu de modification)-*-*-*-*-\n");
    printf("1) Pour modifier la description\n");
    printf("2) Pour modifier le statut\n");
    printf("3) Pour modifier le deadline\n");
    scanf(" %c", &updatechoice);
}

void updatedes(tache tab[100], int id)
{
    int found = 0;
    int i;
    int ap;
    for (i = 0; i < size; i++) 
    {
        ap = tab[i].id;
        if (ap == id)
        {
            scanf(" %99[^\n]", &tab[i].description);
            found = 1; // Task found and updated
            break;   // No need to continue the loop once found
        }
    }

    if (found == 1) 
    {
        printf("Description Update\n");
    }
    else
    {
        printf("Not found\t id = %d\n", ap);
    }
}


void updatestat(tache tab[100], int id)
{
    printf("Entrer le nouveau statut\n 1=> A realiser\t 2=> En cours\t 3=> finalise\n");
    int found = 0;
    int i;
    int ap;
    for (i = 0; i < size; i++) 
    {
        ap = tab[i].id;
        if (ap == id)
        {
            scanf(" %d", &tab[i].status);
            found = 1; // Task found and updated
            break;   // No need to continue the loop once found
        }
    }

    if (found == 1) 
    {
        printf("Status Updated\n");
    }
    else
    {
        printf("Not found\t id = %d\n", ap);
    }
}


int main()
{
    
    do
    {   displaymenu();
        
        switch (choice)
        {
            case '1':   //ajouter une tache

                printf("Entrer le nombre de tache que voulez ajoute: ");
                scanf("%d", &n);
                addtask(t);
                break;
                
            case '2': // Afficher les taches

                for (int i = 0; i <size; i++)
                {
                    displaytask(t, i);
                }
                break;
            
            case '3':  // Trier les taches
                displaysortmenu();
                switch (choice2)
                {
                    case '1':
                        sortalpha(t);
                        break;
                    case '4':
                        displaymenu();
                        break;
                
                    default:
                        break;
                }
            case '4': // Modifier les taches
                 updatesumenu();
                 printf("Choisissez l id du tache \n");
                 scanf("%d", &searchid);
                switch (updatechoice)
                {
                    case '1':
                        printf("Changer la description de l'element [%d] \n", searchid);
                        updatedes(t, searchid);
                        break;
                    case '2':
                        printf("Changer le statut de l'element [%d] \n", searchid);
                        updatestat(t, searchid);
                        break;
                
                    default:
                        break;
                }
        }
    }while (choice != '#');
}