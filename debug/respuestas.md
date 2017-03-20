# Respuestas Debug

## Varios bugs

Hay tres códigos con bugs: add_array_dynamic, add_array_segfault y add_array_static. Al compilarlos con -c ninguno da errores ni warnings y al ejecutarlos add_array_dynamic da el resultado correcto mientras que add_array_static da cualquier cosa y add_array_segfault da un segmentation fault.
Entonces los compilo con el flag -g para poder después usar el debugger gdb; con -O0 para que el compilador no haga ninguna optimización y con el flag -Wall para ver todos los warnings. Entonces add_array_dynamic y add_array_static siguen dando igual pero add_array_segfault ahora da un warning de que las variables *a y *b no están inicializadas. Ahora uso el debugger gdb para el programa add_array_segfault. Devuelve que el problema del segfault es en la línea 19 y es debido al warning que ya sabía. El problema en add_array_dynamic, add_array_static y también en add_array_segfault es que en la definición de la función el for va hasta i<=n+1, mientras que el vector va hasta i<n, por lo tanto está haciendo operaciones con cosas que no sé que son, podrían ser cualquier cosa.

## Floating point exception

Al compilar los tres programas con el flag -c da todo bien. Al de square_root.c tuve que agregarle #include <math.h> y linkearlo con -lm para que funcione. 
Al correrlos y hacer la divisón por cero devuelve inf como resultado, y al calcularle la raiz a un número negativo devuelve -nan como resultado.
Ahora los compilo con $gcc -DTRAPFPE -Ifpe_x87_sse/ -c nombre.c, y para correrlos hago $ gcc nombre.o fpe_x87_sse/fpe_x87_sse.o -lm -o ejecutale.x
Al correrlos así y querer dividir por cero y también al querer sacar la raiz de un número negativo da "Excepción de coma flotante (`core' generado)". 

## Segmentation fault

En el caso de C, tanto el programa con SIZE=100 como con SIZE=2500 compila sin problema, pero a diferencia del primero, el segundo al ejecutarse devuelve un segmentation fault. Entonces ejecuto en la terminal antes de compilarlo ulimit -s unlimited y ahora sí se ejecuta completo y bien. Para intentar entender qué hace ese comando entonces corro el programa sin el comando y tipeo en la terminal ulimit -a y hago lo mismo después de haberlo corrido con el unlimited. Cambia sólo una cosa entre la tira de datos que devuelve el comando ulimit -a y es el stack size: en un caso, el primero tiene un ramaño de 8192, mientras que en el segundo caso dice unlimited. O sea que puedo decir que el comando lo que hace es permitirme guardar en el stack más cosas que antes, no le pone un límite, cosa que tampoco está tan buena en todos los casos.

En el caso de Fortran, le faltaba un argumento a la llamada de la subrutina. Se lo agrego y lo corro con gdb. Corre, se toma su tiempo, eso sí, pero no tiene ningún problema.

## Valgrind



## Funny