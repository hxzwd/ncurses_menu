
#include "menu_main.h"
#include "menu_handlers.h"


void d_msg(char * message)
{
	fprintf(stderr, "%s", message);
}

void d_msg_e(char * message, char * flags)
{
	char tmp_buffer[2048];
	sprintf(tmp_buffer, "%%s%s", flags); 
	fprintf(stderr, tmp_buffer, message);
}

void clear_screen(void)
{
	clear();
}

void get_screen_size(int32_t * max_rows, int32_t * max_cols)
{
	getmaxyx(stdscr, *max_rows, *max_cols);
}

void print_at_point(int32_t row_pos, int32_t col_pow, char * message)
{
	mvwprintw(stdscr, row_pos, col_pow, "%s", message);
}

int32_t get_current_x_pos(void)
{
	int32_t current_x_pos;
	int32_t current_y_pos;
	getyx(stdscr, current_y_pos, current_x_pos);
	return current_x_pos;
}

int32_t get_current_y_pos(void)
{
	int32_t current_x_pos;
	int32_t current_y_pos;
	getyx(stdscr, current_y_pos, current_x_pos);
	return current_y_pos;
}

void move_at_position(int32_t x_pos, int32_t y_pos)
{
	move(y_pos, x_pos);
}

void move_at_start_of_line(int32_t row_num)
{
	move(row_num, 0);
}

void clear_current_line(void)
{
	clrtoeol();
}

void clear_line(int32_t row_num)
{
	int32_t current_x_pos;
	int32_t current_y_pos;

	current_x_pos = get_current_x_pos();
	current_y_pos = get_current_y_pos();

	move_at_start_of_line(row_num);

	clear_current_line();

	move_at_position(current_x_pos, current_y_pos);

}

void clear_line_at(int32_t row_num, int32_t col_num)
{
	int32_t current_x_pos;
	int32_t current_y_pos;

	current_x_pos = get_current_x_pos();
	current_y_pos = get_current_y_pos();

	move_at_position(col_num, row_num);

	clear_current_line();

	move_at_position(current_x_pos, current_y_pos);

}


void fill_part_of_line(int32_t x_pos, int32_t y_pos, int32_t size_of_part, char fill_symbol)
{
	char buffer[512] = { 0 };

	for(uint32_t i = 0; i < size_of_part; i++)
	{
		buffer[i] = fill_symbol;
	}
	buffer[strlen(buffer)] = '\0';

	print_at_point(y_pos, x_pos, buffer);
}


void disable_cursor(void)
{
	curs_set(0);
}

void enable_cursor(void)
{
	curs_set(1);
}

void disable_keypad(void)
{
	keypad(stdscr, 0);
}

void enable_keypad(void)
{
	keypad(stdscr, 1);
}

void disable_echo(void)
{
	noecho();
}

void enable_echo(void)
{
	echo();
}

void set_half_delay(int32_t seconds)
{
	halfdelay(seconds * 10);
}

void enable_colors(void)
{
	start_color();
}

void set_color_pair(int32_t index, int32_t color1, int32_t color2)
{
	init_pair(index, color1, color2);
}

void refresh_screen(void)
{
	refresh();
}

void on_colors(int32_t index)
{
	attron(COLOR_PAIR(index));
}

void off_colors(int32_t index)
{
	attroff(COLOR_PAIR(index));
}



int32_t get_key_codes_list_length(void)
{
	int32_t list_length;
	/*
	fprintf(stderr, "sizeof(key_codes_list) = %d\n", sizeof(key_codes_list));
	fprintf(stderr, "sizeof(st_key_code) = %d\n", sizeof(struct st_key_code));
	*/

	list_length = sizeof(key_codes_list) / sizeof(struct st_key_code);
	return list_length;
}

int32_t check_in_key_codes_list(int32_t key_code, struct st_key_code * key_data)
{

	int32_t list_length;

	key_data->code = -1;
	strcpy(key_data->desc, "EMPTY KEY");

	list_length = get_key_codes_list_length();

	for(uint32_t i = 0; i < list_length; i++)
	{
		if(key_codes_list[i].code == key_code)
		{
			key_data->code = key_codes_list[i].code;
			strcpy(key_data->desc, key_codes_list[i].desc);
			return i;
		}
	}

	return -1;
}

