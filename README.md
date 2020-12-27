# cub3D
Proyecto de escuela 42 que simula el funcionamiento del juego de 1992 Wolf3D (http://users.atw.hu/wolf3d/)

Para probar este proyecto simplemente tras ejecutar el makefile habrá que introducir el comando:

```./cub3D maps/map.cub```

Donde map.cub es uno de los mapas de prueba que están integrados en la carpeta maps.

## Para entender el funcionamiento del código añado una pequeña guía de seguimiento:
Crearemos la biblioteca cub3d.h, incluiremos mlx.h y libft.h (get_next_line.h si lo necesitas, lo puedes integrar) esto quiere decir que tendremos tres carpetas con las correspondientes funciones. Después creamos una estructura, la llamaremos t_map y es donde iremos metiendo las variables, de momento sólo un char *mapchar que es donde dejaremos la lectura del archivo que pase el mapa (un archivo de extensión cub, map.cub por ejemplo).
Empezamos en el main:
- Comprobamos argumentos que nos pasan, pueden ser 2 o 3. 2 en el caso de que sólo pasemos el mapa y 3 para “—save” y hacer la captura de pantalla. Si esto está ok ejecutará el programa
-	Hacemos malloc para crear la estructura tab, donde iremos metiendo los parámetros necesarios para cada elemento
-	Parsename comprobará que el mapa que pasamos es de formato .cub
-	Initvar iniciará unas cuantas variables que iremos necesitando con algún contenido, en algunos casos serán más constantes que en otras. Todas estas variables estarán en tab
-	Readfile iniciará la lectura del mapa que a través de open y con get next line iremos almacenando en las distintas variables. 
	-	Con get_info cogemos las líneas una por una y según sea el comienzo de esta la enfocamos a una variable diferente (resolución, texturas, colores o mapa)
	-	importante hacer free para no dejar leaks en la memoria
	-	Si encontramos un tercer argumento, revisamos que sea exactamente “—save” para que no de error
-	Readmap saca la anchura y la altura del mapa, después toda parte que no sea numérica de mapchar la transformamos en número
	-	tabulaciones en  cuatro 8
	-	espacios en 9
	-	la dirección del jugador, la guardamos en una variable y le damos el valor 3
	- si hay sprites, vienen como 2 y acumulamos el número de ellos que aparezcan. Luego hacemos un malloc para hacer puntero a una estructura y crear una por cada sprite
	-	después con matrix, transformamos mapchar en un array bidimensional, cambiando las tabulaciones por espacios (de 8 a 9)
-	checkmap chequea que el mapa y su lectura sea correcto
	-	checkborder revisa los 4 lados del mapa
	-	check content revisa la posición de los sprites y el jugador. Luego revisa que no haya paredes abiertas en el mapa
	-	luego comprobamos que no haya más o menos de 1 jugador
	-	después que hayamos recogido correctamente las texturas, se pueden intercambiar entre ellas pero no puede llegar un archivo diferente al que tenemos
	-	y por último si la resolución es mayor a la predefinida, la reducimos a la máxima que hayamos decretado. Se puede hacer lo mismo con resoluciones pequeñas pero no lo piden
-	después liberamos el string de map
-	y arrancamos openall

Después viene openall:
-	lo primero iniciamos la mlx, nos aseguramos que esté bien, si no marcamos un error
-	abrimos ventana con el ancho que marque el mapa (winx y winy) y el nombre que le queramos poner
-	añadimos las texturas guardadas a las variables y estas con get data addr nos devuelve el punto de area de memoria donde tenemos almacenada la imagen y liberamos las variables que recogían los datos del mapa.
-	Después marcamos la posición del player
-	arranca raycasting
	-	tutorial notion https://www.notion.so/06-raycastingBasics-a72362d1c6c94a0d9cb8eb0700ff9bcc
-	luego dejamos los hook para las funciones de las teclas, la posibilidad de cerrar con el aspa de la ventana y la posibilidad de salir
-	y mantenemos el loop abierto hasta que cerremos


#### Este ha sido mi proyecto para la escuela de programación 42 Madrid como jeserran, puedes utilizarlo como guía para realizar tu proyecto pero nunca copiarlo para utilizarlo como propio.
