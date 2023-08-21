#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

 char *SearchIntEnv(char *startWith)
{
	char **s = environ;

	for (; *s; s++ )
	/* && s[i][5] != '\0' && s[i][5] != ' ' */
		if (!strncmp(startWith, *s, 5 ) )
			return (*s);

return (NULL);
}
/**
 * @brief
 *
 * @return char**
 */
char **TokenEnvfPath()
{
	size_t i, j;
	/* copy the Enviroment path  antoher string so we doont tokenize the system path*/
	char* envPath = strdup(SearchIntEnv("PATH="));
	if (!envPath )
	{

		perror("(null)  Enc.c:32 ");
		return (NULL);
	}

	/* inctrement the string pointer which store the  path copy py 5 (0 -> 4)  to strart point the charcter after "PATH="   */
	envPath += 5;


	//  printf("\n \033[1;31m-PATH BEFFORE\033[0m\n %s\n",envPath);

	char **PathArr= tokenize(envPath, ":");

	// printDblArr(PathArr, 0);


	return (PathArr);
}

/*
mohamed@DESKTOP-S296B4S:~$ env
SHELL=/bin/bash
WSL_DISTRO_NAME=Ubuntu-20.04
NAME=DESKTOP-S296B4S
PWD=/home/mohamed
LOGNAME=mohamed
HOME=/home/mohamed
LANG=C.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=mohamed
SHLVL=1
WSLENV=
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/mnt/c/Program Files/WindowsApps/CanonicalGroupLimited.Ubuntu20.04LTS_2004.6.16.0_x64__79rhkp1fndgsc:/mnt/c/Python311/Scripts/:/mnt/c/Python311/:/mnt/c/Program Files/Microsoft/jdk-11.0.12.7-hotspot/bin:/mnt/c/Program Files/Common Files/Oracle/Java/javapath:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files/Microsoft SQL Server/150/Tools/Binn/:/mnt/c/Program Files/Microsoft SQL Server/Client SDK/ODBC/170/Tools/Binn/:/mnt/c/Program Files/dotnet/:/mnt/c/Users/Active/AppData/Local/Programs/Microsoft VS Code/bin:/mnt/c/mingw64/bin:/mnt/c/msys64/mingw64/bin:/mnt/c/msys64/clang64/bin:/mnt/c/Program Files/nodejs/:/mnt/c/ProgramData/chocolatey/bin:/mnt/c/Users/Active/AppData/Roaming/npm:/mnt/c/Program Files (x86)/Microsoft SQL Server/150/Tools/Binn/:/mnt/c/Program Files/Microsoft SQL Server/150/DTS/Binn/:/mnt/c/Program Files/Azure Data Studio/bin:/mnt/c/Program Files/Git/cmd:/mnt/c/Users/Active/AppData/Local/Programs/Python/Python310/Scripts/:/mnt/c/Users/Active/AppData/Local/Programs/Python/Python310/:/mnt/c/Users/Active/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/Active/.dotnet/tools:/mnt/c/Program Files/heroku/bin:/mnt/c/Users/Active/AppData/Local/GitHubDesktop/bin:/snap/bin
HOSTTYPE=x86_64
_=/usr/bin/env

*/


// char *cmdExeCheck(char *command)
// {
// 	int arrItor ,acessRes;

// 	char *envPaht = GetEnv("PATH="),*envPathCopy,
// 	**pathArray;
// 	/*why PATH= not just PATH GetEnv Chaeck first 4 chars*/
// 		if ((access(command, X_OK))  == 0)
// 		{
// 			envPathCopy = strdup(command);
// 			return (envPathCopy);
// 		}
// 		/* chaeck for path should done before access "executabilty"*/
// 		if (envPaht == NULL)
// 			{
// 				perror(envPaht);
// 				return (NULL);
// 			}

// }
// int appendTo( char *envPath, char *command)
// {
// 	int comdLen =(int)strlen(command);
// }
