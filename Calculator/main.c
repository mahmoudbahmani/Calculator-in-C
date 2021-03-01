#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define d 1.e-6 
#define PI 3.14159265359
#define dim 3
#define E 2.7182818284

//-------------------------------COLORS------------------------------------------------
void red () {
  printf("\033[1;31m");
}

void cyan () {
  printf("\033[1;36m");
}

void blue () {
  printf("\033[1;34m");
}

void green() {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

//-------------------------------FACTORIAL------------------------------------------------
double factorial(double m)
{
  double i, fact=1;
  for(i=0; i<m+1; i++)
  {
  if(i) fact*=i;
  }
  return fact;
}

//------------------------------SQUARE-ROOT------------------------------------------------
float squareroot(float c)
{
float m, n;  
for (m = c, n = 0; n < 100; n++,m = ((m + (c / m)) / 2));
return m;
}

//-------------------------------ABSOLUTE-VALUE------------------------------------------------
double fabs(double x)
{
double result;
  if(x>=0)
  {
    result=x;
  }
  else
    result=-1*x;
return result; 
}

//-----------------------------NTH-POWER------------------------------------------------
double powern(double a, double b)
{
double result; //result.power
int cont;
    result=1;
    for(cont=0; cont<(int)b; cont++)
        result*=a;
return result;
}

//-------------------------------NTH-SQUARE-ROOT------------------------------------------------
double sqrtn(double a, double n)
{
double result=0; //result.power
double y, step=1;
while(step>d)
{
    do
    {
        result+=step;
        y=powern(result,n);
    }
    while(y<a);
    if(y==a)
    break;
    result-=step;
    step=step/10;
}
return result;
}

//-------------------------------REAL-POWER------------------------------------------------
double powerr(double a, double b)
{
double dec, y, result;
int x=1;
    if(b==(int)b)
    {
        result=powern(a,b);
    }
    else
    {
    do
    {
        x=x+1;
        dec=b*x;
    }
    while(dec>(int)dec);
    y=sqrtn(a, x);
    result=powern(y, dec);
    }
  return result;
}

//-------------------------------LOGARITHMS------------------------------------------------
double ln(double b)
{
double a, result;
        if(b>=1)
        {
        result=0;
        for(a=1; a<=b; a+=d)
        result+= d/a;
        }
        if(b<1)
        result=0;
        for(a=b; a<=1; a+=d)
        result-=d/a;

    return result;
}

//-------------------------------TRIGONOMETRIC-OPS------------------------------------------------
double sin(double x) //Uses the Taylor series for sines
{
double factorial=1, deriv=1, result=0;
int i, order=20;
  while(x>PI)  {    x=x-2*PI;   }
  while(x<-1*PI) {    x=x+2*PI;   }
    for(i=0; i<order; i++)
    {
      if(i) factorial*=i;

      if(i%2)
      {
        result+=deriv*powern(x,i)/factorial;
        deriv*=-1;
      }
    }
  return result;
}

double cos(double x)
{
double result;
  result=sin(x+PI/2);
  return result;
}

//-------------------------------INVERSE-TRIG-OPS------------------------------------------------
double arcsin( double x)
{
double result=0;
  if(x>=0) 
  { if(x==1)    {   result=PI/2;    }
    else
    while(sin(result)<=x)    {   result+=d;    }
  }
  else
    {
      if(x==-1)    {   result=-1*PI/2;    }
    else
      while(x<=sin(result))  {   result-=d;    }
    }
  return result;
}

double arctan( double x)
{
double result=0;
  if(x>=0) 
  { 
    while(sin(result)/cos(result)<=x)    {   result+=d;    }
  }
  else
    while(x<=sin(result)/cos(result))  {   result-=d;    }
 return result;
}

double arccsc(double x)
{
double result;
     result=arcsin(1/x);
return result;
}

//-------------------------------VECTORS------------------------------------------------
void printfvec(double *w)
{
	int i;
	printf("= [");
	for(i=0;i<dim;i++)
	{
		printf("%lf,",w[i]);
	}
	printf("\b]\n");
}

void vectorsum(double *u, double *v, double *sum)
{
int i;
	for(i=0;i<dim;i++)
	sum[i]=u[i]+v[i];
}

void vectordif(double *u, double *v, double *dif)
{
int i;
	for(i=0;i<dim;i++)
		dif[i]=(u[i])-(v[i]);
}

void scalevec(double *u, double a, double *w)
{
	int i;
	for(i=0;i<dim;i++)
		w[i]=a*u[i];
} 
  
double pprod(double *u, double *v)
{
	int i;
	double prod=0;
	for(i=0;i<dim;i++)
	{
		prod+=(u[i])*(v[i]);
	}
	return prod;
}

void cprod(double *u, double *v, double *prod)
{
	prod[0]=(u[1]*v[2])-(u[2]*v[1]);
	prod[1]=(u[2]*v[0])-(u[0]*v[2]);
	prod[2]=(u[0]*v[1])-(u[1]*v[0]);
}

//--------------------------------------HELP---------------------------------------------
void help() 
{ 
    FILE *filePointer ; 
    char Readfile[50]; 
    filePointer=fopen("help.txt","r") ; 
    if (filePointer==NULL) 
    { 
        printf("Try again...\n"); 
    } 
    else
    {    
        while(fgets(Readfile, 50, filePointer)!=NULL) 
        { 
            printf("%s",Readfile); 
         } 
        fclose(filePointer); 
        printf("\n\n"); 
    }         
} 

void exit(int status);

//-------------------------------------MAIN------------------------------------------------

int main(void)
{  
    int choice, next=0, z, l, num, count, x=1, fact = 1, s = 0, o = 0, i;
    double ans=0, y, q, result=0;
    float a, b, c, m, n, dec;
    char fullOperation[100], trash[10], oper;
    double u[dim];
    double v[dim];
    double w[dim];
    double V[]={0,0,0};
    int check=1, cont=0;

    red();
    printf("\n🧠 Calculator 🔬:\n");
    yellow();
    printf("\nEnter 'h' for help.\n");
    printf("Enter 'q' to exit.\n\n");
do
{
    green();
    printf("→ ");
  scanf("%s", &fullOperation[0]);
  switch(fullOperation[0])
  {
  case 't':
  sscanf(fullOperation,"%c%c%c%c%c%c%c", &trash[0], &trash[1], &trash[2], &trash[3], &trash[4], &trash[5], &trash[6]);
      trash[7]='\x0';
  if(fullOperation[5]=='R') {y=ans;}
      else
      {
      if(fullOperation[5]=='p') {y=PI;}
      else
      {
      if(fullOperation[5]=='e') {y=E;}
      else y=atof(&fullOperation[5]);
      }
      }
    switch(trash[1])
    {
    case 's':
      switch(trash[2])
      {
        case 'i':
        result=sin(y);
        break;
        case 'e':
        if(cos(y))    {result=1/cos(y);}
        else
        {
        printf("Error, undefined operation....jajaja\n\n");
        check=0;
        }
        break;
        default:
        printf("Unknown operation....jajaja\n\n");
        check=0;
      }
      break;

    case 'c':
      switch(trash[2])
      {
        case 'o':
        result=cos(y);
        break;
        case 't':
        if(sin(y))    {result=cos(y)/sin(y);}
        else
        {
        printf("Error, undefined operation....jajaja\n\n");
        check=0;
        }
        break;
        case 's':
        if(sin(y))    {result=1/sin(y);}
        else
        {
        printf("Error, undefined operation....jajaja\n\n");
        check=0;
        }
        break;
        default:
        printf("Unknown operation....jajaja\n\n");
        check=0;
      }
      break;

    case 't':
      if(cos(y))    {result=sin(y)/cos(y);}
      else
      {
      printf("Error, undefined operation....jajaja\n\n");
      check=0;
      }
      break;
     default:
		 printf("Unknown operation...\n\n");
     check=0;
      }
    if(check) {printf("= %lf\n", result);}
    break;
    
  case 'a':
  sscanf(fullOperation,"%c%c%c%c%c%c%c", &trash[0], &trash[1], &trash[2], &trash[3], &trash[4], &trash[5], &trash[6]);
      trash[7]='\x0';
    if(fullOperation[5]=='R') {y=ans;}
      else
      {
      if(fullOperation[5]=='p') {y=PI;}
      else
      {
      if(fullOperation[5]=='e') {y=E;}
      else y=atof(&fullOperation[5]);
      }
      }
    switch(trash[1])
    {
    case 's':
      switch(trash[2])
      {
        case 'i':
        if(fabs(y)<=1) {   result=arcsin(y); }
        else
        {
          printf("Error operation.... |%lf|>1\n\n",y);
          check=0;
        }
        break;
        case 'e':
        if(fabs(y)>=1)    {result=PI/2-arccsc(y);}
        else
        {
        printf("Error operation.... |%lf|<1\n\n",y);
        check=0;
        }
        break;
        default:
        printf("Unknown operation....hahaha");
        check=0;
      }
      break;
    case 'c':
      switch(trash[2])
      {
        case 'o':
        if(fabs(y)<=1) {   result=PI/2-arcsin(y); }
        else
        {
          printf("Error operation.... |%lf|>1\n\n",y);
          check=0;
        }
        break;
        case 't':
          result=PI/2-arctan(y);
        break;
        case 's':
        if(fabs(y)>=1)    {result=arccsc(y);}
        else
        {
         printf("Error operation.... |%lf|<1\n\n",y);
         check=0;
        }
        break;
        default:
        printf("Unknown operation....jajaja");
        check=0;
      }
      break;
    case 't':
      result=arctan(y);
      break;
     default:
		 printf("Unknown operation...\n\n");
     check=0;
    }
    if(check) {printf("= %lf\n", result);}
  break;
  
  case 'l':
    sscanf(fullOperation,"%c%c%c%c%c", &trash[0], &trash[1], &trash[2],&trash[3],&trash[4]);
      trash[5]='\x0';
      if(fullOperation[3]=='R') {y=ans;}
      else
      {
      if(fullOperation[3]=='p') {y=PI;}
      else
      {
      if(fullOperation[3]=='e') {y=E;}
      else y=atof(&fullOperation[3]);
      }
      }
    switch(trash[1])
    {
        case 'n':
        if(y>0) { result=ln(y); }
        else
        {
        printf("Undefined Operation %lf<=0\n\n",y);
        check=0;
        }
        break;
        case 'g':
        if(y>0) { result=ln(y)/ln(10); }
        else
        {
        printf("Undefined Operation %lf<=0\n\n",y);
        check=0;
        }
        break;
        default:
        printf("Unknown operation...\n\n");
        check=0;
    }
    if(check) {printf("= %lf\n",result);}
    break;
    
case 'v':
      sscanf(fullOperation,"%c%c%lf%c%lf%c%lf%c%c%c%lf%c%lf%c%lf%c",&trash[0],&trash[1],&u[0],&trash[2],&u[1],&trash[3],&u[2],&trash[4],&oper,&trash[5],&v[0],&trash[6],&v[1],&trash[6],&v[2],&trash[8]);
		   trash[9]='\x0';

     if(fullOperation[1]=='V')
     {
      sscanf(fullOperation,"%c%c%c%c%lf%c%lf%c%lf%c",&trash[0],&trash[1],&oper,&trash[2],&v[0],&trash[3],&v[1],&trash[4],&v[2],&trash[5]);
		  trash[6]='\x0';
      switch(oper)
		    {
		      case '+':
		      vectorsum(V,v,w);
		      printfvec(w);
		      break;

		      case '-':
		      vectordif(V,v,w);
		      printfvec(w);
		      break;

		      case '*':
		      result=pprod(V,v);
		      printf("= %lf\n",result);
		      break;

          case 'x':
		      cprod(V,v,w);
		      printfvec(w);
		      break;

		      default:
		      printf("Unknown operation...\n\n");
		     }
     }
     else
     {
       if(fullOperation[1]=='[')
       {
         sscanf(fullOperation,"%c%c%lf%c%lf%c%lf%c%c%c%lf%c%lf%c%lf%c",&trash[0],&trash[1],&u[0],&trash[2],&u[1],&trash[3],&u[2],&trash[4],&oper,&trash[5],&v[0],&trash[6],&v[1],&trash[6],&v[2],&trash[8]);
		     trash[9]='\x0';
         switch(oper)
		    {
		      case '+':
		      vectorsum(u,v,w);
		      printfvec(w);
		      break;

		      case '-':
		      vectordif(u,v,w);
		      printfvec(w);
		      break;

		      case '*':
		      result=pprod(u,v);
		      printf("= %lf\n",result);
		      break;

          case 'x':
		      cprod(u,v,w);
		      printfvec(w);
		      break;

		      default:
		      printf("Unknown operation...\n\n");
		     }
       }
       else
       {
         if(fullOperation[1]=='|')
         {
         sscanf(fullOperation,"%c%c%c%lf%c%lf%c%lf%c",&trash[0],&trash[1],&trash[2],&u[0],&trash[2],&u[1],&trash[3],&u[2],&trash[4]);
		     trash[5]='\x0';
         if(fullOperation[2]=='V') { result=sqrtn(pprod(V,V),2); }
         else {   result=sqrtn(pprod(u,u),2);    }
         printf("= %lf\n", result);
         }
         else 
         {
          if(fullOperation[1]=='(')
           {
           sscanf(fullOperation,"%c%c%lf%c%c%lf%c%lf%c%lf%c",&trash[0],&trash[1],&y,&trash[2],&trash[3],&u[0],&trash[4],&u[1],&trash[5],&u[2],&trash[6]);
		      trash[7]='\x0';
          if(trash[3]=='V')  { scalevec(V,y,w);}
          else   {    scalevec(u,y,w);    }
          printfvec(w);
          }
          else
          printf("Unknown operation...\n\n");
          }
       }
     }
     break;

    case'h':
    blue();
    help();
    break;

    case'q':
    yellow();
    printf("\nLast One Out, Get the Lights...💡\n\n");
    exit(0);
    break;

    default:
    sscanf(fullOperation,"%c%c%lf", &trash[0], &oper, &q);
      trash[4]='\x0';
      if(fullOperation[0]=='R') {y=ans;}
      else
      {
      if(fullOperation[0]=='p') {y=PI;}
      else
      {
      if(fullOperation[0]=='e') {y=E;}
      else
        sscanf(fullOperation,"%lf%c%lf", &y, &oper, &q); 
      }
      }
      switch(oper)
      {
       case '+':
        result=y+q;
        break;
       case '-':
        result=y-q;
        break;
       case '*':
        result=y*q;
        break;
       case '/':
        if(q==0)
           {
             printf("Error: division by zero...\n\n\n");
             check=0;
           }
        else
          result=y/q;
          break;
      case '^':
        if(y>0)
           {
             if(q>=0)  {   result=powerr(y,q);  }
             else     result=1/powerr(y,-1*q);
           }
        if(y<0)
           { 
              if(q>=0)
              {
                if(q==(int)q)  { result=powern(y,q);  }
                else
                {
                    do
                    {
                    x=x+1;
                    dec=q*x;
                    }
                    while(dec>(int)dec);
                    
                    if((x%2)==0)
                    {
                        printf("Invalid operation...%lf<0\n\n\n",y);
                        check=0;
                    }
                    else
                    {
                    if(((int)dec)%2) { result= -1*powerr(-1*y, q);}
                    else result= powerr(-1*y, q);
                    }
                  }
              }
                if(q<0)
                  {
                    if(q==(int)q)
                    {
                    result=1/powern(y,-1*q);
                    check=0;
                    }
                    else
                    {
                    do
                    {
                    x=x+1;
                    dec=q*x;
                    }
                    while(dec<(int)dec);
                    
                    if((x%2)==0)
                    {
                        printf("Invalid operation...%lf<0\n\n\n",y);
                        check=0;
                    }
                    else
                    {
                    if(((int)dec)%2) { result= -1/powerr(-1*y, -1*q);}
                    else result= 1/powerr(-1*y, -1*q);
                    }
                    }    
                  }
                }
                if(y==0)
                {
                  result=0;
                }
        break;
      case '|':
      if(q<=0)
      {
        printf("n-Root error, %lf must be positive...\n\n", q);
        check=0;
      }
      else
      {
        if(q!=(int)q)
        {
          printf("n-Root error, %lf must be a natural number...\n\n", q);
          check=0;
        }
        else
        result=sqrtn(y,q);
      } 
        break;
      case '!':
      sscanf(fullOperation,"%c%c", &trash[0], &oper);
      trash[1]='\x0';
      if(fullOperation[0]=='R') {y=ans;}
      else
      {
      if(fullOperation[0]=='p') {y=PI;}
      else
      {
      if(fullOperation[0]=='e') {y=E;}
      else
        sscanf(fullOperation,"%lf%c", &y, &oper); 
      }
      }
      if(y<0)
      {
        printf("Error, Did you mean %d!?....\n\n",  -1*((int)y));
        check=0;
      }
      else
      {
        if(y==(int)y) {result=factorial(y);}
        else
        {
          printf("Error, Did you mean %d!?...\n\n", (int)y);
          check=0;
        }
      }
      break;
		 default:
		 printf("\n( ͠° ͟ʖ ͡°) Unknown Operation, press 'h' for help...\n\n");
     check=0; 
     }
     if(check) {printf("= %lf\n", result);}
    
  }
  check=1;
  if(check) {ans=result;}
  for(i=0; i<dim; i++)  {    V[i]=w[i];   }
  }while(next==0);
}

//Created by Marcos Alejandro Hernández Ojeda and José Eduardo Cárdenas Ruiz