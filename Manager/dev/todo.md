# TODO:
	- check that tags are always correct.
	- shall re-do the config file in order to have more explicit options.
	- correct the AST tree.
	- correct copy function so it uses the type to copy table as well.
	- correct init and starting allocation as well as the garbage collector.
	- complete all makefiles and correct inclusions.
# >>>
	- args file and relative user side CLI code shall be moved and re-introduced inside interface/visual module of the manager.
	- builtins shall be moved inside the proc/exec module and feature an access to available builtins to be used inside the tree if necessary.
# >>>
	- we MUST expose internal types of the tokenizer and / or provide support functions.
	- merge some tree add functions inside the root call functions.
	- finish tree module.
	- create a function to check if command is builtin (inside the tree).
	- correct error where memory module cannot clean itself because of memory manager use when free also when free self.