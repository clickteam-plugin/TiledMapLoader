/*
 * Main.cpp
 *
 *  Created on: 14 juil. 2013
 *      Author: picque_j
 */

#include <iostream>
#include "TiledMapLoader.h"

int main()
{
    Tiled::TiledMapLoader tiledMapLoader;

    tiledMapLoader.loadFromFile("C:\\Users\\picque_j\\Desktop\\Stuff\\Super Mario Heart Attack\\media\\maps\\enter_the_mansion.tmx");
    tiledMapLoader.parseMap();
}
