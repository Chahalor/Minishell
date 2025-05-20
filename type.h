/* --------- types ---------- */
	// ---- manager ---- //
# ifndef _T_MANAGER
#  define _T_MANAGER

typedef struct s_params_		t_params_;		// v.1. >>> tag: set->t_params
typedef struct s_state_			t_state_;		// v.1. >>> tag: set->t_params
typedef struct s_env_			t_env_;			// v.1. >>> tag: set->t_env
typedef struct s_histo_			t_histo_;		// v.1. >>> tag: set->t_params
typedef struct s_command_		t_command_;		// v.1. >>> tag: set->t_params
typedef struct s_redir_			t_redir_;		// v.1. >>> tag: set->t_params
typedef struct s_section_		t_section_;		// v.1. >>> tag: set->t_params
typedef struct s_manager_		t_manager_;		// v.1. >>> tag: set->t_params

# endif

/* -------- structs --------- */
	// ---- manager ---- //
# ifndef _S_MANAGER
#  define _S_MANAGER

// params of the shell.
struct s_params_	// v.1. >>> tag: set->s_params
{
	// all of the specific parameters needed such as color infos ...
};
// state of the shell.
struct s_state_		// v.1. >>> tag: set->s_state
{
	char					sudo;		// sudo rights of the actual user.
										// (true / false / none).
	char					*user;		// username.
	/*
	 * The username is quite usefull actually as it alows us
	 * to check his rights before processing a command.
	*/
	char					*cwd;		// current working directory.
};
// env of the shell.
struct s_env_		// v.1. >>> tag: set->s_env
{
	unsigned int			fd;			// fd of the shell env file.
	unsigned int			size;		// size of the env (in vars).
	char					*home;		// home directory for '~'.
	char					*path;		// path value of the env.
	char					**var;		// env. variables.
};
// history of the shell.
struct s_histo_		// v.1. >>> tag: set->s_histo
{
	unsigned int			fd;			// fd of the shell history file.
	unsigned int			size;		// size of the history (in commands).
	char					*path;		// path of the history.
	/*
	 * If only a name is stored inside the path,
	 * we'll consider /etc/ as default base path.
	*/
};
// command representation.
struct s_command_	// v.1. >>> tag: set->s_command
{
	unsigned char			id;			// id of the command to execute.
	unsigned char			cond;		// condition to run command
										// (true / false / none).
	unsigned int			order;		// global processing order.
	char					**args;		// command args to proceed with.
};
// redirection representation (data forwarding).
struct s_redir_		// v.1. >>> tag: set->s_redir
{
	unsigned char			id;			// id of the redirection to process.
	unsigned int			order;		// global processing order.
	char					*src;		// source path to fetch data.
	char					*dest;		// destination path to forward data.
	/*
	 * If src / dest is leaved blank, it means it's either the order - 1
	 * or order + 1 command to be used as the source or destination for
	 * data forwarding.
	*/
	char					*content;	// content to forward.
};
// section of the redirects.
struct s_section_	// v.1. >>> tag: set->s_section
{
	t_command_				*cmd;		// commands to process.
	t_redir_				*redir;		// link / redirs to process.
	/*
	 * Shall hold up to 255 command / links inside channel 1 and 2.
	*/
};
// core manager storage.
struct s_manager_	// v.1. >>> tag: set->s_manager
{
	t_params_				params;
	t_state_				state;
	t_env_					env;
	t_histo_				histo;
	unsigned char			index;		// index of the section.
	unsigned int			order;		// order processed within the section.
	t_section_				*command;
	/*
	 * A command is splitted into multiples small commands and links.
	*/
	// here shall we put the methods ...
};

# endif