void fill_ascii_key_codes_list(void)
{

	for(uint32_t i = 0; i < 256; i++)
	{
		char tmp_buffer[32] = { 0 };
		sprintf(tmp_buffer, "%c", (char)(i));
		strcpy(ascii_key_codes_list[i].desc, tmp_buffer);
		ascii_key_codes_list[i].code = i;
	}

}

int32_t check_ascii_printable(char * key_desc, struct st_key_code * key_data)
{
	int32_t top_limit;
	int32_t bottom_limit;
	int32_t top_limit_2;
	int32_t bottom_limit_2;

	//'!'
	top_limit = 33;
	//'~'
	bottom_limit = 126;

	//`¡`
	top_limit_2 = 161;
	//`ÿ`
	bottom_limit_2 = 255;

	for(uint32_t i = top_limit; i <= bottom_limit; i++)
	{
		if(!strcmp(ascii_key_codes_list[i].desc, key_desc))
		{
			key_data->code = ascii_key_codes_list[i].code;
			strcpy(key_data->desc, ascii_key_codes_list[i].desc);
			return 1000 + i;
		}
	}

	for(uint32_t i = top_limit_2; i <= bottom_limit_2; i++)
	{
		if(!strcmp(ascii_key_codes_list[i].desc, key_desc))
		{
			key_data->code = ascii_key_codes_list[i].code;
			strcpy(key_data->desc, ascii_key_codes_list[i].desc);
			return 1000 + i;
		}

	}

	return  -1;

}

int32_t check_in_key_codes_list_by_desc(char * key_desc, struct st_key_code * key_data)
{

	int32_t list_length;

	key_data->code = -1;
	strcpy(key_data->desc, "EMPTY KEY");

	list_length = get_key_codes_list_length();

	for(uint32_t i = 0; i < list_length; i++)
	{
		if(!strcmp(key_codes_list[i].desc, key_desc))
		{
			key_data->code = key_codes_list[i].code;
			strcpy(key_data->desc, key_codes_list[i].desc);
			return i;
		}
	}

	int32_t ascii_list_index;
	
	ascii_list_index = check_ascii_printable(key_desc, key_data);

	if(ascii_list_index != -1)
	{
		return ascii_list_index;
	}

	return -1;
}

int32_t get_key(void)
{
	int32_t key_code;

	key_code = getch();
	
	return key_code;
}

void key_code_to_char(int32_t key_code, char * buffer)
{

	int32_t list_index;
	int32_t top_limit;
	int32_t bottom_limit;
	int32_t top_limit_2;
	int32_t bottom_limit_2;
	int32_t f_top_limit;
	int32_t f_bottom_limit;

	struct st_key_code key_data;

	//'!'
	top_limit = 33;
	//'~'
	bottom_limit = 126;

	//`¡`
	top_limit_2 = 161;
	//`ÿ`
	bottom_limit_2 = 255;

	//F1
	f_top_limit = 265;
	//F12
	f_bottom_limit = 276;

	if((key_code >= top_limit && key_code <= bottom_limit) || (key_code >= top_limit_2 && key_code <= bottom_limit_2))
	{
		sprintf(buffer, "%c", (char)(key_code));
		return;
	}

	if(key_code >= f_top_limit && key_code <= f_bottom_limit)
	{
		sprintf(buffer, "F%d", key_code - f_top_limit + 1);
		return;
	}

	list_index = check_in_key_codes_list(key_code, &key_data);

	if(list_index != -1)
	{
		sprintf(buffer, "%s", key_data.desc);
	}
	else
	{
		sprintf(buffer, "UNKNOWN KEY");
	}

	return;


	// if(key_code >= top_limit && key_code <= bottom_limit)
	// {
	// 	char result;
	// 	result = (char)(key_code);
	// }

	
}

int32_t wait_for_key(int32_t key_code)
{

	int32_t input_key;

	while(1)
	{
		input_key = get_key();
		if(input_key == key_code)
		{
			break;
		}
	}

	return input_key;
}

