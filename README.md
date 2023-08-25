# 🖥️ Laboratorio 2 - PARALELA 💽

## 🧑‍💻 Autores

- 🕺 Alejandro Gomez
- 🚶 Fredy Velasquez

## 📜 Descripción

Leer datos de números desde un archivo csv y clasificarlos. Escribir la lista ordenada de números a un segundo archivo. Paralelizar mediante OpenMP usando parallel for, sections, tasks, modificación de scope de variables, políticas de planificación y medición de tiempos. 

👥 En parejas, realice la creación de un programa secuencial que lee de un archivo, clasifica los datos leídos de menor a mayor y escribe los resultados a un segundo archivo.

🔗 Código de referencia en canvas:
- 🔢 qsort.c
- 📂 fileHandler.cpp

## 📦 Entregables

- 📄 Código fuente (.c /.cpp) de programas finales (secuencial y paralelo)
- 🔧 Instrucciones de compilación (o bien un makefile)
- 📝 Informe escrito donde detalla y lista las modificaciones realizadas al programa secuencial y el porqué de la decisión.

## 🛠️ Materiales

Necesitará una máquina virtual con Linux.

## 📚 Contenido

El programa qsort.c muestra una implementación secuencial de quicksort. Este algoritmo es eficiente y apropiado para manejar una amplia variedad de tipos de datos. Quicksort es del tipo divide and conquer, en el que aplicamos la misma idea a porciones cada vez más reducidas de la data.

La idea general es:

1. 🤔 Elegir cómo dividimos los datos. Usamos un valor fijo p para partir la data y la separamos en valores menores y mayores que el valor p = a[ j ].
2. 📉 La mitad inferior de la data inicia en a[ lo ] hasta a[ j − 1 ]. Toda la data en LO es menor que p. (La diferencia de un valor LO − p es negativa).
3. 📈 La mitad superior de la data inicia en a[ j + 1 ] hasta a[ hi ]. Toda la data en HI es mayor que p. (La diferencia de un valor HI − p es positiva).

🎯 Una de las partes importantes es la elección del pivote. Podemos elegir el primer número de la lista, el último o el valor central. Una vez elegido el pivote comparamos los valores de la lista de forma secuencial. Vamos comparando los valores de los extremos LO y HI de la data y modificando la posición de búsqueda a la siguiente (LO++ o HI--).

🔍 Revise el código sequential en qsort.c y asegúrese de entender el funcionamiento del mismo. Puede usar como referencia visual el link al siguiente:

