DIR_MODULE_BUILTIN		:= builtin
DIR_INTERFACE_BUILTIN	:= $(DIR_MODULE_BUILTIN)
DIR_INTERNAL_BUILTIN	:= $(DIR_MODULE_BUILTIN)/_internal

SRC_INTERFACE_BUILTIN	:= env.c export.c unset.c pwd.c cd.c echo.c exit.c builtin.c history.c 
SRC_INTERNAL_BUILTIN	:= 

OBJ_BUILTIN			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_BUILTIN)/, $(SRC_INTERFACE_BUILTIN:.c=.o))
OBJ_BUILTIN			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_BUILTIN)/, $(SRC_INTERNAL_BUILTIN:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_BUILTIN)/%.o: $(DIR_SRC)/$(DIR_MODULE_BUILTIN)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_BUILTIN)/_internal -c $< -o $@

