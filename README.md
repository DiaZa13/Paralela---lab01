# Paralela-lab01
Cálculo del valor de PI
Para la compilación de los archivos de código .cpp se provee un cmake el cual se puede ejecutar cmake mediante línea de comando, sin embargo, es necesaria la instalación
de cmake.

Por su parte, una manera más fácil de poder compilar los programas es mediante línea de consola directa
```
gcc -fopenmp archivo_a_compilar -o nombre_de_ejecutable N Hilos
```

Para ejecutar con optimizaciones
```
gcc -O2 -fopenmp archivo_a_compilar -o nombre_de_ejecutable
```
