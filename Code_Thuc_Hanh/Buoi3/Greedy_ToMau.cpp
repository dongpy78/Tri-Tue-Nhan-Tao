#include <stdio.h>
#define INPUT "input2.txt"
#define MAX 100
#include <limits.h>

FILE* fp;

int sodinh;
int mtk[MAX][MAX];
int bacdt[MAX];
int V[MAX];
int COLOR[MAX];

void inmt(int mt[][MAX], int size) {
  for (int i = 0; i < size; i++) {
    printf("\n");
    for (int j = 0; j < size; j++) 
      printf("%d ", mt[i][j]);    
  } 
}

void readfile() {
  fp = fopen(INPUT, "r");
  if (fp == NULL) {
    printf("File not found");
    return; 
  } else {
    fscanf(fp, "%d", &sodinh);
    for (int i = 0; i < sodinh; i++)
      for (int j = 0; j < sodinh; j++) 
        fscanf(fp, "%d", &mtk[i][j]);      
    fclose(fp);
  }
  
  // Print values
  printf("So dinh cua ma tran la: %d", sodinh);
  inmt(mtk, sodinh);
}

void inmang(int m[], int size) {
  for(int i = 0; i < size; i++) printf("%3d", m[i]);
}


void init(int m[], int size, int value) {
  for(int i = 0; i < size; i++) 
    m[i] = value;  
}

void bacdothi() {
  init(bacdt, sodinh, 0);
  // tinh bac cua dinh
  for(int i = 0; i < sodinh; i++) {
    int count = 0;
    for(int j = 0; j < sodinh; j++) {
      if(mtk[i][j] == 1) {
        count++;
      }
    }
  bacdt[i] = count;
  }
  printf("\nBac cua dinh: "); inmang(bacdt, sodinh);
}

int timmax(int m[], int size) {
  int max = m[0];
  int posmax = 0;
  for(int i = 1; i < size; i++) 
    if(max < m[i]) {
      max = m[i];
      posmax = i;
    }
  return posmax;
}

void tomau() {
  int max;
  for(int i = 0; i < sodinh; i++) {
    V[i] = i;
  }
  printf("\nCac thanh pho can to mau: "); inmang(V, sodinh);
  // tao mang color chua cac gia tri mau cua thanh pho
  init(COLOR, sodinh, 0);
  for(int color = 1; color <= 3; color++) {
    // tim dinh co bac do thi lon nhat, to mau color cho max
    max = timmax(bacdt, sodinh);
    printf("\nThanh pho co bac dt = max: %d", V[max]);
    COLOR[max] = color;
    // to mau cho cac dinh ke cua V[MAX]
    for(int i = 0; i < sodinh; i++) {
      if(mtk[V[max]][i] == 0 && COLOR[i] == 0) {
        for(int j = 0; j < sodinh; j++) {
          if(mtk[i][j] == 0)
          COLOR[V[i]] = color;
        }
        bacdt[V[max]] = INT_MIN;
      }
    }
  printf("\nCOLOR[]: "); inmang(COLOR, sodinh);
  }
  // gan gia tri cua dinh co bac lon nhat thanh vo cung be
}

int main() {
  readfile();
  bacdothi();
  tomau();
  return 0;
}
