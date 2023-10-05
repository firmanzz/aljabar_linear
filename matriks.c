#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>

//Operasi Matriks
float determinant(float[][25],float);
void cofactor(float[][25],float);
void transpose(float[][25],float[][25],float);
void inverse();
void matrixmultiply();
int multiplication_scalar_operation();
void multireadmatrix(int[][10],int[][10],int,int,int,int);
void multishowmatrix(int[][10],int,int);
void multiprocessmatrix(int[][10],int[][10],int[][10],int,int,int,int);
void matrixadd(float[][25],float[][25],int,int);
void matrixsub(float[][25],float[][25],int,int);
void matrix_output(float[][25],int,int);
void matrixaddsub();
void determinant_input();
void transpose_input();


int main(){
	int a;
	bool valid = true;

	while(valid == true){
		system("cls");
		printf("==============PROGRAM PERHITUNGAN MATRIKS=============\n");
		printf("1. Menghitung Penjumlahan/Pengurangan matriks\n");
		printf("2. Menghitung Perkalian dua matriks\n");
		printf("3. Menghitung Perkalian scalar\n");
		printf("4. Menghitung Transpose matriks\n");
		printf("5. Menghitung Determinan matriks\n");
		printf("6. Menghitung Invers matriks\n");
		printf("7. Exit\n");
		printf("\nMasukan Pilihan : ");
		scanf("%d",&a);
		switch (a)
		{
			case 1:
				system("cls");
				matrixaddsub();
				break;
			case 2:
				system("cls");
				matrixmultiply();
				break;
			case 3:
				system("cls");
				multiplication_scalar_operation();
				break;
			case 4:
				system("cls");
				transpose_input();
				break;
			case 5:
				system("cls");
				determinant_input();
				break;
			case 6:
				system("cls");
				inverse();
				break;
			case 7:
				exit(false);
			default:
				printf("Input Pilihan Tidak  Sesuai!!!\n");
				break;
		}
	}
}

void transpose_input()
{
	int i,j,n;float a[25][25],b[25][25];
	printf("Perhitungan Transpose Matriks\n");
	printf("Masukan ordo dari matriks : ");
	scanf("%d",&n);
	printf("\nMasukan elemen dari matriks %dX%d :\n",n,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%f",&a[i][j]);
	}
	for (i=0;i<n;i++)
    {
     for (j=0;j<n;j++)
       {
         b[i][j]=a[j][i];
        }
    }
    printf("Matriks Hasil:\n");
    matrix_output(b,n,n);
}

int multiplication_scalar_operation(){
	int i, j, rows, columns, Multiplication[10][10], Number;
    system("cls");
    printf("========================================================\n");
	printf("\tPenghitungan Perkalian Scalar Matriks\n\n");
 	printf("Masukan ordo dari matriks : ");
 	scanf("%d %d", &i, &j);
 
 	printf("\nMasukan elemen dari matriks %dX%d :\n",i,j);
 	for(rows = 0; rows < i; rows++){
   		for(columns = 0;columns < j;columns++){
      		scanf("%d", &Multiplication[rows][columns]);
    	}
  	}
   
 	printf("\nMasukan Scalar :\n");
 	scanf("%d", &Number);
 	  
 	for(rows = 0; rows < i; rows++){
   		for(columns = 0; columns < j; columns++){
      		Multiplication[rows][columns] = Number * Multiplication[rows][columns];    
   	 	}
  	}
 
 	printf("\n Matriks Hasil : \n");
 	for(rows = 0; rows < i; rows++){
   		for(columns = 0; columns < j; columns++){
      		printf("%d \t ", Multiplication[rows][columns]);
    	}
    	printf("\n");
  	}
 	return 0;
}


void determinant_input(){
	float a[25][25],k,d;
	int i,j;
	printf("========================================================\n");
	printf("\tPenghitungan Determinan Matriks\n\n");
	
	printf("Masukan ordo dari matriks : ");
	scanf("%f",&k);
	
	printf("Masukan elemen dari matriks %.0fX%.0f : \n",k,k);
	for (i=0;i<k;i++){
	 for (j=0;j<k;j++)
	   {
	    scanf("%f",&a[i][j]);
	    }
	}
	
	d=determinant(a,k);
	printf("Determinan dari matriks adalah %f",d);
}

void matrixadd(float a[][25],float b[][25],int m, int n){
	int i,j;float integral[25][25];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		integral[i][j]=a[i][j] +b[i][j];
	}
	printf("\nHasil penjumlahan dari kedua matriks adalah \n");

	matrix_output(integral,m,n);
}

