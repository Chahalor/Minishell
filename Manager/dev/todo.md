# TODO:
	- check that tags are always correct.
	- shall re-do the config file in order to have more explicit options.
	- correct init and starting allocation as well as the garbage collector.
	- complete all makefiles and correct inclusions.
# >>>
	- args file and relative user side CLI code shall be moved and re-introduced inside interface/visual module of the manager.
	- builtins shall be moved inside the proc/exec module and feature an access to available builtins to be used inside the tree if necessary.
# >>>
	- correct copy function so it uses the type to copy table as well.
	- to avoid any kind of leak we should perhaps reference every allocation in a list.
	- create an unloading function for tokenizer.
	- create a proper file searching function for bins.