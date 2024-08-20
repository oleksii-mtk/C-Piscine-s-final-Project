The first line of the map contains information on how to read the map :
∗ The number of lines on the map;
∗ The "empty" character;
∗ The "obstacle" character;
∗ The "full" character

In the case that more than one solution exists, we’ll choose to represent the
square that’s closest to the top of the map, then the one that’s most to the
left.

◦ Your program must handle 1 to n files as parameters.

1. Дается ссылка на файл. В нем карта.
2. Карта проверяется на валидность
3. Далее она считывается.
4.


[0, 10] /0 - 10
[0, 4] [4, 10] / 4-10
[0, 6] [6, 10] / 6-10
[0, 10] / 6-10
[0, 2], [2, 10]
[0, 3] [3, 10]

можно забрутфорсить с каждой точки. С каждой точки построить самый большой кв.

. . .
. 0 . 
. . .
[0, 3]
[0, 1] [1, 3]
[0, 3]


[0, 3] [0, 1] [0, 3]
x, y, z = 0, 1, 3

[0, 3] [1, 3] [0, 3]

[1, 3, 3]