int32_t wait_for_key_d(int32_t key_code)
{

	int32_t input_key;
	char key_desc_buffer[128] = { 0 };
	char input_key_desc_buffer[128] = { 0 };

	key_code_to_char(key_code, key_desc_buffer);

	while(1)
	{
		input_key = get_key();
		
		key_code_to_char(input_key, input_key_desc_buffer);

		printw("input_key = %d(%s) ", input_key, input_key_desc_buffer);
		printw("[waited key: %d(%s)]\n", key_code, key_desc_buffer);
		
		if(input_key == key_code)
		{
			key_code_to_char(input_key, input_key_desc_buffer);
			
			printw("Keys codes match!:\ninput_key = %d(%s)\n", input_key, input_key_desc_buffer);
			printw("key_code = %d(%s)\n", key_code, key_desc_buffer);
			
			break;
		}
	}

	return input_key;
}

int32_t wait_for_key_desc(char * key_desc)
{

	int32_t result_key;
	int32_t list_index;
	int32_t key_code;

	struct st_key_code key_data;

	result_key = -1;

	list_index = check_in_key_codes_list_by_desc(key_desc, &key_data);

	if(list_index == -1)
	{
		return result_key;
	}

	key_code = key_data.code;

	result_key = wait_for_key(key_code);

	return result_key;
}

int32_t wait_for_key_desc_d(char * key_desc)
{

	int32_t result_key;
	int32_t list_index;
	int32_t key_code;

	struct st_key_code key_data;

	result_key = -1;

	printw("[waited key: (%s)]\n", key_desc);

	list_index = check_in_key_codes_list_by_desc(key_desc, &key_data);

	if(list_index == -1)
	{
		return result_key;
	}

	key_code = key_data.code;

	result_key = wait_for_key_d(key_code);

	return result_key;

}

int32_t wait_for_keys_d(int32_t * keys_code, int32_t num_of_keys)
{

	int32_t input_key;
	char key_desc_buffer[128] = { 0 };

	while(1)
	{
		printw("waited keys (array length is %d):\n", num_of_keys);
		for(uint32_t i = 0; i < num_of_keys; i++)
		{
			key_code_to_char(keys_code[i], key_desc_buffer);
			printw("%d(%s) ", keys_code[i], key_desc_buffer);
		}
		input_key = get_key();
		key_code_to_char(input_key, key_desc_buffer);
		printw("\ninput_key = %d(%s)\n", input_key, key_desc_buffer);
		for(uint32_t i = 0; i < num_of_keys; i++)
		{
			if(input_key == keys_code[i])
			{
				key_code_to_char(input_key, key_desc_buffer);
				printw("Keys codes match!:\ninput_key = %d(%s)\n", input_key, key_desc_buffer);
				key_code_to_char(keys_code[i], key_desc_buffer);
				printw("keys_code[%d] = %d(%s)\n", i, keys_code[i], key_desc_buffer);
				return input_key;
			}
		}

	}

	return input_key;
}

int32_t wait_for_keys(int32_t * keys_code, int32_t num_of_keys)
{

	int32_t input_key;

	while(1)
	{
		input_key = get_key();
		for(uint32_t i = 0; i < num_of_keys; i++)
		{
			if(input_key == keys_code[i])
			{
				return input_key;
			}
		}

	}

	return input_key;
}

int32_t wait_for_keys_desc_d(char * keys_desc[], int32_t num_of_keys)
{

	int32_t result_key;
	int32_t list_index;

	 struct st_key_code key_data;

	char key_desc_buffer[128] = { 0 };

	int32_t * keys_codes;

	result_key = -1;
	keys_codes = NULL;
	keys_codes = (int32_t *)(malloc(sizeof(int32_t) * num_of_keys));

	printw("waited keys desc: (array length is %d)\n", num_of_keys);
	for(uint32_t i = 0; i < num_of_keys; i++)
	{
		printw("(%s) ", keys_desc[i]);
	}
	printw("\n");

	if(keys_codes == NULL)
	{
		fprintf(stderr, "In function: wait_for_keys_desc_d()\nAllocation memory error\n");
		fprintf(stderr, "Bytes requred: sizeof(int32_t) * num_of_keys = %d\n", sizeof(int32_t) * num_of_keys);
		fprintf(stderr, "Return result_key = -1 from function\n");
		return result_key;
	}

	for(uint32_t i = 0; i < num_of_keys; i++)
	{
		list_index = check_in_key_codes_list_by_desc(keys_desc[i], &key_data);
		if(list_index == -1)
		{
			keys_codes[i] = -1;
		}
		else
		{
			keys_codes[i] = key_data.code;
		}
	}

	result_key = wait_for_keys_d(keys_codes, num_of_keys);

	if(keys_codes)
	{
		free(keys_codes);
	}

	return result_key;

}

