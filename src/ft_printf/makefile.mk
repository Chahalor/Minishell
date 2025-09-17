DIR_MODULE_FT_PRINTF		:= ft_printf
DIR_INTERFACE_FT_PRINTF	:= $(DIR_MODULE_FT_PRINTF)
DIR_INTERNAL_FT_PRINTF	:= $(DIR_MODULE_FT_PRINTF)/_internal

SRC_INTERFACE_FT_PRINTF	:= interface.c ft_printf.c 
SRC_INTERNAL_FT_PRINTF	:= utils/_utils.c printf/writer.c 

OBJ_FT_PRINTF			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_FT_PRINTF)/, $(SRC_INTERFACE_FT_PRINTF:.c=.o))
OBJ_FT_PRINTF			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_FT_PRINTF)/, $(SRC_INTERNAL_FT_PRINTF:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_FT_PRINTF)/%.o: $(DIR_SRC)/$(DIR_MODULE_FT_PRINTF)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_FT_PRINTF)/_internal -c $< -o $@

