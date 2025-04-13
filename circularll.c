//circular linked list.
#include<stdio.h>
#include<stdlib.h>
struct adi {
    int data;
    struct adi *nxt;
};
struct adi* strt=0;
struct adi *crt(){
    struct adi * c = malloc(sizeof(struct adi));
    printf("enter a data :");
    scanf("%d",&c -> data);
    c->nxt=0;
    return c;
}
int main(){
struct adi*a =0;
printf("press 1 for inserttaion from start .\npress 2 for inserttaion from end.\npress 3 for inserttaion from middle .\npress 4 for deletation from start .\npress 5 for deletation from end .\npress 6 for deletation from middle .\npress 7 to Display the deta .\npress 8 for exit.");
int b;
while(1){
printf("\nenter your choice :");
scanf("%d",&b);
switch (b){
    case 1:{
        struct adi *k=crt();
        if(strt==0){
            strt=k;
            k->nxt=strt;
        } else{
            struct adi *r=strt;
            while(
                r->nxt!=strt
            ){
                r=r->nxt;
            }
            r->nxt=k;
            k->nxt=strt;
            strt=k;
        }
    break;
    }
    case 2:{
struct adi *k2=crt();
if(strt==0 ||strt->nxt==0){
    printf("There must be atlest two data to inseart in between!");
} else{
        
            printf("enter the data after which you want to inseart :");
                int e;
                scanf("%d",&e);
                struct adi *f;
                struct adi *g;
                struct adi *h;
                f=strt;
                while(f->nxt!=0 && f->data!=e){
                    f=f->nxt;}
                    if(f==0){
                    printf("data not found!");
                } else{
                        
                        k2->nxt=f->nxt;
                        f->nxt=k2;
        }
    }

        break;
    }
    case 3:{
        struct adi *k3=crt();
            if(strt ==0){
                strt=k3;
                k3->nxt=strt;
            } else{
                struct adi *d3=strt;
                do{
                      d3=d3->nxt;
                }
                while(d3->nxt!=strt);
                    d3->nxt=k3;
                    k3->nxt=strt;
            } 
        break;
    }
    case 4:{
        if(strt==0){
            printf("there is no node to delete.");
        } else{
            struct adi *d4=strt;
            struct adi *r=strt;
            while(
                r->nxt!=strt
            ){
                r=r->nxt;
            }
            r->nxt=strt->nxt;
            strt=strt->nxt;
            d4->nxt=0;
            free(d4);
        }
        break;
    }
    case 5:{
          if(strt==0 && strt->nxt==0){
            printf("There is no node to delete!");
        } else{
            printf("enter the data you want to delete :");
            int p;
            scanf("%d",&p);
            struct adi *h =strt;
            struct adi *g;
            while(h->nxt!=0 && h->nxt->data!=p){
                h=h->nxt;
            }
            if(h ==0){
                printf("data not found!");
            } else{
                g=h->nxt;
                h->nxt=g->nxt;
                free(g);
            }
        }

        break;
    }
    case 6:{if(strt==0){
            printf("there is no node to delete.");
        } else{
            struct adi *d6=strt;
             struct adi *b6;
            while(d6->nxt!=strt){
              b6=d6;
                d6=d6->nxt;
                  
            }
            b6->nxt=strt;
            free(d6);
        }
        

        break;
    }
    case 7:{
        struct adi *d=strt;
    do{
         printf("%4d",d->data);
        d= d->nxt;
    }
    while(d!=strt);
       
        break;
    }
    case 8:{

        return 0;
    }
    default:{
        printf("wrong input!\n");
    }
}
}
    return 0;
}