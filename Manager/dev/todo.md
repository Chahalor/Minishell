# TODO:
	- check that tags are always correct.
	- shall re-do the config file in order to have more explicit options.
	- correct the AST tree.
	- correct copy function so it uses the type to copy table as well.
	- correct init and starting allocation as well as the garbage collector.
	- shall introduce fullt nathan's code inside the manager.
	- complete all makefiles and correct inclusions.
# >>>
	- args file and relative user side CLI code shall be moved and re-introduced inside interface/visual module of the manager.
	- builtins shall be moved inside the proc/exec module and feature an access to available builtins to be used inside the tree if necessary.

# >>>
# TESTS:
	- support some tests such as : (cat test.txt; (echo $BOB) > test.txt) > test.txt | cat -e