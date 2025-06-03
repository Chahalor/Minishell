main()
{
	cc ../src/args/**/*.c main.c -I../src/args -o a.out
	if [ $? -ne 0 ]; then
		echo "Compilation failed"
		exit 1
	fi
	./a.out -h
	if [ $? -ne 0 ]; then
		echo "Help command failed"
		exit 1
	fi
	./a.out -v
	if [ $? -ne 1 ]; then
		echo "Version command failed"
		exit 1
	fi
}