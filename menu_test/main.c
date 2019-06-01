
#include "menu_main.h"
#include "menu_handlers.h"


void debug_msg(void)
{
	d_msg_e("[menu_main.c] In main(void)", "\n");
	d_msg("Test debug message\n");
}

void startup_environment(int32_t * max_rows, int32_t * max_cols)
{
	debug_msg();
	fill_ascii_key_codes_list();
	get_screen_size(max_rows, max_cols);
}

void create_new_menu(char * menu_name, int32_t x_pos, int32_t y_pos, struct st_terminal_menu * menu)
{
	init_new_menu(menu_name, menu);

	menu->in_rectangle = 1;
	menu->rectangle_autosize = 0;
	menu->colors_on = 1;
	menu->options_global_color = CP_GREEN_ON_BLACK;

	menu_set_position(x_pos, y_pos, menu);
	menu_set_rectangle_options(9, 2, 40, 8, menu);
}

void add_menu_options(struct st_terminal_menu * menu)
{

	char descs[3][128] = 
	{
		"hui hui hui",
		"bla_bla_bla",
		"na-na-na-na-na-na-na-na-na-na"
	};

	char titles[3][128] =
	{
		"option 1",
		"option 2",
		"option 3"
	};

	struct st_terminal_menu_option option;

	set_option_header(1, descs[0], titles[0], &option);
	set_option_handlers(custom_void_handler, custom_non_void_handler, NULL, &option);
	add_option_to_menu(menu, &option);

	set_option_header(2, descs[1], titles[1], &option);
	set_option_handlers(NULL, NULL, NULL, &option);
	add_option_to_menu(menu, &option);
	
	set_option_header(3, descs[2], titles[2], &option);
	set_option_handlers(NULL, NULL, custom_key_handler, &option);
	add_option_to_menu(menu, &option);
}

int32_t main(int32_t argc, char **argv)
{

	int32_t max_rows;
	int32_t max_cols;

	int32_t menu_status;
	int32_t menu_x_pos;
	int32_t menu_y_pos;

	char * menu_name = "new menu";

	menu_x_pos = 10;
	menu_y_pos = 3;

	struct st_terminal_menu menu;
	

	startup_environment(&max_rows, &max_cols);
	
	create_new_menu(menu_name, menu_x_pos, menu_y_pos, &menu);

	add_menu_options(&menu);


	func_start();

	menu_status = menu_func(&menu);
	
	func_finish();

	return 0;

}



