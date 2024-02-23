#include "../inc/header.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    t_area area = {0, 0};
    bool is_screen_saver = false;
    int c_delay = 60000;

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (mx_strcmp(argv[i], "-s") == 0) {
                is_screen_saver = true;
            }
        }
    }

    t_color color = {1, 2};

    int y = 0;

    const char *phrases[4] = {"Wake up , Neo..", "The matrix has you..", "Follow the white rabbit", "Knock, knock, Neo"};
    int phrases_calls[4];
    for (int i = 0; i < 4; i++) {
        phrases_calls[i] = 0;
    }
    int phrase_counter = is_screen_saver ? 4 : 0;

    int frames = 0;


    initscr();
    start_color();
    noecho();
    curs_set(FALSE);

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);


    // Получение размера окна
    getmaxyx(stdscr, area.height, area.width);

    // Создание массива rain_elements
    t_rain_string rain_elements[STRING_IN_A_ROW][area.width];
    // Заполнение массива rain_elements случайными символами
    for (int i = 0; i < STRING_IN_A_ROW; i++) {
        for (int j = 0; j < area.width; ++j) {
            int offset = 0;
            if (i > 0) {
                offset -= rain_elements[i - 1][j].size - rain_elements[i - 1][j].y_offset;
            }
            mx_randomize_rain_string(&rain_elements[i][j], area, offset, color);
        }
    }

    nodelay(stdscr, TRUE);
    // Главный цикл программы
    while (1) {
        // Определение цветовой пары


        if (frames == area.height * 2) {
            color.main = rand() % 7 + 1;
            color.secondary = color.main % 7 + 1;
            c_delay = rand() % 20001 + 50000;
            frames = 0;

        }

        clear();
        // Text animation
        if (phrase_counter != 4) {
            attron(COLOR_PAIR(2));
            for (int j = 0; j < 4; ++j) {
                if (j == phrase_counter) {
                    if (phrases_calls[j] != mx_strlen(phrases[j])) {
                        phrases_calls[j]++;
                    }
                    for (int i = 0; i <= phrases_calls[j]; ++i) {
                        mvprintw(2, 2 + i, "%c", phrases[j][i]);
                    }
                    if (phrases_calls[j] >= mx_strlen(phrases[j])) {
                        usleep(c_delay);

                        phrase_counter++;
                        usleep(c_delay);
                        usleep(c_delay);
                        clear();
                    }
                    usleep(c_delay);
                }
            }
            attroff(COLOR_PAIR(2));
        } else {
            // Rain
            mx_rain_elements_update(area, rain_elements, y, color);
            y += 1;
            frames++;
        }




        // Обновление экрана
        refresh();

        // Задержка
        usleep(c_delay);

        // Сдвиг координаты y вниз


        // Проверка нажатия клавиши "q" для выхода
        int ch = getch();
        if (ch == 'q') {
            break; // Выход из цикла
        }
    }

    // Освобождение памяти и завершение работы с ncurses
    for (int element = 0; element < STRING_IN_A_ROW; ++element) {
        for (int j = 0; j < area.width; ++j) {
            free(rain_elements[element][j].text);
        }
    }


    endwin();
    return 0;
}
