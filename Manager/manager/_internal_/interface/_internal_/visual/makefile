VISUAL_NAME		:= visual.a

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
AR				:= ar
ARFLAGS			:= rcs

DIR_INTERNAL	:= _internal_
DIR_PRIVATE		:= _private_
DIR_PUBLIC		:= _public_

_INCLUDES		:= -I$(DIR_INTERNAL) -I$(DIR_PRIVATE) -I$(DIR_PUBLIC)
DEPENDENCIES	:= -I../../../../../standards/_public_

SRC_INTERNAL	:=	logic__.c utils__.c writer__.c
SRC_PRIVATE		:=
SRC_PUBLIC		:= visual.c

SRC_INTERNAL	:= $(addprefix $(DIR_INTERNAL)/, $(SRC_INTERNAL))
SRC_PRIVATE		:= $(addprefix $(DIR_PRIVATE)/, $(SRC_PRIVATE))
SRC_PUBLIC		:= $(addprefix $(DIR_PUBLIC)/, $(SRC_PUBLIC))

_OBJS			:= $(SRC_INTERNAL:.c=.o) $(SRC_PRIVATE:.c=.o) $(SRC_PUBLIC:.c=.o)

all: $(VISUAL_NAME)

$(VISUAL_NAME): $(_OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
# @mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@ $(_INCLUDES) $(DEPENDENCIES)

clean:
	rm -f $(_OBJS)

fclean: clean
	rm -f $(VISUAL_NAME)

re: fclean all

debug:
	CFLAGS += -g3
	$(MAKE) re