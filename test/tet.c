char *app_name;
int main(int argc, char **argv)
{
	app_name = argv[0];
	func(app_name);
}

void func(char *app)
{
	printf("%s\n", app);
}