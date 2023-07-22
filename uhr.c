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

    /* Timer */

    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);
    int hour = timeinfo->tm_hour;
    int minute = timeinfo->tm_min;

    char hour0[100] = "";
    char hour1[100] = "";
    char minute0[100] = "";
    char minute1[100] = "";
    char meridiem[200] = "";

    strcpy(hour0, zero);
    strcpy(hour1, zero);
    strcpy(minute0, zero);
    strcpy(minute1, zero);
    strcpy(meridiem, am);

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

    WINDOW *separator = newwin(10, 10, 10, 30);
    refresh();

    mvwprintw(separator, 0, 0, "%s", two_points);

    wrefresh(separator);

    WINDOW *position2 = newwin(10, 10, 10, 40);
    refresh();

    mvwprintw(position2, 0, 0, "%s", minute0);

    wrefresh(position2);

    WINDOW *position3= newwin(10, 10, 10, 50);
    refresh();

    mvwprintw(position3, 0, 0, "%s", minute1);

    wrefresh(position3);

    WINDOW *ampm= newwin(10, 25, 10, 60);
    refresh();

    mvwprintw(ampm, 0, 0, "%s", meridiem);

    wrefresh(ampm);

    getch();
    endwin();

    return 0;
}
