DIR_MODULE_READ_LINE		:= read_line
DIR_INTERFACE_READ_LINE	:= $(DIR_MODULE_READ_LINE)
DIR_INTERNAL_READ_LINE	:= $(DIR_MODULE_READ_LINE)/_internal

SRC_INTERFACE_READ_LINE	:= history.c read_line.c 
SRC_INTERNAL_READ_LINE	:= ansi/_move.c ansi/_ansi.c history/_get.c history/_load.c history/history.c gnl/get_next_line.c gnl/get_next_line_utils.c gnl/interface.c _init.c _read_lines.c _utils.c completions/_free.c completions/_tokenize.c completions/_get.c completions/completions.c completions/_add.c _prompt.c _manager.c _read.c 

OBJ_READ_LINE			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_READ_LINE)/, $(SRC_INTERFACE_READ_LINE:.c=.o))
OBJ_READ_LINE			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_READ_LINE)/, $(SRC_INTERNAL_READ_LINE:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_READ_LINE)/%.o: $(DIR_SRC)/$(DIR_MODULE_READ_LINE)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_READ_LINE)/_internal -c $< -o $@

