CC	=	g++

SRCS =	src/autoclassmain.cpp \
		src/fonction.cpp

INCLUDEDIR =	include

CPPFLAGS =	-Wall -Wextra -Werror -I$(INCLUDEDIR)

OBJS = $(SRCS:.cpp=.o)

EXECNAME =	classgen

PATH_TO_FILE = .lastClassName

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(EXECNAME)

run: all
	@./$(EXECNAME)

runclass:
ifneq ("$(wildcard $(PATH_TO_FILE))","")
	@cd `cat ./.lastClassName`; make -s; ./myprogram
endif

testgenclass:
	@make -s run
	@make -s runClass

clean:
	@rm src/*.o

fclean:
	@rm $(EXECNAME)
	@rm -r `cat ./.lastClassName`
	@rm $(PATH_TO_FILE)
	@make -s clean

# .SILENT:

.PHONY: all clean re fclean