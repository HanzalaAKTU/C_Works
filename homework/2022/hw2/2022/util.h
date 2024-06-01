#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w);

char dt1a(double a,double b);
char dt1b(double a,double b);

double dt2a(double a,double b,double c,int d,int e);
double dt2b(double a,double b,double c,int d,int e);

/* Write the prototype of the functions implementing the decision trees for the third problem */
double dt3a(double a,double b,int c,int d,int e);
double dt3b(double a,double b,int c,int d,int e);

#endif /* _UTIL_H_ */