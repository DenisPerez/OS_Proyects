#ifndef DATA_H
#define DATA_H

#include <stdbool.h>

#define MAP_WIDTH 25
#define MAP_HEIGHT 25

/*#define MAX_ITEMS 42*/
#define MAX_CHARACTERS 9

typedef enum CHARACTER_TYPE { PLAYER, COMPUTER, ENEMY, NO_CHAR } ctype_t;

typedef struct PLAYER_DATA {
  unsigned char x;
  unsigned char y;
  signed char health;
  ctype_t     type;
} character_t;

typedef enum ITEM_TYPES { TREASURE, KEY, NO_ITEM } itype_t;
/*
typedef struct ITEM_DATA {
  unsigned char x;
  unsigned char y;
  itype_t       type;
} item_t;
*/
typedef enum TILE_TYPES { WALL = 0, GRND, DOOR } floor_t;

typedef struct GAME_DATA {
  unsigned char width;
  unsigned char height;
  /*item_t        items[MAX_ITEMS];*/
  character_t   characters[MAX_CHARACTERS];
  floor_t *     map_layer;
} data_t;

data_t * alloc_game_data();
void     init_game_data(data_t * data);
bool     can_move(data_t * data, unsigned char x, unsigned char y);

#endif
