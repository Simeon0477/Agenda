#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/task_mgt.h"

Day  agenda[7] = {
    {"Lundi", {}, 0},
    {"Mardi", {}, 0},
    {"Mercredi", {}, 0},
    {"Jeudi", {}, 0},
    {"Vendredi", {}, 0},
    {"Samedi", {}, 0},
    {"Dimanche", {}, 0}
};

int choice;
char day[10];
int hour, min = 0;
char desc[100];
char ndesc[100];

int main(){
    loadAgenda(agenda, 7);
    printf("\033[35m******** AGENDA HEBDOMADAIRE ******** \n\n\033[0m");
    printf("Que voulez vous faire ? \n");
    printf(" 1 - Ajouter une tâche \n");
    printf(" 2 - Afficher les tâches d'aujourd'hui \n");
    printf(" 3 - Suppression d'une tâche\n");
    printf(" 4 - Edition d'une tâche\n");
    printf(" 5 - Recherche d'une tâche d'une tâche\n");

    printf("\nVotre choix -> ");
    scanf("%d", &choice);

    switch(choice){
        case 1 :{
            printf("\n\033[32m1 - Ajouter une tâche \n\033[0m");
            //Saisie des données
            printf("\nEntrez le jour (Première lettre en majuscule) :\n");
            scanf("%s", day);
            printf("Entrez l'heure de début de la tâche :\n");
            scanf("%d", &hour);
            printf("Entrez les minutes pour plus de précision :\n");
            scanf("%d", &min);
            printf("Entrez la description de la tâche :\n");
            scanf(" %[^\n]", desc);

            //Recherche du jour
            for(int i=0; i < 7; i++){
                if (strcmp(day, agenda[i].name) == 0) {
                    //Ajout
                    addTask (&agenda[i], hour, min, desc);
                    saveAgenda(agenda, 7);
                }
            }
            break;
        }
        case 2 :{
            printf("\n\033[32m2 - Afficher les tâches \n\033[0m");
            //Saisie des données
            printf("\nEntrez le jour (Première lettre en majuscule) :\n");
            scanf("%s", day);

            //Recherche du jour
            for(int i = 0; i < 7; i++){
                if (strcmp(day, agenda[i].name) == 0) {
                    //Affichage
                    showTask (&agenda[i]);
                }
            }
            break;
        }
        case 3 :{
            printf("\n\033[32m3 - Suppression d'une tâche\n\033[0m");
            //Saisie des données
            printf("\nEntrez le jour (Première lettre en majuscule) :\n");
            scanf("%s", day);
            printf("Entrez le nom de la tâche à supprimer de la tâche :\n");
            scanf(" %[^\n]", desc);

            //Recherche de la tâche
            for(int i = 0; i < 7; i++){
                if (strcmp(day, agenda[i].name) == 0) {
                    for(int j = 0; j < agenda[i].taskCount; j++){
                        if (strcmp(desc, agenda[i].tasks[j].desc) == 0){
                            deleteTask (agenda[i].tasks, &agenda[i].taskCount, j);
                            saveAgenda(agenda, 7);
                        }
                    }
                }
            }
            break;
        }
        case 4 :{
            printf("\n\033[32m4 - Edition d'une tâche\n\033[0m");
            //Saisie des données
            printf("\nEntrez le jour (Première lettre en majuscule) :\n");
            scanf("%s", day);
            printf("Entrez le nom de la tâche à modifier :\n");
            scanf(" %[^\n]", desc);
            printf("Entrez le nouveau nom de la tâche :\n");
            scanf(" %[^\n]", ndesc);
            printf("Entrez la nouvelle heure de début de la tâche :\n");
            scanf("%d", &hour);
            printf("Entrez les minutes :\n");
            scanf("%d", &min);

            //Recherche de la tâche
            for(int i = 0; i < 7; i++){
                if (strcmp(day, agenda[i].name) == 0) {
                    for(int j = 0; j < agenda[i].taskCount; j++){
                        if (strcmp(desc, agenda[i].tasks[j].desc) == 0){
                            editTask (agenda[i].tasks, hour, min, ndesc);
                            saveAgenda(agenda, 7);
                        }
                    }
                }
            }
            break;
        }
        case 5 :{
            printf("\n\033[32m3 - Recherche d'une tâche\n\033[0m");
            //Saisie des données
            printf("Entrez le nom de la tâche recherchée :\n");
            scanf(" %[^\n]", desc);

            //Recherche de la tâche
            printf("Résultats de la recherche :\n");
            for(int i = 0; i < 7; i++){
                for(int j = 0; j < agenda[i].taskCount; j++){
                    if (strcmp(desc, agenda[i].tasks[j].desc) == 0){
                        printf("-----------------------\n");
                        printf("Nom : %s \n", agenda[i].tasks[j].desc);
                        printf("Jour : %s \n", agenda[i].name);
                        printf("Heure de début :  - %02d h %02d min \n", agenda[i].tasks[j].hour, agenda[i].tasks[j].min);
                        printf("-----------------------\n");
                    }
                }
            }
            break;
        }
        
        default :{
            printf(" \nChoix invalide\n\n");
        }
    }

    return 0;
}

