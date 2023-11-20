#include <stdio.h>
#include <stdlib.h> 
#define INPUT "doi_tien_2.txt"
#define MAX 50

// Biến toàn cục
FILE* fp;
int soto;
int sotien;
int money[MAX];
int flag[20];

void inmang(int m[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", m[i]); 
  }
  printf("\n"); 
}

void readfile() {
  fp = fopen(INPUT, "r");
  if (fp == NULL) {
    printf("File not found");
    return; 
  }
  fscanf(fp, "%d", &sotien);
  fscanf(fp, "%d", &soto);
  for(int i = 0; i < soto; i++) {
    fscanf(fp, "%d", &money[i]);
  }
  fclose(fp); 
  printf("So tien can doi: %d\n", sotien); 
  printf("So to can doi: %d\n", soto);
  inmang(money, soto);
}

void swap(int *x, int *y) {
  int tam = *x;
  *x = *y;
  *y = tam;
}

void sap_xep_giam(int mang[], int size) {
  for(int i = 0; i < size-1; i++)
    for(int j = i+1; j < size; j++)
      if(mang[i] < mang[j]) swap(&mang[i], &mang[j]);
}

void Greedy_Doitien() {
  sap_xep_giam(money, soto);
  printf("\nMenh gia cac to tien: ");
  inmang(money, soto);
  for(int i = 0; i < soto; i++) {
    if(sotien >= money[i]) {
      flag[i] = 1;
      // printf("\nSo tien con lai: %d", sotien);
      sotien -= money[i];
    }
  } 
  if(sotien > 0) printf("\nKhong doi duoc tien: ");
  else {
    printf("\nCac to tien sau khi doi la: ");
    for(int j = 0; j < soto; j++) {
      // printf("\n");
      
      if(flag[j] == 1) printf("%3d", money[j]);
    } 
  }   
}

int main() {
  readfile();
  Greedy_Doitien(); // Gọi hàm Greedy_Doitien để tìm số tờ tiền cần thiết
  return 0;
}
