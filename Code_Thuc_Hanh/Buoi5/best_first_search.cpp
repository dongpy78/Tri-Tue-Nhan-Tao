#include <stdio.h>
#include <stdlib.h>
#define MTK "input.txt"
#define H "input2.txt"
#include <limits.h>
#define MAX 100

FILE * fp;
int sodinh;
int mtk[MAX][MAX];
int h[MAX];

void inmatran(int mt[MAX][MAX], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      printf("%d ", mt[i][j]);
    }
  printf("\n");
  }
    
}

void inmang(int m[], int size) {
  for(int i =0; i < size; i++)
    printf("%d  ", m[i]);
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

void init_1(int m[], int size, int value) {
  for(int i = 0; i < size; i++)
    m[i] = value; // 
}

void swap(int *x, int *y) {
  int tam = *x;
  *x = *y;
  *y = tam;
}

void BestFirshSearch(int start, int goal) {
  int n;
  int OPEN[MAX];
  int CLOSE[MAX];
  int OPENED[MAX];
  int Tn[MAX]; // Mảng lưu trữ đỉnh cha

  // Khởi tạo cho CLOSE và Tn
  for(int i = 0; i < sodinh; i++) {
    CLOSE[i] = i;
    OPENED[i] = i;
    Tn[i] = -1; // Khởi tạo đỉnh cha của mỗi đỉnh là -1
  }

  int dem = 0; // Kiểm tra số lượng còn lại trong OPEN
  OPEN[dem++] = start;
  
  while (dem > 0) {
    n = OPEN[--dem];
    CLOSE[n] = -1;
    OPENED[n] = -1;
    printf("\nDinh dang xet %d", n);

    if(n == goal) {
      printf("\nTim thay duong di tu %d den %d: ", start, goal);
      // In ra đường đi từ start đến goal
      int path[MAX];
      int count = 0;
      int current = goal;
      while (current != start) {
        path[count++] = current;
        current = Tn[current];
      }
      path[count++] = start;
      for (int i = count - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) {
          printf(" -> ");
        }
      }
      break;
    }
    else {
      // Tìm các đỉnh kề của n
      for(int i = 0; i < sodinh; i++) {
        if(mtk[n][i] == 1 && OPENED[i] != -1 && CLOSE[i] != -1) {
          OPEN[dem++] = i;
          OPENED[i] = -1;
          Tn[i] = n; // Cập nhật đỉnh cha của i là n
        }
      }
      // Sắp xếp OPEN theo thứ tự giảm dần của h[OPEN[i]]
      printf("\nCLOSE[]: "); inmang(CLOSE, sodinh);
      printf("\nOPENED[]: "); inmang(OPENED, sodinh);
      printf("\nOPEN[] truoc SX: "); inmang(OPEN, dem);
      for(int i = 0; i < dem-1; i++) {
        for(int j = i + 1; j < dem; j++) {
          if(h[OPEN[i]] < h[OPEN[j]]) {
            swap(&h[OPEN[i]], &h[OPEN[j]]);
            swap(&OPEN[i], &OPEN[j]);
          }
        }
      }
      printf("\nOPEN[] sau SX: "); inmang(OPEN, dem);
    }
  }  
}

int main() {
  system("cls");
  readfile_mtk();
  printf("\nMa tran thu 2:\n");
  readfile_h();
  BestFirshSearch(0, 1);
}





void BestFirshSearch(int start, int goal) {
  int n;
  int OPEN[MAX];
  int CLOSE[MAX];
  int OPENED[MAX];
  int Tn[MAX]; // Mảng lưu trữ đỉnh cha

  // Khởi tạo cho CLOSE và Tn
  for(int i = 0; i < sodinh; i++) {
    CLOSE[i] = i;
    OPENED[i] = i;
    Tn[i] = -1; // Khởi tạo đỉnh cha của mỗi đỉnh là -1
  }

  int dem = 0; // Kiểm tra số lượng còn lại trong OPEN
  OPEN[dem++] = start;
  
  while (dem > 0) {
    n = OPEN[--dem];
    CLOSE[n] = -1;
    OPENED[n] = -1; 

    if(n == goal) {
      // In ra đường đi từ start đến goal
      int path[MAX];
      int count = 0;
      int current = goal;
      while (current != start) {
        path[count++] = current;
        current = Tn[current];
      }
      path[count++] = start;
      for (int i = count - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) {
          printf(" -> ");
        }
      }
      break;
    }
    else {
      // Tìm các đỉnh kề của n
      for(int i = 0; i < sodinh; i++) {
        if(mtk[n][i] == 1 && OPENED[i] != -1 && CLOSE[i] != -1) {
          OPEN[dem++] = i;
          OPENED[i] = -1;
          Tn[i] = n; // Cập nhật đỉnh cha của i là n
        }
      }
     
      for(int i = 0; i < dem-1; i++) {
        for(int j = i + 1; j < dem; j++) {
          if(h[OPEN[i]] < h[OPEN[j]]) {
            swap(&h[OPEN[i]], &h[OPEN[j]]);
            swap(&OPEN[i], &OPEN[j]);
          }
        }
      }
    }
  }  
}







