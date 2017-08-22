#ifndef INFIX_H
#define INFIX_H


int set_flag(char ch);

void reverse_expression(char *str);

void infix_postfix_conversion(char *infix, char *postfix);

void infix_postfix_evaluation(char *postfix);

void infix_prefix_conversion(char *infix, char *prefix);

void infix_prefix_evaluation(char *prefix);

#endif
