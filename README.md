*This project has been created as part of the 42 curriculum by pabrogi.*

Description:
get_next_line is a project where my goal was to create a function that reads a file descriptor and returns one line at a time.
The function has to keep track of what was previously read, so that every new call starts exactly where the last one stopped.
The main feature of this project is the ability to handle any size of input using a static variable to store what remains after each read.
If a newline character (\n) is found, the function returns the line including the newline.
If there is no newline and the file continues, the function keeps reading until a full line is formed or until the file ends.

Instructions:
Here is a brief explanation on how to use it:
1 - Clone the get_next_line repository inside your project folder.
 git clone (repository link)
2 - Enter the folder you just cloned and compile it using:
 make
3 - Include the get_next_line.h header in your project:
 #include "./get_next_line.h"
4 - Link the compiled library when compiling your own project.
5 - Make sure to use the function like this:
 char *line = get_next_line(fd);
Every call returns the next line until the file ends.


Resources:
The only source that I “used” for understanding how this function had to work it’s just the Oceano video on get_next_line.

Usage examples:
Assuming that you have already followed all the setup steps, using the function is very simple.
You just need to open a file descriptor and call get_next_line every time you want the next line:
int		fd;
char	*line;

fd = open("file.txt", O_RDONLY);
if (fd < 0)
	return (1);
line = get_next_line(fd);
while (line)
{
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
}
close(fd);

Each call will return the next line from the file until there are no more lines to read.
If the file ends, the function returns NULL.