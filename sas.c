#include<stdio.h>
#include<string.h>
#include<time.h>

int i, j, n, tacheid =1, searchid = 0;
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
void addtask(tache t[100], int i)
{
    for (i = 0; i < n; i++)
    {
        tache temp;
        temp.id=size+1;
        printf("Entrer le titre de la tache: ");
        getchar();
        gets(temp.titre);
        printf("Entrer la description de la tache: ");
        gets(temp.description);
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
    for ( i = 0; i < size; i++)
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

void updatemenu()
{
    printf("1) Modifier la description\n");
    printf("2) Modifier le statut\n");
    printf("3) Modifier le deadline\n");
}

void updatesumenu()
{
    printf("-*-*-*-*-( Menu de modification)-*-*-*-*-\n");
    printf("1) Pour modifier la description\n");
    printf("2) Pour modifier le statut\n");
    printf("3) Pour modifier le deadline\n");
    scanf(" %c", &updatechoice);
}

void updatedes(int id, char des[])
{
    /*scanf(" %s", &t[searchid].description);
    strcpy(s, t[id].description);
    //printf("%s", &t[searchid].description);
    printf("\nUpdate succesed\n");
    printf("[%d]", t[searchid].id);*/
    int found = 0;
    for (i = 0; i < size; i++) {
        if ( t[i].id == id) {
            strcpy(t[i].description, des);
            found = 1;
            break;
        }
    }
}

void updatestat()
{
    printf("Entrer le nouveau statut\n 1=> A realiser\t 2=> En cours\t 3=> finalise\n");
    scanf("%d", &j);
    t[searchid].status = j;
}


int main()
{
    tache task[100];
    
    do
    {   displaymenu();
        
        switch (choice)
        {
            case '1':   //ajouter une tache

                printf("Entrer le nombre de tache que voulez ajoute: ");
                scanf("%d", &n);
                addtask(task, i);
                break;
                
            case '2': // Afficher les taches

                for ( i = 0; i < size; i++)
                {
                    displaytask(task, i);
                }
                break;
            
            case '3':  // Trier les taches
                displaysortmenu();
                switch (choice2)
                {
                    case '1':
                        sortalpha(task);
                        break;
                    case '4':
                        displaymenu();
                        break;
                
                    default:
                        break;
                }
            case '4': // Modifier les taches
                //updatemenu();
                updatesumenu();
                printf("Choisissez l id du tache \n");
                scanf("%d", &searchid);
                switch (updatechoice)
                {
                    case '1':
                        printf("Changer la description de l'element [%d] \n", searchid);
                        printf("Entrer la nouvelle description: \n");
                        getchar();
                        gets(s);
                        updatedes(searchid, s);
                        break;
                    case '2':
                        printf("Changer le statut de l'element [%d] \n", searchid);
                        updatestat();
                        printf("[%s]", t[searchid]);
                        break;
                
                    default:
                        break;
                }
        }
    }while (choice != '#');
}