int32_t wait_for_keys_desc(char * keys_desc[], int32_t num_of_keys)
{

	int32_t result_key;
	int32_t list_index;

	 struct st_key_code key_data;

	char key_desc_buffer[128] = { 0 };

	int32_t * keys_codes;

	result_key = -1;
	keys_codes = NULL;
	keys_codes = (int32_t *)(malloc(sizeof(int32_t) * num_of_keys));

	if(keys_codes == NULL)
	{
		fprintf(stderr, "In function: wait_for_keys_desc_d()\nAllocation memory error\n");
		fprintf(stderr, "Bytes requred: sizeof(int32_t) * num_of_keys = %d\n", sizeof(int32_t) * num_of_keys);
		fprintf(stderr, "Return result_key = -1 from function\n");
		return result_key;
	}

	for(uint32_t i = 0; i < num_of_keys; i++)
	{
		list_index = check_in_key_codes_list_by_desc(keys_desc[i], &key_data);
		if(list_index == -1)
		{
			keys_codes[i] = -1;
		}
		else
		{
			keys_codes[i] = key_data.code;
		}
	}

	result_key = wait_for_keys(keys_codes, num_of_keys);

	if(keys_codes)
	{
		free(keys_codes);
	}

	return result_key;
}

void func_start(void)
{
	initscr();
	disable_cursor();
	enable_keypad();
	disable_echo();
	set_half_delay(10);
	enable_colors();
	set_color_pair(CP_RED_ON_BLACK, COLOR_RED, COLOR_BLACK);
	set_color_pair(CP_GREEN_ON_BLACK, COLOR_GREEN, COLOR_BLACK);
	set_color_pair(CP_BLUE_ON_BLACK, COLOR_BLUE, COLOR_BLACK);
	set_color_pair(CP_BLACK_ON_GREEN, COLOR_BLACK, COLOR_GREEN);
}

void func_finish(void)
{
	endwin();
}

void draw_rectangle(int32_t points[])
{
	int32_t y1;
	int32_t y2;
	int32_t x1;
	int32_t x2;

	x1 = points[0];
	y1 = points[1];
	x2 = points[2];
	y2 = points[3];

	mvhline(y1, x1, 0, x2 - x1);
	mvhline(y2, x1, 0, x2 - x1);
	mvvline(y1, x1, 0, y2 - y1);
	mvvline(y1, x2, 0, y2 - y1);
	mvaddch(y1, x1, ACS_ULCORNER);
	mvaddch(y2, x1, ACS_LLCORNER);
	mvaddch(y1, x2, ACS_URCORNER);
	mvaddch(y2, x2, ACS_LRCORNER);
}


void copy_menu_option(struct st_terminal_menu_option * dest, struct st_terminal_menu_option * src)
{
	dest->index = src->index;
	strcpy(dest->desc, src->desc);
	strcpy(dest->title, src->title);
	dest->void_handler = src->void_handler;
	dest->non_void_handler = src->non_void_handler;
	dest->option_key_handler = src->option_key_handler;
}

void add_option_to_menu(struct st_terminal_menu * menu, struct st_terminal_menu_option * option)
{
	int32_t option_index;

	option_index = menu->num_of_options;
	menu->num_of_options++;

	copy_menu_option(&menu->options[option_index], option);
}

void init_new_menu(char * name, struct st_terminal_menu * menu)
{
	strcpy(menu->name, name);
	menu->num_of_options = 0;
	menu->current_option = -1;
	menu->keys_handler = default_menu_keys_handler;
	menu->x_pos = 0;
	menu->y_pos = 0;
	menu->x1 = 0;
	menu->y1 = 0;
	menu->x2 = 0;
	menu->y2 = 0;
	menu->in_rectangle = 0;
	menu->rectangle_autosize = 0;
	for(uint32_t i = 0; i < 4; i++)
	{
		menu->rectangle_points[i] = 0;
	}
	menu->colors_on = 0;
	menu->options_global_color = 0;
	strcpy(menu->option_pointer_active, "> ");
	strcpy(menu->option_pointer_inactive, "  ");
}

