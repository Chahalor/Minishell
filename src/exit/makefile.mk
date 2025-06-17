DIR_MODULE_EXIT		:= exit
DIR_INTERFACE_EXIT	:= $(DIR_MODULE_EXIT)
DIR_INTERNAL_EXIT	:= $(DIR_MODULE_EXIT)/_internal

SRC_INTERFACE_EXIT	:= exit.c 
SRC_INTERNAL_EXIT	:= 

OBJ_EXIT			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_EXIT)/, $(SRC_INTERFACE_EXIT:.c=.o))
OBJ_EXIT			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_EXIT)/, $(SRC_INTERNAL_EXIT:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_EXIT)/%.o: $(DIR_SRC)/$(DIR_MODULE_EXIT)/%.c
	@mkdir -p $(dir $@)
	@printf "Compiling %-60s\n" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_EXIT)/_internal -c $< -o $@

