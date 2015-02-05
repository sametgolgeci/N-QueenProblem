#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
 
    void push(int *,int *,int stack[][2],int tahta[][20]);
    void pop(int *,int *,int stack[][2],int tahta[][20]);
   
    int i,j,k,l,N,dolu,stack[20][2],tahta[20][20],hata;
    
    printf("N sayısını giriniz?\n");
    scanf("%d",&N);
    
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            tahta[i][j]=0;
        }
    }
    j=0;
    dolu=0;
    hata=0;
    
    while (dolu<N) {
        if (j<N) {
            hata=0;
            for (k=0; k<N; k++) {
                if (tahta[dolu][k]==1) {
                    hata++;
                }
                if (tahta[k][j]==1) {
                    hata++;
                }
            }
            k=dolu;
            l=j;
            while ((k<N)&&(l<N)) {
                if (tahta[k][l]==1) {
                    hata++;
                }
                k=k+1;
                l=l+1;
            }
            k=dolu;
            l=j;
            while ((k>-1)&&(l>-1)) {
                if (tahta[k][l]==1) {
                    hata++;
                }
                k=k-1;
                l=l-1;
            }
            k=dolu;
            l=j;
            while ((k<N)&&(l>-1)) {
                if (tahta[k][l]==1) {
                    hata++;
                }
                k=k+1;
                l=l-1;
            }
            k=dolu;
            l=j;
            while ((k>-1)&&(l<N)) {
                if (tahta[k][l]==1) {
                    hata++;
                }
                k=k-1;
                l=l+1;
            }
            if (hata==0) {
                push(&j,&dolu,stack,tahta);
            }
            else
            {
                j=j+1;
            }
        }
        else
        {
            pop(&j,&dolu,stack,tahta);
        }
    }
    
    
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            printf("%d ",tahta[i][j]);
        }
        printf("\n");
    }
    
    for (i=0; i<N; i++) {
        printf("Stack[%d]=%d\n",i,*stack[i]);
    }

    return 0;
}

    void push(int *j,int *dolu,int stack[][2],int tahta[][20]){
        tahta[*dolu][*j]=1;
        stack[*dolu][0]=*j;
        *j=0;
        *dolu=*dolu+1;
        return;
}
    void pop(int *j,int *dolu,int stack[][2],int tahta[][20]){
   
        *dolu=*dolu-1;
        *j=stack[*dolu][0];
        tahta[*dolu][*j]=0;
        *j=*j+1;
        return;
}
