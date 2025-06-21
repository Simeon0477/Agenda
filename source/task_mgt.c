#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/task_mgt.h"

//Ajout d'une tâche
void addTask (Day* jour, int h, int m, const char* desc) {
    if (jour->taskCount < MAX_TASKS) {
        Task* t = &jour->tasks[jour->taskCount++];
        t->hour = h;
        t->min = m;
        strncpy(t->desc, desc, 100);
    }else{
        printf("Plus tard");
    }
}

//Affichage des tâches d'une journée
void showTask(Day* jour) {
    printf("Tâches du %s : \n", jour->name);
    for(int i = 0; i < jour->taskCount; i++){
        Task t = jour->tasks[i];
        printf(" - %02d h %02d min : %s \n", t.hour, t.min, t.desc);
    }
}

void saveAgenda(Day agenda[], int size) {
    FILE *file = fopen("agenda.txt", "w");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %d\n", agenda[i].name, agenda[i].taskCount);
        for (int j = 0; j < agenda[i].taskCount; j++) {
            fprintf(file, "%d %d %s\n", agenda[i].tasks[j].hour, agenda[i].tasks[j].min, agenda[i].tasks[j].desc);
        }
    }

    fclose(file);
}

void loadAgenda(Day agenda[], int size) {
    FILE *file = fopen("agenda.txt", "r");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    for (int i = 0; i < size; i++) {
        fscanf(file, "%s %d", agenda[i].name, &agenda[i].taskCount);
        for (int j = 0; j < agenda[i].taskCount; j++) {
            fscanf(file, "%d %d %[^\n]", &agenda[i].tasks[j].hour, &agenda[i].tasks[j].min, agenda[i].tasks[j].desc);
        }
    }

    fclose(file);
}