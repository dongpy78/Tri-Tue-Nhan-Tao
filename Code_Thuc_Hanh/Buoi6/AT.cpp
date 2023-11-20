#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MTK "input.txt"
#define H "input2.txt"
#define MAX 100

FILE * fp;
int mtk[MAX][MAX];
int h[MAX];
int sodinh;

void inmang(int m[], int size) {
  for(int i =0; i < size; i++)
    printf("%d  ", m[i]);
}

void inmatran(int mt[MAX][MAX], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      printf("%d ", mt[i][j]);
    }
  printf("\n");
  }    
}

void readfile_mtk() { // doc va luu ma tran ke cua do thi
  fp = fopen(MTK, "r");
  if(fp == NULL) printf("File not found");
  else {
    // doc so dinh
    fscanf(fp, "%d", &sodinh);
    printf("So dinh cua do thi: %d", sodinh);
    // doc ma tran ke
    for(int i = 0; i < sodinh; i++) 
      for(int j = 0; j < sodinh; j++)
        fscanf(fp, "%d", &mtk[i][j]);
    // in ra ma tran ke
    printf("\nMa tran ke: \n");
    inmatran(mtk, sodinh);
    fclose(fp);
  }
}

void readfile_h() {
  fp = fopen(H, "r");
  if (fp == NULL) {
    printf("\nFile not found");
    return; 
  } else {
    // doc so cong viec can hoan thanh
    fscanf(fp, "%d", &sodinh);
    for(int i = 0; i < sodinh; i++) {
      fscanf(fp, "%d", &h[i]);    
  }  
  // Print values
  printf("%d \n", sodinh);
  inmang(h, sodinh);
    fclose(fp);
  }
}

void AT(int start, int goal) {
  int n;
  int OPEN[MAX];
  int CLOSE[MAX]; // dinh da xet
  int Tn[MAX]; // dinh tiem nang
  int OPENED[MAX];
  int g[MAX]; // tap cac gia tri tu i -> j
  int dem = 0;
  int CHA[MAX];
  // khoi tao
  for(int i = 0; i < sodinh; i++) {
    CLOSE[i] = i;    
    OPENED[i] = i;
    g[i] = 0;
    CHA[i] = -1;
  }
  OPEN[dem++] = start;
  g[start] = 0;
  while(dem >= 0) {
    n = OPEN[--dem];
    printf("\nDinh dang xet: %d", n);
    OPENED[n] = -1;
    CLOSE[n] = -1;
    if(n == goal) {
      printf("\nTim thay duong di tu %d den %d", start, goal);
      printf("\nCHA[]: "); inmang(CHA, sodinh);
      int len = 0;
      int duongdi[MAX];
      for(int i = goal; i != -1; i = CHA[i]) {
        duongdi[len++] = i;
      }
      // in ra duong di tu start - goal
      printf("\nDuong di: ");
      for(int i = len-1; i >= 0; i--) {
        printf("--> %d ", duongdi[i]);
      }
      return;
    }
    for(int i = 0; i < sodinh; i++) {
      if(mtk[n][i] == 1 && OPENED[i] != -1 && CLOSE[i] != -1) {
        g[i] = g[n] + h[i];
        Tn[dem] = g[i];
        OPENED[i] = -1;
        OPEN[dem++] = i;
        CHA[i] = n;
      }
    }

    printf("\nCLOSE[]: "); inmang(CLOSE, sodinh);
    printf("\nOPEN[]: "); inmang(OPEN, dem);
    printf("\nOPENED[]: "); inmang(OPENED, sodinh);
    printf("\ng[]: "); inmang(g, sodinh);
    printf("\nTn[]: "); inmang(Tn, dem);

    for(int i = 0; i < dem - 1; i++) {
      for(int j = i + 1; j < dem ;j++) {
        if(Tn[i] < Tn[j]) {
          int tam = Tn[i];
          Tn[i] = Tn[j];
          Tn[j] = tam;

          tam = OPEN[i];
          OPEN[i] = OPEN[j];
          OPEN[j] = tam;
        }
      }
    }
    
    // in lai danh sach
    printf("\nOPEN_sort: "); inmang(OPEN, dem);    
  }
  printf("\nKhong tim thay duong di tu %d den %d", start, goal);  
}

int main() {
  system("cls");    
  readfile_mtk();
  readfile_h();
  AT(0, 1);
  return 0;
}


