
#ifndef H_MENU_HANDLERS
#define H_MENU_HANDLERS


#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"
#include "memory.h"
#include "ncurses.h"


struct st_terminal_menu;
struct st_key_code;



void empty_handler(void);

void default_option_void_handler(void);
int32_t default_option_non_void_handler(char * message);
int32_t default_menu_keys_handler(struct st_terminal_menu * menu, struct st_key_code * key_data);
int32_t default_option_key_handler(int32_t key_code, struct st_terminal_menu * menu);

int32_t custom_key_handler(int32_t key_code, struct st_terminal_menu * menu);
void custom_void_handler(void);
int32_t custom_non_void_handler(char * message);

#endif