void init_new_option(int32_t index, char * desc, char * title, void (*void_h)(void), int32_t (*non_void_h)(char *), int32_t (*key_h)(int32_t, struct st_terminal_menu *), struct st_terminal_menu_option * option)
{
	option->index = index;
	strcpy(option->desc, desc);
	strcpy(option->title, title);

	if(void_h != NULL)
	{
		option->void_handler = void_h;
	}
	else
	{
		option->void_handler = default_option_void_handler;
	}
	
	if(non_void_h != NULL)
	{
		option->non_void_handler = non_void_h;
	}
	else
	{
		option->non_void_handler = default_option_non_void_handler;
	}

	if(key_h != NULL)
	{
		option->option_key_handler = key_h;
	}
	else
	{
		option->option_key_handler = default_option_key_handler;
	}
	
}

void set_option_header(int32_t index, char * desc, char * title, struct st_terminal_menu_option * option)
{
	option->index = index;
	strcpy(option->desc, desc);
	strcpy(option->title, title);
}

void set_option_handlers(void (*void_h)(void), int32_t (*non_void_h)(char *), int32_t (*key_h)(int32_t, struct st_terminal_menu *), struct st_terminal_menu_option * option)
{
	if(void_h != NULL)
	{
		option->void_handler = void_h;
	}
	else
	{
		option->void_handler = default_option_void_handler;
	}
	
	if(non_void_h != NULL)
	{
		option->non_void_handler = non_void_h;
	}
	else
	{
		option->non_void_handler = default_option_non_void_handler;
	}

	if(key_h != NULL)
	{
		option->option_key_handler = key_h;
	}
	else
	{
		option->option_key_handler = default_option_key_handler;
	}
}

void set_option_position(int32_t index, int32_t x1, int32_t y1, int32_t x2, int32_t y2, struct st_terminal_menu * menu)
{
	struct st_option_pos * ptr;
	ptr = &(menu->options_pos[index]);
	ptr->x1 = x1;
	ptr->y1 = y1;
	ptr->x2 = x2;
	ptr->y2 = y2;
}

void draw_menu(struct st_terminal_menu * menu)
{
	int32_t current_x_pos;
	int32_t current_y_pos;
	int32_t menu_x_pos;
	int32_t menu_y_pos;
	int32_t tmp_current_x_pos;
	int32_t tmp_current_y_pos;

	current_x_pos = get_current_x_pos();
	current_y_pos = get_current_y_pos();

	menu_x_pos = menu->x_pos;
	menu_y_pos = menu->y_pos;

	clear_screen();

	menu->x1 = menu_x_pos;
	menu->y1 = menu_y_pos;
	menu->x2 = menu_x_pos;
	menu->y2 = menu_y_pos;

	move_at_position(menu_x_pos, menu_y_pos);

	for(uint32_t i = 0; i < menu->num_of_options; i++)
	{
		move_at_position(menu_x_pos, menu_y_pos + i);


		if(i == menu->current_option)
		{
			printw(menu->option_pointer_active);
		}
		else
		{
			printw(menu->option_pointer_inactive);
		}

		printw("%s", menu->options[i].title);

		tmp_current_x_pos = get_current_x_pos();

		set_option_position(i, menu_x_pos, menu_y_pos + i, tmp_current_x_pos, menu_y_pos + i, menu);

		if(tmp_current_x_pos > menu->x2)
		{
			menu->x2 = tmp_current_x_pos;
		}
	}

	tmp_current_y_pos = get_current_y_pos();

	menu->y2 = tmp_current_y_pos;

	move_at_position(current_x_pos, current_y_pos);
}

void apply_menu_settings(struct st_terminal_menu * menu)
{
	int32_t points[4] = { 0 };

	if(menu->in_rectangle)
	{
		if(menu->rectangle_autosize)
		{
			points[0] = menu->x1 - 1;
			points[1] = menu->y1 - 1;
			points[2] = menu->x2 + 1;
			points[3] = menu->y2 + 1;
			draw_rectangle(points);
		}
		else
		{
			draw_rectangle(menu->rectangle_points);
		}
	}

}

