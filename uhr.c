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

#include <stdio.h>

int main(void) {
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
        "|  __ \\|  \\/  |\n"
        "| |__) | \\  / |\n"
        "|  ___/| |\\/| |\n"
        "| |    | |  | |\n"
        "|_|    |_|  |_| ";



    printf("%s\n", one);
    printf("%s\n", two);
    printf("%s\n", three);
    printf("%s\n", four);
    printf("%s\n", five);
    printf("%s\n", six);
    printf("%s\n", seven);
    printf("%s\n", eight);
    printf("%s\n", nine);
    printf("%s\n", zero);
    printf("%s\n", am);
    printf("%s\n", pm);

    return 0;
}
