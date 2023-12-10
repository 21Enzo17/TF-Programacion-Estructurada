# TF-Programacion-Estructurada
Trabajo final de la materia Programacion Estructurada, programado en C++
## Integrantes
- Enzo Nicolas Meneghini
- Gustavo Zapana

## Descripcion
El misterioso y antiquísimo The Adivinator, es un juego originario del Medio Oriente, que pone aprueba la astucia, perspicacia e intuición de quienesse atreven a jugarlo.
- El juego presenta un tablero mágico con 6 valores ocultos que el jugador deberá descubrir para liberar a un poderoso genio que, en agradecimiento, concederá 3 deseos.
- Los números ocultos en el tablero tienen diferentes cifras, pero el jugador contará con las pistas de “The Adivinator” para intentar descubrirlos.
- ¿Serás capaz de superar este desafío?
## Reglas de Juego
El tablero oculta 6 valores aleatorios de 2, 3, 4, 5, 6 y 7
cifras, respectivamente, considerando:
- Valores de 2 cifras del intervalo 10 a 99
- Valores de 3 cifras del intervalo 300 a 499
- Valores de 4 cifras del intervalo 5400 5599
- Valores de 5 cifras mayores a 25000
- Valores de 6 cifras mayores a 500000
- Valores de 7 cifras
- La partida inicia con el valor más pequeño y continúa
hasta adivinar el mayor . Si el jugador no adivina alguno
de los números entonces el juego finaliza, quedando
atrapado en la lámpara junto al genio.
- Por cada número el jugador dispondrá de 5 intentos y en
cada uno podrá usar una pista para, sucesivamente,
reducir el conjunto de posibles valores solución.
### Las pistas consisten en :
- Pista 1: muestra el intervalo que contiene al número
secreto considerando ± N (aleatorio entre 50 y 100)
- Pistas 2: muestra los valores de la pista 1 que sean
pares/impares según la paridad del valor secreto.
- Pistas 3: muestra los valores de la pista 2 que sean
primos o no según sea el valor secreto.
- Pistas 4: muestra los valores de la pista 2 que sean
cuadrados o no según sea el valor secreto.
- Pistas 5: muestra los valores de la pista 2 que sean
Fibonacci o no según sea el valor secreto.
- Cada número vale su peso (cantidad de dígitos) en oro (7
monedas por dígito), y el jugador podrá ganar monedas
por cada número que adivine.
- Según las pistas que use el jugador se descontarán (del
número actual): P1) 2 monedas, P2) 3 monedas, P3) 4
monedas, P4) 5 monedas o P5) 6 monedas.
## Implementacion de Juego
El programa debe presentar un menú con las
siguientes opciones:
1. Gestión de Jugadores
2. Generación del Tablero
3. Jugar
4. Ranking de jugadores
5. Salir
- La opción Gestión de Jugadores accede a un submenú
para agregar jugadores, consultar y/o modificar
jugadores, listar jugadores y eliminar jugadores.
- La opción Generar Tablero permite crear los 6 valores
secretos del tablero del genio.
- La opción Jugar permite iniciar una partida, lo que
requiere que el jugador se identifique (login).
- La opción Ranking muestra los jugadores ordenados
por puntaje (monedas acumuladas), omitiendo
aquellos que no hayan ganado ninguna partida. El
orden (creciente o decreciente) es indicado por el
usuario.
- Los jugadores deben almacenarse en vectores de
registros, almacenando los siguientes datos:
  - id de jugador, apellido, nombre, nickname, monedas
acumuladas, partidas ganadas y contraseña. Los
jugadores deben ordenarse por nickname (que debe
ser único).
- El tablero debe construirse con matrices de registros,
almacenando los siguientes datos:
  - Por cada número secreto debe registrarse: valor,
monedas, rango (pista 1), paridad (pista 2), primo
(pista 3), cuadrado (pista 4) y Fibonacci (pista 5).
- El tablero del juego se carga con valores aleatorios
según los intervalos especificados en las reglas del
juego (incluya un módulo especial para mostrar el
tablero solo a fines de probar el programa).
- Para iniciar un partida debe verificarse que al menos
exista 1 jugador registrado y que el tablero del juego
haya sido generado.
El jugador que inicia la partida debe identificarse ingresando
su usuario y contraseña.
- Al registrar los datos de los jugadores debe validarse que la
contraseña sea de 6 caracteres incluyendo, al menos, una
minúscula, una mayúscula y un dígito.
- Las operaciones mostrar/buscar sobre vectores deben
desarrollarse mediante algoritmos recursivos.
- Las operaciones de búsqueda en vectores deben
implementarse mediante búsqueda binaria.
- El ranking de jugadores debe desarrollarse utilizando el
algoritmo de ordenación por inserción.
- Para iniciar la aplicación deberá ingresarse el usuario
“admin” y su contraseña “apu2008”, en caso contrario no se
tendrá acceso al juego.
- Adicione todos los controles y datos adicionales que
considere necesarios para el correcto funcionamiento del
juego.
