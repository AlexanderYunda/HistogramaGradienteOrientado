#include "hog.h"
#include <time.h> 

#define DIR_CEDA_PASO "E:/RESPALDOS/PRUEBAS TESIS/Muestras Bien/1.jpg"
#define ancho_Imagen 32
#define alto_Imagen 32
#define ancho_Celda 4
#define alto_Celda 4
#define ancho_Bloque 2
#define alto_Bloque 2
#define orientaciones 9


//Gradientes *mscGrad;// CREO UN PUNTERO A LA CLASE GRADIENTE
//Celdas *micelda;
HOG *miHOG;
clock_t start, end1;



void main(void){
//mscGrad = new Gradientes(cvSize(ancho_Imagen, alto_Imagen));// CREO EL CONTRUCTOR GRADIENTE
start=clock();
//micelda=new Celdas(cvSize(ancho_Imagen, alto_Imagen), ancho_Celda,alto_Celda, orientaciones); 
	miHOG=new HOG(cvSize(ancho_Imagen, alto_Imagen), ancho_Celda,alto_Celda,ancho_Bloque,alto_Bloque, orientaciones);
IplImage *img1 = cvLoadImage(DIR_CEDA_PASO,CV_LOAD_IMAGE_GRAYSCALE);//CARGO IMAGEN EN ESCALA DE GRISES
IplImage *img2 = cvCreateImage(cvSize(ancho_Imagen, alto_Imagen),8,1);//CREO UNA IMAGEN CON MEDIDAS ESPECIFICAS
ajustarTamano(img1,img2);// AJUSTO EL TAMANO A IMAGENES DE 32X32
cvEqualizeHist(img2,img2);// ECUALIZO LA IMAGEN (ESCALA DE GRISES)
//micelda->matrizHistogramaCelda(img2);


//MUESTRA LOS HISTOGRAMAS POR CELDA
/*
for(int i=0;i<micelda->celda_y;i++)
	{
		for(int j=0;j<micelda->celda_x;j++)
		{
			for(int k=0;k<micelda->orientacion;k++)
			{
			printf("En celda %d,%d el histograma orientado %d = %f \n",i+1,j+1,k+1,micelda->HistCelda[i][j].Hcelda[k]);
			}

		}
	}

*/


//mscGrad->calcularImgMagAng(img2);


miHOG->vectorHOG(img2);


//cvShowImage("Ceda el Paso",img1);
//cvShowImage("Ecualizacion de Ceda el Paso",img2);
//MUESTRA LAS IMAGENES DE MAGNITUD Y ANGULO
//cvShowImage("Angulos",mscGrad->angles);
//cvShowImage("Magnitud",mscGrad->magnit);
end1=clock();
printf("Tiempo= %d ms \n",end1-start);
cvWaitKey(0);
system("Pause");

}

