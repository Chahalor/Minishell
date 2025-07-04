DIR_MODULE_LEXER		:= lexer
DIR_INTERFACE_LEXER	:= $(DIR_MODULE_LEXER)
DIR_INTERNAL_LEXER	:= $(DIR_MODULE_LEXER)/_internal

SRC_INTERFACE_LEXER	:= tree.c lexer.c 
SRC_INTERNAL_LEXER	:= _files.c 

OBJ_LEXER			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_LEXER)/, $(SRC_INTERFACE_LEXER:.c=.o))
OBJ_LEXER			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_LEXER)/, $(SRC_INTERNAL_LEXER:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_LEXER)/%.o: $(DIR_SRC)/$(DIR_MODULE_LEXER)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_LEXER)/_internal -c $< -o $@

