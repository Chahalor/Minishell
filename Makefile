# Big Fat Header\n

# ***************************************************** #
# *                 Configuation                      * #
# ***************************************************** #

MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                    Variables                      * #
# ***************************************************** #

NAME		:= Minishell
BONUS		:=

CC			:= cc
CFLAGS		+= -Wall -Wextra -Werror -Werror=implicit-function-declaration -MMD
DEBUGFLAGS	:= 
DIR_SRC		:= src
DIR_OBJ		:= .build
DIR_BONUS	:= 
INCLUDE_ALL	:=-Iglobal -I$(DIR_SRC)/args -I$(DIR_SRC)/builtin -I$(DIR_SRC)/exec -I$(DIR_SRC)/exit -I$(DIR_SRC)/ft_printf -I$(DIR_SRC)/global-manager -I$(DIR_SRC)/lexer -I$(DIR_SRC)/manager -I$(DIR_SRC)/read_line -I$(DIR_SRC)/signal -I$(DIR_SRC)/utils

_DEPS		:= $(_OBJ_ALL:.o=.d)

# Here we include all the makefile.mk files
include  src/args/makefile.mk src/builtin/makefile.mk src/exec/makefile.mk src/exit/makefile.mk src/ft_printf/makefile.mk src/global-manager/makefile.mk src/lexer/makefile.mk src/manager/makefile.mk src/read_line/makefile.mk src/signal/makefile.mk src/utils/makefile.mk
-include $(_DEPS)

SRC_MAIN	:= main.c
SRC_BONUS	:=

# all object files for the modules
_OBJ_MAIN	:= $(addprefix $(DIR_OBJ)/, $(SRC_MAIN:.c=.o))
_OBJ_BONUS	:= $(addprefix $(DIR_OBJ)/, $(SRC_BONUS:.c=.o))
_OBJ_ALL		:= $(OBJ_ARGS) $(OBJ_BUILTIN) $(OBJ_EXEC) $(OBJ_EXIT) $(OBJ_FT_PRINTF) $(OBJ_GLOBAL-MANAGER) $(OBJ_LEXER) $(OBJ_MANAGER) $(OBJ_READ_LINE) $(OBJ_SIGNAL) $(OBJ_UTILS)

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header norm $(NAME) symbols install

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

$(NAME): $(_OBJ_ALL) $(_OBJ_MAIN)
	@echo "\n ⚙️ $(_YELLOW) Compiling$(_RESET) $(NAME)..."
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) $^ -o $(NAME) 

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -c $< -o $@

bonus: $(_OBJ_ALL) $(_OBJ_BONUS)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) $^ -o $(BONUS)

fast: $(NAME)

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	rm -f $(_OBJ_ALL) $(_OBJ_MAIN) $(_OBJ_BONUS)

fclean:
	rm -rf $(DIR_OBJ)
	rm -f $(NAME) $(BONUS)

re: fclean all

# ***************************************************** #
# *                    Debug Rules                    * #
# ***************************************************** #

.PHONY: debug debug.fsanitize debug.fs debug.pg

debug:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -g3 -D DEBUG=1)
	@echo "\033[1;33m DEBUG MODE ACTIVATED $(_RESET)"

debug.fsanitize: debug
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -fsanitize=address)

debug.fs: debug.fsanitize

debug.pg:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -pg)

# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

.PHONY: header norm install uninstall update symbols

