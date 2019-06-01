
#include "menu_handlers.h"
#include "menu_main.h"

void empty_handler(void)
{

}

int32_t default_menu_keys_handler(struct st_terminal_menu * menu, struct st_key_code * key_data)
{

	int32_t input_key;
	int32_t return_status;
	int32_t option_key_handler_status;

	char message_buffer[512] = { 0 };
	int32_t points[4] = { 0 };

	struct st_terminal_menu_option * current_option;
	
#if 0
	int32_t num_of_keys;
	int32_t keys_codes[] = { 27 /*ESC*/, 10 /*ENTER*/, KEY_UP, KEY_DOWN };
	

	num_of_keys = sizeof(keys_codes)/sizeof(int32_t);

	//input_key = wait_for_keys(keys_codes, num_of_keys);

	input_key = get_key();

	
	key_code_to_char(input_key, key_data->desc);
	key_data->code = input_key;
#endif

	while(1)
	{

		input_key = get_key();

		current_option = &(menu->options[menu->current_option]);

		switch(input_key)
		{
			case KEY_ESC: /*ESC*/
				return_status = 0;
				goto exit_keys_handler_label;
				break;
			case KEY_ENTER: /*ENTER*/
				sprintf(message_buffer, "%s;%s", current_option->desc, current_option->title);
				current_option->non_void_handler(message_buffer);
				return_status = 1;
				break;
			case KEY_UP:
				if(menu->current_option >= 1)
				{
					menu->current_option--;
				}
				return_status = 2;
				goto exit_keys_handler_label;
				break;
				return 2;
			case KEY_DOWN:
				if(menu->current_option != menu->num_of_options - 1)
				{
					menu->current_option++;
				}
				return_status = 3;
				goto exit_keys_handler_label;
				break;
				return 3;
			case KEY_F(1):
				current_option->void_handler();
				return_status = 4;
				break;
			case KEY_SPACE: /*SPACE*/
				return_status = 5;
				func_finish();
				exit(1);
				break;
			case KEY_F(2):
				return_status = 6;
				points[0] = menu->x1 - 1;
				points[1] = menu->y1 - 1;
				points[2] = menu->x2 + 1;
				points[3] = menu->y2 + 1;
				draw_rectangle(points);
				break;
			default:
				option_key_handler_status = current_option->option_key_handler(input_key, menu);
				return_status = -1;
				break;
		}
	}

	exit_keys_handler_label:

	return return_status;

}

void default_option_void_handler(void)
{
	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	int32_t points[4] = { 0 };

	points[0] = max_cols - 20;
	points[1] = 5;
	points[2] = max_cols - 5;
	points[3] = 8;

	draw_rectangle(points);
}

int32_t default_option_non_void_handler(char * message)
{
	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	int32_t row_pos;
	int32_t col_pos;

	row_pos = max_rows / 2;
	col_pos = (max_cols - strlen(message)) / 2;

	int32_t comma_pos;
	char * title_ptr;

	title_ptr = NULL;
	char tmp_message_buffer[1024] = { 0 };
	char tmp_message_buffer_2[512] = { 0 };

	title_ptr = strstr(message, ";");


	if(title_ptr != NULL && title_ptr != message)
	{
		comma_pos = strlen(message) - strlen(title_ptr);
		strcpy(tmp_message_buffer_2, message);
		tmp_message_buffer_2[comma_pos] = '\0';
		sprintf(tmp_message_buffer, "desc: %s", tmp_message_buffer_2);
		clear_line(row_pos);
		print_at_point(row_pos, col_pos, tmp_message_buffer);
		sprintf(tmp_message_buffer, "title: %s", title_ptr + 1);
		clear_line(row_pos + 1);
		print_at_point(row_pos + 1, col_pos, tmp_message_buffer);
		
	}
	else
	{
		clear_line(row_pos);
		print_at_point(row_pos, col_pos, message);	
	}
	
	
}


