/* uhr.c
 *
 * Copyright (c) 2023, Ivan Guerreschi <ivanguerreschi86@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <ncurses.h>
#include <string.h>
#include <time.h>

int main(void) {

    /* Symbols */

    const char *one =
        " __ \n"
        "/_ |\n"
        " | |\n"
        " | |\n"
        " | |\n"
        " |_| ";

    const char *two =
        " ___  \n"
        "|__ \\\n"
        "   ) |\n"
        "  / / \n"
        " / /_ \n"
        "|____| ";

    const char *three =
        " ____  \n"
        "|___ \\\n"
        "  __) |\n"
        " |__ < \n"
        " ___) |\n"
        "|____/  ";

    const char *four =
        " _  _   \n"
        "| || |  \n"
        "| || |_ \n"
        "|__   _|\n"
        "   | |  \n"
        "   |_|   ";

    const char *five =
        " _____  \n"
        "| ____| \n"
        "| |__   \n"
        "|___ \\ \n"
        " ___) | \n"
        "|____/   ";

    const char *six =
        "   __   \n"
        "  / /   \n"
        " / /_   \n"
        "| '_ \\ \n"
        "| (_) | \n"
        " \\___/  ";

    const char *seven =
        " ______ \n"
        "|____  |\n"
        "    / / \n"
        "  / /   \n"
        " / /    \n"
        "/_/      ";

    const char *eight =
        "  ___  \n"
        " / _ \\\n"
        "| (_) |\n"
        " > _ < \n"
        "| (_) |\n"
        " \\___/ ";

    const char *nine =
        "  ___   \n"
        " / _ \\ \n"
        "| (_) | \n"
        " \\__, |\n"
        "   / /  \n"
        "  /_/    ";

    const char *zero =
        "  ___   \n"
        " / _ \\ \n"
        "| | | | \n"
        "| | | | \n"
        "| |_| | \n"
        " \\___/  ";

    const char *am =
        "          __  __    \n"
        "    /\\   |  \\/  | \n"
        "   /  \\  | \\  / | \n"
        "  / /\\ \\ | |\\/| |\n"
        " / ____ \\| |  | |  \n"
        "/_/    \\_\\_|  |_|  ";

    const char *pm =
        " _____  __  __   \n"
        "|  __ \\|  \\/  |\n"
        "| |__) | \\  / | \n"
        "|  ___/| |\\/| | \n"
        "| |    | |  | |  \n"
        "|_|    |_|  |_|   ";

    const char *two_points =
        " _ \n"
        "(_)\n"
        "   \n"
        " _ \n"
        "(_)\n"
        "   ";

    /* Time management */

    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);
    int hour = timeinfo->tm_hour;
    int minute = timeinfo->tm_min;

    char hour0[100] = {0};
    char hour1[100] = {0};
    char minute0[100] = {0};
    char minute1[100] = {0};
    char meridiem[200] = "";

    strcpy(hour0, zero);
    strcpy(hour1, zero);
    strcpy(minute0, zero);
    strcpy(minute1, zero);
    strcpy(meridiem, am);

    char substring_hour[3];
    sprintf(substring_hour, "%d", hour);

    char substring_minute[3];
    sprintf(substring_minute, "%d", minute);

    /* Remove warnings because reset after string termination with '\0' */
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wstringop-truncation"
        strncpy(hour0, substring_hour, 1);
        strncpy(hour1, substring_hour + 1, 1);
        strncpy(minute0, substring_minute, 1);
        strncpy(minute1, substring_minute + 1, 1);
    #pragma GCC diagnostic pop

    /* Add string terminator truncated by strncpy */
    hour0[1] = '\0';
    hour1[1] = '\0';
    minute0[1] = '\0';
    minute1[1] = '\0';

    if (hour > 12)
        strcpy(meridiem, pm);
    else
        strcpy(meridiem, am);

    if (hour1[0] == '\0') {
        strcpy(hour1, hour0);
        strcpy(hour0, zero);
    }

    else if (strcmp(hour0, "0") == 0)
        strcpy(hour0, zero);

    else if (strcmp(hour0, "1") == 0)
        strcpy(hour0, one);

    else if (strcmp(hour0, "2") == 0)
        strcpy(hour0, two);

    else if (strcmp(hour0, "3") == 0)
        strcpy(hour0, three);

    else if (strcmp(hour0, "4") == 0)
        strcpy(hour0, four);

    else if (strcmp(hour0, "5") == 0)
        strcpy(hour0, five);

    else if (strcmp(hour0, "6") == 0)
        strcpy(hour0, six);

    else if (strcmp(hour0, "7") == 0)
        strcpy(hour0, seven);

    else if (strcmp(hour0, "8") == 0)
        strcpy(hour0, eight);

    else
        strcpy(hour0, nine);

    if (strcmp(hour1, "0") == 0)
        strcpy(hour1, zero);

    else if (strcmp(hour1, "1") == 0)
        strcpy(hour1, one);

    else if (strcmp(hour1, "2") == 0)
        strcpy(hour1, two);

    else if (strcmp(hour1, "3") == 0)
        strcpy(hour1, three);

    else if (strcmp(hour1, "4") == 0)
        strcpy(hour1, four);

    else if (strcmp(hour1, "5") == 0)
        strcpy(hour1, five);

    else if (strcmp(hour1, "6") == 0)
        strcpy(hour1, six);

    else if (strcmp(hour1, "7") == 0)
        strcpy(hour1, seven);

    else if (strcmp(hour1, "8") == 0)
        strcpy(hour1, eight);

    else
        strcpy(hour1, nine);

    if (minute1[0] == '\0') {
        strcpy(minute1, minute0);
        strcpy(minute0, zero);
    }

    else if (strcmp(minute0, "0") == 0)
        strcpy(minute0, zero);

    else if (strcmp(minute0, "1") == 0)
        strcpy(minute0, one);

    else if (strcmp(minute0, "2") == 0)
        strcpy(minute0, two);

    else if (strcmp(minute0, "3") == 0)
        strcpy(minute0, three);

    else if (strcmp(minute0, "4") == 0)
        strcpy(minute0, four);

    else if (strcmp(minute0, "5") == 0)
        strcpy(minute0, five);

    else if (strcmp(minute0, "6") == 0)
        strcpy(minute0, six);

    else if (strcmp(minute0, "7") == 0)
        strcpy(minute0, seven);

    else if (strcmp(minute0, "8") == 0)
        strcpy(minute0, eight);

    else
        strcpy(minute0, nine);

    if (strcmp(minute1, "0") == 0)
        strcpy(minute1, zero);

    else if (strcmp(minute1, "1") == 0)
        strcpy(minute1, one);

    else if (strcmp(minute1, "2") == 0)
        strcpy(minute1, two);

    else if (strcmp(minute1, "3") == 0)
        strcpy(minute1, three);

    else if (strcmp(minute1, "4") == 0)
        strcpy(minute1, four);

    else if (strcmp(minute1, "5") == 0)
        strcpy(minute1, five);

    else if (strcmp(minute1, "6") == 0)
        strcpy(minute1, six);

    else if (strcmp(minute1, "7") == 0)
        strcpy(minute1, seven);

    else if (strcmp(minute1, "8") == 0)
        strcpy(minute1, eight);

    else
        strcpy(minute1, nine);

    /* Ncurses */

    initscr();

    curs_set(0);

    WINDOW *position0 = newwin(10, 10, 10, 10);
    refresh();

    mvwprintw(position0, 0, 0, "%s", hour0);

    wrefresh(position0);

    WINDOW *position1 = newwin(10, 10, 10, 20);
    refresh();

    mvwprintw(position1, 0, 0, "%s", hour1);

    wrefresh(position1);

    WINDOW *separator = newwin(10, 5, 10, 30);
    refresh();

    mvwprintw(separator, 0, 0, "%s", two_points);

    wrefresh(separator);

    WINDOW *position2 = newwin(10, 10, 10, 36);
    refresh();

    mvwprintw(position2, 0, 0, "%s", minute0);

    wrefresh(position2);

    WINDOW *position3= newwin(10, 10, 10, 46);
    refresh();

    mvwprintw(position3, 0, 0, "%s", minute1);

    wrefresh(position3);

    WINDOW *ampm= newwin(10, 25, 10, 56);
    refresh();

    mvwprintw(ampm, 0, 0, "%s", meridiem);

    wrefresh(ampm);

    getch();
    endwin();

    return 0;
}