void matrixsub(float a[][25],float b[][25],int m, int n){
	int i,j;float integral[25][25];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		integral[i][j]=a[i][j] - b[i][j];
	}
	printf("\nHasil pengurangan dari kedua matriks adalah \n");

	matrix_output(integral,m,n);
}


void matrixaddsub(){
	int i,j,m,n,cho; float a[25][25],b[25][25];
	printf("========================================================\n");
	printf("\tPenjumlahan/Pengurangan Matriks\n\n");
	
	printf("Masukan dimensi dari matriks sebagai MxN : ");
	scanf("%d %d",&m,&n);
	printf("\nMasukan elemen dari matriks pertama\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%f",&a[i][j]);
		}
	}
	printf("\nMasukan elemen dari matriks kedua\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%f",&b[i][j]);
		}
	}
	menu :
	printf("\n1.Hitung Penjumlahan Matriks.\n");
	printf("2.Hitung Pengurangan Matriks.\n");
	printf("3.Back to Menu");
	printf("Masukan Pilihan : ");
	scanf("%d",&cho);

	switch(cho){
		case 1:
			
			matrixadd(a,b,m,n);
			goto menu;
			break;
		case 2:

			matrixsub(a,b,m,n);
			goto menu;
			break;
		case 3:
			main();
		default:
			printf("Input Pilihan Tidak  Sesuai!!!\n");
			break;
	}

}

void inverse(){
	float a[25][25],k,d;
	int i,j;
	printf("========================================================\n");
	printf("\tMencari Invers Matriks\n\n");
	
	printf("Masukan ordo dari matriks : ");
	scanf("%f",&k);
	
	printf("Masukan elemen dari matriks %.0fX%.0f : \n",k,k);
	for (i=0;i<k;i++){
	 for (j=0;j<k;j++){
	    scanf("%f",&a[i][j]);
	    }
	}
	
	d=determinant(a,k);
	printf("Determinan dari matriks adalah = %f",d);
	if (d==0){
		printf("\nMatriks tidak memiliki invers\n");
	}
	else{
		cofactor(a,k);
	}

}

//For calculating Determinant of the Matrix
float determinant(float a[25][25],float k){
	float s=1,det_mat=0,b[25][25];
	int i,j,m,n,c;
	
	if (k==1){
		return (a[0][0]);
	}
	else{
		det_mat=0;
		for (c=0;c<k;c++){
			m=0;
			n=0;
			for (i=0;i<k;i++){
				for (j=0;j<k;j++){
					b[i][j]=0;
					if (i != 0 && j != c){
						b[m][n]=a[i][j];
						
						if (n<(k-2)){
							n++;	
						}
						else{
							n=0;
							m++;
						}
					}
				}
			}
			det_mat=det_mat + s * (a[0][c] * determinant(b,k-1));
			s=-1 * s;
		}
	}
	return (det_mat);
}

void cofactor(float num[25][25],float f){
	float b[25][25],fac[25][25];
	int p,q,m,n,i,j;
	for (q=0;q<f;q++){
		for (p=0;p<f;p++){
			m=0;
			n=0;
			for (i=0;i<f;i++){
				for (j=0;j<f;j++){
			  		if (i != q && j != p){
			    		b[m][n]=num[i][j];
			    		if (n<(f-2)){
			    			n++;
						}
			    		else{
			       			n=0;
			       			m++;
			       		}
			    	}
				}
			}	
			fac[q][p]=pow(-1,q + p) * determinant(b,f-1);
		}
	}
  	transpose(num,fac,f);
}

//Finding transpose of matrix
void transpose(float num[25][25],float fac[25][25],float r){
	int i,j;
	float b[25][25],inverse[25][25],d;
	
	for (i=0;i<r;i++){
	 	for (j=0;j<r;j++){
	     	b[i][j]=fac[j][i];
	    }
	}
	
	d=determinant(num,r);
	
	for (i=0;i<r;i++){
		for (j=0;j<r;j++){
			inverse[i][j]=b[i][j] / d;
		}
	}
	printf("\n\n\nInverse dari matrix adalah : \n");
	
	for (i=0;i<r;i++){
		for (j=0;j<r;j++){
			printf("\t%f",inverse[i][j]);
		}
		printf("\n");
	}
}

