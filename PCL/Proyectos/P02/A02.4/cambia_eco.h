	// cambia_eco.h
	// Commuta el modo eco / no eco del terminal
	///////////////////////////////////////////////////////////

	#include <unistd.h>
	#include <termios.h>
	//#include <sys/ioctl.h>



void temp_tty (int dseconds)
{
	struct termios tm;

	tcgetattr(0, &tm);
//	tm.c_lflag &= ~FLUSHO;
        tm.c_cc[VTIME]= dseconds;
	tm.c_cc[VMIN]= 0;
	tcsetattr(0, TCSANOW, &tm);
}
 
void no_temp_tty ()
{
	struct termios tm;

	tcgetattr(0, &tm);
        tm.c_cc[VTIME]= 0;
	tcsetattr(0, TCSANOW, &tm);
}

void crudo (struct termios* tm)
{
	struct termios new_tm;

	tcgetattr(0, tm);
	tcgetattr(0, &new_tm);
	cfmakeraw(&new_tm);
	tcsetattr(0, TCSANOW, &new_tm);
}

void cocinado (struct termios* tm)
{
	tcsetattr(0, TCSANOW, tm);
}


	int cambia_eco ()
	{
		int r;
		struct termios tm;
	
		tcgetattr(0, &tm);
		if (tm.c_lflag & ECHO) {
			r= 1;
			tm.c_lflag &= ~ECHO;
		}
		else { 
			r= 0;
			tm.c_lflag |= ECHO;
		}
		tcsetattr(0, TCSANOW, &tm);
		return (r);
	}
