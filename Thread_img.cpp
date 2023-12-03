#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Función para convertir la imagen a blanco y negro
void convertToGrayscale(Mat &img)
{
  cvtColor(img, img, COLOR_BGR2GRAY);
}

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    cout << "Uso: ./programa <imagen_entrada> <nombre_salida> <cantidad_hilos>\n";
    return -1;
  }

  // Cargar la imagen de entrada
  Mat image = imread(argv[1]);

  if (image.empty())
  {
    cout << "No se pudo abrir la imagen.\n";
    return -1;
  }

  // Obtener la cantidad de hilos desde el argumento
  int num_threads = stoi(argv[3]);

  // Mostrar las dimensiones de la imagen
  cout << "Filas: " << image.rows << ", Columnas: " << image.cols << endl;

  // Crear un arreglo de threads
  vector<thread> threads;

  // Medir el tiempo de inicio
  auto start_time = chrono::steady_clock::now();

  // Dividir la imagen en secciones para procesarla en paralelo
  int rows_per_thread = image.rows / num_threads;
  int extra_rows = image.rows % num_threads;
  int start_row = 0;

  // divide la imagen para procesarlas
  for (int i = 0; i < num_threads; ++i)
  {
    int rows_to_process = (i < extra_rows) ? rows_per_thread + 1 : rows_per_thread;
    Mat sub_image = image.rowRange(start_row, start_row + rows_to_process).clone();
    threads.emplace_back(convertToGrayscale, ref(sub_image));
    start_row += rows_to_process;
  }

  // Esperar a que todos los hilos terminen
  for (auto &t : threads)
  {
    t.join();
  }

  // Medir el tiempo de finalización y calcular la duración
  auto end_time = chrono::steady_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

  // Mostrar la duración de la ejecución en segundos
  cout << "Tiempo de ejecucion: " << duration / 1000.0 << " segundos.\n";

  // Guardar la imagen en blanco y negro
  imwrite(argv[2], image);

  return EXIT_SUCCESS;
}
