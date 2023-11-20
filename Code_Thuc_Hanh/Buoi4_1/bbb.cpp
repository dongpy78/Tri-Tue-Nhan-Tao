#include<stdio.h>
#include<limits.h>
#define INPUT "intput1.txt"
//#define INPUT "Xeplich2.inp"
//#define INPUT "Xeplich3.inp"
//#define INPUT "Xeplich4.inp"
#define MAX 100

//khai bao bien
FILE *fp;
int numjob;
int nummc;
int T[MAX];//thoi gian thuc hien cac cong viec
int M[MAX];//so may can thuc hien
int J[MAX];//so cong viec can thuc hien

void inmang(int m[], int size){
	for(int i=0;i<size;i++){
		printf("%d  ",m[i]);
	}
}

void readfile(){
	fp = fopen(INPUT,"r");
	if(fp==NULL){
		printf("\nFile not Found");
	}
	else{
		//doc so cong cong viec can hoan thanh
		fscanf(fp,"%d",&numjob);
		//do thong tin so may can thuc hien
		fscanf(fp,"%d",&nummc);
		//doc thong tin thoi gian hoan thanh cua moi cong viec
		for(int i=0;i<numjob;i++){
			fscanf(fp,"%d",&T[i]);
		}
		fclose(fp);
	}
	//in ra cac gia tri
	printf("%d ",numjob);
	printf("%d\n",nummc);
	inmang(T,numjob);
}

void init(int m[], int size){
	for(int i=0;i<size;i++){
		m[i]=i;
	}
}

void init2(int m[], int size, int value){
	for(int i=0;i<size;i++){
		m[i]=value;
	}
}

void swap(int *x, int *y){
	int tam = *x;
	*x=*y;
	*y=tam;
}

void sort(){
	for(int i=0; i<numjob-1; i++){
		for(int j=i+1; j<numjob; j++){
			if(T[i]<T[j]){
				swap(&T[i],&T[j]);
				swap(&J[i],&J[j]);
			}
		}
	}
}

int MIN(int m[], int size){
	int min = m[0];
	int posmin =0;
	for(int i = 1; i<size;i++){
		if(min >m[i]){
			min = m[i];
			posmin = i;
		}
	}
	return posmin;
}

void Xeplich(){
	//khoi tao so luong may can thuc hien
	init2(M,nummc,-1);
	printf("\nSo may can thuc hien: ");inmang(M,nummc);
	//cac cong viec voi thoi gian hoan thanh
	init(J,numjob);
	printf("\nCac cong viec can thuc hien: ");inmang(J,numjob);
	//thoi gian hoan thah cac cong viec tuong ung
	printf("\nThoi gian hoan thanh c.viec: ");inmang(T,numjob);
	printf("\n\n-----------------------------------------------\n");
	//sap xep cac cong viec theo thoi gian giam dan
	sort();
	printf("\nCac cong viec sau khi sap xep: ");inmang(J,numjob);
	printf("\nThoi gian h.thanh sau sap xep: ");inmang(T,numjob);
	//phan cong nummc cong viec vao nummc may
	int dem =0;
	int Tmax = T[0];//T[0] co gia tri MAX sau hi sap xep giam
	for(int i=0;i<nummc;i++){
		M[i] = T[i];//may M[i] = co thoi gian hoan thanh = T[i]
		dem++;
	}
	printf("\nThoi gian cac may sau lan phan cong viec lan dau tien: \n");
	inmang(M,nummc);
	//phan cong viec vao cac may lan dau tien
	while(dem<numjob){
		//tim may co thoi gian hoan thanh be nhat va phan them viec
		int tmin = M[MIN(M,nummc)];//thoi gian hoan thanh be nhat 
		printf("\nMay co thoi gian hoan thanh be nhat: %d",MIN(M,nummc));
		//co the phan nhieu cong viec cho may min
		while(tmin<=Tmax && dem<numjob){//thoi gian cua may min < Tmax va con viec de phan
			M[MIN(M,nummc)] += T[dem]; 
			//in ra trang thai cua cac may sau khi cap nhat lai cong viec
			printf("\nThoi gian hoan thanh cua cac may: ");inmang(M,nummc);
			dem++;
		}
		printf("\ndem=%d",dem);
		Tmax = M[MIN(M,nummc)];
		printf("\nTmax sau khi cap nhat: %d",Tmax);
	}
	printf("\n--------------------------------------------------");
	
	//tim MAX cua thoi gian hoan thanh cac may M[i]
	int max = M[0];
	for(int i=1;i<numjob;i++){
		if(max<M[i]){
			max=M[i];
		}
	}
	printf("\nThoi gian hoan thanh toi da cua cac cong viec la: %d",max);
}



int main(){
	readfile();
	Xeplich();
	return 0;
}