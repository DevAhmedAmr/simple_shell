#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void function(char *str)
{
	strcpy(str, "a");
	str = "ahmed";
}
int main()
{
	char *str = strdup("string teeeeest");
	printf("%s\n", str);
	function(str);
	printf("%s\n", str);
	free(str);
}
