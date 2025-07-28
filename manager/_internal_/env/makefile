CC				:= cc
AR				:= ar
CFLAGS			:= -Wall -Wextra -Werror -MMD
NAME			:= env.a

INTERNAL		:= _internal_
PRIVATE			:= _private_
PUBLIC			:= _public_
GLOBAL			:= ../../..
CONFIG			:= $(GLOBAL)/config
STANDARDS		:= $(GLOBAL)/standards
WRAPPERS		:= $(STANDARDS)/$(INTERNAL)/wrappers

MANAGER			:= $(GLOBAL)/manager
MEMORY			:= $(MANAGER)/$(INTERNAL)/memory
HISTORY			:= $(INTERNAL)/history
STATE			:= $(INTERNAL)/state
LIB_MANAGER		:= $(MANAGER)/manager.a
LIB_MEMORY		:= $(MEMORY)/memory.a
LIB_HISTORY		:= $(HISTORY)/histo.a
LIB_STATE		:= $(STATE)/state.a
LIBS       		:= $(LIB_MANAGER) $(LIB_MEMORY) $(LIB_HISTORY) $(LIB_STATE)


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
				$(INTERNAL)/env__.h \
				\
				$(PRIVATE)/types_.h \
				$(PRIVATE)/env_.h \
				\
				$(PUBLIC)/types.h \
				$(PUBLIC)/env.h

SRC				:= \
				$(WRAPPERS)/$(INTERNAL)/_expect.c \
				$(WRAPPERS)/$(PUBLIC)/expect.c \
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

$(LIB_MANAGER):
	@$(MAKE) -C $(MANAGER)

$(LIB_MEMORY):
	@$(MAKE) -C $(MEMORY)

$(LIB_HISTORY):
	@$(MAKE) -C $(HISTORY)

$(LIB_STATE):
	@$(MAKE) -C $(STATE)

all: $(LIBS) $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(AR) rcs $@ $(OBJ) $(LIBS)

clean:
	@rm -rf _build_
	@$(MAKE) -C $(MANAGER) clean
	@$(MAKE) -C $(MEMORY) clean
	@$(MAKE) -C $(HISTORY) clean
	@$(MAKE) -C $(STATE) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(MANAGER) fclean
	@$(MAKE) -C $(MEMORY) fclean
	@$(MAKE) -C $(HISTORY) fclean
	@$(MAKE) -C $(STATE) fclean

re: fclean all

.PHONY: all clean fclean re $(LIB_MANAGER) $(LIB_MEMORY) $(LIB_HISTORY) $(LIB_STATE)

-include $(DEP)