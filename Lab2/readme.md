# Lab2: Multiplicación implementación de **OpenMP**
En este laboratorio-teórico práctico se realiza la puesta en marcha de la multiplicación de matrices utilizando **OpenMP**, se tratan de comparar los tiempos de ejecución de la multiplicación de matrices de forma secuencial y de forma paralela.

## Información
Este Laboratorio tiene un analísis pequeño realizado con Python en un notebook de Jupyter, podras observar las estadisticas y las graficas de secuencial vs  parallelo con matrices de 500x500[readme.ipynb](https://github.com/h3ct0rjs/HighPerformanceComputing/blob/master/Lab2/readme.ipynb), se realiza la variacion del numero de threads a utilizar modificando la variable de entorno **OMP_NUM_THREADS** .

## Ejecución
Este programa solo ha sido probado bajo un entorno Debian Gnu/Linux ***Buster*** y en el cluster[lovelace.utp.edu.co](), aunque deberia de funcionar tambien en un entorno Window$. 

Para ejecutar el código solo bastará con hacer :
```sh
user@host:/tmp/: git clone https://github.com/h3ct0rjs/HighPerformanceComputing
user@host:/tmp/: cd HighPerformanceComputing/Lab2 && ./run
```
*Tener presente que para realizar la prueba con otros datos es necesario que los archivos ubicados en **datasets** se llamen data1.txt, data2.txt los datos de las matrices correspondientes, el resultado se mostrará en pantalla y la matriz resultado será almacenada en *result.txt* *