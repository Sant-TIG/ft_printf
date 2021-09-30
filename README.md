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

### va_list

Las variables declaradas con el tipo **va_list** son un puntero a la direccion inicial de cada argumento de la funcion. Cuando lo declaramos por primera vez se almacenará en su interior la direccion del primer argumento.

```
va_list ap; //Declaramos una variable ap de tipo va_list. En esta ya esta almacenada la direccion del primero argumento.
```



### va_start()

La funcion de la macro **va_start()** con prototipo `void va_start(va_list ap, ultimo);` inicializa ap para su uso posterior por el resto de macros. **ultimo** hace referencia al ultimo argumento del que la funcion que llama conoce el tipo.

Ya que la direccion de este argumento puede utilizarse en la macro **va_start()**, no debe declararse como una variable de registro, ni como una funcion o un tipo de matriz.

## va_copy

Esta macro copia la lista de argumentos de la variable src a dest. El comportamiento es como si va_start se aplicara a dest con el mismo ultimo argumento, seguido por el mismo numero de invocaciones de va_arg que se uso para alcanzar el estado actual de src.

Una **funcion variadica** es aquella en la que desconocemos la cantidad y el tipo de parametros con los que vamos a trabajar. Su estructura es la siguiente: `tipo nombre(...)`. La propiedad de poder trabajar con un numero indefinido de argumentos viene dada por el operador **"ellipisis (...)"**.

## Libreria stdarg.h

La libreria `stdarg.h` define un nuevo tipo de variable llamada `va_list` y tres macros que pueden utilizarse para conseguir los argumentos de una **función variádica**. Estas tres macros son:

### va_list

Las variables de tipo va_list tienen la capacidad de almacenar la informacion que necesitan las tres macros siguientes para trabajar. Actuan como punteros a la direccion base de cada parametro.

### Macros

#### va_start()

`void va_start(va_list ap, last_arg)`

Esta macro se encarga de inicializar la variable `ap` para utilizarse con las macros `va_arg` y `va_end`. El parametro `last_arg`es el ultimo argumento fijo conocido que se pasa a la funcion, es decir, el argumento antes de la elipsis.

#### va_arg()

`type va_arg(va_list ap, type)`

Esta macro se encarga recuperar el siguiente argumento en la lista de parametros de la funcion de tipo `type`. Dicho de otro modo, esta macro lee y devuelve el contenido del argumento donde se encuentra el puntero ap. Después de terminar esta tarea, el puntero se mueve automaticamente al siguiente argumento de la variable, por lo que debe llamarse solo una vez. El objetivo de tener como parametro `type` es que este sea del mismo tipo del dato al que apunta para poder desrefenciarlo.

El primer uso de esta macro despues de la macro va_start devuelve el argumento despues de last. si no hay siguiente argumento ocurrira un error aleatorio. si ap es pasado a una funcion que utiliza va_arg(ap, type) el valor de ap es indefinido despues de el resultado de la funcion. 


#### va_end()

`type va_arg(va_list ap, type);`

Esta macro permite devolver un resultado adecuado a las funciones variadicas donde se ha utilizado la macro va_start. Si no se llama a va_end antes de devolver el resultado de la funcion, este resultado sera indefinido, por lo que cada invocacion de va_start debe estar ligada por la correspondiente invocacion de va_end() en la misma funcion.

Dicho de otro modo, se encarga de finalizar la variable ap. Devuelve ap como puntero nulo.

## Instrucciones

Lo primero que haremos será declarar un puntero que almacene la direccion los argumentos, una variable de tipo entero que utilizaremos para contar los caracteres de todos los argumentos, y.

Despues inicializaremos el puntero con la direccion del primer argumento. Despues comprobaremos caracter por caracter toda la cadena pasada. Si no encontramos el operador '%' iremos imprimiendo en pantalla lo que vemos. En cuanto nos topemos con uno, recuperamos el caracter posterior para analizar el formato del argumento.


