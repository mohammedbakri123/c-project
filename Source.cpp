#include<vector>
#include<iomanip>
#include<cstdlib>
#include"input.h"
#include"mylip.h"
#include<fstream>

using namespace std;
using namespace input;
using namespace mylip;
const int password = 1234;
struct mark
{
	int math;
	int education;
	int programming_fundmentals;
	int computer_scince;

};


struct studentinfo
{
	string frist_name;
	string last_name;
	string full_name;
	int id;
	int age;

	mark marks;
	int final_result;
	int average;
	string student_major;
	char grade;
};
void student_mark(string massege, mark& marks)
{
	cout << massege << endl;

	marks.math = read_marks("          Enter math result : ");
	marks.education = read_marks("          Enter islamic education result : ");
	marks.computer_scince = read_marks("          Enter coputer scince result : ");
	marks.programming_fundmentals = read_marks("          Enter programming fundmentals result : ");

}
short supjects_sum(mark marks)
{
	int sum;
	sum = (marks.math + marks.education + marks.programming_fundmentals + marks.computer_scince);
	return sum;

}
short callculate_average(mark marks)
{
	int ave;
	ave = supjects_sum(marks) / 4;
	return ave;
}
char grade(int mark)
{
	if (mark >= 50)

	{
		if (mark >= 90)
		{
			return 'A';
		}
		else if (mark >= 80 && mark < 90)
		{
			return 'B';
		}
		else if (mark >= 70 && mark < 80)
		{
			return 'C';
		}
		else if (mark >= 50 && mark < 70)

		{
			return 'D';
		}
	}
	else
	{
		return 'F';
	}
}
string read_student_major(int student)
{
	if (student == 1)
		return "CS";
	else if (student == 2)
		return "IT";
	else if (student == 3)
		return "IS";
	else if (student == 4)
		return "CYS";
}
int create_ID_number()
{
	int ID;
	fstream ID_FILE;
	ID_FILE.open("ID_file.txt", ios::in);
	if (ID_FILE.is_open())
	{
	
		ID_FILE >> ID;
		ID_FILE.close();
	}
	
	ID_FILE.open("ID_file.txt", ios::out);
	if (ID_FILE.is_open())
	{
		ID_FILE << ID+1;
		ID_FILE.close();
	}
	return ID;
}
void fell_student_info(studentinfo& temp)
{
	temp.frist_name = read_names("          Enter student ftist name : ");
	temp.last_name = read_names("          Enter student last name : ");
	temp.full_name = temp.frist_name + " " + temp.last_name;
	temp.id = create_ID_number();
	cout << "          Your ID is: [" << temp.id << "] please keep it\n";
	temp.age = read_int_number("          Enter student age : ");

	temp.student_major = read_student_major(read_int_number("          Enter student major [1]CS, [2]IT, [3]IS, [4]CYS: ", 4, 1));
	mark marks;
	student_mark("          Enter student marks : ", marks);
	temp.marks = marks;
	temp.final_result = supjects_sum(marks);
	temp.average = callculate_average(marks);
	temp.grade = grade(temp.average);
}


void save_to_file(studentinfo& student)
{
	fstream file;
	file.open(("studentsinfo.txt"), ios::out | ios::app);
	if (file.is_open())
	{
		file << student.full_name << endl;
		file << student.id << endl;
		file << student.age << endl;
		file << student.student_major << endl;
		file << student.marks.math << endl;
		file << student.marks.education << endl;
		file << student.marks.programming_fundmentals << endl;
		file << student.marks.computer_scince << endl;
		file << student.final_result << endl;
		file << student.average << endl;
		file << student.grade << endl;
		file.close();
	}

}
void add_student(studentinfo& student)
{
	fell_student_info(student);
	save_to_file(student);
}
int search_for_student(vector<string>& studentfile, string student_name)
{
	for (int i = 0; i < studentfile.size(); i++)
	{
		if (studentfile[i] == student_name)
		{
			return i;
		}


	}return -1;
}


