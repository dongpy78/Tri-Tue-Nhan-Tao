#include <stdio.h>
#include <limits.h>
#define MAX 100

FILE *fp;
int sodinh;
int mtk[MAX][MAX];
int h[MAX];

void inmatran(int mt[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }
}

void inmang(int m[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d  ", m[i]);
}

void readfile_mtk() {
    fp = fopen("input2.txt", "r"); // Use the filename directly
    if (fp == NULL)
        printf("File not found");
    else {
        fscanf(fp, "%d", &sodinh);
        printf("So dinh cua do thi: %d\n", sodinh);
        for (int i = 0; i < sodinh; i++)
            for (int j = 0; j < sodinh; j++)
                fscanf(fp, "%d", &mtk[i][j]);
        printf("Ma tran ke:\n");
        inmatran(mtk, sodinh);
        fclose(fp);
    }
}

void readfile_h() {
    fp = fopen("input1.txt", "r"); // Use the filename directly
    if (fp == NULL) {
        printf("File not found\n");
        return;
    } else {
        fscanf(fp, "%d", &sodinh);
        for (int i = 0; i < sodinh; i++) {
            fscanf(fp, "%d", &h[i]);
        }
        printf("%d\n", sodinh);
        inmang(h, sodinh);
        fclose(fp);
    }
}

void init_1(int m[], int size, int value) {
    for (int i = 0; i < size; i++)
        m[i] = value;
}

void init_2(int m[], int size) {
    for (int i = 0; i < size; i++)
        m[i] = i;
}

void swap(int *x, int *y) {
    int tam = *x;
    *x = *y;
    *y = tam;
}

void leo_doi(int start, int goal) {
    int OPEN[MAX];
    int CLOSE[MAX];
    int Tn[MAX];
    int OPENED[MAX];
    int PARENT[MAX];
    int n;
    int dem = 0;

    init_2(CLOSE, sodinh);
    init_2(OPENED, sodinh);
    init_1(PARENT, sodinh, -1);

    OPEN[dem++] = start;

    while (dem > 0) {
        n = OPEN[--dem];
        // printf("\nDinh dang xet: %d", n);
        CLOSE[n] = -1;
        // printf("\nCLOSE[]: ");
        // inmang(CLOSE, sodinh);
        OPENED[n] = -1;
        // printf("\nOPENED[]: ");
        // inmang(OPENED, sodinh);

        if (n == goal) {
            // printf("\nTim thay duong di tu %d den %d", start, goal);
            // printf("\nPARENT[]: ");
            // inmang(PARENT, sodinh);

            int PATH[MAX];
            int dem_path = 0;
            for (int i = goal; i != -1; i = PARENT[i]) {
                PATH[dem_path++] = i;
            }
            printf("\nPATH[]:");
            for (int i = dem_path - 1; i >= 0; i--) {
                printf("%d", PATH[i]);
            }
            return;
        } 
        else {
            int mang_tam[MAX];
            int dem_tam = 0;
            for (int i = 0; i < sodinh; i++) {
                if (mtk[n][i] == 1 && CLOSE[i] != -1 && OPENED[i] != -1) {
                    mang_tam[dem_tam++] = i;
                    OPENED[i] = -1;
                    PARENT[i] = n;
                }
            }
            for (int i = 0; i < dem_tam - 1; i++)
                for (int j = i + 1; j < dem_tam; j++)
                    if (h[mang_tam[i]] < h[mang_tam[j]]) {
                        swap(&mang_tam[i], &mang_tam[j]);
                    }
            for (int i = 0; i < dem_tam; i++) {
                OPEN[dem++] = mang_tam[i];
            }
            // printf("\nOPEN[]: ");
            // inmang(OPEN, dem);
        }
    }
    printf("\nKhong tim thay duong di");
}

int main() {
    readfile_mtk();
    readfile_h();
    leo_doi(0, 8);

    return 0; // Add a return statement at the end of main
}








void leo_doi(int start, int goal) {
    int OPEN[MAX];
    int CLOSE[MAX];
    int Tn[MAX];
    int OPENED[MAX];
    int PARENT[MAX];
    int n;
    int dem = 0;

    init_2(CLOSE, sodinh);
    init_2(OPENED, sodinh);
    init_1(PARENT, sodinh, -1);

    OPEN[dem++] = start;

    while (dem > 0) {
        n = OPEN[--dem];        
        CLOSE[n] = -1;        
        OPENED[n] = -1;        

        if (n == goal) {           
            int PATH[MAX];
            int dem_path = 0;
            for (int i = goal; i != -1; i = PARENT[i]) {
                PATH[dem_path++] = i;
            }              
            for (int i = dem_path - 1; i >= 0; i--) {
                printf("%d", PATH[i]);
            }
            return;
        } else {
            int mang_tam[MAX];
            int dem_tam = 0;
            for (int i = 0; i < sodinh; i++) {
                if (mtk[n][i] == 1 && CLOSE[i] != -1 && OPENED[i] != -1) {
                    mang_tam[dem_tam++] = i;
                    OPENED[i] = -1;
                    PARENT[i] = n;
                }
            }
            for (int i = 0; i < dem_tam - 1; i++)
                for (int j = i + 1; j < dem_tam; j++)
                    if (h[mang_tam[i]] < h[mang_tam[j]]) {
                        swap(&mang_tam[i], &mang_tam[j]);
                    }
            for (int i = 0; i < dem_tam; i++) {
                OPEN[dem++] = mang_tam[i];
            }
           
        }
    }
    printf("\nKhong tim thay duong di");
}