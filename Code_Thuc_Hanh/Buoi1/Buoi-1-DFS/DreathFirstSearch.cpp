// #include <stdio.h>
// #include <fstream>
// #define INPUT "BFS1.txt"
// #define MAX 20

// // bien toan cuc
// int a[MAX][MAX]; // chua ma tran ke cua do thi
// FILE *fp;
// int sodinh;

// // ham thu tuc

// void inmt(int mt[][MAX], int size) {
//   for(int i= 0; i < size; i++) {
//       printf("\n");
//     for(int j = 0; j < size; j++) 
//       printf("%3d", mt[i][j]);
//   }
// }

// void readfile() { // doc va luu ma tran ke cua do thi
//   fp = fopen(INPUT, "r");
//   if(fp == NULL) printf("File not found");
//   else {
//     // doc so dinh
//     fscanf(fp, "%d", &sodinh);
//     printf("So dinh cua do thi: %d", sodinh);
//     // doc ma tran ke
//     for(int i = 0; i < sodinh; i++) 
//       for(int j = 0; j < sodinh; j++)
//         fscanf(fp, "%d", &a[i][j]);
//     // in ra ma tran ke
//     printf("\nMa tran ke: \n");
//     inmt(a, sodinh);
//     fclose(fp);
//   }
// }

// void init(int m[], int size, int value) {
//   for(int i = 0; i < size; i++) {
//     m[i] = value;    
//   }
// }

// void inmang(int m[], int size) {
//   for(int j = 0; j < size; j++)
//     printf("%3d", m[j]);
// }

// void DreathFirstSearch(int start, int goal) {
//   int OPEN[MAX];
//   int CLOSE[MAX];
//   int Tn[MAX]; // dinh lan can cua n
//   int Parent[MAX];
//   int n;
//   int dem = 0; // luu tru so phan tu cua open 

//   // khoi tao cho CLOSE
//   init(CLOSE, sodinh, 0);
//   init(Tn, sodinh, 0);
//   init(Parent, sodinh, -1);

//   OPEN[dem++] = start;
//   Tn[start] = -1;
//   Parent[start] = -1;

//   while(dem != 0) {
//     n = OPEN[dem--];
//     printf("\nDinh dang xet: %d", n);
  
//     // dan nhan cho dinh da xet 
//     CLOSE[n] = -1;

//     if(n == goal) {
//       printf("\nTim thay duong di tu %d -> %d: ", start, goal);
//       // in ra duong di tu mang parent
//       int path[sodinh]; int len = 0;
//       for(int i = goal; i != -1; i = Parent[i]) {
//         path[len++] = i;
//       }
//       // in danh sach cua path
//       for(int i = len-1; i >= 0; i--) printf("%3d", path[i]);
//       return;
//     } else {
//       // Tim cac dinh ke voi dinh dang xet n

//       for(int i = 0; i < sodinh; i++) {
//         if(a[n][i] == 1 && CLOSE[i] != -1 && Tn[i] == 0) {
//           // chen vao cuoi danh sach
//           OPEN[dem++] = i;
//           // dinh sau khi chen vao OPEN thi gan Tn[i] = -1
//           Tn[i] = -1;
//           // gan nut cha cho dinh i
//           Parent[i] = n;


//         }
//       }
//       printf("\nOPEN");
//       inmang(OPEN, dem);
//       printf("\nCLOSE");
//       inmang(CLOSE, sodinh);
//       printf("\nTn");
//       inmang(Tn, sodinh);
     
//       printf("\nParent");
//       inmang(Parent, sodinh);  
//       dem--;
//     }
//     if(dem < 0) printf("\nKhong tin thay duong di tu %d den %d", start, goal);
//   }
// }

// int main() {
//   readfile();
//   DreathFirstSearch(0, 5);
//   return 0;
// }


#include <stdio.h>
#include <fstream>
#define INPUT "DFS1.txt"
#define MAX 20

// biến toàn cục
int a[MAX][MAX]; // chứa ma trận kề của đồ thị
FILE *fp;
int sodinh;

// hàm thủ tục

void inmt(int mt[][MAX], int size) {
  for(int i = 0; i < size; i++) {
    printf("\n");
    for(int j = 0; j < size; j++) 
      printf("%3d", mt[i][j]);
  }
}

void readfile() {
  fp = fopen(INPUT, "r");
  if(fp == NULL) printf("File not found");
  else {
    // đọc số đỉnh
    fscanf(fp, "%d", &sodinh);
    printf("So dinh cua do thi: %d", sodinh);
    // đọc ma trận kề
    for(int i = 0; i < sodinh; i++) 
      for(int j = 0; j < sodinh; j++)
        fscanf(fp, "%d", &a[i][j]);
    // in ra ma trận kề
    printf("\nMa tran ke: \n");
    inmt(a, sodinh);
    fclose(fp);
  }
}

void init(int m[], int size, int value) {
  for(int i = 0; i < size; i++) {
    m[i] = value;    
  }
}

void inmang(int m[], int size) {
  for(int j = 0; j < size; j++)
    printf("%3d", m[j]);
}

void DepthFirstSearch(int start, int goal) {
  int OPEN[MAX];
  int CLOSE[MAX];
  int Tn[MAX]; // đỉnh láng giềng của n
  int Parent[MAX];
  int n;
  int dem = 0; // lưu trữ số phần tử của open 

  // khởi tạo cho CLOSE
  init(CLOSE, sodinh, 0);
  init(Tn, sodinh, 0);
  init(Parent, sodinh, -1);

  OPEN[dem++] = start;
  Tn[start] = -1;
  Parent[start] = -1;

  while(dem != 0) {
    n = OPEN[--dem];
    // printf("\nDinh dang xet: %d", n);
  
    // đánh dấu cho đỉnh đã xét 
    CLOSE[n] = -1;

    if(n == goal) {
      printf("\nTim thay duong di tu %d -> %d: ", start, goal);
      // in ra đường đi từ mảng parent
      int path[MAX];
      int len = 0;
      for(int i = goal; i != -1; i = Parent[i]) {
        path[len++] = i;
      }
      // in danh sách của path
      for(int i = len-1; i >= 0; i--) {
        printf("%3d", path[i]);
      }
      return;
    } else {
      // Tìm các đỉnh kề với đỉnh đang xét n
      for(int i = 0; i < sodinh; i++) {
        if(a[n][i] == 1 && CLOSE[i] != -1 && Tn[i] == 0) {
          // chèn vào cuối danh sách
          OPEN[dem++] = i;
          // đánh dấu sau khi chèn vào OPEN thì gán Tn[i] = -1
          Tn[i] = -1;
          // gán nút cha cho đỉnh i
          Parent[i] = n;
        }
      }
    }

    // printf("\nOPEN");
    // inmang(OPEN, dem);
    // printf("\nCLOSE");
    // inmang(CLOSE, sodinh);
    // printf("\nTn");
    // inmang(Tn, sodinh);
    // printf("\nParent");
    // inmang(Parent, sodinh);  
  }
  printf("\nKhong tim thay duong di tu %d den %d", start, goal);
}

int main() {
  readfile();
  DepthFirstSearch(0, 5);
  return 0;
}