void matrixmultiply(){
	int matrix1[10][10],matrix2[10][10],m,n,p,q,multi[10][10];
	printf("========================================================\n");
	printf("\tPenghitungan Perkalian Matriks\n\n");
	
	printf("Masukan dimensi matriks pertama sebagai MxN : ");
	scanf("%d %d",&m,&n);
	printf("Masukan dimensi matriks kedua sebagai MxN : ");
	scanf("%d %d",&p,&q);
	
	if (n==p){
		printf("\n======Masukan Elemen Matriks======\n");
		multireadmatrix(matrix1,matrix2,m,n,p,q);
		multiprocessmatrix(matrix1,matrix2,multi,m,n,p,q);
		printf("\nHasil perkalian dari kedua matriks adalah\n");
		multishowmatrix(multi,m,q);
		printf("\nBack to menu (1) : ");
		scanf("%d",&n);
		if(n==1){
			main();
		}
	}
	else{
		printf("Perkalian matriks tidak memungkinkan");
	}
}

void multishowmatrix(int multi[][10],int n,int p)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%10d ",multi[i][j]);
		}
		printf("\n");
	}
}

void multireadmatrix(int matrix1[][10],int matrix2[][10],int m,int n,int p,int q){
	int i,j;
	printf("\nMasukan elemen matriks pertama\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix1[i][j]);	
		}
	}
	printf("\nMasukan elemen matriks kedua\n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&matrix2[i][j]);	
		}
	}
}

void multiprocessmatrix(int matrix1[][10],int matrix2[][10],int multi[][10],int m, int n, int p, int q){
	int i,j,k;
	for (i=0;i<m;i++){
		for(j=0;j<q;j++){
			multi[i][j]=0;
			for(k=0;k<n;k++){
				multi[i][j]=multi[i][j]+(matrix1[i][k]*matrix2[k][j]);	
			}
		}
	}

}

