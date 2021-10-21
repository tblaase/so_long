# so_long 102/100 (October 2021)
This is my solution for the so_long project of the Core Curriculum of 42 school.<br>

## Explanation of the project

This projects goal is to create your own 2D game where you have a map that can have different dimensions and contents.<br>
A valid map is structured as followed:<br>
- 1 player (P)
- at least 1 exit (E)
- at least 1 collectible (C)
- is recatangular
- has a solid outside border out of walls (1)
- all the empty spaces are filled with 0
- no other characters than:
  * P
  * E
  * C
  * 1
  * 0
<br>
The player can only be moved by `WASD`.<br>
The player can not move into walls.<br>
The player can only exit if all collectibles are collected.<br>
The amount of movements is counted and displayed in the terminal.<br>
Every try to move even if it is invalid will be counted as one move.<br>
<br>
All the visualization is done with the help of the MiniLibX library.<br>

## How to run the game

All of the commands should be run in the root of the directory.<br>
- compile with `make all`
- run the game with `./so_long maps/map1.ber`
This is how the game looks for the map1.ber.<br>
<br>
<img src="images/example.png"><br>
This is what will be written in the terminal during the game and when you successfully win the game.<br>
<img src="images/terminal_win.png"><br>
This is what will be written in the terminal if you give up by closing the game by pressing `ESC` or clicking the red cross.<br>
<img src="images/terminal_give_up.png"><br>
