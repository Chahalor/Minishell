# TODO:
	- shall re do a small and simple version of the fucking GNL project.
	- shall use our GNL like module to read history.
	- we'll for sure have some issues with multiples defined functions name so there's two options to solve that.
	- shall secure history by re-writing it all using memory in case it is removed by incompetent user.
	- modify our read function to return the number of bytes read or an error code. # <<<
	- add some const they are missing in some of the data methods.
	- check that tags are always correct.
	- if params / prompt struct is defined, we shall do an object like module of it.
	- shall correct struct public / internal definition correctly.
	- shall re-do the config file in order to have more explicit options.
	- correct the AST tree.
	- also public types.h files shall only expose types that are usable outside of the module scope, as well as enums and defines but not structs.
	- shall merge the tokenizer module with the tree onto the processor module.
	- modify once more shift search, copy and clean function in order to use the max of the biggest types then we'll retrograde the used type to the lower one until finishing the task with char if necessary.
	-  correct copy function so it uses the type to copy table as well.
	- make sure their is an automatic process in backend for writing, allocation and reading in order to secure everything and self process all.
	- move file reader module inside the memory module.
	- modify the memory module in order to choose inside the config the free pool size.
	- modify search_data file in order to move out of it the rooting function and creating another rooting function that's named mem_compare.
	- think about using a char * for mode and spec instead of just giving a single char, thus you can have infinite levels of call
	- shall delete the utils module as it has been integrated inside the memory module.
	- rename all enums in order to use the module prefix (to be safe).
	- remove env file and related functions (not the whole env).
	- shall move state into the env module.
	- shall create some bridges for each module instead of calling back the get_manager
	functions every time.
	- create some wrappers for all object and structs.
	- add a level of depth to names.
	- shall rename accordingly to depth.
	- shall create a "profile" section method used to split correctly a given contiguous buffer.
# >>>
	- args file and relative user side CLI code shall be moved and re-introduced inside interface/visual module of the manager.
	- builtins shall be moved inside the proc/exec module and feature an access to available builtins to be used inside the tree if necessary.
	- shall re-introduce given 

# >>>
# TESTS:
	- support some tests such as : (cat test.txt; (echo $BOB) > test.txt) > test.txt | cat -e