#include <stdio.h>
#include <stdlib.h>
#define INPUT "BFS1.txt"
#define MAX 20

int a[MAX][MAX];
int sodinh = 0;

void inmt(int mt[][MAX], int size) {
    for (int i = 0; i < size; i++) {
        printf("\n");
        for (int j = 0; j < size; j++)
            printf("%3d", mt[i][j]);
    }
}

void readfile() {
    FILE *fp = fopen(INPUT, "r");
    if (fp == NULL) {
        printf("File not found");
        exit(1);
    } else {
        fscanf(fp, "%d", &sodinh);
        printf("So dinh cua do thi: %d\n", sodinh);
        for (int i = 0; i < sodinh; i++)
            for (int j = 0; j < sodinh; j++)
                fscanf(fp, "%d", &a[i][j]);
        printf("Ma tran ke:\n");
        inmt(a, sodinh);
        fclose(fp);
    }
}

void init(int m[], int size, int value) {
    for (int i = 0; i < size; i++) {
        m[i] = value;
    }
}

void inmang(int m[], int size) {
    for (int j = 0; j < size; j++)
        printf("%3d", m[j]);
}

void BreathFirstSearch(int start, int goal) {
    int OPEN[MAX];
    int CLOSE[MAX];
    int Tn[MAX];
    int Parent[MAX];
    int n;
    int dem = 0;

    init(CLOSE, sodinh, 0);
    init(Tn, sodinh, 0);
    init(Parent, sodinh, -1);

    OPEN[dem] = start;
    Tn[start] = -1;
    Parent[start] = -1;

    while (dem >= 0) {
        n = OPEN[0];
        for (int j = 0; j < dem; j++) {
            OPEN[j] = OPEN[j + 1];
        }
        CLOSE[n] = -1;
        if (n == goal) {
            printf("\nTim thay duong di tu %d -> %d: ", start, goal);
            int path[sodinh];
            int len = 0;
            for (int i = goal; i != -1; i = Parent[i]) {
                path[len++] = i;
            }
            for (int i = len - 1; i >= 0; i--) {
                printf("%3d", path[i]);
            }
            return;
        } else {
            for (int i = 0; i < sodinh; i++) {
                if (a[n][i] == 1 && CLOSE[i] != -1 && Tn[i] == 0) {
                    OPEN[dem++] = i;
                    Tn[i] = -1;
                    Parent[i] = n;
                }
            }
            dem--;
        }
        if (dem < 0) {
            printf("\nKhong tim thay duong di tu %d den %d", start, goal);
        }
    }
}

int main() {
    readfile();
    BreathFirstSearch(0, 5);
    return 0;
}
