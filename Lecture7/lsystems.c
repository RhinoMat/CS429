#include "Production_base.c"
typedef struct Production {
    char var;
    char axiom[100];
    char rule[100];
} Production;

Production prd[10];
int rule_num = 0;

char u[1000000], v[1000000];
double angle, gangle, flen;
int depth;

void square_wave()
{
    gangle = 90;
    angle = 90;
    rule_num = 0;
    strcpy(prd[rule_num].axiom, "A");
    rule_num++;
    prd[rule_num].var = 'A';
    strcpy(prd[rule_num].rule, "f-f-B");
    rule_num++;
    prd[rule_num].var = 'B';
    strcpy(prd[rule_num].rule, "f+f+A");
    rule_num++;
}

void string_interpreter()
{}