# Makefile.am
#
# Copyright (C) 2023 Ivan Guerreschi <ivanguerreschi86@gmailcom>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

all: uhr

uhr: uhr.c
	$(CC) -g -ggdb uhr.c -Wall -W -pedantic -std=c11 -O2 -o uhr -lncurses

install:
	mkdir -p ~/.local/bin && cp uhr ~/.local/bin

clean:
	rm -rf uhr

# Only Emacs
check-syntax:
	$(CC) -o /dev/null -S $(CHK_SOURCES) || true

.PHONY:
	check-syntax
