#ifndef __TASK_MGT_H__
#define __TASK_MGT_H__

#define MAX_TASKS 10

/*struct time {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday
    int tm_mon;
    int year;
    int tm_wday
    int tm_yday
}*/

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