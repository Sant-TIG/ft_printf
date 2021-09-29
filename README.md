# ft_printf



# Variables Variadicas.

Las **funciones Variadicas** son aquellas que nos permiten tener un numero arbitrario de parametros de tipo arbitrario. La mas conocida en C y C++ en la funcion **printf**. 

Para declarar una funcion variadiaca tendremos que poner como parametro tres puntos seguidos **'...'**. Con esto le estamos diciendo al ordenador que este preparado para un numero desconocido de parametros. Este nuevo elemento siempre ha de ser el **ultimo parámetro** dentro de la funcion, a exepcion de los parametros a los que se les asigna un valor directamente.

```
int funcion1(int a, ..., int b) // Error de compilacion
int funcion2(int a, ..., int b = 0); // Correcto
```

Durante la ejecucion de un programa, el ordenador almacena todos los parametros de la funcion variadica en el **stack**. El problema esta en poder acceder a todos esos parametros que no tienen nombre al que hacer referencia. Por eso es conveniente asignar al menos un parametro con nombre es porque sin el no se puede inicializar la referencia de parametros sin nombre.

Para acceder a los parametros utilizaremos el **tipo** `va_list` junto con las **macros** `va_start` `va_arg` y `va_end`.

### va_start()

La funcion de la macro **va_start()** con prototipo `void va_start(va_list ap, ultimo);` inicializa ap para su uso posterior por el resto de macros. **ultimo** hace referencia al ultimo argumento del que la funcion que llama conoce el tipo.

Ya que la direccion de este argumento puede utilizarse en la macro **va_start()**, no debe declararse como una variable de registro, ni como una funcion o un tipo de matriz.

## va_arg()

Esta macro se expande a una expresion que tiene el tipo y el valor del siguiente argumento en la llamada. El argumento ap es el va_list ap inicializado por va_start(). Cada llamada a va_arg() modifica ap para que la siguiente llamada devuelva el siguiente argumento. El tipo de argumento es un nombre de tipo especificado para que el tipo de un puntero a un objetro que tiene el tipo especificado se pueda obtener simplemente agrefando un * al tipo.

El primer uso de esta macro despues de la macro va_start devuelve el argumento despues de last. si no hay siguiente argumento ocurrira un error aleatorio. si ap es pasado a una funcion que utiliza va_arg(ap, type) el valor de ap es indefinido despues de el resultado de la funcion.

## va_end

Cada invocacion de va_start debe estar ligada por la correspondiente invocacion de va_end() en la misma funcion. Despues de la llamada a va_end(ap) la variable ap se vuelve indefinida. va_end puede ser una macro o una funcion. 

## va_copy

Esta macro copia la lista de argumentos de la variable src a dest. El comportamiento es como si va_start se aplicara a dest con el mismo ultimo argumento, seguido por el mismo numero de invocaciones de va_arg que se uso para alcanzar el estado actual de src.