void redraw_menu(struct st_terminal_menu * menu)
{
	int32_t current_x_pos;
	int32_t current_y_pos;
	int32_t menu_x_pos;
	int32_t menu_y_pos;
	int32_t tmp_current_x_pos;
	int32_t tmp_current_y_pos;

	current_x_pos = get_current_x_pos();
	current_y_pos = get_current_y_pos();

	menu_x_pos = menu->x_pos;
	menu_y_pos = menu->y_pos;

	menu->x1 = menu_x_pos;
	menu->y1 = menu_y_pos;
	menu->x2 = menu_x_pos;
	menu->y2 = menu_y_pos;

	move_at_position(menu_x_pos, menu_y_pos);

	for(uint32_t i = 0; i < menu->num_of_options; i++)
	{
		move_at_position(menu_x_pos, menu_y_pos + i);
		
		if(i == menu->current_option)
		{
			printw(menu->option_pointer_active);
		}
		else
		{
			printw(menu->option_pointer_inactive);
		}

		printw("%s", menu->options[i].title);

		tmp_current_x_pos = get_current_x_pos();

		set_option_position(i, menu_x_pos, menu_y_pos + i, tmp_current_x_pos, menu_y_pos + i, menu);

		if(tmp_current_x_pos > menu->x2)
		{
			menu->x2 = tmp_current_x_pos;
		}
	
	}

	tmp_current_y_pos = get_current_y_pos();

	menu->y2 = tmp_current_y_pos;

	move_at_position(current_x_pos, current_y_pos);

}

void on_menu_color(struct st_terminal_menu * menu)
{
	if(menu->colors_on)
	{
		on_colors(menu->options_global_color);
	}
}

void off_menu_color(struct st_terminal_menu * menu)
{
	if(menu->colors_on)
	{
		off_colors(menu->options_global_color);
	}
}

int32_t menu_func(struct st_terminal_menu * menu)
{
	menu->current_option = -1;
	
	on_menu_color(menu);
	draw_menu(menu);
	off_menu_color(menu);
	

	apply_menu_settings(menu);

	

	while(1)
	{
		int32_t status;
		struct st_key_code key_data;

		on_menu_color(menu);
		redraw_menu(menu);
		off_menu_color(menu);

		apply_menu_settings(menu);

		status = menu->keys_handler(menu, &key_data);

		if(status == 0)
		{
			return 0;
		}
	}
}

void menu_set_position(int32_t x_pos, int32_t y_pos, struct st_terminal_menu * menu)
{
	menu->x_pos = x_pos;
	menu->y_pos = y_pos;
}

void menu_set_rectangle_options(int32_t x1, int32_t y1, int32_t x2, int32_t y2, struct st_terminal_menu * menu)
{
	menu->rectangle_points[0] = x1;
	menu->rectangle_points[1] = y1;
	menu->rectangle_points[2] = x2;
	menu->rectangle_points[3] = y2;
}


void draw_corner_window(int32_t x1, int32_t y1)
{
	int32_t max_rows;
	int32_t max_cols;

	
	int32_t points[4] = { 0 };
	
	get_screen_size(&max_rows, &max_cols);
	
	points[0] = x1;
	points[1] = y1;
	points[2] = max_cols - 1;
	points[3] = max_rows - 1;

	draw_rectangle(points);

}

void erase_corner_window(int32_t x1, int32_t y1)
{
	int32_t max_rows;
	int32_t max_cols;

	
	int32_t points[4] = { 0 };
	
	get_screen_size(&max_rows, &max_cols);
	
	points[0] = x1;
	points[1] = y1;
	points[2] = max_cols;
	points[3] = max_rows;

	for(uint32_t i = y1; i <= max_rows; i++)
	{
		clear_line_at(i, x1);
	}

}

void clear_corner_window(int32_t x1, int32_t y1)
{
	erase_corner_window(x1, y1);
	draw_corner_window(x1, y1);

}

void print_in_corner_window(int32_t x1, int32_t y1, int32_t row, int32_t col, char * message)
{
	int32_t current_x_pos;
	int32_t current_y_pos;
	int32_t print_x_pos;
	int32_t print_y_pos;
	int32_t message_len;
	int32_t max_rows;
	int32_t max_cols;
	int32_t window_width;
	int32_t window_height;

	get_screen_size(&max_rows, &max_cols);

	current_x_pos = get_current_x_pos();
	current_y_pos = get_current_y_pos();

	print_x_pos = x1 + col + 1;
	print_y_pos = y1 + row + 1;

	message_len = strlen(message);
	window_width = max_cols - x1;
	window_height = max_rows - y1;

	if(message_len > window_width)
	{
		char tmp_buffer[1024] = { 0 };
		memcpy(tmp_buffer, message, window_width - col - 1);
		print_at_point(print_y_pos, print_x_pos, tmp_buffer);
		print_in_corner_window(x1, y1, row + 1, col, &(message[window_width - col - 1]));
	}
	else
	{
		print_at_point(print_y_pos, print_x_pos, message);
	}

	//move_at_position(current_x_pos, current_y_pos);
}

