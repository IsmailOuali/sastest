#include<stdio.h>
#include<string.h>
#include<time.h>

int  j, n, tacheid =1, searchid = 0, verify;
int size = 0;
char choice;
char choice2, statchoice;
char updatechoice;
char statut[20];
char s[100];
int tasknb = 0, ctask = 0, inctask= 0;

typedef struct 
{
    int day;
    int mounth;
    int year;
}dead;

typedef struct
{
    int id;
    char titre[30];
    char description[100];
    dead deadline;
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
        inctask++;
    }
    else if(t[i].status == 2)
    {
        strcpy(statut, "En cours");
        inctask++;
    }
    else{
        strcpy(statut, "Finalise");
        ctask++;
    }
    printf("ID[%d] Titre: %s | Description: %s | Deadline: %d/%d/%d | Statut(%s)\n", t[i].id, t[i].titre, t[i].description, t[i].deadline.day, t[i].deadline.mounth, t[i].deadline.year, statut);

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
        printf("Entrer le deadline de la tache en format JJ/MM/YYYY: ");
        scanf("%d/%d/%d", &temp.deadline.day, &temp.deadline.mounth, &temp.deadline.year);
        printf("Entrer le status de tache\n1=> A realiser\t 2=> En cours de realiser\t 3=> Done  ");
        scanf("%d", &temp.status);
        t[size]=temp;
        size++;
        tasknb++;
       }
}
void displaysortmenu()
{
    printf("\t\t_-_-_-_- Sort Menu _-_-_-_-\n");
    printf("\n \t\t1) Trier par alphabetic");
    printf("\n \t\t2) Trier par deadline");
    printf("\n \t\t3) Afficher  deadline");
    printf("\n \t\t4) Retourner au menu principal");
    printf("\n \t\t#) Quitter\n");
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

void sortdeadline(tache t[100])
{
    tache temp;
    for (int i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (t[i].deadline.year > t[j].deadline.year){
                        temp = t[i];
                        t[i] = t[j];
                        t[j] = temp;
                    }
                    else if (t[i].deadline.year == t[j].deadline.year)
                    {
                        if (t[i].deadline.mounth > t[j].deadline.mounth)
                        {
                            temp = t[i];
                            t[i] = t[j];
                            t[j] = temp;
                        }
                        else if (t[i].deadline.mounth == t[j].deadline.mounth)
                        {
                            if (t[i].deadline.day > t[j].deadline.day){
                                temp = t[i];
                                t[i] = t[j];
                                t[j] = temp;
                            }
                        }
                    }
        }            
    } 
    printf("Les taches sont trier on deadline\n");
}
            

void updatesumenu()
{
    printf("\t\t-*-*-*-*-( Menu de modification)-*-*-*-*-\n");
    printf("\t\t1) Pour modifier la description\n");
    printf("\t\t2) Pour modifier le statut\n");
    printf("\t\t3) Pour modifier le deadline\n");
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
            printf("Entrer la nouvelle description: \n");
            scanf(" %99[^\n]", &tab[i].description);
            found = 1; 
            break;   
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
    int ap, verify;
    for (i = 0; i < size; i++) 
    {
        ap = tab[i].id;
        if (ap == id)
        {
            scanf(" %d", &tab[i].status);
            found = 1;
            break;
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

void deletetask() 
{
    int i, j, x;

    for (i = 0; i < size; i++) {
        printf("ID %d\n Titre : %s\n", t[i].id, t[i].titre);
    }

    printf("Entrer l'ID de la tache que vous voulez supprimer :");
    scanf("%d", &x);

    for (i = 0; i < size; i++) 
    {
        if (x == t[i].id) 
        {
            for (j = i; j < size - 1; j++) 
            {
                /*if (t[i].status == 1 && t[i].status == 2)
                {
                    inctask--;
                    tasknb--;
                }
                else if (t[i].status == 3)
                {
                    ctask--;
                    tasknb--;
                } */
                t[j] = t[j + 1];
            }
            size--;
            for (j = i; j < size; j++) 
            {
                t[j].id = j + 1;
            }
            printf("Tache supprimee avec succes\n");
            break;
        }
    }
}

void statmenu()
{
    printf("\t\t|||||||||||||||| Statistique ||||||||||||||||\n");
    printf("\t\t1) Afficher le nombre total des taches\n");
    printf("\t\t2) Afficher le nombre total des taches complete et incomplete\n");
    printf("\t\t3) Afficher les jours restants pour chaque tache\n");
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
                    case '2':
                        sortdeadline(t);
                        break;
                    case '4':
                        displaymenu();
                        break;
                
                    default:
                        break;
                }
                break;
            case '4': // Modifier les taches
                updatesumenu();
                printf("Choisissez l id du tache \n");
                scanf("%d", &searchid);
                switch (updatechoice)
                {
                    case '1':
                        printf("Voulez vous Changer la description de l'element [%d]   \t 1=> Oui\t\t 2=> Non\n", searchid);
                        scanf("%d", &verify);
                        if(verify == 1)
                            updatedes(t, searchid);
                        break;
                    case '2':
                        printf("Voulez vous Changer le statut de l'element [%d] \t 1=> Oui\t\t 2=> Non\n", searchid);
                        scanf("%d", &verify);
                        if (verify ==1)
                            updatestat(t, searchid);
                        break;
                
                    default:
                        break;
                }
                break;
                
            case '5': // Supprimer les taches
                deletetask();
                break;
            case '7':
                statmenu();
                scanf(" %c", &statchoice);
                switch (statchoice)
                {
                    case '1':
                        printf("le nombre total des taches est: %d\n", tasknb);
                        break;
                    case '2':
                        printf("le nombre total des taches complete est: %d\nle nombre total des taches incomplete est: %d\n", ctask, inctask);
                        break;
                
                    default:
                        break;
                }
                break;


        }
    }while (choice != '#');
}