void load_data_to_student_names_file(vector<string>studentfile, string file_name)
{
	fstream file;
	file.open(file_name, ios::out);
	if (file.is_open())
	{
		for (string& line : studentfile)
		{
			if (line != "")
			{
				file << line << endl;
			}
		}
	}

}
void load_file_to_vector(vector<string>& studentfile, string file_name)
{
	fstream file;
	file.open(file_name, ios::in);
	if (file.is_open())
	{
		string line;
		
		while (getline(file, line))
		{
			if(line != "")
			studentfile.push_back(line);
		}
		file.close();
	}
}
void barrier()
{
	cout << "        =============================================================" << endl;
}
void delete_element_in_vectore_by_name(vector<string>& deleteing, int position)
{
	for (int i = position; i < position + 11; i++)
	{
		deleteing[i] = "";
	}
}
void delete_element_in_vectore_by_ID(vector<string>& deleteing, int position)
{
	position = position - 3;
	for (int i = position; i < position + 10; i++)
	{
		deleteing[i] = "";
	}
}
void delete_element_in_vectore_by_major(vector<string>& deleteing, int position)
{
	deleteing[position - 3] = "";
	for (int i = position; i < position + 10; i++)
	{
		deleteing[i] = "";
	}
}
void edit_by_name(vector<string>& editing, int position)
{
	cout << "         Enter[1] if you want to edit name     " << endl;
	cout << "         Enter[2] if you want to edit age      " << endl;
	cout << "         Enter[3] if you want to edit major    " << endl;
	int ask_edit = read_int_number("         Enter [1],[2] or [3] : ");
	if (ask_edit == 1)
	{
		string fname = read_names("         Enter new frist name:");
		string lname = read_names("         Enter new last name:");
		string full_name = fname + " " + lname;
		editing[position] = full_name;
	}
	else if (ask_edit == 2)
	{
		string age_edited;
		cout << "         Enter the new age: "; cin >> age_edited;
		editing[position + 2] = age_edited;
	}
	else
	{
		string new_major = read_student_major(read_int_number("          Enter student major [1]CS, [2]IT, [3]IS, [4]CYS: ", 4, 1));
		editing[position + 3] = new_major;
	}

}
void edit_by_ID(vector<string>& editing, int position)
{
	cout << "         Enter[1] if you want to edit name     " << endl;
	cout << "         Enter[2] if you want to edit age      " << endl;
	cout << "         Enter[3] if you want to edit major    " << endl;
	int ask_edit = read_int_number("         Enter [1],[2] or [3] : ");
	if (ask_edit == 1)
	{
		string fname = read_names("         Enter new frist name:");
		string lname = read_names("         Enter new frist name:");
		string full_name = fname + " " + lname;
		editing[position - 1] = full_name;
	}
	else if (ask_edit == 2)
	{
		string age_edited;
		cout << "         Enter the new age: "; cin >> age_edited;
		editing[position + 1] = age_edited;
	}
	else
	{
		string new_major = read_student_major(read_int_number("          Enter student major [1]CS, [2]IT, [3]IS, [4]CYS: ", 4, 1));
		editing[position + 2] = new_major;
	}

}
bool check_admin_password()
{
	int counter = 3;
	
	cout << "          | ENTER ADMIN PASSWORD |              " << endl;
	int ask_pass = read_int_number("          Enter password: ");
	while (password != ask_pass && counter >= 0)
	{
		if (counter == 0)
			return false;
		counter--;
		cout << "         still[" << counter << "] tri     " << endl;

		ask_pass = read_int_number("          Enter password: ");
	}
	return true;
}
void add_new_student(studentinfo& student)
{
	if (check_admin_password())
	{
		cout << "         |Please enter the student infoermation|   \n";
		add_student(student);
		cout << "         |STUDENT WAS ADDED SUCCESSFULLY|         " << endl;
		cout << "         |PRESS ANY KEY TO GO THE MAIN MENU|        ";
		system("pause");
		system("cls");
		
		
	}
	else
	{
		cout << "         |SORRY YOU CAN NOT ADD NEW STUDENT|    " << endl;
		cout << "         |PRESS ANY KEY TO GO THE MAIN MENU|        ";
		system("pause");
	}
}
void show_search_menu()
{
	cout << "        || =====================SEARCH MENU========================= ||" << endl;
	cout << "        || enter [1] if you want to search by name.                  ||" << endl;
	cout << "        || enter [2] if you want to search by ID.                    ||" << endl;
	cout << "        || enter [3] if you want to go back.                         ||" << endl;

}
void search_student()
{
	vector<string>studentfile_search;
	load_file_to_vector(studentfile_search, "studentsinfo.txt");
	string search;
search:
	show_search_menu();
	int ask_search = read_int_number("         Enter [1],[2] or [3] : ", 3, 1);
	system("cls");
	if (ask_search == 1)
	{
	search_by_name:
		string fname = read_names("        || Enter Frist name : ");
		string lname = read_names("        || Enter last name : ");
		search = fname + " " + lname;
		if (search_for_student(studentfile_search, search) != -1)
		{

			int position = search_for_student(studentfile_search, search);
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Student name                    | " << setw(14) << studentfile_search[position] << setw(10) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Student ID                      | " << setw(12) << studentfile_search[position + 1] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Student age                     | " << setw(12) << studentfile_search[position + 2] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Student major                   | " << setw(12) << studentfile_search[position + 3] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Math result                     | " << setw(12) << studentfile_search[position + 4] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |islamic education result        | " << setw(12) << studentfile_search[position + 5] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |programmeing foundmebtals result| " << setw(12) << studentfile_search[position + 6] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |computer since result           | " << setw(12) << studentfile_search[position + 7] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |final result                    | " << setw(12) << studentfile_search[position + 8] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Average                         | " << setw(12) << studentfile_search[position + 9] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Total Grade                     | " << setw(12) << studentfile_search[position + 10] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl << endl;
		after_name_search_point:
			cout << "         Enter[1] if you want to go back.         " << endl;
			cout << "         Enter[2] if you want to edit student info.         " << endl;
			cout << "         Enter[3] if you want delete student.         " << endl;
			int ask_after_search = read_int_number("         Enter[1],[2] or [3]: ");
			system("cls");
			if (ask_after_search == 1)
				goto search;
			else if (ask_after_search == 2)
			{

				if (check_admin_password())
				{
					edit_by_name(studentfile_search, position);
					load_data_to_student_names_file(studentfile_search, "studentsinfo.txt");
					cout << "       ||student info edited successfully" << endl;
					system("pause");
					system("cls");
					goto search;
				}
				else
				{
					cout << "         |SORRY YOU CAN NOT EDIT THE STUDENT|    " << endl;
					system("pause");
					system("cls");
					goto after_name_search_point;
				}
			}
			else
			{
				if (check_admin_password())
				{
					delete_element_in_vectore_by_name(studentfile_search, position);
					load_data_to_student_names_file(studentfile_search, "studentsinfo.txt");
					cout << "       ||student deleted successfully" << endl;
					system("pause");
					system("cls");
					goto search;
				}
				else
				{
					cout << "         |SORRY YOU CAN NOT DELETE THE STUDENT|    " << endl;
					system("pause");
					system("cls");
					goto after_name_search_point;
				}
			}

		}
		else
		{
			cout << "        |STUDENT NOT FOUND|        " << endl;
			cout << "        Enter[1] to research       " << endl;
			cout << "        Enter[2] to go back       " << endl;
			int ask_not_found = read_int_number("        Enter[1] or [2]: ");
			system("cls");
			if (ask_not_found == 1)
				goto search_by_name;
			else
				goto search;
		}

	}
	else if (ask_search == 2)
	{

	search_by_ID:

		cout << "        ||Enter student ID: "; cin >> search;
		if (search_for_student(studentfile_search, search) != -1)
		{

			int position = search_for_student(studentfile_search, search);
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Student name                    | " << setw(14) << studentfile_search[position - 1] << setw(10) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Student ID                      | " << setw(12) << studentfile_search[position] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Student age                     | " << setw(12) << studentfile_search[position + 1] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Student major                   | " << setw(12) << studentfile_search[position + 2] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Math result                     | " << setw(12) << studentfile_search[position + 3] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |islamic education result        | " << setw(12) << studentfile_search[position + 4] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |programmeing foundmebtals result| " << setw(12) << studentfile_search[position + 5] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |computer since result           | " << setw(12) << studentfile_search[position + 6] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |final result                    | " << setw(12) << studentfile_search[position + 7] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Average                         | " << setw(12) << studentfile_search[position + 8] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl;
			cout << "         |Total Grade                     | " << setw(12) << studentfile_search[position + 9] << setw(12) << "|" << endl;
			cout << "         |--------------------------------|------------------------|" << endl << endl;
		after_ID_search_point:
			cout << "         Enter[1] if you want to go back.         " << endl;
			cout << "         Enter[2] if you want to edit student info.         " << endl;
			cout << "         Enter[3] if you want delete student.         " << endl;
			int ask_after_search = read_int_number("         Enter[1],[2] or [3]: ");
			if (ask_after_search == 1)
			{
				system("cls"); goto search;
			}
			else if (ask_after_search == 2)
			{
				if (check_admin_password())
				{
					edit_by_ID(studentfile_search, position);
					load_data_to_student_names_file(studentfile_search, "studentsinfo.txt");
					cout << "       ||student info edited successfully" << endl;
					system("pause");
					system("cls");
					goto search;
				}
				else
				{
					cout << "         |SORRY YOU CAN NOT DELETE THE STUDENT|    " << endl;
					system("pause");
					system("cls");
					goto after_ID_search_point;
				}
			}
			else
			{
				if (check_admin_password())
				{
					delete_element_in_vectore_by_ID(studentfile_search, position);
					load_data_to_student_names_file(studentfile_search, "studentsinfo.txt");
					cout << "       ||student deleted successfully" << endl;
					system("pause");
					system("cls");
					goto search;
				}
				else
				{
					cout << "         |SORRY YOU CAN NOT DELETE THE STUDENT|    " << endl;
					system("pause");
					system("cls");
					goto after_ID_search_point;
				}
			}
		}
		else
		{
			cout << "        |STUDENT NOT FOUND|        " << endl;
			cout << "        Enter[1] to research       " << endl;
			cout << "        Enter[2] to go back       " << endl;
			int ask_not_found = read_int_number("        Enter[1] or [2]: ");
			system("cls");
			if (ask_not_found == 1)
				goto search_by_ID;
			else
				goto search;



		}
	}
}
void show_main_menu()
{
	cout << "        || =====================MAIN MENU========================= ||" << endl;
	cout << "        || enter [1] if you want to search for student information.||" << endl;
	cout << "        || enter [2] if you want to add new student.               ||" << endl;
	cout << "        || enter [3] if you want to view all sudents.              ||" << endl;
	cout << "        || enter [4] if you want to exit                           ||" << endl;
}
void display_by_ID()
{
	vector<string>show;
	load_file_to_vector(show, "studentsinfo.txt");
	cout << "=====================================================================================================================" << endl;
	cout << "|NAME" << setw(20) << "|ID" << setw(23) << "|AGE" << setw(24) << "|MAJOR" << setw(24) << "|AVERAGE" << setw(20) << "|Grade" << endl;
	for (int i = 0; i < show.size(); i = i + 11)
	{
		cout << "|" << show[i] << setw(22 - show[i].size()) << "|" << show[i + 1] << setw(22 - show[i + 1].size()) << "|" << show[i + 2] << setw(22 - show[i + 2].size()) << "|" << show[i + 3] << setw(22 - show[i + 3].size()) << "|" << show[i + 9] << setw(22 - show[i + 9].size()) << "|" << show[i + 10] << endl;
	}
	system("pause");
	system("cls");
}
void copy_vector_if_major(vector<string>&source, vector<string>&dest)
{
	int position = 0;
	string major;
	cout << "enter the major : "; major = read_student_major(read_int_number("          Enter student major [1]CS, [2]IT, [3]IS, [4]CYS: ", 4, 1));
	for (int i = 0; i < source.size(); i++)
	{
		if (search_for_student(source, major) != -1)
		{
			position = search_for_student(source, major) - 3;
			dest.push_back(source[position]);
			dest.push_back(source[position+1]);
			dest.push_back(source[position+2]);
			dest.push_back(source[position+3]);
			dest.push_back(source[position+4]);
			dest.push_back(source[position+5]);
			dest.push_back(source[position+6]);
			dest.push_back(source[position+7]);
			dest.push_back(source[position+8]);
			dest.push_back(source[position+9]);
			dest.push_back(source[position+10]);
			delete_element_in_vectore_by_name(source, position);
		}
	
		
	}

}
void copy_vector_by_grade(vector<string>& source, vector<string>& dest)
{
	int position = 0;
	string grade = read_names("Enter the grade A,B,C,D,F : " ) ;
	
	for (int i = 0; i < source.size(); i++)
	{
		if (search_for_student(source, grade) != -1)
		{
			position = search_for_student(source, grade) - 10;
			dest.push_back(source[position]);
			dest.push_back(source[position + 1]);
			dest.push_back(source[position + 2]);
			dest.push_back(source[position + 3]);
			dest.push_back(source[position + 4]);
			dest.push_back(source[position + 5]);
			dest.push_back(source[position + 6]);
			dest.push_back(source[position + 7]);
			dest.push_back(source[position + 8]);
			dest.push_back(source[position + 9]);
			dest.push_back(source[position + 10]);
			delete_element_in_vectore_by_name(source, position);
		}


	}

}
void display_by_major()
{
	vector<string>show;
	load_file_to_vector(show, "studentsinfo.txt");
	
	try 
	{
		vector<string>temp;
		copy_vector_if_major(show, temp);
		cout << "=====================================================================================================================" << endl;
		cout << "|NAME" << setw(20) << "|ID" << setw(23) << "|AGE" << setw(24) << "|MAJOR" << setw(24) << "|AVERAGE" << setw(20) << "|Grade" << endl;
		for (int i = 0; i < temp.size(); i = i + 11)
		{
			cout << "|" << temp[i] << setw(22 - temp[i].size()) << "|" << temp[i + 1] << setw(22 - temp[i + 1].size()) << "|" << temp[i + 2] << setw(22 - temp[i + 2].size()) << "|" << temp[i + 3] << setw(22 - temp[i + 3].size()) << "|" << temp[i + 9] << setw(22 - temp[i + 9].size()) << "|" << temp[i + 10] << endl;
		}
	}
	catch( ... )

	{

		cout << "THERE IS NO STUDENT STUDYING THIS MAJOR AT THE CRRENT TIME.";
	}
	system("pause");
	system("cls");
}
void display_by_Grade()
{
	vector<string>show;
	load_file_to_vector(show, "studentsinfo.txt");

	try
	{
		vector<string>temp;
		copy_vector_by_grade(show, temp);
		cout << "=====================================================================================================================" << endl;
		cout << "|NAME" << setw(20) << "|ID" << setw(23) << "|AGE" << setw(24) << "|MAJOR" << setw(24) << "|AVERAGE" << setw(20) << "|Grade" << endl;
		for (int i = 0; i < temp.size(); i = i + 11)
		{
			cout << "|" << temp[i] << setw(22 - temp[i].size()) << "|" << temp[i + 1] << setw(22 - temp[i + 1].size()) << "|" << temp[i + 2] << setw(22 - temp[i + 2].size()) << "|" << temp[i + 3] << setw(22 - temp[i + 3].size()) << "|" << temp[i + 9] << setw(22 - temp[i + 9].size()) << "|" << temp[i + 10] << endl;
		}
	}
	catch (...)

	{

		cout << "THERE IS NO STUDENT STUDYING .";
	}
	system("pause");
	system("cls");
}
void show_all_student()
{
	display:
	cout << "        || =====================DISPLAY MENU========================= ||" << endl;
	cout << "        || enter [1] if you want to dIsplay by ID                     ||" << endl;
	cout << "        || enter [2] if you want to dIsplay by major                  ||" << endl;
	cout << "        || enter [3] if you want to dIsplay by Grade                  ||" << endl;
	cout << "        || enter [4] if you want to exit                              ||" << endl;
	int ask_display = read_int_number("         Enter[1],[2],[3] or [4]: ", 4, 1);
	system("cls");
	if (ask_display == 1)
	{
		display_by_ID();
		goto display;
	}
	else if (ask_display == 2)
	{
		display_by_major();
		goto display;
	}
	else if (ask_display == 3)
	{
		display_by_Grade();
		goto display;
	}


}

int main()
{
	srand((unsigned)time(NULL));
	studentinfo student;
	start:
	show_main_menu();
	int ask_main = read_int_number("         Enter[1],[2],[3] or [4]: ", 4, 1);
	system("cls");
	if (ask_main == 2)
	{
		add_new_student(student);
		goto start;
	}
	else if (ask_main == 1)
	{
		search_student();
		goto start;
	}
	else if(ask_main == 3)
	{
		
		show_all_student();
		
		system("cls");
		goto start;
	}



}

