```
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   README.MD                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:29:39 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/11/22 15:21:06 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```
# so_long


![win](https://user-images.githubusercontent.com/54211553/203583331-3abb7ceb-5417-4cd9-a735-c36b41831ce9.gif)



# Description
This project is a very small 2D game. It is built to make you work with textures, sprites. And some very basic gameplay elements.

## How to Play the Game
To play this game, you can use any map of your choice as long as it follows the following rules:

* The extension must be `.ber`
* It must be rectangular, surrounded by walls `1`
* It must have only one exit, one player, and at least one collectible
* The following characters are allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | wall                     |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player starting position |
|     *Z*     | Enemy starting position  |


# Example of Death in the Game

![dead](https://user-images.githubusercontent.com/54211553/203583384-f59673dd-bb5d-44db-897b-4047d1d9f847.gif)

To compile the project, run the following command:

``make``

Or with bonuses:

``make bonus``

To start the game:

``./so_long``

# Commands:

| Key | Action |
|---|---|
| <kbd>W</kbd>| Jump |
| <kbd>S</kbd>| Move down |
| <kbd>A</kbd>| Move left |
| <kbd>D</kbd>| Move right |
| <kbd>ESC</kbd>| Close the game |
---

### Map File
You can create your own map file as you like but it needs to follow these rules:
- The map is covered with walls
- The map contains 1 item, 1 player, and 1 exit door
- The map must be rectangular
- The map file name needs to end with `.ber`
- Place the map file in the `maps` directory

# Example of a Map:
```
111111111111111111
10100C00010000C0C1
10000C0CC000CP0011
1100010CC000100011
1000C00E000C000001
111111111111111111
```
## Resources
- [MiniLibX]
- [MiniLibX Document]
- [MiniLibX Tutorial]
- [MiniLibX Example]


[MiniLibX]: https://github.com/42Paris/minilibx-linux
[MiniLibX Document]: https://harm-smits.github.io/42docs/libs/minilibx/introduction.html
[MiniLibX Tutorial]: https://aurelienbrabant.fr/blog/pixel-d
