#include <stdlib.h>
#include <string.h>

#include "data.h"

const floor_t MAP[MAP_WIDTH * MAP_HEIGHT] = {
  WALL, DOOR, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL,
  WALL, GRND, WALL, WALL, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, WALL, GRND, WALL, GRND, GRND, WALL,
  WALL, GRND, WALL, GRND, GRND, WALL, GRND, WALL, GRND, WALL, GRND, WALL, GRND, WALL, GRND, WALL, WALL, WALL, GRND, WALL, GRND, WALL, GRND, GRND, WALL,
  WALL, GRND, WALL, GRND, GRND, DOOR, GRND, GRND, GRND, GRND, GRND, GRND, GRND, DOOR, GRND, WALL, GRND, GRND, GRND, GRND, GRND, DOOR, GRND, GRND, WALL,
  WALL, GRND, GRND, GRND, GRND, WALL, GRND, WALL, GRND, WALL, GRND, WALL, GRND, WALL, GRND, WALL, WALL, WALL, GRND, WALL, GRND, WALL, DOOR, WALL, WALL,
  WALL, WALL, WALL, WALL, DOOR, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL, GRND, GRND, WALL,
  WALL, GRND, GRND, GRND, GRND, WALL, WALL, WALL, WALL, WALL, DOOR, WALL, WALL, WALL, WALL, GRND, WALL, WALL, GRND, WALL, GRND, WALL, GRND, GRND, WALL,
  WALL, GRND, GRND, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL, GRND, GRND, WALL,
  WALL, GRND, GRND, GRND, WALL, WALL, GRND, WALL, GRND, GRND, GRND, GRND, WALL, WALL, GRND, GRND, GRND, WALL, GRND, GRND, GRND, DOOR, GRND, GRND, WALL,
  WALL, GRND, GRND, GRND, DOOR, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL, WALL, WALL, GRND, GRND, WALL, GRND, GRND, WALL,
  WALL, WALL, WALL, WALL, WALL, GRND, GRND, WALL, GRND, GRND, WALL, DOOR, WALL, WALL, WALL, GRND, GRND, WALL, GRND, GRND, GRND, WALL, GRND, GRND, WALL,
  WALL, WALL, WALL, WALL, WALL, GRND, GRND, WALL, GRND, GRND, WALL, GRND, GRND, GRND, WALL, GRND, GRND, WALL, GRND, GRND, GRND, WALL, GRND, GRND, WALL,
  EXIT, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL, GRND, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, WALL, WALL, DOOR, WALL,
  WALL, WALL, WALL, WALL, WALL, GRND, GRND, WALL, GRND, GRND, WALL, GRND, GRND, GRND, DOOR, GRND, GRND, GRND, GRND, WALL, GRND, GRND, GRND, GRND, WALL,
  WALL, WALL, WALL, WALL, WALL, GRND, GRND, WALL, GRND, GRND, WALL, DOOR, WALL, WALL, WALL, GRND, GRND, WALL, WALL, GRND, GRND, GRND, GRND, GRND, WALL,
  WALL, GRND, GRND, DOOR, GRND, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL, WALL, GRND, GRND, GRND, WALL, GRND, WALL,
  WALL, GRND, GRND, WALL, WALL, WALL, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, WALL, GRND, WALL,
  WALL, GRND, GRND, GRND, GRND, WALL, GRND, GRND, GRND, WALL, GRND, WALL, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL, WALL, GRND, WALL,
  WALL, GRND, GRND, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL,
  WALL, WALL, WALL, WALL, DOOR, WALL, GRND, GRND, GRND, GRND, GRND, GRND, WALL, GRND, GRND, WALL, WALL, WALL, GRND, GRND, GRND, WALL, GRND, GRND, WALL,
  WALL, GRND, GRND, GRND, GRND, GRND, GRND, WALL, WALL, WALL, WALL, GRND, GRND, GRND, GRND, GRND, GRND, WALL, GRND, GRND, WALL, WALL, GRND, GRND, WALL,
  WALL, GRND, WALL, WALL, WALL, GRND, GRND, WALL, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL,
  WALL, GRND, GRND, GRND, WALL, WALL, GRND, DOOR, GRND, GRND, DOOR, GRND, GRND, WALL, WALL, GRND, WALL, WALL, GRND, WALL, GRND, WALL, GRND, GRND, WALL,
  WALL, GRND, GRND, GRND, GRND, GRND, GRND, WALL, GRND, GRND, WALL, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, GRND, WALL,
  WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL
};

data_t * alloc_game_data() {
  data_t * data = (data_t *)malloc(sizeof(data_t));

  data->width = MAP_WIDTH;
  data->height = MAP_HEIGHT;
  data->map_layer = (floor_t *)malloc(MAP_WIDTH * MAP_HEIGHT * sizeof(floor_t));

  if (data == NULL) {
    return NULL;
  } else {
    /*memset(data->items, 0, sizeof(item_t) * MAX_ITEMS);*/
    memset(data->characters, 0, sizeof(character_t) * MAX_CHARACTERS);
    memset(data->map_layer, GRND, sizeof(floor_t) * MAP_WIDTH * MAP_HEIGHT);
    return data;
  }
}

void init_game_data(data_t * data) {
  int i;

  if (data == NULL)
    return;

  /* Set the map data */
  memcpy(data->map_layer, MAP, sizeof(floor_t) * MAP_WIDTH * MAP_HEIGHT);

  /* Set the player data */
  data->characters[0].x = 13;
  data->characters[0].y = 13;
  data->characters[0].health = 100;
  data->characters[0].type = PLAYER;

  /* Set the NPC's */
  for (i = 1; i < 3; i++) {
    data->characters[i].x = 20;
    data->characters[i].y = 10 + i;
    data->characters[i].health = 80;
    data->characters[i].type = COMPUTER;
  }

  /* Set the enemies */
  for (i = 3; i < 7; i++) {
    if (i<=5){
      data->characters[i].x = 11;
      data->characters[i].y = 8 + i;
      data->characters[i].health = 40;
      data->characters[i].type = ENEMY;
    }
    else if(i<=8)
    {
      data->characters[i].x = 12;
      data->characters[i].y = 5 + i;
      data->characters[i].health = 40;
      data->characters[i].type = ENEMY;
    }
    else
    {
      data->characters[i].x = 13;
      data->characters[i].y = 2 + i;
      data->characters[i].health = 40;
      data->characters[i].type = ENEMY;
    }
  }

  /* Set empty character slots */
  for (i = 7; i < MAX_CHARACTERS; i++) {
    data->characters[i].x = 0;
    data->characters[i].y = 0;
    data->characters[i].health = 0;
    data->characters[i].type = NO_CHAR;
  }

  /* Set 3 treasues */
  /*
  for (i = 0; i < MAX_ITEMS; i++) {
    data->items[i].x = 10;
    data->items[i].y = 7 + i;
    data->items[i].type = i < 3 ? TREASURE : (i < 7 ? KEY : NO_ITEM);
  }
  */
}

bool can_move(data_t * data, unsigned char x, unsigned char y) {
  int i;

  if (data->map_layer[(x * data->width) + y] == WALL)
    return false;
  /*
  if (data->map_layer[(x * data->width) + y] == DOOR)
    return false;
  */

  for (i = 0; i < MAX_CHARACTERS; i++)
    if (data->characters[i].type != NO_CHAR && data->characters[i].x == x && data->characters[i].y == y)
      return false;

  return true;
}
