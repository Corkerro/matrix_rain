#include "../inc/header.h"

void mx_randomize_rain_string(t_rain_string *rain_string, t_area area, int additional_offset, t_color color) {
    rain_string->time_calls = 0;
    rain_string->size = (rand() % area.height) / 2 + 5;
    rain_string->color = color;
    rain_string->y_offset = additional_offset + rand() % 51 - 51;
    if (additional_offset != 0) {
        rain_string->y_offset -= rain_string->size;
    }
    int size = area.height * 2 - rain_string->y_offset - rain_string->size;
    rain_string->text = (char *)malloc((size+ 1) * sizeof(char));
    for (int i = 0; i < size; ++i) {
        int random_ascii = rand() % (126 - 33 + 1) + 33; // Генерация ASCII-кодов от 33 до 126 (включительно)
        if (random_ascii == 32) { // Если символ является пробелом, заменяем его
            rain_string->text[i] = 'X'; // Замените 'X' на любой другой символ по вашему выбору
        } else {
            rain_string->text[i] = (char)random_ascii;
        }
    }
    rain_string->text[size] = '\0';
}


void mx_rain_elements_update(t_area area, t_rain_string rain_elements[STRING_IN_A_ROW][area.width], int y, t_color color) {
    // Обновление rain_elements и вывод строк на экран
    for (int element = 0; element < STRING_IN_A_ROW; ++element) {
        for (int j = 0; j < area.width; ++j) {
            if (rain_elements[element][j].time_calls < mx_strlen(rain_elements[element][j].text)) {
                rain_elements[element][j].time_calls++;
            }
            int personal_y = 0;
            for (int i = 0; i < rain_elements[element][j].time_calls; i++) {
                if (i < rain_elements[element][j].size) {
                    int el_color = i == 0 ? rain_elements[element][j].color.main : rain_elements[element][j].color.secondary;
                    attron(COLOR_PAIR(el_color));
                    mvprintw(y - personal_y + rain_elements[element][j].y_offset, j, "%c", rain_elements[element][j].text[rain_elements[element][j].time_calls - i - 1]);
                    personal_y++;
                    attroff(COLOR_PAIR(el_color));
                }
            }
            // Проверка, если символ вышел за пределы поля видимости внизу, перезареспавнить его
            if (y - personal_y + rain_elements[element][j].y_offset - 10 >= area.height) {
                int offset = -y;
                if (element == 0) {
                    offset -= rain_elements[element][j].y_offset - rain_elements[STRING_IN_A_ROW - 1][j].y_offset - rain_elements[STRING_IN_A_ROW - 1][j].size - rand()%11 - 10;
                } else {
                    offset -= rain_elements[element][j].y_offset - rain_elements[element - 1][j].y_offset - rain_elements[element - 1][j].size  - rand()%11 - 10;
                }

                mx_randomize_rain_string(&rain_elements[element][j], area, offset, color);
            }
        }
    }
}

