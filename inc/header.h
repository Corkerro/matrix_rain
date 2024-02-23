#ifndef HEADER_H
#define HEADER_H

// 🅸🅽🅲🅻🆄🅳🅴🆂
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// 🅳🅴🅵🅸🅽🅴🆂
#define STRING_IN_A_ROW 5

// 🆂🆃🆁🆄🅲🆃🆂
typedef struct {
    int main;
    int secondary;
} t_color;
typedef struct {
    int size;
    int time_calls;
    int y_offset;
    t_color color;
    char *text;
} t_rain_string;
typedef struct {
    int width;
    int height;
} t_area;




// 🅿🆁🅾🆃🅾🆃🆈🅴🅿🆂
int mx_strlen(const char *s);

//mx_rain_functions.c
void mx_randomize_rain_string(t_rain_string *rain_string, t_area area, int additional_offset, t_color color);
void mx_rain_elements_update(t_area area, t_rain_string rain_elements[STRING_IN_A_ROW][area.width], int y, t_color color);
int mx_strcmp(const char *s1, const char *s2);

#endif //HEADER_H
