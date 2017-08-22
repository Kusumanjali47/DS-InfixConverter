#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

void c_push(char *array, int size, int *top, char ch);

char c_peak(char *array, int top);

char c_pop(char *array,int *top);

int pop(int *array,int *top);

void push(int *array, int size, int *top, int value);

int is_empty(int top);

int is_full(int size, int top);

#endif
