CC				:= cc
AR				:= ar
CFLAGS			:= -Wall -Wextra -Werror -MMD
NAME			:= mem.a

INTERNAL		:= _internal_
PRIVATE			:= _private_
PUBLIC			:= _public_
GLOBAL			:= ../../../../..
CONFIG			:= $(GLOBAL)/config
STANDARDS		:= $(GLOBAL)/standards
WRAPPERS		:= $(STANDARDS)/$(INTERNAL)/wrappers
MANAGER			:= $(GLOBAL)/manager
MEMORY			:= $(MANAGER)/$(INTERNAL)/memory
LIB_MANAGER		:= $(MANAGER)/manager.a
LIB_MEMORY		:= $(MEMORY)/memory.a
LIBS       		:= $(LIB_MANAGER) $(LIB_MEMORY)

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
				$(INTERNAL)/history__.h \
				\
				$(PRIVATE)/types_.h \
				$(PRIVATE)/history_.h \
				\
				$(PUBLIC)/types.h \
				$(PUBLIC)/history.h

SRC				:= \
				$(WRAPPERS)/$(INTERNAL)/_expect.c \
				$(WRAPPERS)/$(PUBLIC)/expect.c \
				\
				$(INTERNAL)/access__.c \
				$(INTERNAL)/load__.c \
				$(INTERNAL)/find__.c \
				$(INTERNAL)/unload__.c \
				$(INTERNAL)/add__.c \
				$(INTERNAL)/show__.c \
				$(INTERNAL)/init__.c \
				\
				$(INTERNAL)/access_.c \
				$(INTERNAL)/load_.c \
				$(INTERNAL)/find_.c \
				$(INTERNAL)/unload_.c \
				$(INTERNAL)/add_.c \
				$(INTERNAL)/show_.c \
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

$(LIB_MANAGER):
	@$(MAKE) -C $(READER)

$(LIB_MEMORY):
	@$(MAKE) -C $(WRITER)

all: $(LIBS) $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(AR) rcs $@ $(OBJ) $(LIBS)

clean:
	@rm -rf _build_
	@$(MAKE) -C $(MANAGER) clean
	@$(MAKE) -C $(MEMORY) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(MANAGER) fclean
	@$(MAKE) -C $(MEMORY) fclean

re: fclean all

.PHONY: all clean fclean re $(LIB_MANAGER) $(LIB_MEMORY)

-include $(DEP)