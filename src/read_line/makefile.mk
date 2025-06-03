DIR_MODULE_READ_LINE		:= read_line
DIR_INTERFACE_READ_LINE	:= $(DIR_MODULE_READ_LINE)
DIR_INTERNAL_READ_LINE	:= $(DIR_MODULE_READ_LINE)/_internal

SRC_INTERFACE_READ_LINE	:= read_line.c 
SRC_INTERNAL_READ_LINE	:= _utils.c ansi/_ansi.c history/_load.c history/history.c gnl/get_next_line.c gnl/interface.c gnl/get_next_line_utils.c _init.c _read.c dir/dir.c dir/_tokenize.c dir/_free.c 

OBJ_READ_LINE			:= $(addprefix $(DIR_OBJ)/$(DIR_INTERFACE_READ_LINE)/, $(SRC_INTERFACE_READ_LINE:.c=.o))
OBJ_READ_LINE			+= $(addprefix $(DIR_OBJ)/$(DIR_INTERNAL_READ_LINE)/, $(SRC_INTERNAL_READ_LINE:.c=.o))

$(DIR_OBJ)/$(DIR_MODULE_READ_LINE)/%.o: $(DIR_SRC)/$(DIR_MODULE_READ_LINE)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(DIR_MODULE_READ_LINE)/_internal -c $< -o $@
