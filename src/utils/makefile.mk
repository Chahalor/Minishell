DIR_MODULE_UTILS		:= utils
DIR_INTERFACE_UTILS	:= $(DIR_MODULE_UTILS)
DIR_INTERNAL_UTILS	:= $(DIR_MODULE_UTILS)/_internal

SRC_INTERFACE_UTILS	:= ft_split.c utils.c utils2.c file.c 
SRC_INTERNAL_UTILS	:= 

OBJ_UTILS			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_UTILS)/, $(SRC_INTERFACE_UTILS:.c=.o))
OBJ_UTILS			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_UTILS)/, $(SRC_INTERNAL_UTILS:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_UTILS)/%.o: $(DIR_SRC)/$(DIR_MODULE_UTILS)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_UTILS)/_internal -c $< -o $@

