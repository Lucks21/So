#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  cout << "Ejecutando " << endl;
  if (argc != 3)
  {
    cout << "Uso: " << argv[0] << " <ruta de la imagen>" << endl;
    return -1;
  }

  // Cargar la imagen desde la línea de comando
  Mat image = imread(argv[1]);

  if (image.empty())
  {
    cout << "No se pudo cargar la imagen." << endl;
    return -1;
  }

  // Convertir la imagen a una matriz (array 2D)
  Mat_<uchar> imgMatrix = image;

  // Contar filas y columnas
  int filas = imgMatrix.rows;
  int columnas = imgMatrix.cols;

  cout << "Filas de la imagen: " << filas << endl;
  cout << "Columnas de la imagen: " << columnas << endl;

  cout << "Inicio de la conversion a escala de grises" << endl;
  auto start = chrono::steady_clock::now();

  // Convertir la imagen a escala de grises
  Mat grayImage;
  cvtColor(image, grayImage, COLOR_BGR2GRAY);

  auto end = chrono::steady_clock::now();
  cout << "Fin de la conversion a escala de grises" << endl;

  cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

  // Guardar la imagen en escala de grises
  imwrite(argv[2], grayImage);

  cout << "Imagen en blanco y negro guardada como: " << argv[2] << endl;

  // Mostrar la imagen original y la imagen en escala de grises
  namedWindow("Imagen Original", WINDOW_NORMAL);
  namedWindow("Imagen en Blanco y Negro", WINDOW_NORMAL);

  imshow("Imagen Original", image);
  imshow("Imagen en Blanco y Negro", grayImage);

  waitKey(0);
  destroyAllWindows();
  return EXIT_SUCCESS;
}
