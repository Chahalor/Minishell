DIR_MODULE_BUILTIN		:= builtin
DIR_INTERFACE_BUILTIN	:= $(DIR_MODULE_BUILTIN)
DIR_INTERNAL_BUILTIN	:= $(DIR_MODULE_BUILTIN)/_internal

SRC_INTERFACE_BUILTIN	:= echo.c exit.c history.c pwd.c env.c unset.c cd.c export.c builtin.c which.c 
SRC_INTERNAL_BUILTIN	:= 

OBJ_BUILTIN			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_BUILTIN)/, $(SRC_INTERFACE_BUILTIN:.c=.o))
OBJ_BUILTIN			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_BUILTIN)/, $(SRC_INTERNAL_BUILTIN:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_BUILTIN)/%.o: $(DIR_SRC)/$(DIR_MODULE_BUILTIN)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_BUILTIN)/_internal -c $< -o $@

