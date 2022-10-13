#include <stdio.h>

void see_help(char * name)
{
	printf("See %s --help for details.\n", name);
}

void file_err(char * filename)
{
	printf("File %s could not be read from.\n", filename);
}

int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		see_help(argv[0]);
		return 0;
	}
	if (argc == 2)
	{
		FILE *fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			file_err(argv[1]);
			return -1;
		}

		int c = fgetc(fp);
		fseek(fp, 0, SEEK_END);
		char file[ftell(fp)];
		fseek(fp, 0, SEEK_SET);

		for (int i = 0; c != EOF; i++)
		{
			c = fgetc(fp);
			file[i] = c;
		}

		for (int i = 0; i < (int) sizeof file; i++)
		{
			putc(file[i], stdout);
		}
	}

	return 0;
}
