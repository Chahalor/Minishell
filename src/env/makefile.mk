DIR_MODULE_ENV		:= env
DIR_INTERFACE_ENV	:= $(DIR_MODULE_ENV)
DIR_INTERNAL_ENV	:= $(DIR_MODULE_ENV)/_internal

SRC_INTERFACE_ENV	:= env.c 
SRC_INTERNAL_ENV	:= _env.c _expand.c _export.c 

OBJ_ENV			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_ENV)/, $(SRC_INTERFACE_ENV:.c=.o))
OBJ_ENV			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_ENV)/, $(SRC_INTERNAL_ENV:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_ENV)/%.o: $(DIR_SRC)/$(DIR_MODULE_ENV)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_ENV)/_internal -c $< -o $@

