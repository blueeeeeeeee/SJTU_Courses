/**
 * Representation of a task in the system.
 */

#ifndef TASK_H
#define TASK_H



// representation of a task
typedef struct task {
    char *name;
    int tid;
    int priority;
    int burst;
    int starting_time;
    int waiting_time;
    int last_time;
    int response_time;
    int turn_time;
} Task;

#endif