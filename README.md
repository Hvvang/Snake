## Content

- [Description](#description)
- [Requirements](#requirements)
- [Installation](#installation)
- [Implemented functionality](#implemented-functionality)
- [Tested systems](#tested-systems)
- [License]($license)

## Description
Implementation of Snake game, using the C++ programming language and [SFML](https://github.com/SFML/SFML) framework.

## Requirements
- cmake 3.1v and higher.

## Installation
>**1. git clone --recursive https://github.com/Hvvang/Snake.git**  
>**2. cd Snake && zsh install.sh**  
>**3. cmake . -Bbuild && cmake --build ./build**
>**4. cd ./build/app**
>**5. ./race00 [width] [height]**

## Implemented functionality
- It consists of three screens:
  1. New game;
  2. Leaderboard;
  3. Gameplay.
- The playing area consists of square blocks along which Player can move. Square blocks consists of 40 pixels.
- The edges of the playing area can't be traversed.
- The size of the playing area is determined by width and height, passed as command-line arguments.
- If there is an incorrect number of arguments or the arguments are incorrect, the program-game prints usage: ```./race00 [width] [height]```.
- Player appears in the middle of the game area with length of 4 blocks.
- Player moves forward automatically.
- Each block of Snake's tail follows the head path.
- Player is able to turn left or right using the arrows on the keyboard.
- The game area has one item of food.
- The food position is random but the food can't appear in Snake's position.
- When Snake eats one item of food, one block is added to the tail and food disappears.
- Speed of Snake depends on its length. The longer Snake is - the slower it is.
- Every 4 seconds the size of Snake is reduced by 1 block.
- If Snake's length is less than 2 blocks - the game is over.
- When Snake eats one item of food - the timer restarts.
- If Snake hits an edge of game area or one of its own blocks - the game is over.
- After the game is over the New game screen appears.
- After each game the final score is saved and displayed.
- Leaderboard screen is a list containing the top 10 results. It saves results between app launch.

## Tested systems
  - MacOS

## License
Collision is an open-sourced software licensed under the [MIT license](LICENSE).
