#include <stdio.h>
#include "util.h"

int dt0(int t, double p, double h, char s, int w)
{
    int r = 0;

    if (t>35 && w!=3) r = 1;

    else if (t<=35 && s==0) r = 1;

    return r;
}

char dt1a(double a,double b)
{
    char r;  

    if (a<2.45) r='b';

    else if (a>=2.45 && b>=1.75) r='o';

    else if (a>=2.45 && b<1.75 && a>=4.95) r='o';

    else if (a>=2.45 && b<1.75 && a<4.95 && b>=1.65) r='o';

    else if (a>=2.45 && b<1.75 && a<4.95 && b<1.65) r='g';

    return r;
}

char dt1b(double a,double b)
{
    char r; 
    
    if (a<2.55) r='b';

    else if (a>=2.55 && b>=1.69) r='o';

    else if (a>=2.55 && b<1.69 && a>=4.85) r='o';

    else if (a>=2.45 && b<1.75 && a<4.85) r='g';

    return r;
}

double dt2a(double a,double b,double c,int d,int e)
{
    double r; 

    if(a<31.5 && b>-2.5) r=5.3;

    else if(a<31.5 && b<=-2.5 && ((b-0.1)<=a && a<=(b+0.1))) r=2.15;

    else if(a<31.5 && b<=-2.5 && ((b-0.1)>a || a>(b+0.1))) r=-1.16;

    else if(a>=31.5 && (-1<c && c<=2)) r=1.47;

    else if(a>=31.5 && (-1>=c || c>2) && (d==1 && e==1)) r=-2.28;

    else if(a>=31.5 && (-1>=c || c>2) && (d==0 || e==0)) r=11.3;

    return r;
}

double dt2b(double a,double b,double c,int d,int e)
{
    double r; 

    if((12<a && a<22) && c>1.67) r=-2.7;

    else if((12<a && a<22) && (c<=1.67) && ((a-0.1)<=c && a<=(c+0.1))) r=1.12;

    else if((12<a && a<22) && (c<=1.67) && ((a-0.1)>a || a>(c+0.1))) r=-7.5;

    else if((12>=a || a>=22) && (d==1 && e==1)) r=-1.2;

    else if((12>=a || a>=22) && (d==0 || e==0) && (-1<=b && b<=2)) r=-0.20;

    else if((12>=a || a>=22) && (d==0 || e==0) && (-1>b || b>2)) r=0.53;

    return r;
}

double dt3a(double a,double b,int c,int d,int e)
{
    double r; 

    if(a<=35 && (c==1) && b>=10000) r=0.0;

    else if(a<=35 && (c==1) && b<10000 && (d<=4 && e<=2)) r=0.12;

    else if(a<=35 && (c==1) && b<10000 && (d>4 || e>2)) r=0.19;

    else if(a<=35 && (c==0) && (50000<b && b<250000) && d>=5) r=0.65;

    else if(a<=35 && (c==0) && (50000<b && b<250000) && d<=4 && e<=9) r=0.33;

    else if(a<=35 && (c==0) && (50000<b && b<250000) && d<=4 && e>9) r=0.39;

    else if(a<=35 && (c==0) && (50000>=b || b>=250000) && d>=5 ) r=0.88;

    else if(a<=35 && (c==0) && (50000>=b || b>=250000) && d<5 )  r=0.59;

    else if(a>35 && b<=50000 && d<5) r=0.78;

    else if(a>35 && b<=50000 && d>=5) r=0.97;

    else if(a>35 && b>50000 && (9<=e && e<=12)) r=0.42;

    else if(a>35 && b>50000 && (9>e || e>12) && d>=5) r=0.77;

    else if(a>35 && b>50000 && (9>e || e>12) && d<5) r=0.40;

    return r;
}

double dt3b(double a,double b,int c,int d,int e)
{
    double r; 

    if(a>35 && b>=45000 && d<5) r=0.50;

    else if(a>35 && b>=45000 && d>=5) r=0.75;

    else if(a>35 && b<45000 && e>=6) r=0.87;

    else if(a>35 && b<45000 && e<6 && d>=5) r=0.99;

    else if(a>35 && b<45000 && e<6 && d<5) r=0.61;

    else if(a<=35 && (c==0) && b>=65000 && d>=5) r=0.58;

    else if(a<=35 && (c==0) && b>=65000 && d<5) r=0.38;

    else if(a<=35 && (c==0) && b<65000 && e<6) r=0.64;

    else if(a<=35 && (c==0) && b<65000 && e>=6) r=0.47;

    else if(a<=35 && (c==1) && b<9000 && d<5) r=0.14;

    else if(a<=35 && (c==1) && b<9000 && d>=5) r=0.21;

    else if(a<=35 && (c==1) && b>=9000) r=0.00;

    return r;
}