void matrix_output(float dis[][25],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%10f",dis[i][j]);
		}
		printf("\n");
	}
}
///////////////////////////////////////////////////SPL///////////////////////////////////////////////////
/*
float a[20][20];
float b[20];
float temp;
int n,i,j;
void TampilMatriks();
int o,p;

void SPL(){
	int bool = 1;
	printf("========================================================\n");
	printf("\tPenghitungan SPL Matriks dengan Gauss Jordan\n\n");
	
	while(bool=1){
 	//untuk baris dan kolom
		printf("Masukkan jumlah variabel : ");
		scanf("%d",&o);
		printf("Masukkan jumlah persamaan : ");
		scanf("%d",&p);
		if(p>o){
			printf("\nJumlah persamaan tidak boleh lebih besar dari jumlah variabel, silakan input kembali\n");
		}
		else{
			break;	
		}
		 
	}
	printf("\nMasukkan elemen matriks %dx%d : \n",o,p);
	int i=0;
	int j=0;
	for(i=0;i<p;i++){
		for(j=0;j<o;j++){
			//printf(" Input A[%d][%d] : ",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0;i<p;i++){
		printf("Input Hasil[%d] : ",i+1);
		scanf("%f",&b[i]);
	}
	
	printf("\nMatriks Awal : \n");
	printf("========================================================\n");
	TampilMatriks();

//penyelesaian menggunakan metode Gauss-Jordan
	printf("\nPENYELESAIAN : \n");
	printf("========================================================\n");
	for (n=0;n<p;n++) {
		printf("\nTahap %d \n",n+1);
		temp=a[n][n];
			for (j=0;j<o;j++){
				a[n][j]=a[n][j]/temp;
			}
			b[n]=b[n]/temp;
			for (i=0;i<o;i++){
				if (i!=n){
					temp=a[i][n];
					for (j=n;j<o;j++){
						a[i][j]=a[i][j]-(temp*a[n][j]);
					}
					b[i]=b[i]-(temp*b[n]);
				}
			}
		//menampilkan matriks
		TampilMatriks();
	}

//pembuktian
//cout<<"\nDari penyelesaian diatas diperoleh solusi nilai x dari sistem persamaan linier yaitu : \n";
	for (i=0;i<p;i++){
		if(isinf(b[i])||isnan(b[i])){
			printf("\nMatriks tidak konsisten, tidak dapat menghasilkan solusi persamaan linier, silakan input matriks kembali");
			break;
		}
		else{
			printf("\n");
			printf("X%d = %3.4f \n",(i+1),b[i]);
		}
	}
	getch();
}

void TampilMatriks(){
	for (i=0;i<p;i++){
		printf(" | ");
		for (j=0;j<o;j++){
			if (a[i][j]>=0)
				printf(" %3.4f ",a[i][j]);
			else
				printf("%3.4f ",a[i][j]);
		}
		printf("| |x%d|",i+1);
			if (i==3)
				printf(" = ");
			else
				printf("   ");
				printf("| %3.4f |",b[i]);
		printf("\n");
	}
}
///////////////////////////////////////////////////SPLCramer///////////////////////////////////////////////////

  float x[20][20], y[20][20], det_cram = 0; 
  int order;
  
void SPLCramer (){
  int i, j;
  printf("========================================================\n");
  printf("\tPenghitungan SPL Matriks dengan Cramer\n"); 
  printf ("\nMasukan Ordo Matriks : ");
  scanf ("%d", &order);
  printf ("\nMasukan Elemen Matriks\n");
  for (i = 1; i <= order; i++)
    {
      for (j = 1; j <= order; j++)
	{
	  printf ("a[%d][%d] = ", i, j);
	  scanf ("%f", &x[i][j]);
	}
    }
  printf ("\n\nMatriks\n");
  printf("========================================================\n");
  for (i = 1; i <= order; i++)
    {
      printf ("\n");
      for (j = 1; j <= order; j++)
	{
	  printf ("\t%0.2f \t", x[i][j]);	//Printing A array
	}
    }
  printf ("\nMasukan Constanta Matriks\n");
  for (i = 1; i <= order; i++)
    {
      for (j = 1; j <= 1; j++)
	{
	  printf ("b[%d][%d] = ", i, j);
	  scanf ("%f", &y[i][j]);
	}
    }
  printf("========================================================\n");
  printf ("Constanta Matriks \n");
  for (i = 1; i <= order; i++)
    {
      printf ("\n");
      for (j = 1; j <= 1; j++)
	{
	  printf ("\t%0.2f \t", y[i][j]);	//Printing B array
	}
    }
  printf ("\n \n");
  
  printf ("\n Determinant Matriks : %0.2f \n", determinant_cramer (x, order));
  if (determinant_cramer (x, order) == 0)
    {
      printf ("\n As Determinant of Matrix A is 0, cannot proceed.");
    }
  else
    {
      cramer_rule (x, y);
    }

  getch ();
}

float determinant_cramer (float A[20][20], int order)
{
  float sign, c[20], minorA[20][20];
  int j, row, col, s;
  if (order == 1)    
  {      
   det_cram = A[1][1];                           //If order is 1, Determinant is 0     
   return (det_cram);    
  }
	else
  if (order == 2)
    {
      det_cram = 0;			                        //If order is 1, Determinant is 0
      det_cram = (A[1][1] * A[2][2]) - (A[1][2] * A[2][1]);	//If order is 2, then simply calculate the Determinant
      return (det_cram);
    }
  else
    {
      for (j = 1; j <= order; j++)
	{
	  int minori = 1, minorj = 1;
	  for (row = 1; row <= order; row++)
	    {
	      for (col = 1; col <= order; col++)
		{
		  if (row != 1 && col != j)	//Condition for Matrix of miniors
		    {
		      minorA[minori][minorj] = A[row][col];
		      minorj++;
		      if (minorj > order - 1)
			{
			  minori++;
			  minorj = 1;
			}
		    }
		}
	    }
	  for (s = 1, sign = 1; s <= (1 + j); s++)
	    sign = (-1) * sign;
	  c[j] = sign * determinant_cramer (minorA, order - 1);	//Sign assining for Cofactor matrix
	}
      for (j = 1, det_cram = 0; j <= order; j++)
	{
	  det_cram = det_cram + (A[1][j] * c[j]);
	}
      return (det_cram);
    }
}

float cramer_rule (float t[20][20], float q[20][20])
{
  int i, j, tempi, tempj;
  float eachDet, realDet = det_cram;
  float values;
  float temp[20][20];
  for (j = 1; j <= order; j++)
    {
      for (tempi = 1; tempi <= order; tempi++)
	{
	  for (tempj = 1; tempj <= order; tempj++)
	    {
	      temp[tempi][tempj] = t[tempi][tempj];	//Storing in Temporary array without changing orginal array
	    }
	}
      for (i = 1; i <= order; i++)
	{
	  temp[i][j] = q[i][1];
	}
      eachDet = determinant_cramer (temp, order);
    
      values = (float) eachDet / (float) realDet;
      printf ("\n%f / %f",eachDet,realDet);
      printf ("\nx[%d] is %f", j, values);

    }
}
*/