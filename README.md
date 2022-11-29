
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

## How play the game
To play this game you can use any map of your choice as long follow the following rues:

* The extension need be `.ber`
* Its must be rectangular, surrounded by wall `1`
* Must have only one exit, only one player and at least one collectible
* Characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | wall                     |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player starting position |
|     *Z*     | Enemy starting position  |


# Example if you die

![dead](https://user-images.githubusercontent.com/54211553/203583384-f59673dd-bb5d-44db-897b-4047d1d9f847.gif)

To compile the project, run the following command:

``make``

Or with bonuses:

``make bonus``

to start the game:

``./so_long``

# Commandes :

| Clave | Action |
|---|---|
| <kbd>W</kbd>| Jump |
| <kbd>S</kbd>| Move down |
| <kbd>A</kbd>| Move left |
| <kbd>D</kbd>| Move right |
| <kbd>ESC</kbd>| close the game |
---

### Map File
You can create your own map file as you like but need to follow these rules.
- map is covered with walls
- map is contained with 1 item, 1 player and 1 exit door.
- The map must be rectangular
- map file name need end with `.ber`
- place map file in `maps` directory

# Exemple for map:

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
[MiniLibX Tutorial]: https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx
[MiniLibX Example]: https://github.com/terry-yes/mlx_example
