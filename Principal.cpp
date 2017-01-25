#include "hog.h"
#include <time.h> 

#define DIR_CEDA_PASO "E:/1.jpg" //Direccion de la imagen a utilizar
#define ancho_Imagen 32 //tamaño en pixeles
#define alto_Imagen 32 //tamaño en pixeles
#define ancho_Celda 4 //tamaño en pixeles
#define alto_Celda 4 //tamaño en pixeles
#define ancho_Bloque 2 //tamaño en celdas
#define alto_Bloque 2 //tamaño en celdas
#define orientaciones 9 //division del rango de orientacion del gradiente entre -pi/2 hasta pi/2



HOG *miHOG;
clock_t start, end1;



void main(void){
start=clock();
miHOG=new HOG(cvSize(ancho_Imagen, alto_Imagen), ancho_Celda,alto_Celda,ancho_Bloque,alto_Bloque, orientaciones);
IplImage *img1 = cvLoadImage(DIR_CEDA_PASO,CV_LOAD_IMAGE_GRAYSCALE);//CARGO IMAGEN EN ESCALA DE GRISES
IplImage *img2 = cvCreateImage(cvSize(ancho_Imagen, alto_Imagen),8,1);//CREO UNA IMAGEN CON MEDIDAS ESPECIFICAS
ajustarTamano(img1,img2);// AJUSTO EL TAMANO A IMAGENES DE 32X32
cvEqualizeHist(img2,img2);// ECUALIZO LA IMAGEN (ESCALA DE GRISES)
miHOG->vectorHOG(img2);

cvShowImage("Ceda el Paso",img1);//Imagen Original
cvShowImage("Ecualizacion de Ceda el Paso",img2);//Imagen ajustado tamaño y ecualizada
	
//MUESTRA LAS IMAGENES DE MAGNITUD Y ANGULO
cvShowImage("Angulos",mscGrad->angles);
cvShowImage("Magnitud",mscGrad->magnit);
end1=clock();
printf("Tiempo= %d ms \n",end1-start);// Tiempo de computo del descriptor
cvWaitKey(0);
system("Pause");

}

