DIR_MODULE_MANAGER		:= manager
DIR_INTERFACE_MANAGER	:= $(DIR_MODULE_MANAGER)
DIR_INTERNAL_MANAGER	:= $(DIR_MODULE_MANAGER)/_internal

SRC_INTERFACE_MANAGER	:= mmanager.c fdmanager.c 
SRC_INTERNAL_MANAGER	:= memory/_mm.c memory/_utils.c files/_files.c 

OBJ_MANAGER			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_MANAGER)/, $(SRC_INTERFACE_MANAGER:.c=.o))
OBJ_MANAGER			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_MANAGER)/, $(SRC_INTERNAL_MANAGER:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_MANAGER)/%.o: $(DIR_SRC)/$(DIR_MODULE_MANAGER)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_MANAGER)/_internal -c $< -o $@
