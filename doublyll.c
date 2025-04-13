//doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct adi{
    struct adi *prv;
    int data;
    struct adi *nxt;
};
typedef struct adi ad;
ad *strt=0;
ad* cn(){
ad *a=(malloc(sizeof(ad)));
printf("Enter a data :");
a->prv=0;
a->nxt=0;
scanf("%d",&a->data);
return a;
}
int main(){
    printf("press 1 for insertation from start.\npress 2 for insertation from middle.\npress 3 for insertation from end .\npress 4 for deletation from start.\npress 5 for deletetation from middle.\npress 6 for deletation from end .\npress 7 to display the data.\npress 8 to exit.\npress 9 to delete the linkedlist.\n");
   while(1){
            int c;
            printf("\nenter your chooice :");
            scanf("%d",&c);
            switch(c){
                case 1:{
                    ad *cl=cn();
                    if(strt ==0){
                            strt=cl;
                    } else {
                        cl->nxt=strt;
                        strt->prv=cl;
                        strt=cl;
                    }

                    break;
                }
                case 2:{
                    if(strt==0||strt->nxt==0){
                        printf("there must be atleast two node to insert inbetween.");
                    } else{
                        printf("enter tha data after which you want to insert :");
                        int ld;
                        scanf("%d",&ld);
                        ad *t=strt;
                        while(t!=0 && t->data!=ld){
                            t=t->nxt;
                        }
                        if(t==0){
                            printf("The data you have entered is not listed.\n");
                    } else {
                         ad *cl=cn();
                        cl->nxt=t->nxt;
                        t->nxt->prv=cl;
                        cl->prv=t;
                        t->nxt=cl;
                    }
                    }
                    break;
                }
                case 3:{
                          ad *cl=cn();
                    if(strt ==0){
                            strt=cl;
                    } else {
                        ad *t=strt;
                      while(t->nxt!=0){
                        t=t->nxt;
                      }
                      t->nxt=cl;
                      cl->prv=t;
                    }

                    break;
                }
                case 4:{
                 if(strt==0){
                    printf("there is no data to delete.");
                 } else {
                       ad *d=strt;
                    strt=strt->nxt;
                    free(d);
                 }
                    break;
                }
                case 5:{
                    ad *t=strt;
                    ad *d;
                    if(strt==0){
                        printf("There is no data to delete.");
                    } else{
                        printf("Ender the data you want to delete :");
                        int ch;
                        scanf("%d",&ch);
                        while(t!=0 && t->nxt->data!=ch){
                            t=t->nxt;
                        }
                        if(t==0){
                            printf("The data you have entered is not listed.");
                        } else{
                            d=t->nxt;
                            t->nxt=d->nxt;
                            d->nxt->prv=t;
                            d->nxt=0;
                            d->prv=0;free(d);

                        }
                    }
                    break;
                }
                case 6:{
                  if(strt==0){
                    printf("there is no data to delete.");
                  } else{
                      ad *d;
                    ad *t=strt;
                    if(t->nxt==0){
                        free(t);
                        strt=0;
                    } else{
                    while(t->nxt->nxt!=0){
                        t=t->nxt;
                    }
                   d=t->nxt;
                    t->nxt=0;
                    d->prv=0;
                   free(d);
                  }
                  }
                    break;
                }
                case 7:{
                    ad *t=strt;
                   if(strt==0){
                    printf("There is no data to show.");
                   } else {
                     while(t!=0){
                        printf("%4d",t->data);
                        t=t->nxt;
                    }
                   }

                    break;
                }
                case 8:{
                    exit(0);
                }
                case 9:{
                    strt= 0;
                    main();
                }
                default :{
                        printf("you have enterd a wrong input!!\n");
                }
            }
    }
    return 0;
}