int32_t default_option_key_handler(int32_t key_code, struct st_terminal_menu * menu)
{

	int32_t max_rows;
	int32_t max_cols;
	int32_t x_pos;
	int32_t y_pos;
	char key_desc_buffer[32] = { 0 };
	char message_buffer[128] = { 0 };

	get_screen_size(&max_rows, &max_cols);

	x_pos = max_cols - 20 + 2;
	y_pos = 5 + 1;

	key_code_to_char(key_code, key_desc_buffer);

	clear_line_at(y_pos, x_pos);
	print_at_point(y_pos, x_pos, "Key pressed: ");
	sprintf(message_buffer, "%d(%s)", key_code, key_desc_buffer);
	clear_line_at(y_pos + 1, x_pos);
	print_at_point(y_pos + 1, x_pos, message_buffer);

	return -1;
}

int32_t custom_key_handler(int32_t key_code, struct st_terminal_menu * menu)
{

	int32_t current_x_pos;
	int32_t current_y_pos;
	int32_t custom_x_pos;
	int32_t custom_y_pos;
	int32_t option_index;
	int32_t max_rows;
	int32_t max_cols;
	int32_t x_pos;
	int32_t y_pos;
	char key_desc_buffer[32] = { 0 };
	char message_buffer[128] = { 0 };

	get_screen_size(&max_rows, &max_cols);

	x_pos = max_cols - 20 + 2;
	y_pos = 5 + 1;

	key_code_to_char(key_code, key_desc_buffer);

	current_x_pos = get_current_x_pos();
	current_y_pos = get_current_y_pos();

	option_index = menu->current_option;
	struct st_option_pos * ptr;
	ptr = &(menu->options_pos[option_index]);
	custom_x_pos = ptr->x1;
	custom_y_pos = ptr->y1;

	//print_at_point(current_y_pos, current_x_pos, "HELLO FROM CUSTOM HANDLER");
	print_at_point(custom_y_pos, custom_x_pos, "HELLO FROM CUSTOM HANDLER");

	if(menu->colors_on)
	{
		on_colors(CP_RED_ON_BLACK);
	}

	clear_line_at(y_pos, x_pos);
	print_at_point(y_pos, x_pos, "Key pressed: ");
	sprintf(message_buffer, "%d(%s)", key_code, key_desc_buffer);
	clear_line_at(y_pos + 1, x_pos);
	print_at_point(y_pos + 1, x_pos, message_buffer);

	if(menu->colors_on)
	{
		off_colors(CP_RED_ON_BLACK);
	}

	return -1;
}


void custom_void_handler(void)
{
	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	int32_t points[4] = { 0 };

	points[0] = max_cols - 20;
	points[1] = 9;
	points[2] = max_cols - 5;
	points[3] = 13;


	draw_rectangle(points);


}


int32_t custom_non_void_handler(char * message)
{

	clear_screen();
	
	return -1;
}


int32_t custom_non_void_handler_1(char * message)
{

	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	clear_screen();

	draw_corner_window(max_cols - 45, 15);
	
	return -1;
}

int32_t custom_non_void_handler_2(char * message)
{

	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	erase_corner_window(max_cols - 45, 15);
	
	return -1;
}

int32_t custom_non_void_handler_3(char * message)
{

	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	clear_corner_window(max_cols - 45, 15);
	
	return -1;
}

int32_t custom_non_void_handler_4(char * message)
{

	int32_t max_rows;
	int32_t max_cols;

	get_screen_size(&max_rows, &max_cols);

	print_in_corner_window(max_cols - 45, 15, 1, 2, message);
	
	return -1;
}

int32_t custom_non_void_handler_5(char * message)
{

	clear_status_line();
	
	return -1;
}

int32_t custom_non_void_handler_6(char * message)
{

	on_colors(CP_BLACK_ON_GREEN);
	print_in_status_line(5, message);
	off_colors(CP_BLACK_ON_GREEN);
	
	return -1;
}


