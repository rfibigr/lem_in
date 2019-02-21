# LEM_IN

The goal of this project is to find the quickest way to get n ants across the farm.
They will also need to avoid traffic jams as well as walking all over their fellow ants.
At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible.

to know more about the project, you can read the instruction in the [lem_in.pdf](https://github.com/rfibigr/lem_in/divers/lem_in.fr.pdf)


## The ant farm

The ant farm are defined by the following patern
+ first : the number_of_ants
+ then : the_rooms
+ and finaly : the_links between the room

The rooms, are defined by: name coord_x coord_y
The links, which are defined by: name1-name2
Some comments can be add and start with #
The lines that start with ## are commands modifying the properties of the line that comes right after

exemple:

```bash
42
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
```

with represent the following maps with 42 ants to transfer.

```bash
                  _______________
                 /               \
         ______[5]----[3]----[1] |
        /              |     /   |
       [6]-----[0]----[4]   /    |
        \  _________/  |   /     |
         \/          [2]/_______/
         [7]_________/
```


## the ant colony

Lx-y Lz-w Lr-o
x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.

• Example 1 :
For an ant maps that look like the following
[0]-[2]-[3]-[1]
And a number of ants of 3, the result expected is decribe below.

```bash
$ ./lem-in < subjet1.map
3
##start
0 1 0
##end
1 5 0
2 9 0
3 13 0
0-2
2-3
3-1
L1-2
L1-3 L2-2
L1-1 L2-3 L3-2
L2-1 L3-3
L3-1
```

## library used

allowed funtions :
+ malloc
+ free
+ read
+ write
+ strerror
+ perror
+ exit

I use the library [libft](https://github.com/rfibigr/libft)
and the [minilibx library](https://github.com/rfibigr/push_swap/tree/master/lib/minilibx_macos) (a custom graphic library) to create the visualizer.


## My implementation

To realise this project I implement a breath search algorithm that i customise to be able to find multi unique path.

I also had in a bonus a visualizer that i write the [minilibx library](https://github.com/rfibigr/push_swap/tree/master/lib/minilibx_macos) (a custom graphic library).

![Alt Text](https://github.com/rfibigr/lem_in/blob/master/divers/lem_in_visu.gif)



## How to install

```bash
git clone https://github.com/rfibigr/lem_in.git --recurse
cd lem_in
make
```

or

```bash
git clone https://github.com/rfibigr/lem_in.git
cd lem_in
git submodule init
git submodule update
make
```

## How to run

Lem_in read on the standard entry and wait for the input of a maps
Some maps are at disposition in the folder maps.

```bash
./lem-in < [map]
```

to use the visualizer add the option -visualizer

```bash
./lem-in -visualizer < [map]
```
exemple to test
```bash
./lem-in -visualizer < map/test3
```
The `space key` start the visualizer.
The `echap key` to close the windows


## Author

Romain Fibigr : rfibigr@student.42.fr
