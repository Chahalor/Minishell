DIR_MODULE_PARSER		:= parser
DIR_INTERFACE_PARSER	:= $(DIR_MODULE_PARSER)
DIR_INTERNAL_PARSER	:= $(DIR_MODULE_PARSER)/_internal

SRC_INTERFACE_PARSER	:= lexer.c to_exec.c 
SRC_INTERNAL_PARSER	:= _files.c _is.c _sub_handler.c _handlers.c _alloc.c _check.c _tokenizer.c _free.c 

OBJ_PARSER			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_PARSER)/, $(SRC_INTERFACE_PARSER:.c=.o))
OBJ_PARSER			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_PARSER)/, $(SRC_INTERNAL_PARSER:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_PARSER)/%.o: $(DIR_SRC)/$(DIR_MODULE_PARSER)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_PARSER)/_internal -c $< -o $@

