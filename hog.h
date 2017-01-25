#ifndef HOG_H
#define HOG_H

#include <opencv\cv.h>
#include <opencv\highgui.h>
#define pi 3.14159265359
  
using namespace std;

struct HistogramaCelda{
	float *Hcelda;
};

class Gradientes{
	public:
	CvMat *filter_x;
	CvMat *filter_y;
	CvSize tmImagen;
	public:
	IplImage *img_diff_x;
	IplImage *img_diff_y;
	IplImage *img_32f;
	private:
	void  imgMagnitudAngulo(IplImage *diff_x,IplImage *diff_y,IplImage *angs,IplImage *magt);
	public:
	IplImage *magnit;
	IplImage *angles;
	public:
	Gradientes(CvSize szImg);
	void calcularImgMagAng(const IplImage *src);	
	~ Gradientes(void);		
};

void ajustarTamano(IplImage *src,IplImage *dst);

class Celdas{

	private:
	CvSize tmImg;
	CvRect **divisionCeldas;
	double *divisionOrientacion;
	
public:
	int celda_x;
	int celda_y;
	struct HistogramaCelda **HistCelda;
	int orientacion;
	IplImage *tplAng;
	IplImage *tplMag;

	Gradientes *mscGrad;	
	
	Celdas(CvSize Img, int celda_ancho,int celda_alto, int num_orientacion);
	void calcularHistogramaCelda(IplImage *magt,IplImage *angs, float Hcel[]);
	void matrizHistogramaCelda(const IplImage *src);

	~Celdas(void);
};

class HOG {

public:

	int bloque_x;   // numero de bloques en x
	int bloque_y;   // numero de bloques en y
	int bloque_xx;   // tamano del bloque en celdas (ancho)
	int bloque_yy;   // tamano del bloque en celdas (alto)
	float *HsN;		// vector por bloque sin normalizar
	float *HcN;		// vector por bloque normalizado
	Celdas *micelda;
	float *V_HOG; // vector con caracteristicas HOG
	int dim_bloq; // dimension del vector por bloque
	int dim_hog; // dimension del vector HOG

	HOG(CvSize Img, int celda_ancho,int celda_alto,int bloque_ancho,int bloque_alto, int num_orientacion);
	void vectorHOG(const IplImage *src);
	float normalizar(float *H2);
	~HOG(void);

};





#endif