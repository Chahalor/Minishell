DIR_MODULE_ARGS		:= args
DIR_INTERFACE_ARGS	:= $(DIR_MODULE_ARGS)
DIR_INTERNAL_ARGS	:= $(DIR_MODULE_ARGS)/_internal

SRC_INTERFACE_ARGS	:= args.c 
SRC_INTERNAL_ARGS	:= 

OBJ_ARGS			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_ARGS)/, $(SRC_INTERFACE_ARGS:.c=.o))
OBJ_ARGS			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_ARGS)/, $(SRC_INTERNAL_ARGS:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_ARGS)/%.o: $(DIR_SRC)/$(DIR_MODULE_ARGS)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_ARGS)/_internal -c $< -o $@

