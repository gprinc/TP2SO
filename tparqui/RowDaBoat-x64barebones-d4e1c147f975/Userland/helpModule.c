/* helpModule.c */
//writes a help message to the shell console

//buena suerte chicoos!

/*
  problems to be solved:
		printf works?
		getChar works as is?
*/

int main() {
	 printf( "JUGULUconsole version .0001\n
            Portable command shell built on the Pure64 Baremetal kernel loader\n
            Permitted commands are defined internally, implementations shown below\n
            \n
            -$ help \n
                 Prints message to shell console, describes programs available to user\n
            \n
            -$ man [PROGRAM] \n
                 Displays manual information about the program, including it's options\n
                 and calling protocol\n
            \n
            -$ time \n
                 Prints the current system time to the screen\n
            \n
            -$ graphicMode [M VALUE] [B VALUE] [POWER]\n
                 Draws a representation of a lineal function, given through the shell,
                 to the screen. \n
            \n
            Type 'q' to exit this screen\n");

  char c = 'a';
  while (c != 'q'){
    c = getChar()
  }


}
