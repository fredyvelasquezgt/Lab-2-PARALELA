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

🔍 Revise el código sequential en qsort.c y asegúrese de entender el funcionamiento del mismo. 

# Ejercicio 1 (50 puntos) 

## Descripción 📝

¡Bienvenido al emocionante mundo de los números y el ordenamiento! Este programa te llevará a través de un viaje en varias etapas para generar, ordenar y guardar números aleatorios. 🚀

1. **Generación de Números Aleatorios:** ¿Cuántos números mágicos necesitas? Elige la cantidad y observa cómo el programa utiliza su hechizo especial `generateRandomNumbers()` junto con `rand()` y `srand(time(NULL))` para generarlos. 🎩✨

2. **Lectura y Almacenamiento:** Los números generados son leídos desde un pergamino (archivo) y guardados en un cofre (memoria) para su manipulación. 🔍📦

3. **Ordenamiento Místico:** Aquí es donde entra en juego el legendario QuickSort. Como un mago que organiza sus cartas, este algoritmo ordena los números de menor a mayor. ♠️♥️♦️♣️

4. **Guardar el Tesoro Ordenado:** Los números ordenados son cuidadosamente guardados en otro pergamino (archivo), listos para ser consultados cuando lo desees. 🗄️🔒

## Componentes Mágicos 🔮

### 1. Generación de Números Aleatorios

La función `generateRandomNumbers()` conjura números aleatorios usando el antiguo encantamiento de `rand()`. Además, asegura la variabilidad con la poderosa semilla `srand(time(NULL))`.

### 2. Ordenamiento de Números: QuickSort

La magia del QuickSort entra en juego para organizar los números en un orden deseado. Los números son como cartas que se reorganizan en función de un pivote mágico.

### 3. Manejo de Archivos

El programa utiliza hechizos de lectura y escritura (`ofstream` e `ifstream`) para interactuar con los pergaminos (archivos) llamados "numeros_aleatorios.csv" y "numeros_ordenados.csv".

## Análisis del Modo Secuencial 🔍

### Ventajas del Modo Secuencial

- **Sencillez Hechizante:** La ejecución secuencial del programa es como seguir un camino de piedras mágicas. Fácil de entender y solucionar si algo se sale de control. 🛤️
- **Adecuado para Conjuros Pequeños:** Si estás tratando con pocos números, no hace falta complicarse. A veces, la simplicidad es la clave. 👌

### Desventajas del Modo Secuencial

- **Tiempo Fluyente:** Cuando los números son muchos, este método se toma su tiempo. No aprovecha la multitud de corazones (núcleos) de las máquinas modernas. ⏳
- **Limitaciones de Escalabilidad:** A medida que el ejército numérico crece, la eficacia del programa en modo secuencial disminuye en comparación con una versión de hechizos paralelos.


# Ejercicio 2 (50 puntos) 

## Paralelización Inicial ⚡

### 1.1 Cambios Iniciales

¡Hora de hacer que QuickSort brille aún más! Este algoritmo es como una estrella fugaz 🌠, listo para ser paralelizado. En su versión original, ya ordena dos mitades del arreglo por separado. ¡Genial! Ahora, en lugar de quedarnos con eso, vamos a lanzar un hechizo adicional.

Introducimos la directiva mágica `#pragma omp parallel sections` en la función `quickSort` para paralelizar esas dos llamadas recursivas. 🧙‍♂️✨

### Justificación ✅

Las dos llamadas a `quickSort` son como dos magos independientes, ¡sin necesidad de hablar el uno con el otro! Al paralelizar estas llamadas, podemos ver cómo el tiempo de ejecución se reduce como por arte de magia.

## Paralelización Completa 🔀

### 2.1 Cambios Adicionales

Ahora que las bases están hechas, es hora de convertirnos en maestros de la paralelización. 💪

- ¡Generación de Números Mágicos en Paralelo! 🔢✨
- ¡Lectura de Números desde el Archivo en Equipo! 📚👥

Cada número generado es como un hechizo único, sin relación con los demás. ¡Así que, adelante, genera esos números en paralelo y siente la potencia mágica! ⚡

La lectura de números desde el archivo también entra en la fiesta paralela, pero ¡cuidado! Asegurémonos de que todo esté en orden para evitar que los magos (hilos) se tropiecen. No queremos problemas de "condiciones de carrera", ¿verdad?

La magia de OpenMP se une a la fiesta para darle una velocidad alucinante a tareas como la clasificación. Solo ten en cuenta dónde aplicar el truco y asegúrate de que no haya conflicto de hechizos o dependencias. Con un poco de atención, ¡lograrás una aceleración impresionante! 🌟🔥



