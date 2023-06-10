#include "ui.h"

static lv_obj_t *ui_Screen2;
static lv_obj_t *error_img;
static lv_obj_t *error_info;

LV_FONT_DECLARE(red_error);
LV_FONT_DECLARE(big_myfont);

void set_error_info(char* error_message)
{
    lv_label_set_text(error_info, "错误: ");
    lv_label_ins_text(error_info,LV_LABEL_POS_LAST,error_message);
}

void show_error_screen()
{
    lv_disp_load_scr(ui_Screen2);
}

void ui_Screen2_screen_init()
{
    ui_Screen2 = lv_obj_create(NULL, NULL);

    error_img = lv_img_create(ui_Screen2, NULL);
    lv_img_set_src(error_img, &red_error);
    lv_img_set_zoom(error_img, 200);
    lv_obj_set_x(error_img, 165);
    lv_obj_set_y(error_img, 25);
    lv_img_set_pivot(error_img, 0, 0); /*Rotate around the top left corner*/

    error_info = lv_label_create(ui_Screen2, NULL);
    lv_label_set_recolor(error_info, true);
    lv_obj_set_style_local_text_font(error_info, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &big_myfont);
    lv_obj_set_width(error_info, 200);  /// 1
    lv_obj_set_height(error_info, 150); /// 1
    lv_obj_set_x(error_info, 130);
    lv_obj_set_y(error_info, 200);
    lv_label_set_text(error_info, "错误: ");
}
