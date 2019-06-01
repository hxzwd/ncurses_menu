

#ifndef H_MENU_MAIN
#define H_MENU_MAIN


#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"
#include "memory.h"
#include "ncurses.h"


#define KEY_ESC 	27
#define KEY_ENTER	10
#define KEY_SPACE	32


#define CP_RED_ON_BLACK		1
#define CP_GREEN_ON_BLACK	2
#define CP_BLUE_ON_BLACK	3
#define CP_BLACK_ON_GREEN	20

struct st_key_code
{
	int32_t code;
	char desc[32];
} __attribute__((packed));

/*
struct st_key_code key_codes_list[] = { { 48, "0" }, { 20, "CAPS LOCK" }, { 16, "SHIFT" }, { 190, "PERIOD" }, { 91, "LEFT WINDOW KEY" },
{ 92, "RIGHT WINDOW KEY" }, { 49, "1" }, { 50, "2" }, { 51, "3" }, { 17, "CTRL" }, { 53, "5" },
{ 101, "NUMPAD 5" }, { 56, "8" }, { 57, "9" }, { 65, "A" }, { 66, "B" }, { 67, "C" }, { 68, "D" },
{ 96, "NUMPAD 0" }, { 70, "F" }, { 71, "G" }, { 72, "H" }, { 73, "I" }, { 74, "J" }, { 75, "K" },
{ 103, "NUMPAD 7" }, { 77, "M" }, { 78, "N" }, { 79, "O" }, { 80, "P" }, { 81, "Q" }, { 82, "R" },
{ 104, "NUMPAD 8" }, { 84, "T" }, { 85, "U" }, { 86, "V" }, { 87, "W" }, { 88, "X" },{ 89, "Y" },
{ 90, "Z" }, { 97, "NUMPAD 1" }, { 98, "NUMPAD 2" }, { 99, "NUMPAD 3" }, { 100, "NUMPAD 4" },
{ 69, "E" }, { 54, "6" },  { 55, "7" }, { 76, "L" }, { 182, "MY COMPUTER (MULTIMEDIA KEYBOARD)" },
{ 18, "ALT" }, { 83, "S" }, { 144, "NUM LOCK" }, { 145, "SCROLL LOCK" }, { 44, "PRINT SCREEN" }, 
{ 183, "MY CALCULATOR (MULTIMEDIA KEYBOARD)" }, { 189, "DASH" }, { 52, "4" }, { 105, "NUMPAD 9" },
{ 127, "BACKSPACE" }, { 9, "TAB" }, { 10, "ENTER" }, { 29, "PAUSE/BREAK" }, { 125, "CLOSE BRAKET" },
{ 27, "ESCAPE" }, { 339, "PAGE UP" }, { 32, "SPACE" }, { 338, "PAGE DOWN" }, { 102, "NUMPAD 6" },
{ 360, "END" }, { 262, "HOME" }, { 260, "ARROW LEFT" }, { 259, "ARROW UP" }, { 61, "EQUAL SIGN" },
{ 261, "ARROW RIGHT" }, { 258, "ARROW DOWN" }, { 331, "INSERT" }, { 330, "DELETE" }, { 275, "F11" },
{ 42, "MULTIPLY" }, { 43, "ADD" }, { 45, "SUBTRACT" }, { 46, "DECIMAL POINT" }, { 92, "BACK SLASH" },
{ 47, "DIVIDE" }, { 265, "F1" }, { 266, "F2" }, { 267, "F3" }, { 58, "SEMI-COLON" }, { 274, "F10" }, 
{ 268, "F4" }, { 269, "F5" }, { 270, "F6" }, { 271, "F7" }, { 123, "OPEN BRACKET" }, { 276, "F12" },
{ 272, "F8" }, { 273, "F9" }, { 47, "FORWARD SLASH" }, { 44, "COMMA" }, { 39, "SINGLE QUOTE" } };
*/

static struct st_key_code key_codes_list[] =
	{
		{ 127, "BACKSPACE" }, { 9, "TAB" },
		{ 10, "ENTER" }, { 29, "PAUSE/BREAK" },
		{ 27, "ESCAPE" }, { 339, "PAGE UP" },
		{ 32, "SPACE" }, { 338, "PAGE DOWN" },
		{ 360, "END" }, { 262, "HOME" },
		{ 260, "ARROW LEFT" }, { 259, "ARROW UP" },
		{ 261, "ARROW RIGHT" }, { 258, "ARROW DOWN" },
		{ 331, "INSERT" }, { 330, "DELETE" },
		{ 42, "MULTIPLY" }, { 43, "ADD" },
		{ 45, "SUBTRACT" }, { 46, "DECIMAL POINT" },
		{ 47, "DIVIDE" }, { 265, "F1" },
		{ 266, "F2" }, { 267, "F3" },
		{ 268, "F4" }, { 269, "F5" },
		{ 270, "F6" }, { 271, "F7" },
		{ 272, "F8" }, { 273, "F9" },
		{ 274, "F10" }, { 275, "F11" },
		{ 276, "F12" }, { 58, "SEMI-COLON" },
		{ 61, "EQUAL SIGN" }, { 44, "COMMA" },
		{ 47, "FORWARD SLASH" }, { 123, "OPEN BRACKET" },
		{ 92, "BACK SLASH" }, { 125, "CLOSE BRAKET" },
		{ 39, "SINGLE QUOTE" }, { -1, "EMPTY KEY" }
	};

static struct st_key_code ascii_key_codes_list[256];

