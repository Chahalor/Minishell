CC				:= cc
AR				:= ar
CFLAGS			:= -Wall -Wextra -Werror -MMD
NAME			:= mem.a

INTERNAL		:= _internal_
PRIVATE			:= _private_
PUBLIC			:= _public_
GLOBAL			:= ../../..
CONFIG			:= $(GLOBAL)/config
STANDARDS		:= $(GLOBAL)/standards
WRAPPERS		:= $(STANDARDS)/wrappers

INCLUDES		:= \
				$(CONFIG)/$(INTERNAL)/_default.h \
				$(CONFIG)/$(INTERNAL)/_config.h \
				$(CONFIG)/config.h \
				\
				$(STANDARDS)/$(INTERNAL)/_dependencies.h \
				$(STANDARDS)/$(INTERNAL)/_types.h \
				$(STANDARDS)/$(INTERNAL)/_support.h \
				$(STANDARDS)/$(INTERNAL)/_standards.h \
				$(WRAPPERS)/$(INTERNAL)/_types.h \
				$(WRAPPERS)/$(INTERNAL)/_wrappers.h \
				$(WRAPPERS)/wrappers.h \
				$(STANDARDS)/types.h \
				$(STANDARDS)/standards.h \
				\
				$(INTERNAL)/types__.h \
				$(INTERNAL)/memory__.h \
				\
				$(PRIVATE)/types_.h \
				$(PRIVATE)/memory_.h \
				\
				$(PUBLIC)/types.h \
				$(PUBLIC)/memory.h

SRC				:= \
				$(WRAPPERS)/$(INTERNAL)/_expect.c \
				$(WRAPPERS)/expect.c \
				\
				$(INTERNAL)/format__.c \
				$(INTERNAL)/access__.c \
				$(INTERNAL)/manage__.c \
				$(INTERNAL)/alloc__.c \
				$(INTERNAL)/clean__.c \
				$(INTERNAL)/size__.c \
				$(INTERNAL)/write__.c \
				$(INTERNAL)/read__.c \
				$(INTERNAL)/copy__.c \
				$(INTERNAL)/shift__.c \
				$(INTERNAL)/compare__.c \
				$(INTERNAL)/search__.c \
				$(INTERNAL)/init__.c \
				\
				$(PRIVATE)/format_.c \
				$(PRIVATE)/access_.c \
				$(PRIVATE)/manage_.c \
				$(PRIVATE)/alloc_.c \
				$(PRIVATE)/clean_.c \
				$(PRIVATE)/size_.c \
				$(PRIVATE)/write_.c \
				$(PRIVATE)/read_.c \
				$(PRIVATE)/copy_.c \
				$(PRIVATE)/shift_.c \
				$(PRIVATE)/compare_.c \
				$(PRIVATE)/search_.c \
				\
				$(PUBLIC)/init.c

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