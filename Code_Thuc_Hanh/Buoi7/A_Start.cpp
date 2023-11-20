#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MTK "input1.txt"
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

void Astart(int start, int goal){
	int OPEN[MAX];
	int CLOSE[MAX];
	int OPENED[MAX];
	int g[MAX]; //tap chi phi den thoi diem hien tai
	int f[MAX];
  int CHA[MAX];
	
	//khoi tao tao cac gtri
	for(int i=0; i<sodinh; i++){
		CLOSE[i]=i;
		OPENED[i]=i;
		g[i]=0;
		f[i]=0;
	} 
	int dem=0;//dem la so luong cac dinh con lai
	OPEN[dem++]=start;//dem=1 OPEN[0]=start
	
	while(dem>=0){//con dinh trong OPEN con xet
		int n=OPEN[--dem];//
		printf("\ndinh dang xet: %d", n);
		CLOSE[n]=-1;
		OPENED[n]=-1;
		g[n]=0;
		f[n]=h[n];
		
		if(n==goal){
			printf("\ntim thay duong di tu %d -> %d", start, goal);
      printf("\nCHA[]: "); inmang(CHA, sodinh);
      int duongdi[MAX];
      int len = 0;
      for(int i = goal; i != -1; i=CHA[i]) {
        duongdi[len++] = i;
      }
      for(int i = len-1; i >= 0; i--) {
        printf("%d ->", duongdi[i]);
      }
			return;
		}
		//nguo lai ta di xet cac dinh ke cua n
		for(int i=0; i<sodinh; i++){
			if(mtk[n][i]!=0){
				g[i]=g[n]+mtk[n][i];
				f[i]=g[i]+h[i];
				OPENED[i]=-1;
			}
		}
		//xet co j (dinh) nao thuoc OPENED[] nam trong OPEn
		for(int i=0; i<sodinh; i++){
			for(int j=0; j<dem; j++){
				if(OPENED[i]==-1 && OPEN[j]==OPENED[i]){//i thuoc ve OPENED
					if(f[i]<f[j]){
						//cap nhat lai gtri cua g, f
						g[j]=g[i];
						f[j]=f[i];
					}
				}
			}
		}
		//xet co dinh j nao thuoc CLOSE nam trong OPENED
		for(int i=0; i<sodinh; i++){//OPENDED
			for(int j=0; j<dem; j++){//CLOSE
				if(OPENED[i]==-1 && CLOSE[j]==-1 && OPENED[i]==CLOSE[j]){
					if(f[i]<f[j]){
						g[j]=g[i];
						f[j]=f[i];
					}
				}
			}
		}
		//
		for(int i=0; i<sodinh; i++){
			if(mtk[n][i]!=0 && OPENED[i]==-1 && CLOSE[i]!=-1 && OPEN[i]!=i){
				OPEN[dem++]=i;
        CHA[i] = -1;
			}
		}
		//in ra man hinh ca gtri
		printf("\nOPEN[]: "); inmang(OPEN, dem);
		printf("\nCLOSE[]: "); inmang(CLOSE, sodinh);
		printf("\nOPENED[]: "); inmang(OPENED, sodinh);
		printf("\nh[]: "); inmang(h, sodinh);
		printf("\ng[]: "); inmang(g, sodinh);
printf("\nf[]: "); inmang(f, sodinh);
		//sap xep open theo thu tu giam dan
		for(int i=0; i<dem; i++){
			for(int j=i+1; j<dem; j++){
				if(f[OPEN[i]]<f[OPEN[i]]){
					int tam=OPEN[i];
					OPEN[i]=OPEN[j];
					OPEN[j]=OPEN[tam];
				}
			}
		}
		printf("\nOPEN_sort[]: "); inmang(OPEN, dem);
	}
}
int main() {
  readfile_mtk();
  readfile_h();
  Astart(0,10);
  return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MTK "input1.txt"
#define H "input2.txt"
#define MAX 100

FILE * fp;
int mtk[MAX][MAX];
int h[MAX];
int sodinh;
int CHA[MAX];

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

void Astart(int start, int goal){
	int OPEN[MAX];
	int CLOSE[MAX];
	int OPENED[MAX];
	int g[MAX]; //tap chi phi den thoi diem hien tai
	int f[MAX];
	
	//khoi tao tao cac gtri
	for(int i=0; i<sodinh; i++){
		CLOSE[i]=i;
		OPENED[i]=i;
		g[i]=0;
		f[i]=0;
	} 
	int dem=0;//dem la so luong cac dinh con lai
	OPEN[dem++]=start;//dem=1 OPEN[0]=start
	
	while(dem>=0){//con dinh trong OPEN con xet
		int n=OPEN[--dem];//
		printf("\ndinh dang xet: %d", n);
		CLOSE[n]=-1;
		OPENED[n]=-1;
		g[n]=0;
		f[n]=h[n];
		
		if(n==goal){
			printf("\ntim thay duong di tu %d -> %d", start, goal);
      printf("\nCHA[]: "); inmang(CHA, sodinh);
      int duongdi[MAX];
      int len = 0;
      for(int i = goal; CHA[i] != -1; i=CHA[i]) {
        duongdi[len++] = i;
      }
      duongdi[len++] = start;
      for(int i = len-1; i >= 0; i--) {
        printf("%d ->", duongdi[i]);
      }
			return;
		}
		//nguo lai ta di xet cac dinh ke cua n
		for(int i=0; i<sodinh; i++){
			if(mtk[n][i]!=0){
				g[i]=g[n]+mtk[n][i];
				f[i]=g[i]+h[i];
				OPENED[i]=-1;
        CHA[i] = n;
			}
		}
		
		for(int i=0; i<sodinh; i++){
			if(mtk[n][i]!=0 && OPENED[i]==-1 && CLOSE[i]!=-1 && OPEN[i]!=i){
				OPEN[dem++]=i;
			}
		}

	
		
		printf("\nOPEN[]: "); inmang(OPEN, dem);
		printf("\nCLOSE[]: "); inmang(CLOSE, sodinh);
		printf("\nOPENED[]: "); inmang(OPENED, sodinh);
		printf("\nh[]: "); inmang(h, sodinh);
		printf("\ng[]: "); inmang(g, sodinh);
		printf("\nf[]: "); inmang(f, sodinh);
		
		for(int i=0; i<dem; i++){
			for(int j=i+1; j<dem; j++){
				if(f[OPEN[i]]<f[OPEN[j]]){
					int tam=OPEN[i];
					OPEN[i]=OPEN[j];
					OPEN[j]=tam;
				}
			}
		}
		printf("\nOPEN_sort[]: "); inmang(OPEN, dem);
	}
}

int main() {
  readfile_mtk();
  readfile_h();
  Astart(0,10);
}