struct st_option_pos
{
	int32_t x1;
	int32_t y1;
	int32_t x2;
	int32_t y2;

} __attribute__((packed));

struct st_terminal_menu_option
{

	int32_t index;
	char desc[128];
	char title[128];
	void (*void_handler)(void);
	int32_t (*non_void_handler)(char *);
	int32_t (*option_key_handler)(int32_t, struct st_terminal_menu *);
} __attribute__((packed));

struct st_terminal_menu
{
	int32_t x1;
	int32_t y1;
	int32_t x2;
	int32_t y2;
	int32_t rectangle_points[4];
	int32_t in_rectangle;
	int32_t rectangle_autosize;
	int32_t colors_on;
	int32_t options_global_color;
	char option_pointer_active[32];
	char option_pointer_inactive[32];
	int32_t x_pos;
	int32_t y_pos;
	char name[128];
	int32_t num_of_options;
	int32_t current_option;
	struct st_terminal_menu_option options[64];
	struct st_option_pos options_pos[64];
	char reserve[1024];
	int32_t (*keys_handler)(struct st_terminal_menu *, struct st_key_code *);
} __attribute__((packed));

void copy_menu_option(struct st_terminal_menu_option * dest, struct st_terminal_menu_option * src);
void add_option_to_menu(struct st_terminal_menu * menu, struct st_terminal_menu_option * option);
void init_new_menu(char * name, struct st_terminal_menu * menu);
void init_new_option(int32_t index, char * desc, char * title, void (*void_h)(void), int32_t (*non_void_h)(char *), int32_t (*key_h)(int32_t, struct st_terminal_menu *), struct st_terminal_menu_option * option);
void menu_set_position(int32_t x_pos, int32_t y_pos, struct st_terminal_menu * menu);
void menu_set_rectangle_options(int32_t x1, int32_t y1, int32_t x2, int32_t y2, struct st_terminal_menu * menu);
void apply_menu_settings(struct st_terminal_menu * menu);

void set_option_header(int32_t index, char * desc, char * title, struct st_terminal_menu_option * option);
void set_option_handlers(void (*void_h)(void), int32_t (*non_void_h)(char *), int32_t (*key_h)(int32_t, struct st_terminal_menu *), struct st_terminal_menu_option * option);

void set_option_position(int32_t index, int32_t x1, int32_t y1, int32_t x2, int32_t y2, struct st_terminal_menu * menu);

void draw_menu(struct st_terminal_menu * menu);
void redraw_menu(struct st_terminal_menu * menu);

inline void on_menu_color(struct st_terminal_menu * menu);
inline void off_menu_color(struct st_terminal_menu * menu);




int32_t main_old(void);
int32_t main_old_2(int32_t argc, char **argv);
int32_t main_old_3(int32_t argc, char **argv);
int32_t main_old_4(int32_t argc, char **argv);
void d_msg(char * message);
void d_msg_e(char * message, char * flags);

void func_start(void);
void func_finish(void);
inline void clear_screen(void);
inline void clear_current_line(void);
inline void clear_line(int32_t row_num);
inline void clear_line_at(int32_t row_num, int32_t col_num);
void fill_part_of_line(int32_t x_pos, int32_t y_pos, int32_t size_of_part, char fill_symbol);
inline void get_screen_size(int32_t * max_rows, int32_t * max_cols);
inline int32_t get_current_x_pos(void);
inline int32_t get_current_y_pos(void);
inline void enable_colors(void);
inline void set_color_pair(int32_t index, int32_t color1, int32_t color2);
inline void refresh_screen(void);
inline void on_colors(int32_t index);
inline void off_colors(int32_t index);
inline void move_at_position(int32_t x_pos, int32_t y_pos);
inline void move_at_start_of_line(int32_t row_num);
inline void disable_cursor(void);
inline void enable_cursor(void);
inline void disable_keypad(void);
inline void enable_keypad(void);
inline void disable_echo(void);
inline void enable_echo(void);
inline void set_half_delay(int32_t seconds);
void print_at_point(int32_t row_pos, int32_t col_pos, char * message);
void draw_rectange(int32_t points[]);
int32_t get_key(void);
int32_t wait_for_key(int32_t key_code);
int32_t wait_for_keys(int32_t * keys_code, int32_t num_of_keys);
int32_t wait_for_key_d(int32_t key_code);
int32_t wait_for_keys_d(int32_t * keys_code, int32_t num_of_keys);
void key_code_to_char(int32_t key_code, char * buffer);
int32_t get_key_codes_list_length(void);
int32_t check_in_key_codes_list(int32_t key_code, struct st_key_code * key_data);
int32_t check_in_key_codes_list_by_desc(char * key_desc, struct st_key_code * key_data);
int32_t wait_for_keys_desc_d(char * keys_desc[], int32_t num_of_keys);
int32_t wait_for_keys_desc(char * keys_desc[], int32_t num_of_keys);
int32_t wait_for_key_desc(char * key_desc);
int32_t wait_for_key_desc_d(char * key_desc);
void fill_ascii_key_codes_list(void);
int32_t check_ascii_printable(char * key_desc, struct st_key_code * key_data);

void draw_corner_window(int32_t x1, int32_t y1);
void erase_corner_window(int32_t x1, int32_t y1);
void clear_corner_window(int32_t x1, int32_t y1);
void print_in_corner_window(int32_t x1, int32_t y1, int32_t row, int32_t col, char * message);

void clear_status_line(void);
void print_in_status_line(int32_t x_pos, char * message);

#endif

