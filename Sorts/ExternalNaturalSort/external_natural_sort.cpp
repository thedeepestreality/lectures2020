#include <iostream>
#include <time.h>
#include <fstream>

void generate_file(char* filename, int size)
{
	std::ofstream out;
	out.open(filename);
	if (!out.is_open())
	{
		throw "File opening error";
	}

	for (int i = 0; i < size; ++i)
		out << rand() - 2 * rand() << " ";

	out.close();
}

void open_stream(std::fstream& stream, const char filename[], bool read = true)
{
	if (read)
		stream.open(filename, std::ios::in);
	else
		stream.open(filename, std::ios::out);

	if (!stream.is_open())
	{
		throw "File opening error";
	}
}

void sort_file(const char filename[], size_t const size)
{
	std::fstream source;
	std::fstream f1;
	std::fstream f2;

	char f1name[] = "f1.txt";
	char f2name[] = "f2.txt";

	int curr_number;
	int prev_number;

	//For switching between files
	bool file_flag = true;
	//Current sequence length
	int count = 0;
	int f1_number;
	int f2_number;
	//Maximal sequence length
	//(for output)
	int max_count = 0;

	while (true)
	{
		//SPLIT STEP
		open_stream(source, filename);
		open_stream(f1, f1name, false);
		open_stream(f2, f2name, false);

		source >> curr_number;
		prev_number = curr_number;
		while (!source.eof())
		{
			if (curr_number < prev_number)
			{
				file_flag = !file_flag;
				count = 0;
				if (count > max_count)
					max_count = count;
			}

			(file_flag ? f1 : f2) << curr_number << " ";

			prev_number = curr_number;
			source >> curr_number;

			if (++count == size)
			{
				std::cout << "sorted!\n";
				source.close();
				f1.close();
				f2.close();
				return;
			}
		}

		if (count > max_count)
			max_count = count;

		source.close();
		f1.close();
		f2.close();

		open_stream(source, filename, false);
		open_stream(f1, f1name);
		open_stream(f2, f2name);

		//MERGE STEP
		f1 >> f1_number;
		f2 >> f2_number;
		while (!f1.eof() && !f2.eof())
		{
			if (f1_number < f2_number)
			{
				source << f1_number << " ";
				f1 >> f1_number;
			}
			else
			{
				source << f2_number << " ";
				f2 >> f2_number;
			}
		}
		while (!f1.eof())
		{
			source << f1_number << " ";
			f1 >> f1_number;
		}

		while (!f2.eof())
		{
			source << f2_number << " ";
			f2 >> f2_number;
		}

		source.close();
		f1.close();
		f2.close();

		//cout << "Current max count: " << maxCount << endl;
		count = 0;
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	const size_t Size = 1e3;

	if (argc < 3)
	{
		std::cout << "Not enough arguments\n";
		system("pause");
		return 0;
	}

	char* mode = argv[1];

	switch (mode[0])
	{
		case 'g':
		{
			try
			{
				generate_file(argv[2], Size);
			}
			catch (char* message)
			{
				std::cout << message << '\n';
				return -1;
			}
			break;
		}
		case 's':
		{
			try
			{
				sort_file(argv[2], Size);
			}
			catch (char* message)
			{
				std::cout << message << '\n';
				return -1;
			}
			break;
		}
		default:
		{
			std::cout << "Wrong arguments\n";
			return -1;
		}
	}

	return 0;
}