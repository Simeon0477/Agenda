#ifndef __TASK_MGT_H__
#define __TASK_MGT_H__

#define MAX_TASKS 48

typedef struct{
    int hour;
    int min;
    char desc[100];
} Task;

typedef struct{
    char name[10];
    Task tasks[MAX_TASKS];
    int taskCount;
} Day;

void addTask (Day* jour, int h, int m, const char* desc);
void showTask(Day* jour);
void deleteTask(Task task[], int *count, int index);
void editTask (Task* t, int h, int m, const char* desc);
void saveAgenda(Day agenda[], int size);
void loadAgenda(Day agenda[], int size);

#endif