void clear_status_line(void)
{
	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	clear_line(max_rows - 1);
}

void print_in_status_line(int32_t x_pos, char * message)
{
	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	print_at_point(max_rows - 1, x_pos, message);
}

int32_t main_old_4(int32_t argc, char **argv)
{

	d_msg_e("[menu_main.c] In main(void)", "\n");
	d_msg("Test debug message");
	

	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	fill_ascii_key_codes_list();

	
	int32_t menu_status;
	int32_t menu_x_pos;
	int32_t menu_y_pos;

	struct st_terminal_menu menu;
	struct st_terminal_menu_option option;

	init_new_menu("new menu", &menu);

	init_new_option(1, "hui hui hui", "option 1", NULL, NULL, NULL, &option);
	add_option_to_menu(&menu, &option);

	init_new_option(2, "bla_bla_bla", "option 2", NULL, NULL, NULL, &option);
	add_option_to_menu(&menu, &option);
	
	init_new_option(3, "na-na-na-na-na-na-na-na-na-na", "option 3", NULL, NULL, custom_key_handler, &option);
	add_option_to_menu(&menu, &option);
	
	menu_x_pos = 10;
	menu_y_pos = 3;

	menu_set_position(menu_x_pos, menu_y_pos, &menu);
	menu_set_rectangle_options(9, 2, 40, 8, &menu);
	menu.in_rectangle = 1;
	menu.rectangle_autosize = 0;
	menu.colors_on = 1;
	menu.options_global_color = CP_GREEN_ON_BLACK;

	func_start();

	menu_status = menu_func(&menu);
	
	func_finish();

	return 0;

}



int32_t main_old_3(int32_t argc, char **argv)
{

	d_msg_e("[menu_main.c] In main(void)", "\n");
	d_msg("Test debug message");
	

	fill_ascii_key_codes_list();

	struct st_terminal_menu menu;
	struct st_terminal_menu_option option;

	init_new_menu("new menu", &menu);
	init_new_option(1, "hui hui hui", "option 1", NULL, NULL, NULL, &option);
	add_option_to_menu(&menu, &option);
	init_new_option(2, "bla_bla_bla", "option 2", NULL, NULL, NULL, &option);
	add_option_to_menu(&menu, &option);
	init_new_option(3, "na-na-na-na-na-na-na-na-na-na", "option 3", NULL, NULL, NULL, &option);
	add_option_to_menu(&menu, &option);
	

	func_start();

	menu.current_option = -1;
	
	draw_menu(&menu);

	while(1)
	{
		
		int32_t status;
		struct st_key_code key_data;

		redraw_menu(&menu);

		status = menu.keys_handler(&menu, &key_data);

		if(status == 0)
		{
			break;
		}
	}

	finish_label:

/*
	int32_t key_code;
	int32_t num_of_keys;
	char * keys_desc_array[] = { "F1", "SPACE", "A", "c" };
	num_of_keys = 4;


	key_code = wait_for_keys_desc_d(keys_desc_array, num_of_keys);

	printw("key_code = %d\n", key_code);
*/
	func_finish();

	return 0;

}

int32_t main_old_2(int32_t argc, char **argv)
{

	d_msg_e("[menu_main.c] In main(void)", "\n");
	d_msg("Test debug message");


	func_start();

	int32_t key_code;
	int32_t keys_array[] = { KEY_F(1), 'q' };

	key_code = wait_for_keys_d(keys_array, 2);

	printw("key_code = %d\n", key_code);

	func_finish();

	return 0;

}



int32_t main_old(void)
{

	d_msg_e("[menu_main.c] In main(void)", "\n");
	d_msg("Test debug message\n");
	
	func_start();

	while(1)
	{
		int32_t key_code;
		key_code = get_key();
		switch(key_code)
		{
			case 'q':
				printw("Bye\n");
				break;
			case KEY_F(2):
				printw("Key F2 pressed\n");
				goto finish_label;
			default:
				printw("Key code: key_code = %d\n", key_code);
				break;
		}
	}


finish_label:

	func_finish();

	return 0;

}

