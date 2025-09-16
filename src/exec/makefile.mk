DIR_MODULE_EXEC		:= exec
DIR_INTERFACE_EXEC	:= $(DIR_MODULE_EXEC)
DIR_INTERNAL_EXEC	:= $(DIR_MODULE_EXEC)/_internal

SRC_INTERFACE_EXEC	:= exec.c heredoc.c 
SRC_INTERNAL_EXEC	:= _exec.c _pipe.c _signals.c 

OBJ_EXEC			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_EXEC)/, $(SRC_INTERFACE_EXEC:.c=.o))
OBJ_EXEC			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_EXEC)/, $(SRC_INTERNAL_EXEC:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_EXEC)/%.o: $(DIR_SRC)/$(DIR_MODULE_EXEC)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_EXEC)/_internal -c $< -o $@

