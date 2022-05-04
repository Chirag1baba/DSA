#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct nodetype
{
int power;
int coeff;
struct nodetype *next;
}node;
void main()
{ node *ptr1,*ptr2,*ptr3;
  int choice,element,after,before,ptr;
  void newpolynomial(node **);
  void outputpolynomial(node *);
  void addpolynomial(node *,node *,node **);
  void addnode(node **,int,int);
  void deletepolynomial(node **);
  void outputpolynomial(node *ptr);
  ptr1=ptr2=ptr3=NULL;
  clrscr();
  printf("\nADD Two Polynimial");
  printf("\n Enter the first polynomial");
  newpolynomial(&ptr1);
  printf("\n Enter the second polynomial");
  newpolynomial(&ptr2);
  addpolynomial(ptr1,ptr2,&ptr3);
  printf("\nAddition of polynomial = ");
  outputpolynomial(ptr1);
  printf("\nADD");
  outputpolynomial(ptr2);
  printf("\nis = ");
  outputpolynomial(ptr3);
  deletepolynomial(&ptr1);
  deletepolynomial(&ptr2);
  deletepolynomial(&ptr3);
  getch();
  }
  void addnode(node **ptr,int coef,int powe)
  {
    node *tptr;
    tptr=(node *)malloc(sizeof (node));
    tptr->coeff=coef;
    tptr->power=powe;
    if(*ptr==NULL)
    {
      tptr->next=NULL;
      *ptr=tptr;
      }
      else
      {
	tptr->next=*ptr;
	*ptr=tptr;
	}
      }
  void newpolynomial(node **p)
  {
    int cff,power;
    printf("\n Enter the term in the ascending order of power ");
    while(1)
    {
      printf("\nEnter the dgree of x = ");
      scanf("%d",&power);
      printf("\nEnter the cofficient = ");
      scanf("%d",&cff);
      addnode(p,cff,power);
      break;
      printf("\nWant to enter more term (y/n) = ");
      if(toupper(getch())=='Y');
      }
      }
    void outputpolynomial(node *ptr)
     {
       if (ptr!=NULL)
       printf("%d%d",ptr->coeff,ptr->next);
       for(ptr=ptr->next;ptr!=NULL;ptr=ptr->next)
       {
	if(ptr->coeff>0)
	printf(" + ");
	if(ptr->power==0)
	printf("%d",ptr->coeff);
	else if(ptr->power==1)
	printf("%d",ptr->coeff);
	else
	printf("%d^%d,ptr->coeff,ptr->coeff");
	}
       }
      void addpolynomial(node *ptr1,node *ptr2, node **ptr3)
      {
	 int powe;
	 float coef;
	 while((ptr1!=NULL)&&(ptr2!=NULL))
	 {
	 if(ptr1->power>ptr2->power)
	 { powe=ptr1->power;
	   coef=ptr1->coeff;
	   ptr1=ptr1->next;
	 }
	 else if(ptr1->power<ptr2->power)
	 {  powe=ptr2->power;
	    coef=ptr2->coeff;
	    ptr2=ptr2->next;
	 }
	 else
	 {
	    coef=ptr1->coeff+ptr2->coeff;
	    powe=ptr1->power;
	    ptr1=ptr1->next;
	    ptr2=ptr2->next;
	 }
	 if(coef!=0)
	 addnode(ptr3,coef,powe);
	 }
	 if(ptr1==NULL)
	 {
	   for(;ptr2!=NULL;ptr2=ptr2->next)
	   addnode(ptr3,ptr1->coeff,ptr1->power);
	   }
	   }
	   void deletepolynomial(node **ptr)
	   {
	     node*t;
	     while(*ptr!=NULL)
	     {
	      t=*ptr;
	      *ptr=(*ptr)->next;
	      free(t);
	      }
	  }

