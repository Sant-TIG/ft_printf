# Conversion Specifiers

Los **especificadores de formato** o **especificadores de conversion** son utilizados durante la **entrada** y la **salida de datos** de un programa. Gracias a estos especificadores, el compilador sabe que tipo de dato hay almacenado en una variable durante el uso del printf() y del scanf(). Dicho de otro modo, **representan un caracter que especifica el tipo de conversion que se va a aplicar**.

La estructura de estos elementos es la siguiente: `%nombre`. El caracter `%` **siempre** ha de ser el **primero** en escribirse a la hora de declarar el especificador. Sin embargo, dependiendo del tipo de dato con el que se  este trabajando, entre el caracter `%` y el nombre del especificador podemos incluir mas caracteres que pueden representar las distintas **banderas**, el **ancho de campo minimo** o la **precision**, por ejemplo. Los especificadores que se muestran a continuación son solo los que se mandan analizar en el subject del proyecto.

## %c

Este especificador es el responsable de interpretar los datos de tipo caracter `char`. Este toma un argumento de tipo entero `int` para despues convertirlo en uno de tipo caracter sin signo `unsigned char`. Una vez hecha la conversión, la funcion printf escribirá el caracter dado.

Este especificador no admite las siguientes flags: `#` `0` `` `+`; ni tampoco admite la precision. Si se encuentra con alguna de ellas simplemente la omitirá.

## d, i

El argumento de tipo entero `int` es convertido a notación decimal con signo. La precision se representa en este tipo de conversor como el minimo numero de digitos que deberian aparecer en la conversion. Si el valor convertido requiere menos digitos, se coloca a la izquierda con ceros. Por defecto, la precision tiene el valor de 1. Cuando se imprime un 0 con una precision explicita de 0, la salida esta vacia.
