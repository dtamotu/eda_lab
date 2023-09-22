#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <fstream>
using namespace  std;
void generar(vector<float>  &puntos_aleatorios, int cantidad)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> random_entre(1.0, 2.0);
    for (int n = 0; n < cantidad; ++n)
        puntos_aleatorios.push_back(random_entre(gen));
    cout << '\n';

}

float  euclidiana(vector<float> &p1, vector<float> &p2)
{
    float suma_cuadrados;
    for (size_t i = 0; i < p1.size(); i++) {
        suma_cuadrados+= pow(p1[i] - p2[i], 2);
    }
    return sqrt(suma_cuadrados);
}
int main()
{   ofstream archivo("datos.txt");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return  0;
    }
    int cantidad;
    vector<int> dimensiones={10,50,100,500,1000,2000,5000};
    cantidad=100;
    archivo<<dimensiones.size()<<"\n";
    for(size_t i=0;i<dimensiones.size();i++)
        archivo<<"Dimension_"<<dimensiones[i]<<" ";
    archivo<<"\n";

    for(auto dimension:dimensiones){
        vector<vector<float>> matriz_aleatorios;
        for(int i=0; i<cantidad;i++ )
        {
            vector<float> puntos_aleatorios;
            generar(puntos_aleatorios, dimension);
            matriz_aleatorios.push_back(puntos_aleatorios);
        }
        for (int i = 0; i <cantidad ; ++i) {
            for (int j = i+1; j <cantidad ; ++j) {
                float distancia= euclidiana(matriz_aleatorios[i], matriz_aleatorios[j]);
                    archivo <<distancia<<"\n";
                }
                }
        archivo <<"//\n";
        }
        archivo.close(); // Cierra el archivo

}
