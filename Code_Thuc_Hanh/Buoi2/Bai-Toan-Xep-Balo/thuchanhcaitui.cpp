#include<stdio.h>
#define INPUT "caitui2.txt"
#define MAX 50
// bien toan cuc
FILE *fp;
int sodovat;
int Pmax;
int VW[MAX];
int V[MAX]; // gia tri cua cac do vat
int W[MAX]; // trong luong
float CS[MAX];// CS = V/W;
int dem=0;

void i_swap(int *x, int *y){
    int tam=*x; *x=*y; *y=tam;
}
void f_swap(float *x, float *y){
    float tam=*x; *x=*y; *y=tam;
}
void inmang(int m[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", m[i]);
    }
}

void init(int mang[], int size, int value){
    for(int i=0; i<size; i++){
        mang[i]=value;
    }
}
void read(){
    fp = fopen(INPUT, "r");
    if(fp== NULL){
        printf("Not");
        return;
    }
    else{
        fscanf(fp, "%d", &sodovat);
        fscanf(fp, "%d", &Pmax);
        for(int i=0; i<sodovat*2; i++){
            fscanf(fp, "%d", &VW[i]);
        }
        // tach VW thanh V va W
        
        for(int i=0; i<sodovat*2; i=i+2){
            W[dem]=VW[i];V[dem]=VW[i+1];
            CS[dem]=(float)V[dem]/W[dem];
            dem++;
        }
        fclose(fp);
    }
    // in ra cac gia tri
    printf("So do vat cho truoc: %d", sodovat);
    printf("\nTrong luong toi da: %d", Pmax);
    printf("\nGia tri cua do vat: "); inmang(V, sodovat);
    printf("\nTrong luong cua do vat: "); inmang(W, sodovat);
    printf("\nCS= V/W: ");
    for(int i=0; i<dem; i++){
        printf("%.2f ", CS[i]);
    }
}
void Greedy_CaiTui(){
    for(int i=0; i<sodovat-1; i++){
        for(int j=i+1; j<sodovat; j++){
            if(CS[i]<CS[j]){
                f_swap(&CS[i], &CS[j]);
                i_swap(&V[i], &V[j]);
                i_swap(&W[i], &W[j]);
            }
        }
    }
    printf("\nMang sau khi sap xep: ");
    printf("\nV[]: "); inmang(V, sodovat);
    printf("\nW[]: "); inmang(W, sodovat);

    // in ra gia tri toi da mang theo
    int bestvalue=0;
    int bestweight=0;
    int vet[MAX];
    init(vet, sodovat, 0);

    for(int i=0; i<sodovat; i++){
        if(Pmax>= W[i]){
            Pmax -= W[i];
            bestvalue+=W[i];
            bestweight+=W[i];
            vet[i]=-1;
        }
    }
    printf("\nTrong luong toi da co the mang theo: %d", bestweight);
    printf("\nGia tri toi da co the mang theo: %d", bestvalue);
    printf("\nCac mon do da duoc cho vao balo: V[] W[]");
    for(int i=0; i<sodovat; i++){
        if(vet[i]==-1){
            printf("\nV[%d]: %d ", i, V[i]);
            printf("\nW[%d]: %d ", i, W[i]);
        }
    }
}
int main(){
    read();
    Greedy_CaiTui();
}