_YELLOW	:= \033[1;33m
_GREEN	:= \033[1;32m
_RED	:= \033[1;31m
_RESET	:= \033[0m

header:
ifeq ($(MAKELEVEL), 0)
	@echo "Big Fat Header\n"
endif

help:
	@echo "\033[1;33mUsage: make [target]$(_RESET)\n" 	"$(_YELLOW)├──$(_GREEN)all$(_RESET)			- Build the project\n" 	"$(_YELLOW)├──$(_GREEN)bonus$(_RESET)		- Build the bonus part of the project\n" 	"$(_YELLOW)├──$(_GREEN)fast$(_RESET)			- Build the project quickly\n" 	"$(_YELLOW)├──$(_GREEN)clean$(_RESET)		- Remove object files\n" 	"$(_YELLOW)├──$(_GREEN)fclean$(_RESET)		- Remove object files and executable\n" 	"$(_YELLOW)├──$(_GREEN)re$(_RESET)			- Clean and rebuild the project\n" 	"$(_YELLOW)├──$(_GREEN)debug$(_RESET)		- Enable debug mode\n" 	"$(_YELLOW)├──$(_GREEN)debug.fsanitize$(_RESET)	- Enable debug mode with address sanitizer\n" 	"$(_YELLOW)├──$(_GREEN)debug.fs$(_RESET)		- Enable debug mode with full sanitizer\n" 	"$(_YELLOW)├──$(_GREEN)debug.pg$(_RESET)		- Enable debug mode with profiling\n" 	"$(_YELLOW)├──$(_GREEN)norm$(_RESET)			- Check code style with Norminette\n" 	"$(_YELLOW)├──$(_GREEN)install$(_RESET)		- Install the executable to ~/.local/bin\n" 	"$(_YELLOW)├──$(_GREEN)uninstall$(_RESET)		- Uninstall the executable from ~/.local/bin\n" 	"$(_YELLOW)├──$(_GREEN)update$(_RESET)		- Update the Makefile using auto.sh script\n" 	"$(_YELLOW)└──$(_GREEN)symbols$(_RESET)		- Check for forbidden symbols in the binary\n"

# -----| Norminette check  |----- #

NORM_FILES := global/ src/
norm:
	@printf "$(_YELLOW) 🔎 Checking norminette...$(_RESET)"
	@NORM_OUTPUT="$$(norminette $(NORM_FILES) | grep 'Error')" ; \
	if [ -z "$$NORM_OUTPUT" ]; then \
		printf "$(_GREEN) ✅ Norminette passed with no errors.$(_RESET)\n"; \
	else \
		printf "\r" ; 		printf "$$NORM_OUTPUT" | awk '\
		/\.c: Error!/ || /\.h: Error!/ { file=$$0; next } \
		/Error:/ { \
			l=match($$0, /line: *[0-9]+/); \
			c=match($$0, /col: *[0-9]+/); \
			line=substr($$0, l+6, 10); \
			col=substr($$0, c+5, 10); \
			gsub(/\(line: *[0-9]+, *col: *[0-9]+\): */, "", $$0); \
			sub(/Error: /, "", $$0); \
			split(file, parts, ":"); \
			printf "$(_RED)Error$(_RESET): %s:%-3s:%-2s: %s\n", parts[1], line+0, col+0, $$0; \
		}' ; \
		echo "$(_RED) ❌ Norminette errors found$(_RESET)" ; \
	fi

# -----| Install / Uninstall |----- #

INSTALL_DIR = $(HOME)/.local/bin
install:
	mkdir -p $(INSTALL_DIR)
	cp $(NAME) $(INSTALL_DIR)/
	chmod +x $(INSTALL_DIR)/$(NAME)
	$(call _completion)
	echo "$(_GREEN) ✅ $(NAME) installed to $(INSTALL_DIR) $(_RESET)"; \

uninstall:
	rm -rf $(INSTALL_DIR)/$(NAME)
	echo "$(_GREEN) ✅ $(NAME) uninstalled from $(INSTALL_DIR) $(_RESET)";

update:
	if [ -f ./auto.sh ]; then \
		echo "\033[1;33m Updating Makefile... $(_RESET)"; \
	else \
		echo "$(_RED) auto.sh not found, please add the script to automate the update $(_RESET)"; \
		exit 1; \
	fi
	./auto.sh
	echo "$(_GREEN) ✅ Makefile updated $(_RESET)";


# -----| Symbols check |----- #
SUPPRESED_SYMBOLS	:=	memset
ALLOWED_SYMBOLS		:=	readline rl_clear_history rl_on_new_line rl_replace_line rl_redisplay add_history \
						printf malloc free write access open read close fork wait waitpid wait3 wait4 signal \
						sigaction sigemptyset sigaddset kill exit getcwd chdir stat lstat fstat unlink execve \
						dup dup2 pipe opendir readdir closedir strerror perror isatty ttyname ttyslot ioctl \
						getenv tcsetattr tcgetattr tgetent tgetflag tgetnum tgetstr tgoto tputs
symbols:
	@nm -uj $(NAME) | sort -u | sed 's/@.*//' | grep -v '^__' | \
	awk ' \
	BEGIN { \
		split("$(ALLOWED_SYMBOLS)", allowed); \
		split("$(SUPPRESSED_SYMBOLS)", suppressed); \
		for (i in allowed) allow[allowed[i]] = 1; \
		for (i in suppressed) supp[suppressed[i]] = 1; \
		suppressed_count = 0; \
		forbidden_count = 0; \
		output = ""; \
	} \
	{ \
		sym = $$0; \
		if (sym in allow) \
			output = output sprintf("$(_YELLOW)│   $(_GREEN)%s (allowed)$(_RESET)\n", sym); \
		else if (sym in supp) \
			suppressed_count++; \
		else \
		{ \
			output = output sprintf("$(_YELLOW)├$(_RED)── %s (forbidden)$(_RESET)\n", sym); 			forbidden_count++; \
		} \
	} \
	END { \
		if (suppressed_count > 0 || forbidden_count > 0) \
		{ \
			printf "$(_YELLOW)SYMBOLS:$(_RESET)\n"; \
			printf "%s", output; \
		} \
		else \
			printf "$(_YELLOW)├──$(_GREEN)✅ Only allowed symbols found!$(_RESET)\n"; \
		printf "$(_YELLOW)├── functions suppressed (%d)\n",  suppressed_count; \
		printf "$(_YELLOW)└── functions forbidden (%d)\n", forbidden_count; \
	}'

# Variables de suivi
COMPILED := 0
TOTAL := 100
BAR_WIDTH := 50

define compile
	COMPILED=$$((COMPILED + 1)); \
	TOTAL=$(TOTAL); \
	RATIO=$$(echo "$$COMPILED * $(BAR_WIDTH) / $$TOTAL" | bc); \
	printf "\rCompiling %-40s \n[" "$1"; \
	for i in $$(seq 1 $$RATIO); do printf "="; done; \
	for i in $$(seq $$((BAR_WIDTH))); do printf " "; done; \
	printf "]\n"
endef

.SILENT:
	@echo "\033[1;33m SILENT MODE ACTIVATED $(_RESET)"
