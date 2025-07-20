CC				:= cc
AR				:= ar
CFLAGS			:= -Wall -Wextra -Werror -MMD
NAME			:= reader.a

INTERNAL		:= _internal_
PRIVATE			:= _private_
PUBLIC			:= _public_
GLOBAL			:= ../../../../..
CONFIG			:= $(GLOBAL)/config
STANDARDS		:= $(GLOBAL)/standards
WRAPPERS		:= $(STANDARDS)/$(INTERNAL)/wrappers

INCLUDES		:= \
				$(CONFIG)/$(INTERNAL)/default__.h \
				$(CONFIG)/$(INTERNAL)/config__.h \
				$(CONFIG)/$(PUBLIC)/config.h \
				\
				$(STANDARDS)/$(INTERNAL)/_dependencies.h \
				$(STANDARDS)/$(INTERNAL)/_types.h \
				$(STANDARDS)/$(INTERNAL)/_support.h \
				$(STANDARDS)/$(INTERNAL)/_standards.h \
				$(WRAPPERS)/$(INTERNAL)/_types.h \
				$(WRAPPERS)/$(INTERNAL)/_wrappers.h \
				$(WRAPPERS)/$(PUBLIC)/wrappers.h \
				$(STANDARDS)/$(PUBLIC)/types.h \
				$(STANDARDS)/$(PUBLIC)/standards.h \
				\
				$(INTERNAL)/types__.h \
				$(INTERNAL)/reader__.h \
				\
				$(PRIVATE)/types_.h \
				$(PRIVATE)/reader_.h \
				\
				$(PUBLIC)/types.h \
				$(PUBLIC)/reader.h

SRC				:= \
				$(WRAPPERS)/$(INTERNAL)/_expect.c \
				$(WRAPPERS)/$(PUBLIC)/expect.c \
				\
				$(INTERNAL)/access__.c \
				$(INTERNAL)/add__.c \
				$(INTERNAL)/find__.c \
				$(INTERNAL)/remove__.c \
				$(INTERNAL)/read__.c \
				$(INTERNAL)/init__.c \
				$(INTERNAL)/setup__.c \
				\
				$(INTERNAL)/access_.c \
				$(INTERNAL)/add_.c \
				$(INTERNAL)/find_.c \
				$(INTERNAL)/remove_.c \
				$(INTERNAL)/read_.c \
				$(INTERNAL)/init_.c \
				\
				$(PUBLIC)/setup.c

LOCAL_SRC  		:= $(filter-out $(GLOBAL)/%,$(SRC))
GLOBAL_SRC		:= $(filter     $(GLOBAL)/%,$(SRC))
OBJ_LOCAL		:= $(patsubst %.c,_build_/%.o,$(LOCAL_SRC))
OBJ_GLOBAL		:= $(patsubst $(GLOBAL)/%.c,_build_/%.o,$(GLOBAL_SRC))
OBJ				:= $(OBJ_GLOBAL) $(OBJ_LOCAL)
DEP				:= $(OBJ:.o=.d)
HEADERS			:= $(foreach h,$(INCLUDES),-include $(h))

_build_/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

_build_/%.o: $(GLOBAL)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

clean:
	@rm -rf _build_ $(OBJ) $(DEP)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)