/* uhr.c
   
   Copyright (C) 2023 Ivan Guerreschi <ivanguerreschi86@gmailcom>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int
main (void)
{
  char hour0[100] = { 0 };
  char hour1[100] = { 0 };
  char minute0[100] = { 0 };
  char minute1[100] = { 0 };

  int hour = 0;
  int minute = 0;

  char substring_hour[3] = { 0 };
  char substring_minute[3] = { 0 };

  const char *one = " __ \n" "/_ |\n" " | |\n" " | |\n" " | |\n" " |_| ";

  const char *two =
    " ___  \n" "|__ \\\n" "   ) |\n" "  / / \n" " / /_ \n" "|____| ";

  const char *three =
    " ____  \n" "|___ \\\n" "  __) |\n" " |__ < \n" " ___) |\n" "|____/  ";

  const char *four =
    " _  _   \n"
    "| || |  \n" "| || |_ \n" "|__   _|\n" "   | |  \n" "   |_|   ";

  const char *five =
    " _____  \n"
    "| ____| \n" "| |__   \n" "|___ \\ \n" " ___) | \n" "|____/   ";

  const char *six =
    "   __   \n"
    "  / /   \n" " / /_   \n" "| '_ \\ \n" "| (_) | \n" " \\___/  ";

  const char *seven =
    " ______ \n"
    "|____  |\n" "    / / \n" "  / /   \n" " / /    \n" "/_/      ";

  const char *eight =
    "  ___  \n" " / _ \\\n" "| (_) |\n" " > _ < \n" "| (_) |\n" " \\___/ ";

  const char *nine =
    "  ___   \n"
    " / _ \\ \n" "| (_) | \n" " \\__, |\n" "   / /  \n" "  /_/    ";

  const char *zero =
    "  ___   \n"
    " / _ \\ \n" "| | | | \n" "| | | | \n" "| |_| | \n" " \\___/  ";

  const char *two_points = " _ \n" "(_)\n" "   \n" " _ \n" "(_)\n" "   ";

  initscr ();
  curs_set (0);

  WINDOW *position0 = newwin (10, 10, 10, 10);
  refresh ();
  mvwprintw (position0, 0, 0, "%s", hour0);
  wrefresh (position0);

  WINDOW *position1 = newwin (10, 10, 10, 20);
  refresh ();
  mvwprintw (position1, 0, 0, "%s", hour1);
  wrefresh (position1);

  WINDOW *separator = newwin (10, 5, 10, 30);
  refresh ();
  mvwprintw (separator, 0, 0, "%s", two_points);
  wrefresh (separator);

  WINDOW *position2 = newwin (10, 10, 10, 36);
  refresh ();
  mvwprintw (position2, 0, 0, "%s", minute0);
  wrefresh (position2);

  WINDOW *position3 = newwin (10, 10, 10, 46);
  refresh ();
  mvwprintw (position3, 0, 0, "%s", minute1);
  wrefresh (position3);

  for (;;)
    {
      double interval = 1;
      time_t start = time (NULL);

      sleep (interval);

      time_t rawtime = time (NULL);
      struct tm *timeinfo = localtime (&rawtime);

      hour = timeinfo->tm_hour;
      minute = timeinfo->tm_min;

      sprintf (substring_hour, "%d", hour);
      sprintf (substring_minute, "%d", minute);

      /* Remove warnings because reset after string termination with '\0' */
      #pragma GCC diagnostic push
      #pragma GCC diagnostic ignored "-Wstringop-truncation"
        strncpy (hour0, substring_hour, 1);
        strncpy (hour1, substring_hour + 1, 1);
        strncpy (minute0, substring_minute, 1);
        strncpy (minute1, substring_minute + 1, 1);
      #pragma GCC diagnostic pop

      /* Add string terminator truncated by strncpy */
      hour0[1] = '\0';
      hour1[1] = '\0';
      minute0[1] = '\0';
      minute1[1] = '\0';

      if (hour1[0] == '\0')
	{
	  strcpy (hour1, hour0);
	  strcpy (hour0, zero);
	}

      else if (strcmp (hour0, "0") == 0)
	strcpy (hour0, zero);

      else if (strcmp (hour0, "1") == 0)
	strcpy (hour0, one);

      else if (strcmp (hour0, "2") == 0)
	strcpy (hour0, two);

      else if (strcmp (hour0, "3") == 0)
	strcpy (hour0, three);

      else if (strcmp (hour0, "4") == 0)
	strcpy (hour0, four);

      else if (strcmp (hour0, "5") == 0)
	strcpy (hour0, five);

      else if (strcmp (hour0, "6") == 0)
	strcpy (hour0, six);

      else if (strcmp (hour0, "7") == 0)
	strcpy (hour0, seven);

      else if (strcmp (hour0, "8") == 0)
	strcpy (hour0, eight);

      else
	strcpy (hour0, nine);

      if (strcmp (hour1, "0") == 0)
	strcpy (hour1, zero);

      else if (strcmp (hour1, "1") == 0)
	strcpy (hour1, one);

      else if (strcmp (hour1, "2") == 0)
	strcpy (hour1, two);

      else if (strcmp (hour1, "3") == 0)
	strcpy (hour1, three);

      else if (strcmp (hour1, "4") == 0)
	strcpy (hour1, four);

      else if (strcmp (hour1, "5") == 0)
	strcpy (hour1, five);

      else if (strcmp (hour1, "6") == 0)
	strcpy (hour1, six);

      else if (strcmp (hour1, "7") == 0)
	strcpy (hour1, seven);

      else if (strcmp (hour1, "8") == 0)
	strcpy (hour1, eight);

      else
	strcpy (hour1, nine);

      if (minute1[0] == '\0')
	{
	  strcpy (minute1, minute0);
	  strcpy (minute0, zero);
	}

      else if (strcmp (minute0, "0") == 0)
	strcpy (minute0, zero);

      else if (strcmp (minute0, "1") == 0)
	strcpy (minute0, one);

      else if (strcmp (minute0, "2") == 0)
	strcpy (minute0, two);

      else if (strcmp (minute0, "3") == 0)
	strcpy (minute0, three);

      else if (strcmp (minute0, "4") == 0)
	strcpy (minute0, four);

      else if (strcmp (minute0, "5") == 0)
	strcpy (minute0, five);

      else if (strcmp (minute0, "6") == 0)
	strcpy (minute0, six);

      else if (strcmp (minute0, "7") == 0)
	strcpy (minute0, seven);

      else if (strcmp (minute0, "8") == 0)
	strcpy (minute0, eight);

      else
	strcpy (minute0, nine);

      if (strcmp (minute1, "0") == 0)
	strcpy (minute1, zero);

      else if (strcmp (minute1, "1") == 0)
	strcpy (minute1, one);

      else if (strcmp (minute1, "2") == 0)
	strcpy (minute1, two);

      else if (strcmp (minute1, "3") == 0)
	strcpy (minute1, three);

      else if (strcmp (minute1, "4") == 0)
	strcpy (minute1, four);

      else if (strcmp (minute1, "5") == 0)
	strcpy (minute1, five);

      else if (strcmp (minute1, "6") == 0)
	strcpy (minute1, six);

      else if (strcmp (minute1, "7") == 0)
	strcpy (minute1, seven);

      else if (strcmp (minute1, "8") == 0)
	strcpy (minute1, eight);

      else
	strcpy (minute1, nine);

      mvwprintw (position0, 0, 0, "%s", hour0);
      wnoutrefresh (position0);
      doupdate ();

      mvwprintw (position1, 0, 0, "%s", hour1);
      wnoutrefresh (position1);
      doupdate ();

      mvwprintw (position2, 0, 0, "%s", minute0);
      wnoutrefresh (position2);
      doupdate ();

      mvwprintw (position3, 0, 0, "%s", minute1);
      wnoutrefresh (position3);
      doupdate ();

      time_t end = time (NULL);

      double elapsed = difftime (end, start);
      int seconds_to_sleep = (int) (interval - elapsed);
      if (seconds_to_sleep > 0)
	sleep (seconds_to_sleep);
    }

  getch ();
  endwin ();

  return 0;
}
